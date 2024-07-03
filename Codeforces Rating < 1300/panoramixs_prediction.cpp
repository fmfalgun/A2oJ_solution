#include <iostream>

using namespace std;

bool prime_check(int i){
	bool result = true;
	for(int j=2; j <i; j++)
		if (i%j == 0) {
			result = false;
			break;
		}
	return result;
}

int main(void){

	int n, m;
	cin >> n >> m;
	bool exist = false;
	for (int i=n+1; i<=m; i++){
		exist = prime_check(i);
		if (exist) break;	
	}

	cout << (exist?"YES":"NO"); 

	return 0;
}
