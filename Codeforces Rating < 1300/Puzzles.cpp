#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
	int n, m;
	cin >> n >> m;
	vector<int> f(m);

	for (int i=0; i<m; i++) cin >> f[i];

	sort(f.begin(), f.end());

	for(int i=0; i<m; i++) cout << f[i] << " ";
	cout << "\n";
	//cout << "\n" << m-1 << " " << m-n-1 << " " << f[m-1] << " " << f[m-n-1] << endl;
	//cout << (f[m-1]-f[m-n]) << (f[n-1]-f[0]) << endl;
		
	int val = 1001;
	for(int i=0; i<m; i++){
	       	if((f[i+n]-f[i]<val) && (i+n <= m-1)) val = f[i+n]-f[i];
		cout << val << " ";
	}
	cout << "\n" << val;

	//if (m!=n) cout << min((f[m-1]-f[m-n]),(f[n-1]-f[0]));
	//.else cout << (f[n-1]-f[0]);
    return 0;
}


