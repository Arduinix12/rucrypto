#include"3DES.h"
string input;
string output;
string key;
int main() {
	threDES d(input,output,key);
	d.read_Datafile(1);
}