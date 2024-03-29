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
    
    // create buffers for each filter - gain can be applied in the place to these buffers.
    for (size_t i = 0; i < numTempBuffers; ++i)
        tempBlocks[i] = juce::dsp::AudioBlock<float> (tempBuffersMemory[i], spec.numChannels, spec.maximumBlockSize);
    
    // setup the filters
    for (auto& f : filters)
        f.prepare (spec); // prepare state
    
    // setup the gains
    for (auto& p : gains)
        p.prepare (spec);
}

void EQFilters::process(const juce::dsp::ProcessContextReplacing<float>& context)
{
    // get block sample count
    const auto numSamples = context.getInputBlock().getNumSamples();
    
    // create array for sub blocks of input buffer
    std::array<juce::dsp::AudioBlock<float>, numTempBuffers> processingTempBlocks;
    
    // parallel process each filter seperatly
    for(size_t i = 0; i < numTempBuffers; ++i)
    {
        // only get the block needed for processing - since the block may be < max block size.
        processingTempBlocks[i] = tempBlocks[i].getSubBlock (0, numSamples);
        
        // apply filtering to temp buffers
        juce::dsp::ProcessContextNonReplacing<float> nonReplacingContext(context.getInputBlock(), processingTempBlocks[i]);
        filters[i].process(nonReplacingContext);
    
        // apply gain to temp block
        juce::dsp::ProcessContextReplacing<float> replacingContext(processingTempBlocks[i]);
        gains[i].process(replacingContext);
    }
    
    // the last filter can be processed in place
    filters.back().process (context);
    gains  .back().process(context);
    
    // add the temp buffers to the output buffer
    for (auto& tempBlock : processingTempBlocks)
        context.getOutputBlock() += tempBlock;
}

void EQFilters::makeCoefficients()
{
    // define coefficients type to simplify the code
    using IIRCoefficients = juce::dsp::IIR::ArrayCoefficients<float>; // using the ArrayCoefficients type for audio thread-safety
    
    // make IIR coefficients
    auto lowCoefficients     = IIRCoefficients::makeLowPass(sampleRate, lowPassFreq, lowQ);
        
    auto lowMidCoefficients  = IIRCoefficients::makeBandPass(sampleRate, lowMidBandFreq, lowMidQ);
    
    auto highMidCoefficients = IIRCoefficients::makeBandPass(sampleRate, highMidBandFreq, highMidQ);
    
    auto highCoefficients    = IIRCoefficients::makeHighPass(sampleRate, highPassFreq, highQ);
    
    // apply the coefficients to each filters state.
    StereoIIR& lowPass     = filters[lowPassIndex];
    *lowPass.state         = lowCoefficients;
    
    StereoIIR& lowMidBand  = filters[lowMidBandIndex];
    *lowMidBand.state      = lowMidCoefficients;
    
    StereoIIR& highMidBand = filters[highMidBandIndex];
    *highMidBand.state     = highMidCoefficients;

    StereoIIR& highPass    = filters[highPassIndex];
    *highPass.state        = highCoefficients;
}

void EQFilters::setFilterGains()
{
    gains[lowPassIndex]    .setGainDecibels(lowGainDb);
    gains[lowMidBandIndex] .setGainDecibels(lowMidGainDb);
    gains[highMidBandIndex].setGainDecibels(highMidGainDb);
    gains[highPassIndex]   .setGainDecibels(highGainDb);
}
