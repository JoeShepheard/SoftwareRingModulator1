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
    mixSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    mixSlider.setRange(0.0, 0.5);
    mixSlider.setValue(0.5);
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
    auto sliderLeft = 120;
       frequencySlider.setBounds (sliderLeft, 20, getWidth() - sliderLeft - 10, 20);
       mixSlider .setBounds (sliderLeft, 50, getWidth() - sliderLeft - 10, 20);
   
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
void  SoftwareRingModulatorAudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider ==&mixSlider)
    {
        processor.level = mixSlider.getValue();
    }
    else if (slider ==&frequencySlider){
        processor.level = frequencySlider.getValue();
    }
}

