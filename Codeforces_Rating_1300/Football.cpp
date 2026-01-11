#include <iostream>
#include <string>

using namespace std;

int main() {
    
	string s;
	cin >> s;

	bool flag=false;
	for (int i=0; i+7<=s.length(); i++)
		if (s.substr(i,7)=="0000000" || s.substr(i,7)=="1111111"){
			flag = true;
			break;
		}
	cout << (flag?"YES":"NO");
    return 0;
}


