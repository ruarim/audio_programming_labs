#include <JuceHeader.h>

class Equaliser
{
public:
    Equaliser();
    ~Equaliser();
    
    void process(float* channelData, int channel, int numSamples, int mode); // type eg. serial, parralel, casscade
    void prepareToPlay(int numChannels, float sampleRate);
    void makeCoefficients();
    
    // expose eq params
    float lowGainDb = 0.0f;
    float lowQ = 0.0f;
    
    float midGainDb = 0.0f;
    float midQ = 0.0f;
    
    float highGainDb = 0.0f;
    float highQ = 0.0f;
    
private:
    float sampleRate = 0;
    
    // eq filters
    // low shelf
    juce::OwnedArray<juce::IIRFilter> lowFilters;
    const float lowFreq = 400.0f;
    
    // mid peaking
    juce::OwnedArray<juce::IIRFilter> midFilters;
    const float midFreq = 3000.0f;
    
    // add high mid filters
    
    // high shelf
    juce::OwnedArray<juce::IIRFilter> highFilters;
    const float highFreq = 16000.0f;
    
    void processSerial(float* channelData, int channel, int numSamples);
    //void processParralel();
};
