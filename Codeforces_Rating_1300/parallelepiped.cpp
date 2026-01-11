#include <iostream>
#include <cmath>
using namespace std;

int gcd (int a, int b){
	if (a < b){
		int temp = a;
		a = b; 
		b = temp;
	}

	while(b!=0){
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main() {
    
	int ar1, ar2, ar3;
	cin >> ar1 >> ar2 >> ar3;

	int s1, s2, s3, xum;
	s1 = sqrt((ar1*ar2)/ar3);
	s2 = sqrt((ar2*ar3)/ar1);
	s3 = sqrt((ar3*ar1)/ar2);
	xum = 4*(s1+s2+s3);
	cout << xum;
	return 0;
}


