#include <Backend/X11VULKANBackend.hh>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <unistd.h>
#include <time.h>

#include <xcb/xcb.h>

#include <vulkan.hpp>

namespace Fission::Backends {
	X11VULKANBackend::X11VULKANBackend(void) {

	}

	std::unique_ptr<WindowContext_t>  X11VULKANBackend::ConstructBackend(void) {
		X11VULKANWindowContext_t win_ctx = {};
		win_ctx.xcbConn = xcb_connect(NULL, &win_ctx.screen_num);


		return std::make_unique<X11VULKANWindowContext_t>(win_ctx);
	}

	void X11VULKANBackend::DestructBackend(std::unique_ptr<WindowContext_t> ctx) {
		// auto win_ctx = static_cast<X11VULKANWindowContext&>(ctx);


		// xcb_disconnect(win_ctx.xcbConn);
	}

	X11VULKANBackend::~X11VULKANBackend(void) {

	}

	void X11VULKANWindowContext::ShowWindow(void) {
		DEBUG("X11VULKAN Show Window %p", this->xcbConn);
	}

	void X11VULKANWindowContext::DtorWindow(void) {
		DEBUG("X11VULKAN Dtor Window %p", this->xcbConn);

	}
}