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

	std::unique_ptr<WindowContext_t> WAYGL3Backend::ConstructBackend(void) {
		WAYGL3WindowContext_t win_ctx = {};


		return std::make_unique<WAYGL3WindowContext_t>(win_ctx);
	}

	void WAYGL3Backend::DestructBackend(std::unique_ptr<WindowContext_t> ctx) {

	}

	WAYGL3Backend::~WAYGL3Backend(void) {

	}

	void WAYGL3WindowContext::ShowWindow(void) {
		DEBUG("WAYGL3 Show Window %p", this->xcbConn);
	}

	void WAYGL3WindowContext::DtorWindow(void) {
		DEBUG("WAYGL3 Dtor Window %p", this->xcbConn);

	}
}