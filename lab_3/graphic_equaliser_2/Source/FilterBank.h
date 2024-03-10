/*
  ==============================================================================

    FilterBank.h
    Created: 10 Mar 2024 1:33:17am
    Author:  Ruari Molyneux

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class FilterBank
{
public:
    FilterBank();
    ~FilterBank();
    
    void prepareToPlay(int numChannels, float sampleRate);
    void process(float* channelData, int channel, int numSamples);
    void makeCoefficients();
    
    // expose eq params
    float lowGainDb = 0.0f;
    float lowQ = 0.1f;
     
    float lowMidGainDb = 0.0f;
    float lowMidQ = 0.1f;
    
    float highMidGainDb = 0.0f;
    float highMidQ = 0.1f;
     
    float highGainDb = 0.0f;
    float highQ = 0.1;
    
private:
    float sampleRate = 0;
    
    // low shelf
    juce::OwnedArray<juce::IIRFilter> lowFilters;
    const float lowFreq = 400.0f;
    
    // low mid peaking
    juce::OwnedArray<juce::IIRFilter> lowMidFilters;
    const float lowMidFreq = 3000.0f;
    
    // high mid peaking
    juce::OwnedArray<juce::IIRFilter> highMidFilters;
    const float highMidFreq = 6000.0f;
    
    // high shelf
    juce::OwnedArray<juce::IIRFilter> highFilters;
    const float highFreq = 16000.0f;

    
    void processSerial(float* channelData, int channel, int numSamples);
};
