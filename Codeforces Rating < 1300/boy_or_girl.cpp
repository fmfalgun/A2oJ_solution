#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
	string username;
	cin >> username;
	vector<char> unique_letters;
	for(int i=0; i<username.size();i++)
	{
		bool found = false;
		for (int j=0; j<unique_letters.size(); j++)
			if(username[i] == unique_letters[j])
				found = true;
		if (!found) unique_letters.push_back(username[i]);
	}

	if ((unique_letters.size())%2 == 0) 
		cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";

	return 0;
}
