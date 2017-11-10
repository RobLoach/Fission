/*! \file WAYGL3Backend.hh
	\brief The Wayland OpenGL3 rendering backend

	This class implements the Wayland OpenGL3 rendering backend used to render
	the widgets on screen as well as handle the OS window.
*/
#pragma once
#if !defined(__BACKEND_WAYCKEND_HH__)
#define __BACKEND_WAYCKEND_HH__

#include <Utility/Singleton.hh>
using Fission::Utility::Singleton;

#include <Backend/GenericBackend.hh>



namespace Fission::Backends {
	/*! \class WAYGL3Backend
		\brief Wayland OpenGL3 rendering backend

		Implementation of the Fission::Backend::GenericBackend for X11 and
		OpenGL3.

		This backend targets Linux systems only.
	*/
	class WAYGL3Backend : GenericBackend, public Singleton<WAYGL3Backend> {
	private:

	public:
		WAYGL3Backend(void);
		virtual struct WindowContext ConstructBackend(void) final;
		virtual void DestructBackend(struct WindowContext& ctx) final;
		~WAYGL3Backend(void);
	};

	struct WAYGL3WindowContext : WindowContext {

	};
}
#endif /* __BACKEND_WAYCKEND_HH__ */