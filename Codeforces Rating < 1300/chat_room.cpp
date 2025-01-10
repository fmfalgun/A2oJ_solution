#include <iostream>
#include <string>
#include <map>

using namespace std;

bool canGenerateHello(string &original){
	string target = "hello";
	int i=0, j=0;

	while(i<target.size() && j<original.size()){
		if (target[i] == original[j]) i++;
		j++;
	}

	return i == target.size();
}

int main() {
    
	string s;	
	cin >> s;
	cout << (canGenerateHello(s)?"YES":"NO");

    return 0;
}


