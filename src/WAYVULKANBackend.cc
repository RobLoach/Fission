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

	std::unique_ptr<WindowContext_t> WAYVULKANBackend::ConstructBackend(void) {
		WAYVULKANWindowContext_t win_ctx = {};

		return std::make_unique<WAYVULKANWindowContext_t>(win_ctx);
	}

	void WAYVULKANBackend::DestructBackend(std::unique_ptr<WindowContext_t> ctx) {

	}

	WAYVULKANBackend::~WAYVULKANBackend(void) {

	}

	void WAYVULKANWindowContext::ShowWindow(void) {
		DEBUG("WAYVULKAN Show Window %p", this->xcbConn);
	}

	void WAYVULKANWindowContext::DtorWindow(void) {
		DEBUG("WAYVULKAN Dtor Window %p", this->xcbConn);

	}
}