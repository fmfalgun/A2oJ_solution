#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void){

    // saving all inputs in unordered map which is hash based list, with search time complexity of O(1)
    unordered_map<char, int> freq;
    string input;
    getline(cin,input);

    for (char c : input) {
        if (freq[c] > 0) freq[c] ++;
        else freq[c] = 1;
    }

    // clearing the input string to reuse it for the second input    
    input.clear();
    getline(cin, input);
    bool feasible = true;
    
    // main validation logic to generate the response
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