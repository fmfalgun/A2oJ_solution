#include <iostream>

using namespace std;

int main() {
    
	string p;
	cin >> p;

	bool prints=false;
	for(int i=0; i<p.size(); i++)
		if (p[i] == 'H' || p[i] == 'Q' || p[i] == '9')
		{
			prints = true;
			break;
		}

	if (prints) cout << "YES";
	else cout << "NO";

	return 0;
}


