/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#define FILTER_SKEW_FACTOR 0.25f


//==============================================================================
Karplus_strong_1AudioProcessor::Karplus_strong_1AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                         .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
                         .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
      )
#endif
{
    // set precise ranges
    auto widthRange = juce::NormalisableRange<float>(0.001f, 0.02f);
    auto filterRange = juce::NormalisableRange<float>(50.0f, 10000.0f, FILTER_SKEW_FACTOR);

    // create parameters
    addParameter(burstSignalParam = new juce::AudioParameterChoice("burstSignal", "Burst Signal", {"Noise", "Sine", "Square", "Triangle", "Saw"}, 0));
    addParameter(pluckParam = new juce::AudioParameterBool("pluck", "Pluck string - Press Spacebar", 0));
    addParameter(delayFeedbackParam = new juce::AudioParameterFloat("feedback", "Decay", 0.80f, 0.999f, 0.90f));
    addParameter(widthParam = new juce::AudioParameterFloat("width", "Width", widthRange, 0.01f));
    addParameter(burstGainParam = new juce::AudioParameterFloat("bustGain", "Burst Gain", 0.0f, 1.0f, 0.5f));
    addParameter(freqParam = new juce::AudioParameterFloat("burstFreq", "Burst Freq", 20.0f, 1000.0f, 800.0f));
    addParameter(filterCutoffParam = new juce::AudioParameterFloat("filterCutoff", "Filter Cutoff", filterRange, 5000.0f));
    addParameter(driveParam = new juce::AudioParameterFloat("drive", "Drive", 0.5f, 0.99f, 0.5f));
    addParameter(noteFreqParam = new juce::AudioParameterFloat("noteFreq", "Note Frequency", 20.0f, 2000.0f, 440.0f));

    delayBuffer = new CircularBuffer();
}

Karplus_strong_1AudioProcessor::~Karplus_strong_1AudioProcessor()
{
    delete (delayBuffer);
}

void Karplus_strong_1AudioProcessor::spaceBarPluck(bool &pluck)
{
    if (juce::KeyPress::isKeyCurrentlyDown(juce::KeyPress::spaceKey) && !burstOn)
    {
        pluck = true;
        burstOn = true;
    }
    else if (!juce::KeyPress::isKeyCurrentlyDown(juce::KeyPress::spaceKey))
        burstOn = false;
}

float Karplus_strong_1AudioProcessor::calcBurstSignal(int choice, float phase, float gain)
{
    float sine = gain * sinf(juce::MathConstants<float>::twoPi * phase);

    switch (choice)
    {
        case 0: // noise
            return (2.0f * (((float)rand() / RAND_MAX) - 0.5f)) * gain;
        case 1: // sine
            return sine;
        case 2: // square
            return (sine >= 0) ? gain : -gain;
        case 3: // triangle
            return (2.0f * std::abs(2.0f * (phase - std::floor(phase + 0.5f))) - 1.0f) * gain;
        case 4: // saw
            return (2.0f * (phase - std::floor(phase) - 0.5f)) * gain;
        default:
            return 0.0f;
    }
}

float Karplus_strong_1AudioProcessor::freqToDelayTime(float freq, float sampleRate)
{
    int samplesDelay = sampleRate / freq;
    return samplesDelay / sampleRate;
}

//==============================================================================
const juce::String Karplus_strong_1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Karplus_strong_1AudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool Karplus_strong_1AudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool Karplus_strong_1AudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double Karplus_strong_1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Karplus_strong_1AudioProcessor::getNumPrograms()
{
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
              // so this should be at least 1, even if you're not really implementing programs.
}

int Karplus_strong_1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Karplus_strong_1AudioProcessor::setCurrentProgram(int index)
{
}

const juce::String Karplus_strong_1AudioProcessor::getProgramName(int index)
{
    return {};
}

void Karplus_strong_1AudioProcessor::changeProgramName(int index, const juce::String &newName)
{
}

//==============================================================================
void Karplus_strong_1AudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    int inChannels = getTotalNumInputChannels();

    // init circular buffer
    delayBuffer->prepareToPlay(sampleRate, maxDelayTimeSeconds, inChannels);
    delayBuffer->setReadPosition(delayTime, sampleRate);
}

