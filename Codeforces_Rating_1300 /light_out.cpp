#include <iostream>
using namespace std;

int main(void){

	int lights[3][3];

	for (int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			lights[i][j] = 1;
	
	int grid_pressed[3][3];

	for (int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			cin >> grid_pressed[i][j];

	
	for (int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(grid_pressed[i][j]%2 != 0){
				lights[i][j] = (lights[i][j]==0)?1:0;
				if(i-1 > -1) lights[i-1][j] = (lights[i-1][j]==0)?1:0;
				if(i+1 < 3) lights[i+1][j] = (lights[i+1][j]==0)?1:0;
				if(j-1 > -1) lights[i][j-1] = (lights[i][j-1]==0)?1:0;
				if(j+1 < 3) lights[i][j+1] = (lights[i][j+1]==0)?1:0;
			}


	for (int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++){
			cout << lights[i][j];
		}
		cout << "\n";
	}

	return 0;
}
