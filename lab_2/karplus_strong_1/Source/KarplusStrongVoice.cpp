/*
  ==============================================================================

    KarplusStrongVoice.cpp
    Created: 19 Feb 2024 4:18:36pm
    Author:  Ruari Molyneux

  ==============================================================================
*/

#include "KarplusStrongVoice.h"
#include <JuceHeader.h>
#include "KarplusStrongSound.h"

KarplusStrongVoice::KarplusStrongVoice()
{
    delayBuffer = new CircularBuffer();
}

KarplusStrongVoice::~KarplusStrongVoice()
{
    delete (delayBuffer);
}

// OVERRIDES
void KarplusStrongVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* /*sound*/, int)
{
    //burstOn = true;
    
    notePitch = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    burstGain = velocity / 1.0f;
}

void KarplusStrongVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
    //burstOn = false;
    
    clearCurrentNote();
}

void KarplusStrongVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    sampleRate = getSampleRate();
    
    // Update buffer read positions
    delayBuffer->setReadPosition(delayTime, sampleRate);

    // loop through samples
    for (int i = 0; i < numSamples; ++i)
    {
        // calculate burst signal for both channels
        float burst = 0.0;
        
        // only calculate burst gain above 0
        if (burstGain > 0.0)
        {
            // calculate phase
            phase += burstFreq / sampleRate;
            
            // wrap phase
            if (phase >= 1.0)
                phase -= 1.0;
            
            // create signal
            burst = calcBurstSignal(burstChoice, phase, burstGain);
        }
        else
            phase = 0.0f; // reset phase every pluck
        
        // loop through channels
        for (int j = 0; j < outputBuffer.getNumChannels(); ++j)
        {
            // get buffer read / write positions
            int delayReadPosition = delayBuffer->readPosition;
            int delayWritePosition = delayBuffer->writePosition;
            
            // get delay data
            float *delayData = delayBuffer->getWritePointer(j);
            
            // apply delay
            float delayed = burst + delayData[delayReadPosition] * delayFeedback;
            
            // alpha coefficient eq - 1 / 1 + (fs / 2 * pi * fc) - fs = sample rate fc = filter cutoff
            float alpha = 1 / (1 + (sampleRate / (2.0f * juce::MathConstants<float>::pi * filterCutoff)));
            
            // first order IIR filter transfer function - y[n] = a * x[n] + (1 - a) * y[n-1]
            float filtered = alpha * delayed + (1 - alpha) * (delayWritePosition > 0 ? delayData[delayWritePosition - 1] : delayed);
            
            // write to delay buffer
            delayData[delayWritePosition] = filtered;
            
            // write currrent output to buffer
            float out = burst + delayData[delayReadPosition]; // only apply delay if time > 0
            
            // apply tanh saturation
            out = tanh(drive * out);
            
            // render output
            outputBuffer.getWritePointer(j)[i] = out;
        }
        
        
        // length of burst in samples
        int burstSamples = (burstWidth * (float)sampleRate);
        // gradually reduce burst gain over burst length in samples
        if (burstGain >= 0.0)
            burstGain = burstGain - 1.0 / burstSamples;
        
        // wrap buffer
        delayBuffer->wrapBuffer();
    }
}

// HELPER FUNCTIONS
void::KarplusStrongVoice::setupDelayBuffer(int inChannels)
{
    delayBuffer->prepareToPlay(getSampleRate(), 2.0f, inChannels);
    delayBuffer->setReadPosition(delayTime, getSampleRate());
}

void KarplusStrongVoice::setVoiceParams(float burstWidth, int burstChoice, float delayTime, float delayFeedback, float drive, float filterCutoff)
{
    this->burstWidth = burstWidth;
    this->burstChoice = burstChoice;
    this->delayTime = delayTime;
    this->delayFeedback = delayFeedback;
    this->drive = drive;
    this->filterCutoff = filterCutoff;
}
    
float KarplusStrongVoice::calcBurstSignal(int choice, float phase, float gain)
{
    float sine = gain * sinf(juce::MathConstants<float>::twoPi * phase);

    switch (choice)
    {
    case 0: // noise
        return 2.0 * gain * ((double)rand() / RAND_MAX - 1.0);
    case 1: // sine
        return sine;
    case 2: // square
        return (sine >= 0) ? gain : -gain;
    case 3: // triangle
        return (2.0f * std::abs(2.0f * (phase - std::floor(phase + 0.5f))) - 1.0f) * gain;
    case 4: // saw
        return (2.0f * (phase - std::floor(phase)) - 1) * gain;
    default:
        return 0.0f;
    }
}

float KarplusStrongVoice::pitchToDelayTime(float pitch, float sampleRate)
{
    int samplesDelay = sampleRate / pitch;
    return samplesDelay / sampleRate;
}
