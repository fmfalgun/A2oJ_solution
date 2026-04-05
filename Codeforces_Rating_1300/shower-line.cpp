#include <bits/stdc++.h>
using namespace std;

int g[6][6];

int main(){
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            cin >> g[i][j];

    int permutation[5] = {1,2,3,4,5};
    int answer = 0;
    int happy, a, b, w[] = {1,1,2,2};

    do {
        happy = 0;
        for (int i=0; i<4; i++){
            a = permutation[i];
            b = permutation[i+1];

            happy += w[i] * (g[a][b] + g[b][a]);
        }
        if (happy > answer) answer = happy;
    } while (next_permutation(permutation, permutation+5));
    cout << answer << endl;
}


//   int g[6][6];

//   int main() {
//       for (int i = 1; i <= 5; i++)
//           for (int j = 1; j <= 5; j++)
//               cin >> g[i][j];

//       int perm[5] = {1, 2, 3, 4, 5};
//       int ans = 0;

//       do {
//           int *p = perm;
//           int happy = 0;
//           // weights: positions (0,1)=1, (1,2)=1, (2,3)=2, (3,4)=2
//           int w[] = {1, 1, 2, 2};
//           for (int i = 0; i < 4; i++) {
//               int a = p[i], b = p[i+1];
//               happy += w[i] * (g[a][b] + g[b][a]);
//           }
//           ans = max(ans, happy);
//       } while (next_permutation(perm, perm + 5));

//       cout << ans << endl;
//   }