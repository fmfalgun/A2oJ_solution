#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    
	int k;
	cin >> k;
	string s;
	cin >> s;

	map<char, int> freq;
	for (char c: s) freq[c] ++;

	bool fair = true;
	for (const auto& pair: freq)
		if (pair.second%k != 0) fair = false;

	string result = "";
	if (!fair) cout << -1;
	else {
		for (int i=0; i<k; i++)
			for (const auto& pair: freq)
				for (int j=0; j<(pair.second/k); j++)
				result += pair.first;
		cout << result;
	}

    return 0;
}


