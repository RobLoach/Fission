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