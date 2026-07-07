#include <iostream>
#include <string>
using namespace std;

int main() {

	string 	s, temp = ".";
	cin >> s;
	int i=0;
	while(i<s.length()){
		s[i] = tolower(s[i]);
		if (s[i] == 'a' ||
			s[i] == 'e' ||
			s[i] == 'i' ||
			s[i] == 'o' ||
			s[i] == 'u' ||
			s[i] == 'y'){
				s.replace(i,1,"");
		}
		else i++;
	}

	for (int i=0; i<s.length();i=i+2)
		s.insert(i,temp);

	cout << s;
    return 0;
}


