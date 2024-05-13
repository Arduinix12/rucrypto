//RSA.h
#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
static long int p, q,t;


 static vector<long int> encryptedText(100, 0);

static vector<long int> decryptedText(100, 0);

static bool flag;
static string msg;

using namespace std;

class RSA
{
public:
	string encrypt(string msg);
	string decrypt(string msg);
	int genereytkey(int p, int q);
	
	static long int e, n;
private:
	bool isPrime(long int prime);
	long int calculateE(long int t);
	long int greatestCommonDivisor(long int e, long int t);
	long int calculateD(long int e, long int t);
	
	long int encryptions(long int i, long int e, long int n);
	long int decryptions(long int i, long int d, long int n);
	 static long int d;
};

#endif