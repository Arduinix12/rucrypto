#ifndef DES_H
#define DES_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>

#define DEBUG 0

using namespace std;

extern const int IP[64];
extern const int IP_1[64];
extern const int E_exp[48];
extern const int P_transform[32];
extern const int PC_1[56];
extern const int PC_2[56];
extern const int SBOX_1[4][16];
extern const int SBOX_2[4][16];
extern const int SBOX_3[4][16];
extern const int SBOX_4[4][16];
extern const int SBOX_5[4][16];
extern const int SBOX_6[4][16];
extern const int SBOX_7[4][16];
extern const int SBOX_8[4][16];
 typedef const int(*SBOX)[16];


class DES {
    
    public:
       

        void encode(string str, string key);
        void decode(string str, string key);
    private:
        bool flag = false;
        int chekstring(string str);
        int chekkey( string key);
        string total_code, total_key;
        string tempCode_1, tempCode_2;
        string m_code, code;
        string L, R, C, D;
        vector<string> K;
        void fill(string str);
        void formatSourceCode();
        void getIP0();
        string Feistel(string R, string K);
        string getPTransform(string str);
        string Feistel_SBOX(string str, int num);
        string E_expend(string str);
        string XORoperation(string a, string b);
        string iterationT_A(int begin, int end);
        string iterationT_D(int begin, int end);
        string getIP1(string str);
        string formatResult(string str);
        string formatAndReduceResult(string str);
        int Two2Ten(string num);
        string formatKey();
        string getPC1Key(string str);
        void get_C_D(string str);
        void getKeyI();
        void LS_1(string& str);
        void LS_2(string& str);
        string getPC2Key(string str);
        void getKeys();
    };

#endif
