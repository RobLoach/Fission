/*! \file GenericBackend.hh
	\brief Generic rendering backend abstract class

	This class provides an abstract API for rendering backends to be implemented
	on.
*/
#pragma once
#if !defined(__BACKEND_GENERICBACKEND_HH__)
#define __BACKEND_GENERICBACKEND_HH__


namespace Fission::Backends {
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

		virtual struct WindowContext ConstructBackend(void) = 0;
		virtual void DestructBackend(struct WindowContext& ctx) = 0;


	};

	struct WindowContext {
		// uint winid;
	};
}
#endif /* __BACKEND_GENERICBACKEND_HH__ */