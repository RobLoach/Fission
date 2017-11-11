#include <Fission.hh>
#include <FissionConfig.hh>
#include <Utility/Strutil.hh>
#include <Utility/Logger.hh>

#include <string>

using Fission::Utility::startswith;
using Fission::Utility::substr;
using Fission::Utility::FRONT;

#include <iostream>

FissionM::FissionM(void) {
	INFO("Fission %s (%s Backend) [%s %s]",
		FISSION_VERSION, FISSION_BACKEND,
		COMPILER_NAME, COMPILER_VERSION);
}

FissionM::~FissionM(void) {

}

void FissionM::Initialize(int argc, char** argv) {
	FissionM::GetInstance()->ParseArgs(argc, argv);
	FissionM::GetInstance()->InitializeBackend();

}

int FissionM::WaitExit(void) {
	return 0;
}


void FissionM::ParseArgs(int argc, char* argv[]) {
	static char prfx[] = "-f"; // C++ is stupid
	for(int i = 1; i < argc; i++) {
		std::string arg(argv[i]);
		if(startswith<prfx>(arg)) {
			arg = substr<2, FRONT>(arg);
			std::size_t eq = arg.find("=");
			if(eq == std::string::npos) {
				// this->Args.emplace(arg, "");
			} else {

			}
		}
	}
}

void FissionM::InitializeBackend(void) {
	#if defined(__X11GL3)
		this->_bkend = std::unique_ptr<Fission::Backends::GenericBackend>(new Fission::Backends::X11GL3Backend());
	#elif defined(__X1VULKAN)
		this->_bkend = std::unique_ptr<Fission::Backends::GenericBackend>(new Fission::Backends::X11VULKANBackend());
	#elif defined(__WAYGL3)
		this->_bkend = std::unique_ptr<Fission::Backends::GenericBackend>(new Fission::Backends::WAYGL3Backend());
	#elif defined(__WAYVULKAN)
		this->_bkend = std::unique_ptr<Fission::Backends::GenericBackend>(new Fission::Backends::WAYVULKANBackend());
	#endif
}