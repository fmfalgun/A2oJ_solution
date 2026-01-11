#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;

	int drinks_for_toast = (k*l)/nl;
	int limes_for_toast = (c*d);
	int salt_for_toast = (p/np);

	int feasible_toast = min(drinks_for_toast, min(limes_for_toast, salt_for_toast))/n;
	cout << feasible_toast ;

	return 0;
}


