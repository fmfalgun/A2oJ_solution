#include <iostream>

using namespace std;

int main() {
    
	int n, m;
	cin >> n >> m;
	int maxx = max(n,m), pair_count=0;
	for (int i=0; i<=maxx; i++)
		for (int j=0; j<=maxx; j++)
			if ((((i*i)+j)==n) && ((i+(j*j)) == m)){
				//cout << i << " " << j << endl;
				pair_count++;
			}
	cout << pair_count;
    return 0;
}


