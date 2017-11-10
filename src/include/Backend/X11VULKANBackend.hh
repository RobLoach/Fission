/*! \file X11VULKANBackend.hh
	\brief The X11 Vulkan rendering backend

	This class implements the X11 Vulkan rendering backend used to render
	the widgets on screen as well as handle the OS window.
*/
#pragma once
#if !defined(__BACKEND_X11VULKANBACKEND_HH__)
#define __BACKEND_X11VULKANBACKEND_HH__

#include <Utility/Singleton.hh>
using Fission::Utility::Singleton;

#include <Backend/GenericBackend.hh>

#include <xcb/xcb.h>

namespace Fission::Backends {
	/*! \class X11VULKANBackend
		\brief X11 Vulkan rendering backend

		Implementation of the Fission::Backend::GenericBackend for X11 and
		Vulkan.

		This backend targets Linux systems only.
	*/
	class X11VULKANBackend : GenericBackend, public Singleton<X11VULKANBackend> {
	private:

	public:
		X11VULKANBackend(void);
		virtual struct WindowContext ConstructBackend(void) final;
		virtual void DestructBackend(struct WindowContext& ctx) final;
		~X11VULKANBackend(void);
	};

	struct X11VULKANWindowContext : WindowContext {
		int screen_num;
		xcb_connection_t* xcbConn;
		xcb_atom_t WindowAtom;
	};
}
#endif /* __BACKEND_X11VULKANBACKEND_HH__ */