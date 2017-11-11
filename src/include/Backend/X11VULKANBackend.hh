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
	struct X11VULKANWindowContext : public WindowContext {
		int screen_num;
		xcb_connection_t* xcbConn;
		xcb_atom_t WindowAtom;

		void ShowWindow(void);
		void DtorWindow(void);
	} X11VULKANWindowContext_t;

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
		virtual std::unique_ptr<WindowContext_t> ConstructBackend(void) final;
		virtual void DestructBackend(std::unique_ptr<WindowContext_t> ctx) final;
		~X11VULKANBackend(void);
	};
}
#endif /* __BACKEND_X11VULKANBACKEND_HH__ */