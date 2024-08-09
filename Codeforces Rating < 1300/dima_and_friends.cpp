#include <iostream>

using namespace std;

int main() {
    
	int n, summ=0;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		summ += arr[i];
	}

	int number_of_ways=0;
	for (int i=1; i<6; i++)
		if ((summ+i)%(n+1)!=1)
			number_of_ways += 1;

	cout << number_of_ways;

	return 0;
}


