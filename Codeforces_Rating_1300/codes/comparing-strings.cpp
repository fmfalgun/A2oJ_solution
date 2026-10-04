#include <iostream>
#include <string>

using namespace std;

int main(void){

    // collecting inputs
    string str1, str2;
    cin >> str1 >> str2;

    // setting variables
    bool swap_possible = true;
    int mismatch = 0;
    int indx1, indx2;

    // conditional checking starts
    // better approach, replacing extra arrays with small int variable
    // removed extra string based swapping logic
    if(str1.length()  != str2.length()) swap_possible = false;
    else {
        int mismatch_index_counter = 0;
        for (int i = 0; i < str1.length(); i++)
            if (str1[i] != str2[i]) {
                mismatch++;
                if (mismatch == 1) indx1 = i;
                if (mismatch == 2) indx2 = i;  
            }
        if (mismatch != 2) swap_possible = false;
        else {
            if (!(str1[indx1] == str2[indx2]
            && str1[indx2] == str2[indx1])) swap_possible = false;
        }
    }

    cout << (swap_possible ? "YES" : "NO");

    return 0;
}