#include <Fission.hh>
#include <FissionWindow.hh>

namespace Fission {
	FissionWindow::FissionWindow(std::string WindowTitle, WindowSize Size, WindowPos Position) {
		this->_WindowName = WindowTitle;
		this->_Size = Size;
		this->_Position = Position;
	}

	FissionWindow::~FissionWindow(void) {

	}
}