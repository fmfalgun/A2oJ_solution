#include <iostream>

using namespace std;

int main() {
    
	int k, a[12], min_months=0;
	cin >> k;

	for (int i=0; i<12; i++) cin >> a[i];	
	
	while(k>0 && min_months < 12){
		int maxx = -1, position= -1;
		for(int i=0; i<12; i++){
			if (a[i] > maxx){
				maxx = a[i];
				position = i;
			}
		}
		if (maxx >= 0){
			k = k-maxx;
			min_months ++;
			a[position] = -1;
		}
		//cout << k << " " << min_months << " " << maxx << endl;
	}
	if (min_months == 12 && k != 0) min_months = -1;
	cout << min_months;

    return 0;
}


