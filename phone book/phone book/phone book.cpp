#include <iostream>
#include <string>
using namespace std;
struct names
{
	string name;
	string number;
};
// function to convert letters to small (if they are capital)
string small(string s) {
	for (int i = 0; i < s.length();i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	return s;
}
// function to check if the search of the user is found or not 
bool search(string name_or_num, string sub) //name or num =>olready exist | sub => the search item
{
	// ahmed => med
	int a = name_or_num.length();
	int b = sub.length();
	for (int i = 0; i <= a - b; i++) {
		bool found = true;
		for (int j = 0; j < b; j++) {
			if (name_or_num[i + j] != sub[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			return true;
		}
	}
	return false;
}
int main()
{
	//to ask the user if he want to try again
	
	bool again = true;
	while (again){
	cout << "                            ______________________________________" << endl;
	cout << "                                    (welcome to phone book)       " << endl;
	cout << "                            ______________________________________" << endl<<endl <<endl;
	names phone_book[10] = {
		{"Nada Ezz eldein ", "01030787354"},
		{"Usra Amin       ", "01150042556"},
		{"Hadeer Mostafa  ", "01010093930"},
		{"Sandy Makram    ", "01208715534"},
		{"Ali Omar        ", "01005133161"},
		{"Mohamed Ahmed   ", "01069778645"},
		{"Saad Yasser     ", "01062876093"},
		{"Haidy Sobhy     ", "01221623460"},
		{"Sohaila Emad    ", "01028733784"},
		{"Nour Hossam     ", "01109873643"}
	};
	string s1;
	cout << "Please enter the name or the number that you want to search for : ";
	getline(cin, s1);
	if (s1.size() != 1 && s1[0] == ' ') {
		s1.erase(0, 1);
	}
	s1 = small(s1);
	bool found = false;
	cout << "The results of your search is:\n";
	for (int i = 0; i < 10; i++) {
		string small_name = small(phone_book[i].name);
		if (search(small_name, s1) || search(phone_book[i].number, s1)) {
			cout << "** " << phone_book[i].name << " : " << phone_book[i].number << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No matches found!\n\n";
	}
	cout << "Do you want to search again? \n Press 1 to search again and 0 to exit: ";
	cin >> again;
	cin.ignore(10000, '\n');
	while (again > 1 || again < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nInvalid number. please enter another number\n";
		cin >> again;
		cin.ignore(10000, '\n');
	}
	}
	cout << "\n\nThank you for using our programme\n";
	return 0;
  }
