#include <JuceHeader.h>

class Equaliser
{
public:
    Equaliser();
    ~Equaliser();
    
    void process(float* channelData, int channel, int numSamples, int mode); // type eg. serial, parralel, casscade
    void prepareToPlay(int numChannels, float sampleRate);
    void makeCoefficients(float lowGainDb, float lowQ, float midGainDb, float midQ, float highGainDb, float highQ);
    
private:
    float sampleRate = 0;
    
    // low shelf
    juce::OwnedArray<juce::IIRFilter> lowFilters;
    const float lowFreq = 400.0f;
    
    // mid peaking
    juce::OwnedArray<juce::IIRFilter> midFilters;
    const float midFreq = 3000.0f;
    
    // high shelf
    juce::OwnedArray<juce::IIRFilter> highFilters;
    const float highFreq = 16000.0f;

    
    void processSerial(float* channelData, int channel, int numSamples);
    //void processParralel();
};
