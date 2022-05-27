#include <iostream>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

void hashtext(string str, string &output) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'Z') str[i] = 'A';
		else str[i]--;
	}
	output += str;
}
void hashfind(string &str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'Z') str[i] = 'A';
		else str[i]--;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	string str, output, search;
	ifstream file("input.txt");
	while (getline(file, str)) {
		cout << str << endl; //DEBUG
		hashtext(str, output);
	}
	cout << output << endl;
	cout << "Искомая строка: " << endl;
	getline(cin, search);
	hashfind(search);
	int i = output.find(search);
	if (i != -1) {
		cout << "Index: " << i << endl;
	}
	else cout << "Not Found";
	return 0;
}