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

	struct WindowContext X11VULKANBackend::ConstructBackend(void) {
		struct X11VULKANWindowContext win_ctx;
		memset(&win_ctx, 0, sizeof(struct X11VULKANWindowContext));

		win_ctx.xcbConn = xcb_connect(NULL, &win_ctx.screen_num);


		return static_cast<WindowContext>(win_ctx);
	}

	void X11VULKANBackend::DestructBackend(struct WindowContext& ctx) {
		auto win_ctx = static_cast<X11VULKANWindowContext&>(ctx);


		xcb_disconnect(win_ctx.xcbConn);

	}

	X11VULKANBackend::~X11VULKANBackend(void) {

	}
}