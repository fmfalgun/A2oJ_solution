#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

int main() {
    
	int n ,m, value, pos, maxx, minn;
	cin >> n >> m;
	vector<int> p, q;	
	
	for (int i=0; i<m; i++){
		cin >> value;
	       	p.push_back(value);
	}
	q = p;
	value = 0;
	for(int i=0; i<n; i++){
		maxx = INT_MIN;
		for(int i=0; i<m; i++){
			if (p[i] >= maxx && p[i]>0){ 
				maxx = p[i];
				pos = i;
			}
		}
		value += p[pos];
		p[pos] = p[pos] -1;
	}
	cout << value;

	value = 0;
	while(n--){
		minn = INT_MAX;
		for(int i=0; i<m; i++){
			if (q[i] <= minn && q[i] > 0){
			       	minn = q[i];
				pos = i;
			}
		}
		value += minn;
		q[pos] = minn -1;
	}
	cout << " " << value;
    return 0;
}


