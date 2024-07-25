//RSA.h
#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include<fstream>

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
	RSA();
	RSA(string inputfile);
	RSA(string inputfile, string outputfile);
	RSA(string inputfile, string outputfile, string keyfile);
	~RSA();
	int read_Datafile(int cryptomode, int p,int q);
	int read_Datafile(int cryptomode);
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

	 fstream finputfile;
	 fstream foutputfile;
	 fstream fkeyfile;
	 string	inputfile = "con";
	 string outputfile = "con";
	 string keyfile = "con";
	 string errorstr = "con";
	 string end = ".txt";
	 int mode;
	 int cryptomode;
	 bool deleteFile(string filePath);
	 int chekfile();
	 int get_fkey(vector<char> buffer,int p,int q);
	 int p, q;
	
};

#endif