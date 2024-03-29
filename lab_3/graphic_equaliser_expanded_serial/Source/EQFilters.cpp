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

void EQFilters::prepare(const juce::dsp::ProcessSpec &spec)
{
    // save sample rate for coefficient calculation
    sampleRate = spec.sampleRate;
    
    // make sure the processor chain is cleared.
    processorChain.reset();
    
    // prepare the chain for processing based on the provided spec
    processorChain.prepare(spec);
}

void EQFilters::process(const juce::dsp::ProcessContextReplacing<float>& context)
{
    processorChain.process(context);
}

void EQFilters::makeCoefficients()
{
    // define coefficients type to simplify the code and reduce typing
    // using the ArrayCoefficients type for audio thread-safety
    using IIRCoefficients = juce::dsp::IIR::ArrayCoefficients<float>;
    
    // make IIR coefficients
    float lowGain = dBToLinear(lowGainDb); // convert dB gain to linear gain
    auto lowCoefficients = IIRCoefficients::makeLowShelf(sampleRate, lowFreq, lowQ, lowGain);
    
    float lowMidGain = dBToLinear(lowMidGainDb);
    auto lowMidCoefficients = IIRCoefficients::makePeakFilter(sampleRate, lowMidFreq, lowMidQ, lowMidGain);
    
    float highMidGain = dBToLinear(highMidGainDb);
    auto highMidCoefficients = IIRCoefficients::makePeakFilter(sampleRate, highMidFreq, highMidQ, highMidGain);
    
    float highGain = dBToLinear(highGainDb);
    auto highCoefficients = IIRCoefficients::makeHighShelf(sampleRate, highFreq, highQ, highGain);
    
    // apply the coefficients to each filters state.
    StereoIIR& lowShelf = processorChain.get<lowShelfIndex>();
    *lowShelf.state = lowCoefficients;
    
    StereoIIR& lowMidPeak = processorChain.get<lowMidPeakIndex>();
    *lowMidPeak.state = lowMidCoefficients;
    
    StereoIIR& highMidPeak = processorChain.get<highMidPeakIndex>();
    *highMidPeak.state = highMidCoefficients;
    
    StereoIIR& highShelf = processorChain.get<highShelfIndex>();
    *highShelf.state = highCoefficients;

}

float EQFilters::dBToLinear(float dbGain)
{
    return pow(10, dbGain / 20.0);
}
