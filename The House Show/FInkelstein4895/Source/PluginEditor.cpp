/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TheHouseShowAudioProcessorEditor::TheHouseShowAudioProcessorEditor (TheHouseShowAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 450);
   
    //Saturation knob
    saturationSlider.addListener(this);
    saturationSlider.setSliderStyle(Slider::Rotary);
    saturationSlider.setBounds(0.5, 75, 175, 175);
    saturationSlider.setRange(1.0f, 100.0f);
    addAndMakeVisible(saturationSlider);
    addAndMakeVisible (saturationLabel);
    saturationLabel.setText("Saturation", dontSendNotification);
    saturationLabel.attachToComponent (&saturationSlider, true);
    saturationLabel.setBounds(0.5, 120, 100, 40);
    
    
    //Low-Shelf Filter
    low_filterSlider.addListener(this);
    low_filterSlider.setSliderStyle(Slider::LinearBar);
    low_filterSlider.setBounds(250, 120, 150, 100);
    low_filterSlider.setRange(30, 500);
    low_filterSlider.setSkewFactorFromMidPoint(150.0f);
    addAndMakeVisible(low_filterSlider);
    addAndMakeVisible(low_filterLabel);
    low_filterLabel.attachToComponent(&low_filterSlider, true);
    low_filterLabel.setBounds(300, 100, 50, 50);
    
    //High-Shelf Filter
    high_filterSlider.addListener(this);
    high_filterSlider.setSliderStyle(Slider::LinearBar);
    high_filterSlider.setBounds(250, 240, 150, 100);
    high_filterSlider.setRange(6000, 15000);
    high_filterSlider.setSkewFactorFromMidPoint(10000.0f);
    addAndMakeVisible(high_filterSlider);
    addAndMakeVisible(high_filterLabel);
    high_filterLabel.attachToComponent(&low_filterSlider, true);
    high_filterLabel.setBounds(300, 100, 50, 50);
    
   
    //Wet/Dry mix slider
    EFXgainSlider.addListener(this);
    EFXgainSlider.setSliderStyle(Slider::LinearVertical);
    EFXgainSlider.setBounds(500, 100, 100, 320);
    EFXgainSlider.setRange(0.0f, 2.0f);
    EFXgainSlider.setMouseDragSensitivity(15);
    EFXgainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
    EFXgainSlider.setTextValueSuffix(" - Makeup Gain");
    addAndMakeVisible(EFXgainSlider);
    
   
  
}

TheHouseShowAudioProcessorEditor::~TheHouseShowAudioProcessorEditor()
{
}

//==============================================================================
void TheHouseShowAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    ColourGradient gradient;
    auto viewBounds = getLocalBounds();
    
    gradient.point1 = viewBounds.getTopLeft().toFloat();
      gradient.point2 = viewBounds.getTopRight().toFloat();
        gradient.addColour(0.0, Colours::darkslategrey);
    gradient.addColour(1.0, Colours::dimgrey);
        g.setGradientFill(gradient);
    g.fillRect((getLocalBounds()));



    g.setColour (Colours::darkcyan);
    g.setFont (80.0f);
    g.drawFittedText ("HOUSE SHOW", getLocalBounds(), Justification::topLeft, 1);
}

void TheHouseShowAudioProcessorEditor::resized()
{

}

void
TheHouseShowAudioProcessorEditor::sliderValueChanged(Slider* slider){
 
 
    if (slider == &low_filterSlider){
        processor.freqVal = low_filterSlider.getValue();
    }
    if (slider == &high_filterSlider){
        processor.freqVal2 = high_filterSlider.getValue();
    }
 
    if (slider == &saturationSlider){
       processor.drive = saturationSlider.getValue();
    }
    if (slider == &EFXgainSlider){
        processor.makeupGain = EFXgainSlider.getValue();
    }
}


