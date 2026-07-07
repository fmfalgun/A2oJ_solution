#include <iostream>

using namespace std;

int main() {
    
	long long int n, k;
	cin >> n >> k;

	if (n%2 == 0) cout << (((n/2) < k)?((k-(n/2))*2):((k-1)*2+1));
	else cout << (((n/2) < k-1)?((k-1-(n/2))*2):((k-1)*2+1));
	return 0;
}


