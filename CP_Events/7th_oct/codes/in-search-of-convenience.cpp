#include <iostream>


using namespace std;

int main(void){

	int testcases;
	cin >> testcases;
	while (testcases--){

		int x, y, r;
		cin >> x >> y >> r;
		
		// condition says all set of options accepted, so this logic is enough
		cout << x << " " << (r+y) << endl;

	}

}
