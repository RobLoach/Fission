/*! \file Logger.hh
	\brief Basic Logging Utility

	This class provides a basic logging system.

	It defines 4 Macros, DEBUG, INFO, WARN, ERROR, as well
	as the respective static member methods on the Logger class.

	The macros append some "useful" information to the message, mainly
	the filename and line number where the log was invoked.
*/
#pragma once
#if !defined(__UTILITY_LOGGER_HH__)
#define __UTILITY_LOGGER_HH__

#include <Utility/Singleton.hh>

#include <cstdarg>

#define STR(x) #x
#define STRINGIFY(x) STR(x)

#define __POS_TAG "<" __FILE__ ":" STRINGIFY(__LINE__) "> "

#define DEBUG(MSG, ...) Fission::Utility::Logger::Debug(__POS_TAG MSG, ##__VA_ARGS__)
#define INFO(MSG, ...) Fission::Utility::Logger::Info(__POS_TAG MSG, ##__VA_ARGS__)
#define WARN(MSG, ...) Fission::Utility::Logger::Warn(__POS_TAG MSG, ##__VA_ARGS__)
#define ERROR(MSG, ...) Fission::Utility::Logger::Error(__POS_TAG MSG, ##__VA_ARGS__)

namespace Fission::Utility {
	/*! \class Logger
		\brief Provides simple logging machinery
	*/
	class Logger : Singleton<Logger> {
	private:
		bool IsTTY;

	public:
		Logger(void);
		~Logger(void);

		enum class LogLevel {
			Debug,
			Info,
			Warn,
			Error
		};

		/*! \brief Print the given message to stdout

			This method takes the given LogLevel and format string, along with
			any arguments and prints them to the console.

			\param lvl [IN] The level to log this message at
			\param fmt [IN] The printf-style format string
			\param args [IN] The arguments for fmt
		*/
		void Log(LogLevel lvl, const char* fmt, va_list args) const;

		static void Debug(const char* fmt, ...);
		static void Info(const char* fmt, ...);
		static void Warn(const char* fmt, ...);
		static void Error(const char* fmt, ...);
	};
}
#endif /* __UTILITY_LOGGER_HH__ */