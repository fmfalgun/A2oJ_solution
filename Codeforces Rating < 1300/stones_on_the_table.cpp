#include <iostream>

using namespace std;

int main(void){

	int len;
	cin >> len;

	string str, result;
	cin >> str;

	int count = 0;
	char main;
	for(char c: str){
		if (main == c && count != 0) {
			result += c;
			main = c;
		}	
	}

	cout << result.length();

	return 0;
}
