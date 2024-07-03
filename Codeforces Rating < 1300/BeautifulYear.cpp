#include <iostream>
#include <unordered_set>

using namespace std;

bool allDistinct(string str){

	unordered_set<char> charSet;

	for(char c: str){
		if (charSet.find(c) != charSet.end())
			return false;
		else charSet.insert(c);
	}
	return true;
}


int main(void){

	string year;
	cin >> year;

	bool result=false;
	int num=stoi(year);
	while(!result){
		num++;
		year = to_string(num);
		result = allDistinct(year);
	}

	cout << year;
	
	return 0;
}
