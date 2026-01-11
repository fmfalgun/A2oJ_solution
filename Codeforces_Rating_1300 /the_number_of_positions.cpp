#include <iostream>

using namespace std;

int main() {
    
	int n, a, b, result;
	cin >> n >> a >> b;
	
	result = n - max(a+1, n-b) +1;

	cout << result;

    return 0;
}


