/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Graphical_equaliser_4AudioProcessor::Graphical_equaliser_4AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    // create equaliser filters shared pointer
    eq = std::make_shared<EQFilters>();
}

Graphical_equaliser_4AudioProcessor::~Graphical_equaliser_4AudioProcessor()
{
}

//==============================================================================
const juce::String Graphical_equaliser_4AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Graphical_equaliser_4AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Graphical_equaliser_4AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Graphical_equaliser_4AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Graphical_equaliser_4AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Graphical_equaliser_4AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Graphical_equaliser_4AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Graphical_equaliser_4AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Graphical_equaliser_4AudioProcessor::getProgramName (int index)
{
    return {};
}

void Graphical_equaliser_4AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Graphical_equaliser_4AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // create processing spec
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    
    // pass the spec to the equaliser
    eq->prepare(spec);
}

void Graphical_equaliser_4AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Graphical_equaliser_4AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Graphical_equaliser_4AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto numInputChannels  = getTotalNumInputChannels();
    auto numOutputChannels = getTotalNumOutputChannels();
    for (auto i = numInputChannels; i < numOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // set up eq fitlers
    eq->makeCoefficients();
    eq->setFilterGains();
    
    // create processing context
    juce::dsp::AudioBlock <float> block (buffer);
    juce::dsp::ProcessContextReplacing<float> context (block);
    
    // apply equaliser to the processing context
    eq->process(context);
}

//==============================================================================
bool Graphical_equaliser_4AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Graphical_equaliser_4AudioProcessor::createEditor()
{
    return new Graphical_equaliser_4AudioProcessorEditor(*this);
}

//==============================================================================
void Graphical_equaliser_4AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Graphical_equaliser_4AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Graphical_equaliser_4AudioProcessor();
}
