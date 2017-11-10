/*! \file Event.hh
	This file contains the machinery needed for event subscription and pushing,
	it's not very complex, but it works, for now.
*/
#pragma once
#if !defined(__UTILITY_EVENTS_HH__)
#define  __UTILITY_EVENTS_HH__

#include <functional>
#include <typeinfo>
#include <string>
#include <mutex>
#include <map>

namespace Fission::Utility {
	/*! \struct BaseEvent
		\brief The base class for all Fission events

		This class provides the base class for the Fission event system,
		all events that can be subscribed to and raised must be children of
		this class.

	*/
	struct BaseEvent {
		virtual ~BaseEvent(void) = default;

		/*! \brief Retrieve event name
			\returns The name of the event
		*/
		std::string GetName(void) const {
			return typeid(*this).name();
		}
	};

	typedef std::function<void(const BaseEvent&)> EventHandler;

	/*! \class Event
		\brief Event management

		This class provides the event registration and raising.
	*/
	class Event {
	private:
		static std::multimap<const std::type_info*, const EventHandler> EventMap;
		// static std::mutex EMMutex;
	public:
		/*! \brief Register a functor to an event

			This method lets you register a function or a lambda to an event
			trigger. It will be called each time the event type is raised.

			\param Handler [IN] A reference to a function or lambda to handle the event

		*/
		template<class EventType>
		static void Register(const EventHandler& Handler) {
			// std::scoped_lock(Event::EMMutex);
			Event::EventMap.emplace(&typeid(EventType), Handler);
		}

		/*! \brief Raise the given event

			This method will call all event handlers that fall under the typeid
			of ev and pass a reference of ev to them.

			\param ev [IN] Reference to an event object
		*/
		static void Raise(const BaseEvent& ev) {
			// This is beautiful >.>
			auto events = Event::EventMap.equal_range(&typeid(ev));
			while(events.first != events.second) {
				(events.first++)->second(ev);
			}
		}
	};

	std::multimap<const std::type_info*, const EventHandler> Event::EventMap;

}
#endif /* __UTILITY_EVENTS_HH__ */