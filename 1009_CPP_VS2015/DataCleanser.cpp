#include "DataCleanser.h"
#include <algorithm>  // for copy_if()
#include <iterator>   // for the back_inserter
#include <regex> 

using std::back_insert_iterator;
using std::sregex_iterator;
using std::smatch;

namespace ICT1009
{
	namespace Utility
	{

		DataCleanser::DataCleanser()
		{


		}

		string DataCleanser::removeExtraWhitespaces(const string& str)
		{
			string new_string;
			//output.clear();  // unless you want to add at the end of existing sring...
			unique_copy(str.begin(), str.end(), back_insert_iterator<string>(new_string), [](char a, char b) { return isspace(a) && isspace(b);});
			return new_string;
			//cout << output << endl;
		}

		string DataCleanser::removeSymbols(const string& str)
		{
			string new_string;
			regex reg("[a-zA-Z!,.]+");
			sregex_iterator currentMatch(str.begin(), str.end(), reg);
			sregex_iterator lastMatch;
			while (currentMatch != lastMatch)
			{
				smatch match = *currentMatch;
				// cout << match.str();
				new_string += match.str();
				currentMatch++;
			}
			return new_string;
		}

		string DataCleanser::cleanseString(string str)
		{
			return removeExtraWhitespaces(removeSymbols(str));
		}
	}
}