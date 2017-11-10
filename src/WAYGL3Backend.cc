#include <Backend/WAYGL3Backend.hh>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <unistd.h>
#include <time.h>


#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glxext.h>

namespace Fission::Backends {
	WAYGL3Backend::WAYGL3Backend(void) {

	}

	struct WindowContext WAYGL3Backend::ConstructBackend(void) {
		struct WAYGL3WindowContext win_ctx;
		memset(&win_ctx, 0, sizeof(struct WAYGL3WindowContext));

		win_ctx.xcbConn = xcb_connect(NULL, &win_ctx.screen_num);


		return static_cast<WindowContext>(win_ctx);
	}

	void WAYGL3Backend::DestructBackend(struct WindowContext& ctx) {
		auto win_ctx = static_cast<WAYGL3WindowContext&>(ctx);


		xcb_disconnect(win_ctx.xcbConn);

	}

	WAYGL3Backend::~WAYGL3Backend(void) {

	}
}