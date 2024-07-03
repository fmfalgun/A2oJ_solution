#include <iostream>

using namespace std;

int main(void){

	int n, m;
	cin >> n >> m;
	bool flag = false;
	for (int i=n+1; i<m; i++){
		flag = true;
		for(int j=2; j <i; j++){
			if (i%j == 0) {
				flag = true;
				break;
			}
			cout << i << " " << j << " " <<flag << endl;
		}	
		if (flag) break;
	}

	cout << flag; 

	return 0;
}
