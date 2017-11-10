# Fission Tutorial
The following is a simple tutorial that walks you through the process of using Fission and developing an application with it.

# Setup
In the case of setup, I'll assume that you've already built/installed the library appropriately.

For the duration of the tutorial we will be working with the following directory structure:
```
- /
- meson.build
- tutorial.cc
- build/
```

Not very complicated, and I'll even provide you the example `meson.build` file.

```py
project('fission-tut', 'cpp',
	default_options: [
		'cpp_std=c++1z',
		'warning_level=3'
	]
)

fission = dependency('fission', required : true)

executable('fission-tut',
	'tutorial.cc',
	dependencies: [ fission ]
)
```

And to start off, `tutorial.cc` will start with the following:

```cpp
#include <Fission.hh>

int main(int argc, char* argv[]) {

	return 0;
}
```

# Initialization and Cleanup
When it comes to Fission, there are two rather importation things that must be done for every application, initialization, and cleanup. Fortunately this is pretty much taken care of for you, you just need to provide two simple method calls.

As a prior note, all of the global / generic machinery for Fission lives in `FissionM`, you can think of that as 'Fission Main' or 'Fission Machine'. It's not important that you know everything that it does at the moment, but it is important to know that it exists.

The first of these calls is `FissionM::Initialize`, it takes both `argc`, and `argv` as parameters and does what it says on the tin, mostly. It is responsible for ensuring that the base of Fission is all setup and proper, it also provides a simple command line parsing mechanism that can be used to override default Fission configuration values. It's simple enough to add, right after `main` just tack in `FissionM:Initialize(argv, argc)` and all is well.

Next is `FissionM::WaitExit`, this is a blocking call that ensures the application will not terminate while there are active `FissionWindow`s active. It returns an int exit status, and all of the needed cleanup for Fission is done prior to this method returning, so it's completely acceptable for `return FissionM::WaitExit();`, and that's exactly what we are going to do.

So now at this point, our main method should look as follows:
```cpp
int main(int argc, char** argv) {
	// Initialize Fission
	FissionM::Initialize(argc, argv);

	// Wait for all the application windows to close
	return FissionM::WaitExit();
}
```

Not too bad so far, eh?

# Your first window
Now before I begin I need to clarify things, Fission actually has two types of windows, confusing  I know, but let me elaborate.

The first type of window is the `FissionWindow`, this is the main window that is handled by your operating system, it's responsible for holding and rendering all of the Fission widgets.

Next there is the `Window` widget, you can think of this like a sub-window, it's a little floating window that is rendered inside of the `FissionWindow`.


In this case, we want a `FissionWindow`, to create one is super easy, just include `FissionWindow.hh` and create a new instance, like so:
```cpp
Fission::FissionWindow mainWindow("Fission Demo", {200, 200});
```

The `FissionWindow` API is described in more detail in the documentation, so for right now I'll just cover what we've used.

The first argument is the window title, this is mandatory and is what is displayed as the  name of the window in your operating system. Next is the window side, this argument is optional and is simply a struct that describes the width and height of the window, in that order.

To show the window, simply call `mainWindow.Show()` and that's all there is to it.

# A widget by any other name
Now, just a blank window is not really of any use, so we need to add some widgets. I won't go into details on all of them just one or two, but Fission has [a whole lot](WidgetList.md).

To make things easy on yourself, you can include the `Widgets/AllWidgets.hh` header and pull in all the widgets, or alternatively you can just include each one you use. In this case, I'll just include all of them because I'm lazy.

The first widget we are covering is the button, it's an important one that allows for users to actually trigger actions for your application to take.

To create the widget is easy, just create a new `Fission::Widgets::Button`, it takes one mandatory argument and some optional ones, but I'll just cover the mandatory one right now. The one thing all buttons have are names, and therefore that's the one thing that's required, so you can just make a button like so:
```cpp
Fission::Widgets::Button btn("Click Me");
```

Now a button is no good if we can't see it, so add it to `mainWindow` like so:
```cpp
mainWindow.AddWidget(&btn);
```

After that call `mainWindow.Show()` and bask in the glory that is your UI.

Here is what `main` looks like now:
```cpp
int main(int argc, char** argv) {
	// Initialize Fission
	FissionM::Initialize(argc, argv);

	// Create a new window
	Fission::FissionWindow mainWindow("Fission Demo", {200, 200});

	// Buttons are good
	Fission::Widgets::Button btn("Click Me");

	// Add the widget
	mainWindow.AddWidget(&btn);

	// Let there be light~
	mainWindow.Show();

	// Wait for all the application windows to close
	return FissionM::WaitExit();
}
```
# The buttons, they do nothing!
Here is a good point to introduce you to the built in event system Fission has. Seeing as how most if not all user interfaces are event driven, it's important to be able to actually subscribe to events that components trigger.

There are many types of events in Fission, from `WindowResize` events to `ButtonClick` events, so as it stands, we care about the `ButtonClick` event, seeing as we want to do something when the user clicks our button.

So, simply include `Utility/Event.hh`, now we have access to the whole Fission event system. To subscribe to an event we simply pass a function handle to the `Event::Register<T>()` method where T is the type of event we want to subscribe to. Here's an example for the button:
```cpp
Event::Register<ButtonClick>([](const BaseEvent& ev) {
	// Button Click!
});
```

Simple right?

One downside to this is that this will fire for **every** button click, what if we want just the events for our button? Well there are two ways to do this, the first is to `static_cast<const ButtonClick&>(ev)` and pull out the `buttonID` and check it against our button's ID.

Alternatively there is a simpler way to do it, and it looks a little more syntactically pleasing than that. Recall that the button takes several optional arguments, the fist of which is a handle for the click event of that button. The new button instantiation looks like this:
```cpp
Fission::Widgets::Button btn("Click Me", [](const BasicEvent& ev) {
	// This button click~
});
```

I don't know about you, but that looks a lot better in my option.

# Widgets, one or more
Now, while our simple UI has been fine, for any sufficiently complex interface, there will be a load of components, so the calls to `mainWindow.AddWidget` will bet quite verbose and tedious but fret not, there is a solution!

The call `AddWidgets` is provided so that complex interfaces can be built rather naturally, seeing as it displays the widget hierarchy. This call takes a list of `BaseWidget` pointers and uses that to build the interface. you can use it as follows:
```cpp
mainWindow.AddWidgets({
	new StaticRow(30, 80, 1),
	new Button("Demo", [](const BaseEvent& e) {
		std::cout << "Button clicked!" << std::endl;
	}),
	new Label("Demo", Label::TextLeft)
});
```

Now forgive me for introducing two new widgets there, but it helped me introduce this concept, for more information on said widgets I highly suggest that you read the Fission API documentation.