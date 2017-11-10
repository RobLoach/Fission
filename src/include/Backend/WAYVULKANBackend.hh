/*! \file WAYVULKANBackend.hh
	\brief The Wayland Vulkan rendering backend

	This class implements the Wayland Vulkan rendering backend used to render
	the widgets on screen as well as handle the OS window.
*/
#pragma once
#if !defined(__BACKEND_WAYCKEND_HH__)
#define __BACKEND_WAYCKEND_HH__

#include <Utility/Singleton.hh>
using Fission::Utility::Singleton;

#include <Backend/GenericBackend.hh>



namespace Fission::Backends {
	/*! \class WAYVULKANBackend
		\brief Wayland Vulkan rendering backend

		Implementation of the Fission::Backend::GenericBackend for X11 and
		Vulkan.

		This backend targets Linux systems only.
	*/
	class WAYVULKANBackend : GenericBackend, public Singleton<WAYVULKANBackend> {
	private:

	public:
		WAYVULKANBackend(void);
		virtual struct WindowContext ConstructBackend(void) final;
		virtual void DestructBackend(struct WindowContext& ctx) final;
		~WAYVULKANBackend(void);
	};

	struct WAYVULKANWindowContext : WindowContext {

	};
}
#endif /* __BACKEND_WAYCKEND_HH__ */