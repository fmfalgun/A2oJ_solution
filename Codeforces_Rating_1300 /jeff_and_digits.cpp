#include <iostream>

using namespace std;

int main() {
    
	int n, zero_count=0, five_count=0;
	cin >> n;
 	int a[n];
	for (int i=0; i<n; i++){
	       cin >> a[i];
	       if (a[i] == 5) five_count ++;
	       else zero_count ++;
	}
	if (zero_count > 0 && five_count > 8){
		five_count = five_count - (five_count%9);
		while(five_count--) cout << "5";
		while(zero_count--) cout << "0";
	}
	else if (zero_count > 0) cout << "0";
	else cout << "-1";
		

    return 0;
}


