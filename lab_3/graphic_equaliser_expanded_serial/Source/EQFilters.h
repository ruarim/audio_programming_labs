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
    
    // expose eq params
    float lowGainDb = 0.0f; // initalise to 0 dB gain
    float lowQ = 0.2f; // initalise q to 0.2 value must be initalised to > 0
     
    float lowMidGainDb = 0.0f;
    float lowMidQ = 0.2f;
    
    float highMidGainDb = 0.0f;
    float highMidQ = 0.2f;
     
    float highGainDb = 0.0f;
    float highQ = 0.2;
    
private:
    float sampleRate = 0.0f;
    
    // center frequncies based on ISO 266 - https://www.iso.org/standard/1350.html
    // low cut
    const float lowFreq = 80.0f;
    
    // low mid peaking
    const float lowMidFreq = 315.0f;
    
    // high mid peaking
    const float highMidFreq = 1250.0f;
    
    // high cut
    const float highFreq = 5000.0f;
    
    // setup the juce dsp processor chain
    enum {
        lowShelfIndex,
        lowMidPeakIndex,
        highMidPeakIndex,
        highShelfIndex,
    };
    
    // creating type alises to simplify the code.
    // types alises for an IIR Filter and its associated coefficients
    using Filter = juce::dsp::IIR::Filter<float>; // the maths
    using Coefficients = juce::dsp::IIR::Coefficients <float>; // the state
    
    // define a stereo IIR filter type alias
    using StereoIIR = juce::dsp::ProcessorDuplicator<Filter, Coefficients>;
    
    // create a processor chain for the filters - one for each of the eq bands
    juce::dsp::ProcessorChain<StereoIIR, StereoIIR, StereoIIR, StereoIIR> processorChain;
    
    void processSerial(float* channelData, int channel, int numSamples);
    float dBToLinear(float dbGain);
};
