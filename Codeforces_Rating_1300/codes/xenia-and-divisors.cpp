#include <iostream>
using namespace std;

int main (void){

	//inputs
	//first we get sequence length
	int n;
	cin >> n;
	//then initiat the array to represent sequence
	int  sq[n];
	//maintianing a small log of number of each value
	int cnt[8] = {0};
	for (int i = 0; i < n; i++) {
		cin >> sq[i];
		cnt[sq[i]]++;
	}
	
	//feasible combinations are
	//1, 2, 4 = comb[1]
	//1, 3, 6 = comb[2]
	//1, 2, 6 = comb[3]
	
	int comb[4] = {0};
	comb[1] = cnt[4]; // 4 is the only unique value which governs comb[1] count
	comb[2] = cnt[3]; // 3 is the only unique value which governs comb[2] count
	comb[3] = cnt[6] - comb[2]; 
		// 6 is the value which is common in both comb[3] and comb[2]
	
	//validating the state of variable before concluding the result
	bool valid = true;
	if (cnt[5] != 0 || cnt[7] != 0) valid = false;
	if (comb[3] < 0) valid = false;
	if (cnt[1] != comb[1] + comb[2] +comb[3]) valid = false;
	if (cnt[2] != comb[1] + comb[3]) valid = false;

	if (!valid) cout << "-1";
	else {
		if (comb[1]) for(int i=0; i<comb[1]; i++) cout << "1 2 4" << endl;
		if (comb[2]) for(int i=0; i<comb[2]; i++) cout << "1 3 6" << endl;
		if (comb[3]) for(int i=0; i<comb[3]; i++) cout << "1 2 6" << endl;
	}
	

	return 0;
}
