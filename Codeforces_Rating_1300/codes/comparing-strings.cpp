#include <iostream>
#include <string>

using namespace std;

int main(void){

    string str1, str2;
    cin >> str1 >> str2;

    bool swap_possible = true;
    int mismatch = 0;
    int mismatch_index[str1.length()];
    if(str1.length()  != str2.length()) swap_possible = false;
    else {
        int mismatch_index_counter = 0;
        for (int i = 0; i < str1.length(); i++)
            if (str1[i] != str2[i]) {
                mismatch++;
                mismatch_index[mismatch_index_counter++] = i;  
            }
        if (mismatch != 2) swap_possible = false;
        else {
            string temp = str1;
            char temp_chr = str1[mismatch_index[0]];
            temp[mismatch_index[0]]  = temp[mismatch_index[1]];
            temp[mismatch_index[1]]  = temp_chr;
            if (temp != str2) swap_possible = false;
        }
    }

    cout << (swap_possible ? "YES" : "NO");

    return 0;
}