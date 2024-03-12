#include "Equaliser.h"

Equaliser::Equaliser()
{
    
}
Equaliser::~Equaliser()
{

}

void Equaliser::prepareToPlay(int numChannels, float sampleRate)
{
    this->sampleRate = sampleRate;
    
    // make sure filters have no values
    lowFilters.clear();
    midFilters.clear();
    highFilters.clear();
    
    // add filters for each channels
    for(int i = 0; i <= numChannels; i++)
    {
        // Will these be delted - if not how to delete ?
        
        juce::IIRFilter* lowFilter = new juce::IIRFilter();
        lowFilters.add(lowFilter);
        
        juce::IIRFilter* midFilter = new juce::IIRFilter();
        midFilters.add(midFilter);
        
        juce::IIRFilter* highFilter = new juce::IIRFilter();
        highFilters.add(highFilter);
    }
}

void Equaliser::process(float* channelData, int channel, int numSamples, int mode)
{
    switch (mode) {
        case 0: // serial - low -> mid -> high
            return processSerial(channelData, channel, numSamples);
            break;
//        case 1: // parralel - low + mid + high
//            break;
    }
}

void Equaliser::makeCoefficients(float lowGainDb, float lowQ, float midGainDb, float midQ, float highGainDb, float highQ)
{
    // make IIR coefficients
    float lowGain = pow(10, lowGainDb / 20.0);
    auto lowCoefficients = juce::IIRCoefficients::makeLowShelf(sampleRate, lowFreq, lowQ, lowGain);
    
    float midGain = pow(10, midGainDb / 20.0);
    auto midCoefficients = juce::IIRCoefficients::makePeakFilter(sampleRate, midFreq, midQ, midGain);
    
    float highGain = pow(10, highGainDb / 20.0);
    auto highCoefficients = juce::IIRCoefficients::makeHighShelf(sampleRate, highFreq, highQ, highGain);
    
    // set coefs to each filter
    for (int i = 0; i < lowFilters.size(); i++) lowFilters[i]->setCoefficients(lowCoefficients);
    for (int i = 0; i < midFilters.size(); i++) midFilters[i]->setCoefficients(midCoefficients);
    for (int i = 0; i < highFilters.size(); i++) highFilters[i]->setCoefficients(highCoefficients);
}

void Equaliser::processSerial(float* channelData, int channel, int numSamples)
{
    lowFilters[channel]->processSamples(channelData, numSamples);
    midFilters[channel]->processSamples(channelData, numSamples);
    highFilters[channel]->processSamples(channelData, numSamples);

}
