# Fission [![Build Status](https://travis-ci.org/XAMPP/Fission.svg?branch=master)](https://travis-ci.org/XAMPP/Fission)
Fission is a C++-ish wrapper around the [nuklear](https://github.com/vurtun/nuklear) GUI library.

Fission comes with several rendering backends, see the table below:
|   | OpenGL3 | Vulkan |
| -| ------- | ------ |
| X11     | ✓ | ✗ |
| Wayland | ✗ | ✗ |

Anything with a ✓ is supported and (mostly) implemented, everything with ✗ is planned but not yet worked on / done.


## Building
To build Fission you need a few things, the first is `git`, `meson`, `ninja`, and a C++ compiler.
next are the libraries that are needed, these all depend on what backend you're building so it's broken down into the following list.

X11 OpenGL3 (Default):

 * libxcb
 * libgl
 * libglu

X11 Vulkan:

 * libxcb
 * Vulkan SDK

Wayland OpenGL:

 * wayland-client
 * libgl
 * libglu


Wayland Vulkan:

 * wayland-client
 * Vulkan SDK

Next, to build simply just do the following:
```
$ git clone https://github.com/XAMPP/Fission.git
$ cd Fission && meson build
$ cd build && ninja
```

This will by default build the X11 OpenGL3 backend, to specify the backend do the following:
```
$ cd build
$ meson configure -Dgfxbackend=<BACKEND>
```

The values for `<BACKEND>` are as follows:

 * X11GL3 (Default)
 * X11VULKAN
 * WAYGL3
 * WAYVULKAN


## FAQ

**Q**: Why? There is already QT, Wx, GTK, etc...

**A**: Because I wasn't really happy with the API those had to provide.


**Q**: Why wrap the library? Just use it as is.

**A**: Because I don't like the [nuklear](https://github.com/vurtun/nuklear) API either, but it's small and manageable.


**Q**: Will there be Windows™ support?

**A**: The library should be written in such a way that adding support for Direct3D is easy. But I don't use Windows™, so I see no need to implement it myself.



## Example
The following is an example application that uses Fission, if you want a more in-depth example then take a look at the [Fission Tutorial](doc/FissionTutorial.md)

```cpp
#include <iostream>

#include <Fission/Fission.hh>
#include <Fission/Utility/Event.hh>
#include <Fission/FissionWindow.hh>
#include <Fission/Widgets/AllWidgets.hh>

using Fission::FissionWindow;
using Fission::Utility::Event;
using Fission::Utility::BaseEvent;
using WindowResize = Fission::FissionWindow::WindowResize;
using Fission::Widgets;

int main(int argc, char** argv) {
	// Some basic setup
	Fission::Initialize(argc, argv);

	Event::Register<WindowResize>([](const BaseEvent& e) {
		auto& ev = static_cast<const WindowResize&>(e);
		std::cout << "New Window Size: " << ev.NewSize.Width << "x" << ev.NewSize.Height << std::endl;
	});

	FissionWindow mainWindow("Fission Demo", {800, 600});

	mainWindow.AddWidgets({
		new StaticRow(30, 80, 1),
		new Button("Demo", [](const BaseEvent& e) {
			std::cout << "Button clicked!" << std::endl;
		}),
		new Label("Demo", Label::TextLeft)
	});

	// Wait for all the application windows to close
	return Fission::WaitExit();
}
```