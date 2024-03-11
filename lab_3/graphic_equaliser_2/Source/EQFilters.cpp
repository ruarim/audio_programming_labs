/*
  ==============================================================================

    EQFilters.cpp
    Created: 10 Mar 2024 1:33:17am
    Author:  Ruari Molyneux

  ==============================================================================
*/

#include "EQFilters.h"

EQFilters::EQFilters(){}
EQFilters::~EQFilters(){}

void EQFilters::prepareToPlay(int numChannels, float sampleRate)
{
    this->sampleRate = sampleRate;
    
    // make sure filters have no values
    lowFilters.clear();
    lowMidFilters.clear();
    highMidFilters.clear();
    highFilters.clear();
    
    // add filters for each channels
    for(int i = 0; i <= numChannels; i++)
    {
        // Will these be delted - if not how to delete ?
        
        juce::IIRFilter* lowFilter = new juce::IIRFilter();
        lowFilters.add(lowFilter);
        
        juce::IIRFilter* lowMidFilter = new juce::IIRFilter();
        lowMidFilters.add(lowMidFilter);
        
        juce::IIRFilter* highMidFilter = new juce::IIRFilter();
        highMidFilters.add(highMidFilter);
        
        juce::IIRFilter* highFilter = new juce::IIRFilter();
        highFilters.add(highFilter);
    }
}

void EQFilters::process(float* channelData, int channel, int numSamples)
{
    processSerial(channelData, channel, numSamples);
}

void EQFilters::makeCoefficients()
{
    // make IIR coefficients
    float lowGain = dBToLinear(lowGainDb); // convert dB gain to linear gain
    auto lowCoefficients = juce::IIRCoefficients::makeLowShelf(sampleRate, lowFreq, lowQ, lowGain);
    
    float lowMidGain = dBToLinear(lowMidGainDb);
    auto lowMidCoefficients = juce::IIRCoefficients::makePeakFilter(sampleRate, lowMidFreq, lowMidQ, lowMidGain);
    
    float highMidGain = dBToLinear(highMidGainDb);
    auto highMidCoefficients = juce::IIRCoefficients::makePeakFilter(sampleRate, highMidFreq, highMidQ, highMidGain);
    
    float highGain = dBToLinear(highGainDb);
    auto highCoefficients = juce::IIRCoefficients::makeHighShelf(sampleRate, highFreq, highQ, highGain);
    
    // set coefs for each filter
    for (int i = 0; i < lowFilters.size(); i++) lowFilters[i]->setCoefficients(lowCoefficients);
    for (int i = 0; i < lowMidFilters.size(); i++) lowMidFilters[i]->setCoefficients(lowMidCoefficients);
    for (int i = 0; i < highMidFilters.size(); i++) highMidFilters[i]->setCoefficients(highMidCoefficients);
    for (int i = 0; i < highFilters.size(); i++) highFilters[i]->setCoefficients(highCoefficients);
}

void EQFilters::processSerial(float* channelData, int channel, int numSamples)
{
    lowFilters[channel]->processSamples(channelData, numSamples);
    lowMidFilters[channel]->processSamples(channelData, numSamples);
    highMidFilters[channel]->processSamples(channelData, numSamples);
    highFilters[channel]->processSamples(channelData, numSamples);

}

float EQFilters::dBToLinear(float dbGain)
{
    return pow(10, dbGain / 20.0);
}
