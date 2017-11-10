/*! \file X11GL3Backend.hh
	\brief The X11 OpenGL3 rendering backend

	This class implements the X11 OpenGL3 rendering backend used to render
	the widgets on screen as well as handle the OS window.
*/
#pragma once
#if !defined(__BACKEND_X11GL3BACKEND_HH__)
#define __BACKEND_X11GL3BACKEND_HH__

#include <Utility/Singleton.hh>
using Fission::Utility::Singleton;

#include <Backend/GenericBackend.hh>

#include <xcb/xcb.h>

namespace Fission::Backends {
	/*! \class X11GL3Backend
		\brief X11 OpenGL3 rendering backend

		Implementation of the Fission::Backend::GenericBackend for X11 and
		OpenGL3.

		This backend targets Linux systems only.
	*/
	class X11GL3Backend : GenericBackend, Singleton<X11GL3Backend> {
	private:

	public:
		X11GL3Backend(void);
		virtual struct WindowContext ConstructBackend(void) final;
		virtual void DestructBackend(struct WindowContext& ctx) final;
		~X11GL3Backend(void);
	};

	struct X11GL3WindowContext : WindowContext {
		int screen_num;
		xcb_connection_t* xcbConn;
		xcb_atom_t WindowAtom;
	};
}
#endif /* __BACKEND_X11GL3BACKEND_HH__ */