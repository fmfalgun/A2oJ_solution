#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    
	int n, count=0;
	cin >> n;
	int x[n], y[n];
	for(int i=0; i<n; i++)
		cin >> x[i] >> y[i];
	
	bool right, left, lower, upper;	
	for(int i=0; i<n; i++){
		right = false;
		left = false;
		lower = false; 
		upper = false;

		for(int j=0; j<n; j++){
			if (x[j]>x[i] && y[j]==y[i]) right = true;
			else if (x[j]<x[i] && y[j]==y[i]) left = true;
			else if (x[j]==x[i] && y[j]<y[i]) lower = true;	
			else if (x[j]==x[i] && y[j]>y[i]) upper = true;
		}
		if (right && left && lower && upper) count++;
	}

	cout << count;

    return 0;
}


