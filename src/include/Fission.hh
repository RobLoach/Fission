/*! \file Fission.hh
	\brief Fission support methods and the like

	This class provides the machinery needed to keep things running smoothly

*/
#pragma once
#if !defined(__FISSION_HH__)
#define __FISSION_HH__

/* == Backends == */
#include <Backend/GenericBackend.hh>
#include <Backend/X11GL3Backend.hh>

#include <Utility/Singleton.hh>

#include <map>

/*! \class FissionM
	\brief Management Machinery

*/
class FissionM : Fission::Utility::Singleton<FissionM> {
private:




public:
	FissionM();
	~FissionM();

	/* == Static Methods ==*/
	/*! \brief Initialize Fission
		This call initializes everything Fission needs to get going

		\param argc [IN] The argc value from main
		\param argv [IN] the argv value from main

	*/
	static void Initialize(int argc, char** argv);
	/*! \brief Wait for all windows to exit
		This call is a blocking call that waits for the FissionWindow pool to empty indicating
		that all of the active windows have closed, therefore we can exit the application.

		All of the Fission cleanup is done prior to this method returning, therefore it is completely
		acceptable for `return FissionM::WaitExit()` in the main method.

		\returns Exit value
	*/
	static int WaitExit(void);

	/* == Instance Methods == */
	/*! \brief Parse program arguments
		This is used by FissionM::Initialize to setup the argument parsing
	*/
	void ParseArgs(int argc, char* argv[]);
};

#endif /* __FISSION_HH__ */