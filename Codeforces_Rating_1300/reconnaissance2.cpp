#include <iostream>

using namespace std;

int main() {
    
	int diff, min_dif=99999,n,i=0, neigh1, neigh2;
	cin >> n;
	int a[n];
	while (n--){
		cin >> a[i];
		i++;
	}
	for (int j=0; j<i; j++){
		if (j!=i-1) diff = (a[j] > a[j+1])?(a[j]-a[j+1]):(a[j+1]-a[j]);
		else diff = (a[j] > a[0])?(a[j]-a[0]):(a[0]-a[j]);
		if (min_dif > diff) {
			min_dif = diff;
			neigh1 = j+1;
			neigh2 = (j==i-1)?(1):(neigh1+1);
		}
	}

	cout << neigh1 << " " << neigh2;

	return 0;
}


