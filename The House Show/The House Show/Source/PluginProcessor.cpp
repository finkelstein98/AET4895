/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TheHouseShowAudioProcessor::TheHouseShowAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

TheHouseShowAudioProcessor::~TheHouseShowAudioProcessor()
{
}

//==============================================================================
const String TheHouseShowAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TheHouseShowAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TheHouseShowAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TheHouseShowAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TheHouseShowAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TheHouseShowAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TheHouseShowAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TheHouseShowAudioProcessor::setCurrentProgram (int index)
{
}

const String TheHouseShowAudioProcessor::getProgramName (int index)
{
    return {};
}

void TheHouseShowAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TheHouseShowAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    biquad.setFs(sampleRate);
}

void TheHouseShowAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TheHouseShowAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
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

void TheHouseShowAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

 
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // high-pass filter
    biquad.setFreq(freqVal);
    biquad.setQ(QVal);
    biquad.setAmpdB(ampVal);
    biquad.setFilterType(filterType);
    
    //low-pass filter
    biquad2.setFreq(freqVal2);
    biquad2.setQ(QVal);
    biquad2.setAmpdB(ampVal);
    biquad2.setFilterType(filterType2);
    
    miclow.setFreq(500.0f);
    miclow.setQ(1.0f);
    miclow.setAmpdB(-0.8f);
    miclow.setFilterType(filterType3);
    
    michigh.setFreq(3800.0f);
    michigh.setQ(3.0f);
    michigh.setAmpdB(1.5f);
    michigh.setFilterType(filterType4);
    
   // playHead = this->getPlayHead();
   // playHead->getCurrentPosition (currentPositionInfo);
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
   // delayLengthSamples = floor(Fs*delayLengthMS/1000.f);
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        for (int n = 0; n < buffer.getNumSamples(); n++){
       
           float x = buffer.getReadPointer(channel)[n];
            
            x = (2.0f / M_PI)* atan(drive * x);
            
            if (x > 1)
                x = 1;
            if (x < -1)
                x = -1;
            // instantiate delay (feedback parallel)
           // float slapback = x + linearGain * delayBuffer[ index[channel] ][channel];
           // delayBuffer[index[channel]][channel] = slapback;
           // if (index[channel] < delayLengthSamples){
          //      index[channel]++;
          //  }else{
         //       index[channel] = 0;
         //   }
            float y = biquad.processSample(x, channel);  //high-pass
            float z = biquad2.processSample(x, channel); //low-pass
            float a = miclow.processSample(x, channel); //frequency response low-mids
            float b = michigh.processSample(x, channel); //frequency response high-mids
            float fx = y + z + a + b;
            buffer.getWritePointer(channel)[n] = (x + fx);
         
        }
            }
 
}

//==============================================================================
bool TheHouseShowAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TheHouseShowAudioProcessor::createEditor()
{
    return new TheHouseShowAudioProcessorEditor (*this);
}

//==============================================================================
void TheHouseShowAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TheHouseShowAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TheHouseShowAudioProcessor();
}



