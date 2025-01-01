#include <iostream>

using namespace std;

int main() {
    
	int n;
	cin >> n;
	string a, b, temp;
	int count_a=0, count_b=0;
	while (n--){
		cin >> temp;
		if (count_a == 0) a = temp;
		else if (count_b == 0) b = temp;

		if(temp == a) count_a ++;
		else count_b ++;
	}	
	cout << ((count_a > count_b)?a:b);

    return 0;
}


