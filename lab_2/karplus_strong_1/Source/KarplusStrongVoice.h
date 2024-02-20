/*
  ==============================================================================

    KarplusStrongVoice.h
    Created: 19 Feb 2024 4:18:36pm
    Author:  Ruari Molyneux

  ==============================================================================
*/

#pragma once

#include "KarplusStrongVoice.h"
#include <JuceHeader.h>
#include "KarplusStrongSound.h"
#include "CircularBuffer.h"

class KarplusStrongVoice : public juce::SynthesiserVoice {
public:
    KarplusStrongVoice();
    ~KarplusStrongVoice();

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}
    bool canPlaySound(juce::SynthesiserSound* sound) override { return dynamic_cast<KarplusStrongSound*> (sound) != nullptr; }
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* /*sound*/, int) override;
    void stopNote(float /*velocity*/, bool allowTailOff) override;
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    
    //Helpers
    void setVoiceParams(float burstWidth, int burstChoice, float delayTime, float delayFeedback, float drive, float filterCutoff);
    void setupDelayBuffer(int inChannels);
    
private:
    // Buffer Params
    float sampleRate = 0.0f;
    
    // Note pitch
    float notePitch = 440.0f;
        
    // Burst
    bool burstOn = false;
    float burstGain = 0.0f;
    float burstWidth = 0.0f;
    int burstChoice = 0;
    float burstFreq = 0.0f;
    float phase = 0.0f;
    
    // Delay - params
    float delayTime = 0.0f;
    float delayFeedback = 0.0f;
    
    // Drive
    float drive = 0.0f;
    
    // Filter
    float filterCutoff = 0.0f;
    
    // Delay Buffer
    CircularBuffer* delayBuffer;
    
    // Helpers
    float calcBurstSignal(int choice, float phase, float gain);
    float pitchToDelayTime(float pitch, float sampleRate);
};
