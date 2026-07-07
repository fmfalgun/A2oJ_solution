#include <iostream>

using namespace std;

int main() {
    
	int n, lenn;
	cin >> n;
	lenn = 2*n +1;
	bool need2break;
	for(int j=0; j<lenn; j++){
		for(int i=0; i<lenn; i++){
			need2break = false;
			if ((i<=n) && (j<=n) && (i+j >= n)) 
				cout << (i+j-n);
			else if ((i>n)&&(j<=n)&&(i-j<=n)) 
				cout << (n-i+j);
			else if ((i<=n)&&(j>n)&&(j-i<=n))
				cout << ((n+i-j));
			else if ((j>n)&&(i>n)&&(i+j<=3*n))
				cout << ((3*n)-i-j);	
			else cout << " ";
			if((i-j==n)||(i+j==3*n)) break;
		        else cout << " ";
		}
		cout << endl;
	}	

    return 0;
}


