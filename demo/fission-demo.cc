#include <iostream>

#include <Fission.hh>

#include <Utility/Event.hh>
#include <Utility/Logger.hh>

#include <FissionWindow.hh>

using Fission::FissionWindow;
using Fission::Utility::Event;
using Fission::Utility::BaseEvent;
using WindowResize = Fission::FissionWindow::WindowResize;


int main(int argc, char** argv) {
	// Initialize Fission
	FissionM::Initialize(argc, argv);

	DEBUG("Initialize Fission");

	Event::Register<WindowResize>([](const BaseEvent& e) {
		auto& ev = static_cast<const WindowResize&>(e);
		std::cout << "New Window Size: " << ev.NewSize.Width << "x" << ev.NewSize.Height << std::endl;
	});

	INFO("Creating FissionWindow!");

	FissionWindow mainWindow("Fission Demo", {800, 600});

	WARN("Window addr: %x", &mainWindow);

	ERROR("Shit broke %s", "yo");

	// Wait for all the application windows to close
	return FissionM::WaitExit();
}