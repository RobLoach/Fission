#include <Utility/Logger.hh>

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

	std::unique_ptr<WindowContext_t> X11GL3Backend::ConstructBackend(void) {
		X11GL3WindowContext_t win_ctx = {};
		win_ctx.xcbConn = xcb_connect(NULL, &win_ctx.screen_num);


		return std::make_unique<X11GL3WindowContext_t>(win_ctx);
	}

	void X11GL3Backend::DestructBackend(std::unique_ptr<WindowContext_t> ctx) {
		// auto win_ctx = static_cast<X11GL3WindowContext_t&>(ctx);

		// xcb_disconnect(win_ctx->xcbConn);

	}

	X11GL3Backend::~X11GL3Backend(void) {

	}

	void X11GL3WindowContext::ShowWindow(void) {
		DEBUG("X11GL3 Show Window %p", this->xcbConn);
	}

	void X11GL3WindowContext::DtorWindow(void) {
		DEBUG("X11GL3 Dtor Window %p", this->xcbConn);

	}
}

// I'm not so much "alive" as I am a very enthusiastic corpse