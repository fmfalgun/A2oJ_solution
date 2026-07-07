#include <iostream>
#include <string>

using namespace std;

int main() {
    
	string remix, song, repeating_string = "WUB";
	cin >> remix;
	int remix_len = remix.length(),
	repeating_string_len = repeating_string.length();
	bool added_space = false;

	int counter = 0;
	while (counter < remix_len){
		if (remix.substr(counter, repeating_string_len) == repeating_string){
		       	counter+= repeating_string_len;
			if (!song.empty() && !added_space){
				song += " ";
				added_space = true;
			}
		}
		else{
			song += remix[counter];
			counter++;
			added_space = false;
		}
	}	
	cout << song;

    return 0;
}


