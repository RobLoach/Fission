/*! \file GenericBackend.hh
	\brief Generic rendering backend abstract class

	This class provides an abstract API for rendering backends to be implemented
	on.
*/
#pragma once
#if !defined(__BACKEND_GENERICBACKEND_HH__)
#define __BACKEND_GENERICBACKEND_HH__

#include <memory>

namespace Fission::Backends {
	typedef struct WindowContext {
		WindowContext(void) = default;
		virtual ~WindowContext(void) = default;

		virtual void ShowWindow(void) = 0;
		virtual void DtorWindow(void) = 0;
	} WindowContext_t;

	/*! \class GenericBackend
		\brief Abstract backend class

		This class provides the generic API that the rest of Fission uses to render,
		any system/backend specific code is implemented in it's own backend.
	*/
	class GenericBackend {
	private:
	public:
		GenericBackend(void) = default;
		virtual ~GenericBackend(void) = default;

		virtual std::unique_ptr<WindowContext_t>  ConstructBackend(void) = 0;
		virtual void DestructBackend(std::unique_ptr<WindowContext_t> ctx) = 0;


	};
}
#endif /* __BACKEND_GENERICBACKEND_HH__ */