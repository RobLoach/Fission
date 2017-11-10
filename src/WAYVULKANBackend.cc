#include <Backend/WAYVULKANBackend.hh>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <unistd.h>
#include <time.h>

#include <xcb/xcb.h>

#include <vulkan.hpp>

namespace Fission::Backends {
	WAYVULKANBackend::WAYVULKANBackend(void) {

	}

	struct WindowContext WAYVULKANBackend::ConstructBackend(void) {
		struct WAYVULKANWindowContext win_ctx;
		memset(&win_ctx, 0, sizeof(struct WAYVULKANWindowContext));

		win_ctx.xcbConn = xcb_connect(NULL, &win_ctx.screen_num);


		return static_cast<WindowContext>(win_ctx);
	}

	void WAYVULKANBackend::DestructBackend(struct WindowContext& ctx) {
		auto win_ctx = static_cast<WAYVULKANWindowContext&>(ctx);


		xcb_disconnect(win_ctx.xcbConn);

	}

	WAYVULKANBackend::~WAYVULKANBackend(void) {

	}
}