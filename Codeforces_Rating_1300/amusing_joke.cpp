#include <iostream>
#include <string>

using namespace std;

int main() {
    
	string guest_name, host, letters_pile;
	cin >> guest_name >> host >> letters_pile;
	//cout << guest_name << " " << host << " " << letters_pile << endl;
	if (guest_name.size() + host.size() <= letters_pile.size()){
	for (int i=letters_pile.size()-1; i>=0; i--){
		bool removed = false;
		for (int j=guest_name.size()-1; j>=0; j--)
			if (guest_name[j] == letters_pile[i])
			{
				guest_name.erase(guest_name.begin()+j);
				letters_pile.erase(letters_pile.begin()+i);
				removed = true;
				break;
			}
		if (!removed) 
			for (int j=host.size()-1; j>=0; j--)
				if(host[j] == letters_pile[i])
				{
					host.erase(host.begin()+j);
					letters_pile.erase(letters_pile.begin()+i);
					removed = true;
					break;
				}
		//cout << removed << " " << guest_name << " " << host << " " << letters_pile << endl;
	}

	if (letters_pile.size() == 0) cout << "YES";
	else cout << "NO";
	}
	else cout << "NO";
	return 0;
}


