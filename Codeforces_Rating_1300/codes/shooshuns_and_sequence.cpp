#include <iostream>
using namespace std;

int main (void){

	int k, n;
	cin >> n >> k;
	
	int seq[n];

	for (int i = 0; i < n; i++) cin >> seq[i];

	//checking if possible
	int possible = true;
	for (int i = k; i < n; i++) 
		if (seq[i-1] != seq[i]){
			possible = false;
			break;
		}

	if (!possible) cout << "-1";
	else {
		int count = 1;
		while ((k-count >= 0)&&(seq[k-count] == seq[k-1])){
			count ++;
		}
		cout << (k-count+1);
	}	

	return 0;
}
