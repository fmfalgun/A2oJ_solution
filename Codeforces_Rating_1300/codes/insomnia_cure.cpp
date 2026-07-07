#include <iostream>
#include <algorithm>
using namespace std;

int lcm(int a, int b){
	return a*(b/__gcd(a,b));
}

int main() {
    
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int count = 0;

    // Counts of dragons divisible by each number
    int count_k = d / k;
    int count_l = d / l;
    int count_m = d / m;
    int count_n = d / n;

    // Counts of dragons divisible by pairs
    int count_kl = d / lcm(k, l);
    int count_km = d / lcm(k, m);
    int count_kn = d / lcm(k, n);
    int count_lm = d / lcm(l, m);
    int count_ln = d / lcm(l, n);
    int count_mn = d / lcm(m, n);

    // Counts of dragons divisible by triples
    int count_klm = d / lcm(k, lcm(l, m));
    int count_kln = d / lcm(k, lcm(l, n));
    int count_kmn = d / lcm(k, lcm(m, n));
    int count_lmn = d / lcm(l, lcm(m, n));

    // Counts of dragons divisible by all four
    int count_klmn = d / lcm(k, lcm(l, lcm(m, n)));

    // Apply inclusion-exclusion principle
    count = count_k + count_l + count_m + count_n 
          - count_kl - count_km - count_kn - count_lm - count_ln - count_mn
          + count_klm + count_kln + count_kmn + count_lmn
          - count_klmn;

    cout << count << endl;
    return 0;
}


