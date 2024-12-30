#include <iostream>
#include <string>
using namespace std;

int main(void){

	string n;
	cin >> n;
	
	bool flag = true;
	int i = 0;
	while(flag){

		//cout << "i=" << i << "\nand values are:" << n[i] << " " << n.substr(i,2) << " " <<  n.substr(i,3) << endl;
		if (n[i] != '1' && n[i] != '4') flag = false;
		else{
			if (n.substr(i,3) == "144") i = i+3;		
			else if (n.substr(i,2) == "14") i = i+2;	
			else if (n[i] == '1') i++;
			else flag = false;
		}

		if (i >= n.length()) break;
	}
	cout << (flag?"YES":"NO");

	return 0;
}
