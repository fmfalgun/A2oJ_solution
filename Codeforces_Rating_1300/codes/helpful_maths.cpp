#include <iostream>

using namespace std;

int main() {
    
	string s;
	cin >> s;
	for(int j=0; j<s.size(); j++)
	for(int i=0; i<(s.size()-j); i++){
		if ((s[i]!= '+')&& (i+2<s.size())){
			if (s[i] > s[i+2]){
				int temp = s[i];
				s[i] = s[i+2];
				s[i+2] = temp;
			}
		}
	}
	cout << s;
	return 0;
}


