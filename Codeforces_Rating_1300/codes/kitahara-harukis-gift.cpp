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

    // logic says
    // result entire depends on value of 100
    // unless it's value is zero
    int temp;
    while(input_values--){
        cin >> temp;
        if (temp == 100) apples[100]++;
        else apples[200]++;
    }

    //cout << apples[100] << " " << apples[200] << endl;

    if (apples[100] % 2 == 0 && apples[100] != 0) cout << "YES";
    else if (apples[100] == 0 && apples[200] % 2 == 0) cout << "YES";
    else cout << "NO";

    return 0;

}