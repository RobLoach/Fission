/*! \file Singleton.hh
	\brief Basic singleton implementation
*/
#pragma once
#if !defined(__UTILITY_SINGLETON_HH__)
#define __UTILITY_SINGLETON_HH__

#include <memory>

namespace Fission::Utility {
	/*! \class Singleton
		\brief Singleton Implementation

		This templated class allows for any class to be implemented as a singleton
	*/
	template<class Child>
	class Singleton {
	public:
		static Child* GetInstance(void);
	private:
		static std::unique_ptr<Child> _Instance;
	};

	template <class Child>
	std::unique_ptr<Child> Singleton<Child>::_Instance = nullptr;

	template<class Child>
	Child* Singleton<Child>::GetInstance(void) {
		if(_Instance != nullptr)
			return _Instance.get();
		auto ut = std::make_unique<Child>();
		_Instance = std::move(ut);
		return _Instance.get();
	}

}
#endif /* __UTILITY_SINGLETON_HH__ */