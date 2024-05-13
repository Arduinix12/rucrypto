#ifndef CAESER_H
#define CAESER_H

#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <typeinfo>

using namespace std;

class Caeser {
public:
	string decript(string str, int key);
	string encript(string str, int key);
	string getword(string str);
	int getkey(int key);
private:
	string str;
	int key;
	int chekkey(int key);
};
#endif