#include <iostream>

using namespace std;

int main() {
    
	int temp, minn=0, summ=0, n, m;
	cin >> n >> m;
	int sale[n];

	for (int i=0; i<n; i++) cin >> sale[i];

	for (int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if (sale[j] < minn) {
				minn = sale[j];
				temp = j;
			}
		}
		summ += minn;
		sale[temp] = 0;
		minn = 0;
	}
	cout << abs(summ);

    return 0;
}


