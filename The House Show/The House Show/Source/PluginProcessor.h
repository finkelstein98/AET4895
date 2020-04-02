/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Biquad.h"

//==============================================================================
/**
*/
class TheHouseShowAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    TheHouseShowAudioProcessor();
    ~TheHouseShowAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    float fxBlend = 1.0f;
    
     float freqVal = 30.0f;
    float freqVal2 = 10000.0f;
    float QVal = 2.0f;
    float ampVal = 12.0f;

    Biquad::FilterType filterType = Biquad::FilterType::HPF;
    Biquad::FilterType filterType2 = Biquad::FilterType::LPF;
    Biquad::FilterType filterType3 = Biquad::FilterType::NOTCH;
    Biquad::FilterType filterType4 = Biquad::FilterType::PEAK;
    
    float delayLengthMS = 100;
    float linearGain = 0.707;
    float drive = 1.0f;

private:
    
    float inputSample;
    Biquad biquad;
    Biquad biquad2;
    Biquad miclow;
    Biquad michigh;
    
 //   float Fs = 48000.f;
 //   int delayLengthSamples = floor(Fs*delayLengthMS/1000.0f);
    
   // static const int MAX_DELAY_LENGTH = 1000;
  //  float delayBuffer[MAX_DELAY_LENGTH][2] = {{0.0f}};
  //  int index[2] = {0};

    
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TheHouseShowAudioProcessor)
};
