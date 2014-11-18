#include <string>
#include <cstdio>
#include <algorithm>
/* suggested:
#include <boost/algorithm/string.hpp>
benefits: UTF-8 support! efficiency!
*/
using namespace std;

void format (string &s)
{
	for(size_t i = 0; i < s.size(); i++) {
        char curr = s.at(i);
		//Characters to be removed from song title
        switch (curr) {         //can be compacted, left tall for readability
            case ',' :
            case '.' :
            case '`' :
            case '/' :
            case '?' :
            case '\'':
            case '!' :
                s.erase (i, 1);             break;
            case '&' :
                s.erase ((i - 1), 2);        break;
            case ' ' :
                s.at(i) = '-';              break;
            case '(' :
                {
                size_t e = s.find ('(');
                for (; e < s.size(); ++e) {
                    char curr2 = s.at(e);       //utilize error checking
                    switch (curr2) {
                        case ',' :
                        case '.' :
                        case '`' :
                        case '/' :
                        case '?' :
                        case '\'':
                            s.erase (e, 1);          break;
                        case '&' :
                            s.erase ((e - 1), 2);      break;
                        case ' ' :
                            s.at (e) = '-';          break;
                        case ')' :
                            s.erase (e, 1);          break;
                        default: ;
                    }
                }
                s.at (i) = '-';
                break;
                }
            default: ;
        }
	}	
}

void to_lower(string &str)
{
    //reliant on ASCII assumptions, consider boost::algorithm::to_lower
    transform (str.begin(), str.end(), str.begin(), ::tolower);
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("%s\n", "Incorrect number of arguments. -h for usage");
		return 0;
	}
	string str (argv[1]);       //initialize string
	to_lower (str);             //make lowercase
	format (str);               //remove characters
	printf("%s", str.c_str());
}

