/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoftwareRingModulatorAudioProcessorEditor::SoftwareRingModulatorAudioProcessorEditor (SoftwareRingModulatorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    
    mixSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mixSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 25);
    mixSlider.setRange(0.0f, 0.5f, 0.1f);
   // mixSlider.setValue(0.5f);
    mixSlider.setTextValueSuffix("mix percent");
    mixSlider.addListener(this);
    addAndMakeVisible(mixSlider);

    
    frequencySlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    frequencySlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 80, 30);
    frequencySlider.setRange(0.0f, 100.0f, 0.1f);
    frequencySlider.setTextValueSuffix("percent");
    frequencySlider.addListener(this);
    addAndMakeVisible(frequencySlider);
    
  
    
   
    
}

SoftwareRingModulatorAudioProcessorEditor::~SoftwareRingModulatorAudioProcessorEditor()
{
}

//==============================================================================
void SoftwareRingModulatorAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void SoftwareRingModulatorAudioProcessorEditor::resized()
{
    auto sliderLeft = 250;
    auto sliderRight = -20;
    
       frequencySlider.setBounds (sliderRight, 20, getWidth() - sliderRight - 100, 200);
       mixSlider .setBounds (sliderLeft, 50, getWidth() - sliderLeft - 100, 200);
    
   
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
void  SoftwareRingModulatorAudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider ==&mixSlider || slider ==&frequencySlider)
    {
      //  processor.level = mixSlider.getValue();
      //  processor.level = frequencySlider.getValue();
        
        processor.setSinFreq(frequencySlider.getValue());
        
        // we should never write a variable from another class instead of this: we use the above
      //  processor.sinFreq = frequencySlider.getValue();
       // processor.updateAngleDelta();
}
}
