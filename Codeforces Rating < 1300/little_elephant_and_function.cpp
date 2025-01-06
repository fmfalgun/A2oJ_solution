#include <iostream>

using namespace std;

void print_perm(int* arr,int size){
	cout << "\narray = ";
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void recursion(int x, int* arr, int size){
	if (x==0) return;
	recursion(x-1,arr,size);

	int temp = arr[x-1];
	cout << x << " " << temp << endl;
	print_perm(arr,size);
	arr[x-1] = arr[x];
	arr[x] = temp;
}

int main() {
    
	int n;
	cin >> n;
	int perm[n];
	for (int i=0;i<n; i++) perm[i]=i+1;

	recursion (n, perm,n);
	print_perm(perm,n);
    return 0;
}


