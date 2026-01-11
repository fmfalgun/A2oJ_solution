#include <iostream>

using namespace std;

int main (void){

	string code;
	cin >> code;

	int i = 0, len = code.length();
	while(i != len){
		if (code[i] == '.'){
			cout << "0";
			i++;
		}
		else{
			if (code[i+1] == '.') cout << "1";
			else cout << "2";
			i = i+2;
		}
	}

	return 0;
}
