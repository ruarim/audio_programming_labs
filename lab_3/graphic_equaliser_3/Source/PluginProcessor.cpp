/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Graphical_equaliser_3AudioProcessor::Graphical_equaliser_3AudioProcessor()
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
    // create equaliser filters - this is shared because the editor controls the parameters.
    eq = std::make_shared<EQFilters>();
}

Graphical_equaliser_3AudioProcessor::~Graphical_equaliser_3AudioProcessor()
{
}

//==============================================================================
const juce::String Graphical_equaliser_3AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Graphical_equaliser_3AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Graphical_equaliser_3AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Graphical_equaliser_3AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Graphical_equaliser_3AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Graphical_equaliser_3AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Graphical_equaliser_3AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Graphical_equaliser_3AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Graphical_equaliser_3AudioProcessor::getProgramName (int index)
{
    return {};
}

void Graphical_equaliser_3AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Graphical_equaliser_3AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    
    eq->prepare(spec);
}

void Graphical_equaliser_3AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Graphical_equaliser_3AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void Graphical_equaliser_3AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto numInputChannels  = getTotalNumInputChannels();
    auto numOutputChannels = getTotalNumOutputChannels();

    for (auto i = numInputChannels; i < numOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // mid-side equalisation
    // add mono freq control?
    //      - low shelf filter is mono?

    eq->makeCoefficients();

    // white noise for testing standalone
    for (int channel = 0; channel < numInputChannels; ++channel)
    {
        int numSamples = buffer.getNumSamples();
        auto* channelData = buffer.getWritePointer(channel);
        
        for (int i = 0; i < numSamples; ++i) channelData[i] = 2.0f * rand() / (float)RAND_MAX - 1.0f;
    }
    
    juce::dsp::AudioBlock <float> block (buffer);
    eq->process(block);
}

//==============================================================================
bool Graphical_equaliser_3AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Graphical_equaliser_3AudioProcessor::createEditor()
{
    return new Graphical_equaliser_3AudioProcessorEditor(*this);
}

//==============================================================================
void Graphical_equaliser_3AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Graphical_equaliser_3AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Graphical_equaliser_3AudioProcessor();
}
