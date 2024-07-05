#include <iostream>

using namespace std;

int main(void){

	string str1, str2, result;
	cin >> str1 >> str2;

	int count = 0, len = str1.length();

	while(count == len){

		if (str1[count] == str2[count])
				result += "0";
		else result += "1";
		count++;

	}
	cout << result << "ok\n";

	return 0;
}
