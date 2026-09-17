#include <iostream>
#include <unordered_map>
using namespace std;

int main (void){

    // taking first value
    int input_values;
    cin >> input_values;

    // taking second set of values
    unordered_map<int, int> apples;
    apples[100] = 0;
    apples[200] = 0;

    int temp;
    while(input_values--){
        cin >> temp;
        if (temp == 100) apples[100]++;
        else apples[200]++;
    }

    

    return 0;

}