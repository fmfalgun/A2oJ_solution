#include <iostream>

using namespace std;

int main() {
    
	int n;
	cin >> n;
	int arr[n], max=-1, min =9999, amazing=0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if (i==0){
			max = arr[i];
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
			amazing ++;
		}
		if(arr[i] < min){
			min = arr[i];
			amazing++;
		}
	}	
	cout << amazing;

    return 0;
}


