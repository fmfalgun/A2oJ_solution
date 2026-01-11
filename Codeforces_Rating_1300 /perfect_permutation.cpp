#include <iostream>
using namespace std;

int main(void){
    
    int len;
    cin >> len;
    
    if (len <= 1 || len%2!=0) cout << "-1";
    else for(int i=1; i<len; i=i+2){
        cout << i+1 << " " << i << " ";
    }
    
    return 0;
}
