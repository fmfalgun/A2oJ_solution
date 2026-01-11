#include <iostream>
#include <string>

using namespace std;

int main() {
    
	string s, t;
	cin >> s >> t;	

	bool flag = true;
	if (s.length() != t.length()) flag = false;
	else{
		
		int lenn = s.length(), iterator = 0;
		while(iterator < lenn && flag){
			if (s[iterator] != t[lenn - iterator]) flag = false;
			iterator ++;
		}
	}

	cout << (flag?"YES":"NO");

    return 0;
}


