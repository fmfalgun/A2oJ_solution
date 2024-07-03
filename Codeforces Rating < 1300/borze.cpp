#include <iostream>
#include <cctype>
using namespace std;

int main (void){

	string s;
	cin >> s;

	int len = s.length();
	int shortwrds=0, longwrds=0;

	for(int i=0; i<len; i++){
		if(islower(s[i])) shortwrds++;
		else longwrds++;
	}

	if(longwrds > shortwrds)
		for(char &c : s)
			c = toupper(static_cast<unsigned char>(c));
	else
		for(char &c : s)
			c = tolower(static_cast<unsigned char>(c));

	cout << s;

	return 0;
}