void Karplus_strong_1AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Karplus_strong_1AudioProcessor::isBusesLayoutSupported(const BusesLayout &layouts) const
{
#if JucePlugin_IsMidiEffect
    juce::ignoreUnused(layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

        // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif

    return true;
#endif
}
#endif

void Karplus_strong_1AudioProcessor::processBlock(juce::AudioBuffer<float> &buffer, juce::MidiBuffer &midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    // Buffer info
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    int numSamples = buffer.getNumSamples();
    double sampleRate = getSampleRate();

    // Delay, burst, pluck params from gui
    noteFreq = noteFreqParam->get();

    // Get delay time from pitch(Hz)
    delayTime = freqToDelayTime(noteFreq, sampleRate);
    delayFeedback = delayFeedbackParam->get();
    burstWidth = widthParam->get();

    // Pluck string from gui
    bool pluck = pluckParam->get();

    // Pluck string on spacebar down
    spaceBarPluck(pluck);

    // Update buffer read positions
    delayBuffer->setReadPosition(delayTime, sampleRate);

    // get burst gain of pucked and set pluck toggle to false
    if (pluck)
    {
        pluckParam->setValueNotifyingHost(0);
        burstGain = burstGainParam->get();
    }

    // loop through samples
    for (int i = 0; i < numSamples; ++i)
    {
        // calculate burst signal for both channels
        float burst = 0.0;

        // only calculate burst gain above 0
        if (burstGain > 0.0)
        {
            // get burst frequency
            burstFreq = freqParam->get();

            // calculate phase
            phase += burstFreq / sampleRate;

            // wrap phase
            if (phase >= 1.0)
                phase -= 1.0;

            // calcuated selected burst signal type
            burstChoice = burstSignalParam->getIndex();

            // create signal
            burst = calcBurstSignal(burstChoice, phase, burstGain);
        }
        else
            phase = 0.0f; // reset phase every pluck
        
        // loop through channels
        for (int j = 0; j < totalNumInputChannels; ++j)
        {
            // get buffer read / write positions
            int delayReadPosition = delayBuffer->readPosition;
            int delayWritePosition = delayBuffer->writePosition;

            // get delay data
            float *delayData = delayBuffer->getWritePointer(j);

            // apply delay
            float delayed = burst + delayData[delayReadPosition];

            // filter delay line with first order IIR
            float cutoff = filterCutoffParam->get();

            // alpha coefficient eq - 1 / 1 + (fs / 2 * pi * fc) - fs = sample rate fc = filter cutoff
            float alpha = 1 / (1 + (sampleRate / (2.0f * juce::MathConstants<float>::pi * cutoff)));
            
            // first order IIR filter transfer function - y[n] = a * x[n] + (1 - a) * y[n-1]
            float filtered = alpha * delayed + (1 - alpha) * prevFiltered;
            
            // store previous filtered sample
            prevFiltered = filtered;
            
            // write to delay buffer
            delayData[delayWritePosition] = filtered * delayFeedback;

            // write currrent output to buffer
            float out = delayData[delayReadPosition];

            // apply tanh saturation
            drive = driveParam->get();
            out = tanh(drive * out);
            
            // write output to buffer
            buffer.getWritePointer(j)[i] = out;
        }

        // length of burst in samples
        int burstSamples = (burstWidth * (float)sampleRate);
        // gradually reduce burst gain over burst length in samples
        if (burstGain >= 0.0)
            burstGain = burstGain - 1.0 / burstSamples;

        // wrap buffer
        delayBuffer->wrapBuffer();
    }

    // In case we have more outputs than inputs, clear any output channels that didn't contain input data
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    {
        buffer.clear(i, 0, numSamples);
    }
}

//==============================================================================
bool Karplus_strong_1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor *Karplus_strong_1AudioProcessor::createEditor()
{
    return new juce::GenericAudioProcessorEditor(*this);
}

//==============================================================================
void Karplus_strong_1AudioProcessor::getStateInformation(juce::MemoryBlock &destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Karplus_strong_1AudioProcessor::setStateInformation(const void *data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter()
{
    return new Karplus_strong_1AudioProcessor();
}
