#include <iostream>

using namespace std;

int main() {
    
	int s, l;
	cin >> s >> l;
	int x[l], y[l];
	for (int i=0; i<l; i++)
		cin >> x[i] >> y[i];

	int min, min_pos;
	bool weak_dragon;
	for (int i=0; i<l; i++){
		min = s;
		min_pos = -1;
		weak_dragon = false;
		for (int j=0; j<l; j++)
			if (x[j] < s){
				min = x[j];
				min_pos = j;
				weak_dragon = true;
			}
		if(!weak_dragon) break;
		x[min_pos]=100000;
		s += y[min_pos];
	}

	cout << (weak_dragon?"YES":"NO");

    return 0;
}


