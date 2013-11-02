
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "token.h"

using namespace std;

typedef void (*sighandler_t)(int);

void handle_signal(int signo)
{
	cout << "\n[YAN_SHELL ] ";
	fflush(stdout);
}



int main()
{
   	string str;     // C++ STL string
	vector<token> vectorToken;
	string str1;
	string stoken;
	token holder;
	bool quotes = false;
	

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	cout << ("[YAN_SHELL ] " );
	while (getline(cin,str1)) {
		str1 += '\n';
		
		for (int i = 0; i < str1.length(); i++)
		{
			if ((str1[i] == '#' || str1[i] == '<' || str1[i] == '>') && !quotes)
			{
				stoken += str1[i];
				holder.set_values("metachar", stoken);
				vectorToken.push_back(holder);
				stoken.clear();
			}
			else if (str1[i] == ' ' && !quotes)
			{
				holder.set_values("word", stoken);
				vectorToken.push_back(holder);
				stoken.clear();
			}
			else if (str1[i] == '"')
			{
				
				if (quotes)
				{
					holder.set_values("string", stoken);
					vectorToken.push_back(holder);
					stoken.clear();
					quotes = false;
				}
				else
					quotes = true;
				
			}
			else if (str1[i] == '\n')
			{
				if (stoken.length() > 0)
				{
					holder.set_values("word", stoken);
					vectorToken.push_back(holder);
				}
					stoken.clear();
					holder.set_values("end-of-line", "EOL");
					vectorToken.push_back(holder);
				
			}
			else{
				stoken += str1[i];
			}
				
		}
		cout << "[YAN_SHELL ] ";
	}
	
		
	return 0;   
}





