#include <Utility/Logger.hh>

#include <unistd.h>
#include <iostream>
#include <cstdarg>
#include <cstdio>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


namespace Fission::Utility {
	Logger::Logger(void) {
		this->IsTTY = isatty(fileno(stdout));
	}

	Logger::~Logger(void) {
		/* Not a soul around */
	}

	void Logger::Log(LogLevel lvl, const char* fmt, va_list args) const {
		char msgbuffer[4096];
		vsnprintf(msgbuffer, 4096, fmt, args);

		switch(lvl) {
			case LogLevel::Debug: {
				if(this->IsTTY)
					std::cout << ANSI_COLOR_MAGENTA << "[DEBUG] " << msgbuffer << ANSI_COLOR_RESET << "\n";
				else
					std::cout << "[DEBUG] " << msgbuffer << "\n";
				break;
			} case LogLevel::Info: {
				if(this->IsTTY)
					std::cout << ANSI_COLOR_CYAN << "[INFO] " << msgbuffer << ANSI_COLOR_RESET << "\n";
				else
					std::cout << "[INFO] " << msgbuffer << "\n";
				break;
			} case LogLevel::Warn: {
				if(this->IsTTY)
					std::cout << ANSI_COLOR_YELLOW << "[WARN] " << msgbuffer << ANSI_COLOR_RESET << "\n";
				else
					std::cout << "[WARN] " << msgbuffer << "\n";
				break;
			} case LogLevel::Error: {
				if(this->IsTTY)
					std::cerr << ANSI_COLOR_RED << "[ERROR] " << msgbuffer << ANSI_COLOR_RESET << "\n";
				else
					std::cerr << "[ERROR] " << msgbuffer << "\n";
				break;
			} default: {
				/* You shouldn't be here... */
			}
		}
	}

	void Logger::Debug(const char* fmt, ...) {
		va_list args;
    	va_start(args, fmt);
		Logger::GetInstance()->Log(LogLevel::Debug, fmt, args);
		va_end(args);
	}
	void Logger::Info(const char* fmt, ...) {
		va_list args;
    	va_start(args, fmt);
		Logger::GetInstance()->Log(LogLevel::Info, fmt, args);
		va_end(args);
	}
	void Logger::Warn(const char* fmt, ...) {
		va_list args;
    	va_start(args, fmt);
		Logger::GetInstance()->Log(LogLevel::Warn, fmt, args);
		va_end(args);
	}
	void Logger::Error(const char* fmt, ...) {
		va_list args;
    	va_start(args, fmt);
		Logger::GetInstance()->Log(LogLevel::Error, fmt, args);
		va_end(args);
	}

}