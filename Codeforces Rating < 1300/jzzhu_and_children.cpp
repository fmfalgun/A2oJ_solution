#include <iostream>

using namespace std;

int main() {
    
	int n, m, last_kid=0, max_iterations = 0, iterations;
	cin >> n >> m;
	int a[n];
	
	for(int i=0; i<n; i++){
		iterations=0;
		cin >> a[i];
		iterations = (a[i]%m==0)?(a[i]/m):((a[i]/m)+1);
		if (max_iterations <= iterations) {
			last_kid = i;
			max_iterations = iterations;
		}
	}	
	cout << last_kid+1;

	return 0;
}


