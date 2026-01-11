#include <iostream>

using namespace std;

int main(void){

	int n;
	cin >> n;
	int arr[n];
	int max_val=0, min_val=999, max_val_loc, min_val_loc;

	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if (arr[i]>max_val){
			max_val = arr[i];
			max_val_loc = i;
		}
	}
	int prev_max_val_loc = max_val_loc;
	while(arr[0] != max_val){
		arr[max_val_loc] = arr[max_val_loc - 1];
		arr[max_val_loc - 1] = max_val;
		max_val_loc --;
	}
	
	for(int i = 0; i < n; i++){
		if (arr[i] <= min_val){
			min_val = arr[i];
			min_val_loc = i;
		}
	}
	cout << (prev_max_val_loc+n-1-min_val_loc);


	return 0;
}
