#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    
	int n, m;
	cin >> n >> m;
	vector<int> f(m);

	for (int i=0; i<m; i++) cin >> f[i];

	sort(f.begin(), f.end());

	int val = INT_MAX;
	for (int i=0; i<=m-n; i++){
		val = min(val, f[i+n-1]-f[i]);
	}
	cout << val;

    return 0;
}


