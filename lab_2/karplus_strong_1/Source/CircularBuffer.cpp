/*
  ==============================================================================

    CircularBuffer.cpp
    Created: 15 Feb 2024 12:06:06pm
    Author:  Ruari Molyneux

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(){ };

CircularBuffer::~CircularBuffer(){ };

void CircularBuffer::setReadPosition(float delayTime, float sampleRate){
    readPosition = (int)(writePosition - (delayTime * sampleRate) + bufferLength) % bufferLength;
}

void CircularBuffer::prepareToPlay(float sampleRate, float maxDelaySeconds, int inChannels){
    bufferLength = (int)(maxDelaySeconds * sampleRate);
    buffer.setSize(inChannels, bufferLength);
    buffer.clear();
}

float* CircularBuffer::getWritePointer(int channel)
{
    return buffer.getWritePointer(channel);
}

void CircularBuffer::wrapBuffer()
{
    if(++readPosition >= bufferLength) readPosition = 0;
    if(++writePosition >= bufferLength) writePosition = 0;
}
