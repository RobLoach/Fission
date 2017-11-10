/*! \file Strutil.hh
	\brief Utilitarian string methods
*/
#pragma once
#if !defined(__UTILITY_STRSPLIT_HH__)
#define __UTILITY_STRSPLIT_HH__
#include <string>
#include <sstream>
#include <istream>
#include <iterator>
#include <vector>

namespace Fission::Utility {
	template<char delim>
	class __WORD_DELIM_BY : public std::string {
	public:
		friend std::istream& operator>>(std::istream& i, __WORD_DELIM_BY& out) {
			std::getline(i, out, delim);
			return i;
		}
	};

	/*! \brief Split string on given token
			This method splits the given std::string on a token and returns a vector with the resulting substrings

			\tparam tok [IN] The token to split by
			\param str [IN] The string to split

			\returns a std::vector<std::string> of split strings
	*/
	template<char tok>
	std::vector<std::string> strsplit(std::string& str) {
		std::istringstream ss(str);
		return {std::istream_iterator<__WORD_DELIM_BY<tok>>(ss),
						std::istream_iterator<__WORD_DELIM_BY<tok>>()};
	}

	/*! \brief Check if a string starts with a prefix

		This method checks to see of the given string starts with a prefix.

		\tparam prefix [IN] The prefix to check for
		\param str [IN] The string to check

		\returns A bool containing the result if the string has the prefix
	*/
	template<char const* prefx>
	bool startswith(std::string& str) {
		std::string prefix(prefx);
		return (str.compare(0, prefix.length(), prefix) == 0);
	}

	enum subdir {
		FRONT,
		BACK
	};

	template<int num, subdir dir>
	std::string substr(std::string& str) {
		if(dir == FRONT) {
			return str.substr(0, num);
		} else {
			return str.substr(str.length() - num, num);
		}
	}

}
#endif /* __UTILITY_STRSPLIT_HH__ */