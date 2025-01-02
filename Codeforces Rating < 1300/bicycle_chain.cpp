#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    
	int n, m;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	
	cin >> m;
	int b[m];
	for (int i=0; i<m; i++) cin >> b[i];
	
	float gear[n*m];
	int h=0;
	for(int j=0; j<m; j++)
		for(int k=0; k<n; k++)
			gear[h++] = float(float(b[j])/float(a[k]));

	int max_int_gear_ratio = 0, all_integer_gears = 0, temp=0;
	for (int i=0; i<n*m; i++){
		temp = static_cast<int>(gear[i]);
		temp = static_cast<float>(temp);
		if (temp == gear[i]){
			if(int(gear[i] > max_int_gear_ratio)){
				max_int_gear_ratio = int(gear[i]);
				all_integer_gears = 1;
			}
			else if (int(gear[i]) == max_int_gear_ratio) all_integer_gears ++;
		}
	}

	cout << all_integer_gears;
    return 0;
}


