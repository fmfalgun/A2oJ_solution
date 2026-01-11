#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

	long long len;
	cin >> len;
	vector<int> arr(len);
	unordered_map<int, int> position;

	for(int i=0; i<len; i++)
	{
		cin >> arr[i];
		position[arr[i]] = i+1; //store 1-based index
	}


	int m,b;
	long long vasya_count=0,petya_count=0;
	cin >> m;
	while(m--){
		cin >> b;
		
		vasya_count += position[b];
		petya_count += len - position[b] +1;
	}

	cout << vasya_count << " " << petya_count;
	
	return 0;
}


