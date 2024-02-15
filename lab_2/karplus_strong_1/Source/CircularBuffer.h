/*
  ==============================================================================

    CircularBuffer.h
    Created: 15 Feb 2024 12:06:06pm
    Author:  Ruari Molyneux

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class CircularBuffer
{    
public:
    CircularBuffer();
    ~CircularBuffer();
    
    void setReadPosition(float delayTime, float sampleRate);
    float* getWritePointer(int channel);
    void prepareToPlay(float sampleRate, float maxDelaySeconds, int inChannels);
    void wrapBuffer();
    
    int readPosition = 0;
    int writePosition = 0;
    
private:
    juce::AudioSampleBuffer buffer;
    int bufferLength = 0;
    
};
