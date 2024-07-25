#include<iostream>
#include"Caesar.h"

using namespace std;

string texts = "hello world";
int key = 3;
string filename = "test";

int main() {

	cout << "enter the filename\n";
	cin >> filename;
	Caeser f(filename);
	f.read_Datafile(1, key);
	
}