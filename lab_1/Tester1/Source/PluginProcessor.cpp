/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Tester1AudioProcessor::Tester1AudioProcessor()
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
    addParameter(gainParam = new juce::AudioParameterFloat("gain", "Gain", 0.0f, 1.0f, 0.0f));
    addParameter(testSignalParam = new juce::AudioParameterChoice("testSignal", "Test Signal", {"Noise", "Sine", "Pulse"}, 0));
    addParameter(freqParam = new juce::AudioParameterFloat("freq", "Frequency", 20.0f, 20000.0f, 1000.0f));
    addParameter(lfoFreqParam = new juce::AudioParameterFloat("lfofreq", "LFO Frequency", 0.2f, 5.0f, 1.0f));
    addParameter(channelParam = new juce::AudioParameterChoice("channel", "Channel", {"Left", "Center", "Right"}, 1));
}

Tester1AudioProcessor::~Tester1AudioProcessor()
{
}

//==============================================================================
const juce::String Tester1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Tester1AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Tester1AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Tester1AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Tester1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Tester1AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Tester1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Tester1AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Tester1AudioProcessor::getProgramName (int index)
{
    return {};
}

void Tester1AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Tester1AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void Tester1AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Tester1AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void Tester1AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    //BUFFER PARAMS
    int numSamples = buffer.getNumSamples();
    int sampleRate = getSampleRate();
        
    //UI PARAMS
    gain = gainParam->get();
    testSignal = testSignalParam->getIndex();
    freqValue = freqParam->get();
    lfoFreqValue = lfoFreqParam->get();
    channelValue = channelParam->getIndex();

    
    
    for(int sample = 0; sample < numSamples; sample++)
    {
        inputPhase += freqValue / sampleRate;
        while(inputPhase >= 1.0) inputPhase -= 1.0;
        lfoPhase += lfoFreqValue / sampleRate;
        while(lfoPhase >= 1.0) lfoPhase -= 1.0;
        
        for(int channel = 0; channel < getTotalNumOutputChannels(); ++channel)
        {
            auto* channelData = buffer.getWritePointer(channel);
            switch(testSignal){
                case 0:
                    channelData[sample] = 2.0 * gain * ((double)rand() / (RAND_MAX)) - 1.0;
                    break;
                case 1:
                    channelData[sample] = gain * sinf(juce::MathConstants<float>::twoPi * inputPhase);
                    break;
                case 2:
                    if(lfoPhase > 0.05 * lfoFreqValue) channelData[sample] = 0;
                    else
                        channelData[sample] = gain * sinf(juce::MathConstants<float>::twoPi * inputPhase);
                    break;
                default:
                    channelData[sample] = 0;
            }
        }
        // MUTE CHANNEL LEFT OR RIGHT CHANNEL
        if(channelValue == 0) buffer.getWritePointer(1)[sample] = 0;
        if(channelValue == 2) buffer.getWritePointer(0)[sample] = 0;
    }
}

//==============================================================================
bool Tester1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Tester1AudioProcessor::createEditor()
{
    return new juce::GenericAudioProcessorEditor(*this);
}

//==============================================================================
void Tester1AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Tester1AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Tester1AudioProcessor();
}
