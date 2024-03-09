/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Graphical_equaliserAudioProcessor::Graphical_equaliserAudioProcessor()
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
    // create equaliser
    eq = new Equalizer();
}

Graphical_equaliserAudioProcessor::~Graphical_equaliserAudioProcessor()
{
    delete eq;
}

//==============================================================================
const juce::String Graphical_equaliserAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Graphical_equaliserAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Graphical_equaliserAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Graphical_equaliserAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Graphical_equaliserAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Graphical_equaliserAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Graphical_equaliserAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Graphical_equaliserAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Graphical_equaliserAudioProcessor::getProgramName (int index)
{
    return {};
}

void Graphical_equaliserAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Graphical_equaliserAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    int numChannels = getTotalNumInputChannels();
    eq->prepareToPlay(numChannels, sampleRate);
}

void Graphical_equaliserAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Graphical_equaliserAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void Graphical_equaliserAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
//    juce::ScopedNoDenormals noDenormals;
//    auto numInputChannels  = getTotalNumInputChannels();
//    auto numOutputChannels = getTotalNumOutputChannels();
//
//    for (auto i = numInputChannels; i < numOutputChannels; ++i)
//        buffer.clear (i, 0, buffer.getNumSamples());
//
//
//    // mid-side equalisation
//    // add mono freq control?
//    //      - low shelf filter is mono?
//
//    eq->makeCoefficients();
//
//    for (int channel = 0; channel < numInputChannels; ++channel)
//    {
//        int numSamples = buffer.getNumSamples();
//        auto* channelData = buffer.getWritePointer(channel);
//
//        eq->process(channelData, channel, numSamples, processingMode);
//    }
}

//==============================================================================
bool Graphical_equaliserAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Graphical_equaliserAudioProcessor::createEditor()
{
    return new Graphical_equaliserAudioProcessorEditor(*this);
}   

//==============================================================================
void Graphical_equaliserAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Graphical_equaliserAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Graphical_equaliserAudioProcessor();
}
