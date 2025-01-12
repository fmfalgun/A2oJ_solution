#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    
	int temp, n;
	cin >> n;
	vector<long long int> flwr;	
	
	while(n--){
		cin >> temp;
		flwr.push_back(temp);
	}

	long long int max_diff = INT_MIN;
	
	for(int i=0; i<flwr.size(); i++) 
		for(int j=i; j<flwr.size(); j++)
			if (abs(flwr[i]-flwr[j]) > max_diff) max_diff = abs(flwr[i]-flwr[j]);

	long long int perm=0;
	for(int i=0; i<flwr.size(); i++)
		for(int j=i; j<flwr.size(); j++)
			if (abs(flwr[i]-flwr[j]) == max_diff) perm++;
	
	cout << max_diff << " " << perm;
    return 0;
}


