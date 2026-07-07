#include <iostream>

using namespace std;

int main() {
    	
	int t;
	cin >> t;
	int l[t], r[t], l_open_count=0, r_open_count=0;
	for(int i=0; i<t; i++){
		cin >> l[i] >> r[i];
		if (l[i] == 1) l_open_count += 1;
		if (r[i] == 1) r_open_count += 1;
	}
	if(l_open_count > r_open_count)
		if (t-r_open_count > r_open_count)
			cout << (t-l_open_count +r_open_count);
		else cout << (t-l_open_count + t-r_open_count);
	else if (r_open_count > l_open_count) 
		if (t-l_open_count > l_open_count)
			cout << (t-r_open_count+l_open_count);
		else cout << (t-l_open_count + t-r_open_count);
	else 
		if (l_open_count == t || t-l_open_count == t) cout << "0";
		else cout << ((t-l_open_count)*2);
	return 0;
}


