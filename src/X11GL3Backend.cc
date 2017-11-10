#include <Backend/X11GL3Backend.hh>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <unistd.h>
#include <time.h>

#include <xcb/xcb.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glxext.h>

namespace Fission::Backends {
	X11GL3Backend::X11GL3Backend(void) {

	}

	struct WindowContext X11GL3Backend::ConstructBackend(void) {
		struct X11GL3WindowContext win_ctx;
		memset(&win_ctx, 0, sizeof(struct X11GL3WindowContext));

		win_ctx.xcbConn = xcb_connect(NULL, &win_ctx.screen_num);


		return static_cast<WindowContext>(win_ctx);
	}

	void X11GL3Backend::DestructBackend(struct WindowContext& ctx) {
		auto win_ctx = static_cast<X11GL3WindowContext&>(ctx);


		xcb_disconnect(win_ctx.xcbConn);

	}

	X11GL3Backend::~X11GL3Backend(void) {

	}
}

// I'm not so much "alive" as I am a very enthusiastic corpse