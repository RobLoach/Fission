/*! \file FissionWindow.hh
	\brief Native system window wrapper

	This class provides a wrapper for the native operating system window.
	It is dependent on the rendering backend.

	Note that this is different from the Fission::Widgets::Window class, as
	that describes a child window of a parent Fission::FissionWindow.
*/
#pragma once
#if !defined(__FISSION_WINDOW_HH__)
#define __FISSION_WINDOW_HH__

#include <string>
#include <mutex>
#include <thread>
#include <memory>

#include <nuklear.h>

#include <Backend/GenericBackend.hh>

#include <Utility/BasicTypes.hh>
#include <Utility/Event.hh>

using Fission::Utility::WindowPos;
using Fission::Utility::WindowSize;
using Fission::Backends::WindowContext_t;


namespace Fission {

	/*! \class FissionWindow
		\brief This class Represents a OS Window, not to be confused with a WindowWidget

1		Each Fission window has it's own render thread to keep your application logic and
		render events separate.

	*/
	class FissionWindow {
	private:
		std::string _WindowName;
		WindowSize _Size;
		WindowPos _Position;



	public:
		/*! \brief Construct a new FissionWindow

			\param WindowTitle [IN] The title for the window
			\param Size [IN] (Optional) The size of the window (defaults to 800x600)
			\param Position [IN] (Optional) The position of the window (defaults to 0,0)
		*/
		FissionWindow(std::string WindowTitle,
			WindowSize Size = {600, 800},
			WindowPos Position = {0, 0});

		~FissionWindow(void);

		void ShowWindow(void);

		/* == Events == */
		/*! \struct WindowResize
			\brief Triggers when any FissionWindow is resized
		*/
		struct WindowResize : Fission::Utility::BaseEvent  {
			WindowSize NewSize;
			WindowResize(WindowSize Size) : NewSize(Size) {}
		};
	};
}
#endif /* __FISSION_WINDOW_HH__ */