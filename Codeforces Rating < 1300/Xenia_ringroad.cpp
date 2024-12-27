#include <iostream>
using namespace std;
 
int main(void){
    
    int n, m, temp=0, prev_temp;
    long long int result=0;
    cin >> n >> m;
    
    while(m--){
            prev_temp = temp;
            cin >> temp;
            
            if (temp != prev_temp)
	    {
		    if (temp > prev_temp) result += temp-prev_temp;
		    else result += (n-prev_temp) +temp;
	    }
    }
    cout << result-1;
    return 0;
}
