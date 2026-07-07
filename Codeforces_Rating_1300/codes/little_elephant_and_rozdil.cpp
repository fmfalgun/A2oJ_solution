#include <iostream>

using namespace std;

int main() {
    
	int n,len,position=-1,min_cities=0;
	long int min_time = 9999999999;
	cin >> n;
	len = n;
	int a[n];
	while (n--){
		cin >> a[len-n];
		if(min_time > a[len-n]){
			min_time = a[len-n];
			min_cities = 1;
			position = len-n;
		}
		else if (min_time == a[len-n])
			min_cities ++;
	}
	if (min_cities == 1) cout << position;
	else cout << "Still Rozdil";
	
	return 0;
}


