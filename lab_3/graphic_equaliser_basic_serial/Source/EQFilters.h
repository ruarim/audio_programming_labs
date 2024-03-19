/*
  ==============================================================================

    EQFilters.h
    Created: 10 Mar 2024 1:33:17am
    Author:  Ruari Molyneux

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class EQFilters
{
public:
    EQFilters();
    ~EQFilters();
    
    void prepareToPlay(int numChannels, float sampleRate);
    void process(float* channelData, int channel, int numSamples);
    void makeCoefficients();
    
    // expose eq params
    float lowGainDb = 0.0f; // initalise to 0 dB gain
    float lowQ = 0.2f; // q value must be initalised to > 0 - 0.2 is chosen here
     
    float lowMidGainDb = 0.0f;
    float lowMidQ = 0.2f;
    
    float highMidGainDb = 0.0f;
    float highMidQ = 0.2f;
     
    float highGainDb = 0.0f;
    float highQ = 0.2;
    
private:
    float sampleRate = 0;
    
    // center frequncies based on ISO 266 - https://www.iso.org/standard/1350.html
    // low shelf
    juce::OwnedArray<juce::IIRFilter> lowFilters;
    const float lowFreq = 80.0f;
    
    // low mid peaking
    juce::OwnedArray<juce::IIRFilter> lowMidFilters;
    const float lowMidFreq = 315.0f;
    
    // high mid peaking
    juce::OwnedArray<juce::IIRFilter> highMidFilters;
    const float highMidFreq = 1250.0f;
    
    // high shelf
    juce::OwnedArray<juce::IIRFilter> highFilters;
    const float highFreq = 5000.0f;

    
    void processSerial(float* channelData, int channel, int numSamples);
    float dBToLinear(float dbGain);
};
