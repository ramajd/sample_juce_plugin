#include <juce_gui_basics/juce_gui_basics.h>
#include <memory>

class HelloJuceComponent : public juce::Component
{
public:
	HelloJuceComponent()
	{
		helloLabel.setText("Hello, JUCE!", juce::dontSendNotification);
		helloLabel.setFont(juce::Font(24.0f));
		helloLabel.setJustificationType(juce::Justification::centred);

		addAndMakeVisible(helloLabel);
	}

	void resized() override
	{
		helloLabel.setBounds(getLocalBounds());
	}

private:
	juce::Label helloLabel;
};

class HelloJuceApplication : public juce::JUCEApplication
{
public:
	const juce::String getApplicationName() override    { return "Hello JUCE App"; }
	const juce::String getApplicationVersion() override { return "1.0.0"; }

	void shutdown() override { mainWindow.reset(); }

	void initialise(const juce::String&) override
	{
		mainWindow = std::make_unique<MainWindow>(
				"Hello JUCE window",
				new HelloJuceComponent(),
				*this);
	}

private:
	class MainWindow : public juce::DocumentWindow
	{
	public:
		MainWindow(juce::String name,
			   juce::Component* component,
			   juce::JUCEApplication& app)
			: DocumentWindow(name,
				         juce::Colours::lightgrey,
					 DocumentWindow::allButtons)
					, application(app)
		{
			setUsingNativeTitleBar(true);
			setContentOwned(component, true);
			setResizable(true, true);
			setSize(640, 480);
			centreWithSize(getWidth(), getHeight());
			setVisible(true);
		}

		void closeButtonPressed() override
		{
			application.systemRequestedQuit();
		}

	private:
		juce::JUCEApplication &application;
	};

	std::unique_ptr<MainWindow> mainWindow;

};


START_JUCE_APPLICATION(HelloJuceApplication)
