/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class Tester1AudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    Tester1AudioProcessor();
    ~Tester1AudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    juce::AudioParameterFloat* gainParam;
    juce::AudioParameterChoice* testSignalParam;
    juce::AudioParameterFloat* freqParam;
    juce::AudioParameterFloat* lfoFreqParam;
    juce::AudioParameterChoice* channelParam;
    
    float gain = 0.0f;
    float inputPhase = 0.0f;
    float lfoPhase = 0.0f;
    float freqValue = 1000.0f;
    float lfoFreqValue = 1.0f;
    int testSignal = 0;
    int channelValue = 1;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tester1AudioProcessor)
};
