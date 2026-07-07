#include <iostream>

using namespace std;

int main() {
    
	int pgs, sum=0;
 	cin >> pgs;

	int weeks[7];
	for(int i=0; i<7; i++){
	       	cin>> weeks[i];
		sum += weeks[i];
	}

	int total_days = 0;
	int day=0;
	while(pgs>0){
		pgs -= weeks[day];
		if (pgs <= 0) break;
		total_days += 1;
		day += 1;
		if(day >6) day = day%7;
		//cout
		// << total_days << " "  << day << " "<< pgs << " " << endl;
	}

	cout  << day+1;
    return 0;
}


