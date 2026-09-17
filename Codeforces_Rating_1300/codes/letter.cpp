#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void){
    
    unordered_map<char, int> freq;
    string input;
    getline(cin,input);

    for (char c : input) {
        if (freq[c] > 0) freq[c] ++;
        else freq[c] = 1;
    }

    input.clear();
    getline(cin, input);
    bool feasible = true;
    for (char c : input){
        if (freq[c] > 0) continue;
        else{
            feasible = false;
            break;
        }
    }

    cout << (feasible ? "YES" : "NO") << endl;
    return 0;   
}