#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    
	int temp, n;
	cin >> n;
	vector<long long int> flwr;	
	
	while(n--){
		cin >> temp;
		flwr.push_back(temp);
	}

	sort(flwr.begin(), flwr.end());
	long long int max_diff = flwr[flwr.size()-1]-flwr[0];
	
	long long int nn, minValueCount=0, maxValueCount=0;

	for(int i=0; i<flwr.size(); i++){
		if (flwr[i] == flwr[0]) minValueCount++;
		if (flwr[i] == flwr[flwr.size()-1]) maxValueCount++;
	}
	nn = flwr.size();
	long long int perm=(max_diff==0)?((nn*(nn-1)/2)):maxValueCount * minValueCount;
	cout << max_diff << " " << perm;
    return 0;
}


