


#include<iostream>
#include<string>
#include<vector>

using namespace std;

#ifndef OTBASH_H
#define OTBASH_H

class Otbash
{
public:
	string encryptOtbas(string text);
	string decryptOtbas(string text);
private:
	string text;
};


#endif 
