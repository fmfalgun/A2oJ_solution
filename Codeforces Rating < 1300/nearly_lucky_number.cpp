#include <iostream>

using namespace std;

bool contain_lucky_number(char c){
	int num = c-'0';
	if (num == 4 || num == 7) return true;
	return false;
}

int main(void){

	string str;
	cin >> str;
	int count = 0;
	for (char c: str){
		if(contain_lucky_number(c)) count++;
	}	

	cout << ((count == 4 || count == 7)?"YES":"NO");
	return 0;
}
