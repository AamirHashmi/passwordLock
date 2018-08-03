#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

int main() {
	


	int count = 0;
	bool gainedAccess = false;
	bool isLocked = false;
	string attempt;
	string locked;

	ifstream fin;
	fin.open("c:\\meta_verse\\locked.txt", ios::in);
	fin >> locked;
	fin.close();

	if (locked == "locked") {
		isLocked = true;
	}

	if (!isLocked) {
		while (!gainedAccess && count != 3) {
			cout << "Enter the password" << endl;
			cin >> attempt;
			if (attempt == "HelloDaVe123") {
				gainedAccess = true;
				ShellExecute(0, "open", "c:\\meta_verse\\od.txt", NULL, NULL, 1);
			}
			else {
				cout << "Wrong password try again" << endl;
			}
			count++;
		}
		if (!gainedAccess) {
			cout << "Too many wrong attempts" << endl;
			ofstream fout;
			fout.open("c:\\meta_verse\\locked.txt", ios::out);
			fout << "locked";
			fout.close();
		}
		else {
			cout << "Correct" << endl;
		}
	}
	else {
		cout << "app is locked" << endl;
	}
	system("PAUSE");

	return 0;
}