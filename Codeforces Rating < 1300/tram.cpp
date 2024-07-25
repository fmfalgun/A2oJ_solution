#include <iostream>

using namespace std;

int main() {
    
	int n;
	cin >> n;
	int a[n], b[n], max_psng=0, psng=0;
	for (int i=0; i<n; i++){
		cin >> a[i] >> b[i];
		psng = psng - a[i] +b[i];
		if(psng > max_psng) 
			max_psng = psng;
	}	
	cout << max_psng;
    return 0;
}


