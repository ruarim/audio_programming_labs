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
    
    void prepare(const juce::dsp::ProcessSpec &spec);
    void process(const juce::dsp::ProcessContextReplacing<float>& context);
    void makeCoefficients();
    void setFilterGains();
    
    // expose eq params - change to lowPassGainDb
    float lowGainDb = 0.0f; // initalise to 0 dB gain
    float lowQ      = 0.2f; // initalise q to 0.2 value must be initalised to > 0.0
     
    float lowMidGainDb = 0.0f;
    float lowMidQ      = 0.2f;
    
    float highMidGainDb = 0.0f;
    float highMidQ      = 0.2f;
     
    float highGainDb = 0.0f;
    float highQ      = 0.2;
    
private:
    float sampleRate = 0.0f;
    
    // center frequncies based on ISO 266 Nominal Center Frequency range - https://en.wikipedia.org/wiki/Preferred_number#Audio_frequencies
    // low cut
    static constexpr float lowPassFreq      = 80.0f;
    
    // low mid band
    static constexpr float lowMidBandFreq   = 315.0f;
    
    // high mid band
    static constexpr float highMidBandFreq  = 1250.0f;
    
    // high cut
    static constexpr float highPassFreq     = 5000.0f;
    
    // store index
    enum {
        highPassIndex,
        lowMidBandIndex,
        highMidBandIndex,
        lowPassIndex,
    };
    
    static const int numFilters = 4;
    
    // define IIR Filter and its associated coefficients type aliases to simplify code
    using Filter       = juce::dsp::IIR::Filter<float>;
    using Coefficients = juce::dsp::IIR::Coefficients <float>;
    // define stereo IIR filter and Gain types
    using StereoIIR    = juce::dsp::ProcessorDuplicator<Filter, Coefficients>;
    using Gain         = juce::dsp::Gain<float>;
    
    // filters and gains - one for each eq band
    std::array<StereoIIR, numFilters> filters;
    std::array<Gain,      numFilters> gains;
        
    // temp buffers for non replacing context
    static constexpr auto numTempBuffers = numFilters - 1;
    
    // define temp buffers
    std::array<juce::HeapBlock<char>,        numTempBuffers> tempBuffersMemory;
    std::array<juce::dsp::AudioBlock<float>, numTempBuffers> tempBlocks;
};
