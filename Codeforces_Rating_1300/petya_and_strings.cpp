#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main (void){

	string str1, str2;
	cin >> str1 >> str2;
	bool printed = false;
	for(int i=0; i<str1.size(); i++)
	{
		if(tolower(str1[i]) == tolower(str2[i])) continue;
		else {
			if (tolower(str1[i]) > tolower(str2[i])) cout << 1;
			else cout << "-1";
			printed = true;
			break;
		}
	}
	if (!printed) cout << "0";

	return 0;
}
