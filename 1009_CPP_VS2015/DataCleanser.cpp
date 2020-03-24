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

		string DataCleanser::removeExtraWhitespaces(const string& input)
		{
			string new_string;
			//output.clear();  // unless you want to add at the end of existing sring...
			unique_copy(input.begin(), input.end(), back_insert_iterator<string>(new_string), [](char a, char b) { return isspace(a) && isspace(b);});
			return new_string;
			//cout << output << endl;
		}

		string DataCleanser::printMatches(string str, regex reg)
		{
			string new_string;
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
	}
}