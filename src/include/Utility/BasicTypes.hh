#pragma once
#if !defined(__UTILITY_BASICTYPES_HH__)
#define __UTILITY_BASICTYPES_HH__
namespace Fission::Utility {
	typedef struct {
		short X;
		short Y;
	} WindowPos;

	typedef struct {
		short Width;
		short Height;
	} WindowSize;
}
#endif /* __UTILITY_BASICTYPES_HH__ */