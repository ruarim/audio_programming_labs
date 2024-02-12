/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Karplus_strong_1AudioProcessor::Karplus_strong_1AudioProcessor()
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
    // use value tree ?
    // add preset saving - can this be done without value tree
    addParameter(pluckParam = new juce::AudioParameterBool("pluck", "Pluck string", 0));
    addParameter(delayTimeParam = new juce::AudioParameterFloat("delay", "Delay Time", 0.00, 0.020f, 0.010f));
    addParameter(delayFeedbackParam = new juce::AudioParameterFloat("feedback", "Decay", 0.8f, 0.99f, 0.90f));
    addParameter(widthParam = new juce::AudioParameterFloat("width", "Width", 0, 0.02f, 0.01f));
}

Karplus_strong_1AudioProcessor::~Karplus_strong_1AudioProcessor()
{
}

int Karplus_strong_1AudioProcessor::getDelayBufferReadPosition()
{
    int position = (int)(delayWritePosition - (delayTime * getSampleRate()) + delayBufferLength) % delayBufferLength;
    return position;
}

//==============================================================================
const juce::String Karplus_strong_1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Karplus_strong_1AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Karplus_strong_1AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Karplus_strong_1AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Karplus_strong_1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Karplus_strong_1AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Karplus_strong_1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Karplus_strong_1AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Karplus_strong_1AudioProcessor::getProgramName (int index)
{
    return {};
}

void Karplus_strong_1AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Karplus_strong_1AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    int inChannels = getTotalNumInputChannels();
    delayTime = delayTimeParam->get();
    delayBufferLength = (int)(2.0 * sampleRate);
    delayBuffer.setSize(inChannels, delayBufferLength);
    delayBuffer.clear();
    
    delayReadPosition = (int)(delayWritePosition - (delayTime * sampleRate) + delayBufferLength) % delayBufferLength;
    //delayReadPosition = getDelayBufferReadPosition();
}

void Karplus_strong_1AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Karplus_strong_1AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void Karplus_strong_1AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    //Buffer info
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    int numSamples = buffer.getNumSamples();
    double sampleRate = getSampleRate();

    //Params
    float delayTime = delayTimeParam->get();
    float delayFeedback = delayFeedbackParam->get();
    float noiseWidth = widthParam->get();
    bool pluck = pluckParam->get();
    
    
    //Update buffer read positions
    delayReadPosition = (int)(delayWritePosition - (delayTime * sampleRate) + delayBufferLength) % delayBufferLength;
    //auto test = getDelayBufferReadPosition();
    
    if(pluck)
    {
        pluckParam->setValueNotifyingHost(0);
        noiseGain = 1.0;
    }

   
    for(int i = 0; i < numSamples; ++i)
    {
        float in = 0.0;
        if(noiseGain > 0.0) in = 2.0 * noiseGain * ((double)rand()/RAND_MAX-1.0);
        
        for(int j = 0; j < totalNumInputChannels; ++j)
        {
            //get delay data
            float* delayData = delayBuffer.getWritePointer(j);
            
            delayData[delayWritePosition] = in + delayData[delayReadPosition] * delayFeedback;
            
            float out = 0.0f;
            // only apply delay if > 0
            if(delayTime > 0.0) out = in + delayData[delayReadPosition];
            else out = in;
            
            buffer.getWritePointer(j)[i] = out;
        }
        if(noiseGain >= 0.0) noiseGain = noiseGain - 1.0 /(noiseWidth*(float)sampleRate);
        if(++delayReadPosition >= delayBufferLength) delayReadPosition = 0;
        if(++delayWritePosition >= delayBufferLength) delayWritePosition = 0;
    }
    
    // In case we have more outputs than inputs, clear any output channels that didn't contain input data
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
      {
        buffer.clear(i, 0, numSamples);
      }
}

//==============================================================================
bool Karplus_strong_1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Karplus_strong_1AudioProcessor::createEditor()
{
    return new juce::GenericAudioProcessorEditor(*this);
}

//==============================================================================
void Karplus_strong_1AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Karplus_strong_1AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Karplus_strong_1AudioProcessor();
}



