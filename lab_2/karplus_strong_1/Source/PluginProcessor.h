/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CircularBuffer.h"

//==============================================================================
/**
*/
class Karplus_strong_1AudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    Karplus_strong_1AudioProcessor();
    ~Karplus_strong_1AudioProcessor() override;

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
    // Params
    juce::AudioParameterBool* pluckParam;
    juce::AudioParameterFloat* delayFeedbackParam;
    juce::AudioParameterFloat* widthParam;
    juce::AudioParameterFloat* burstGainParam;
    juce::AudioParameterFloat* driveParam;
    juce::AudioParameterChoice* burstSignalParam;
    juce::AudioParameterFloat* freqParam;
    juce::AudioParameterFloat* filterCutoffParam;
    juce::AudioParameterFloat* noteFreqParam;
    
    // Note frequency - gets converted to delay time
    float noteFreq = 440.0f;
    
    // Burst
    bool burstOn = false;
    float burstGain = 0.0f;
    float burstWidth = 0.0f;
    int burstChoice = 0;
    float burstFreq = 0.0f;
    float phase = 0.0f;
    
    // Delay - params
    float delayTime = 0.0f;
    float delayFeedback = 0.0f;
    
    // Drive
    float drive = 0.0f;
    
    // Filter
    float filterCutoff = 0.0f;
    float prevFiltered = 0.0f;
    
    // Delay Buffer
    CircularBuffer* delayBuffer;
    
    // Helpers
    int getDelayBufferReadPosition();
    float calcBurstSignal(int choice, float phase, float gain);
    void spaceBarPluck(bool &pluck);
    float freqToDelayTime(float pitch, float sampleRate);
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Karplus_strong_1AudioProcessor)
};
