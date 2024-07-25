#include "otbash.h"
#include<iostream>

using namespace std;



Otbash::Otbash()
{
    int mode = 0;
    this->mode = mode;

}

Otbash::Otbash(string inputfile)
{
    int mode = 1;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);

    chekfile();
}

Otbash::Otbash(string inputfile, string outputfile)
{
    int mode = 2;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
    this->outputfile = outputfile;
    finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
    chekfile();
}

Otbash::~Otbash()
{
    switch (mode) {
    case 1:
        finputfile.close();
    case 2:
        finputfile.close();
        foutputfile.close();
    }
}

string Otbash::encryptOtbas(string text) {
    string encryptedText = "";


        for (int i = 0; i < text.length(); i++) {
            if (isalpha(text[i])) {
                if (isupper(text[i])) {
                    encryptedText += char('Z' - (text[i] - 'A'));
                }
                else {
                    encryptedText += char('z' - (text[i] - 'a'));
                }
            }
            else {
                encryptedText += text[i];
            }
        }
    return encryptedText;
}

string Otbash::decryptOtbas(string text) {
    string decryptedText = "";


        for (char ch : text) {
            if (isalpha(ch)) {
                if (islower(ch)) {
                    decryptedText += 'a' + ('z' - ch);
                }
                else {
                    decryptedText += 'A' + ('Z' - ch);
                }
            }
            else {
                decryptedText += ch;
            }
        }

    return decryptedText;
}

bool Otbash::deleteFile(string filePath)
{
    if (remove(filePath.c_str()) != 0) {
        cerr << "Error deleting file: " << filePath << "\n";
        return false;
    }
    else {
        return true;
    }
}

int Otbash::chekfile()
{
    switch (mode)
    {
    case 1:

        if (finputfile.is_open()) {

            return 0;
        }
        else
        {
            cerr << "error opened file\n";
            return 1;
        }
    case 2:

        if (finputfile.is_open()) {
            if (foutputfile.is_open()) {

                return 0;
            }
            else
            {
                cerr << "error opened file\n";
                return 2;
            }

        }
        else
        {
            cerr << "error opened file\n";
            return 1;
        }
    }

}

int Otbash::read_Datafile(int cryptomode)
{
    switch (mode)
    {
    case 1:
        if (cryptomode == 0) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            encryptOtbas(str);
            finputfile.close();
            deleteFile(inputfile);
            finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
            finputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decryptOtbas(str);
            finputfile.close();
            deleteFile(inputfile);
            finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
            finputfile << str;
            return 0;
        }
        break;
    case 2:
        if (cryptomode == 0) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            encryptOtbas(str);
            foutputfile << str;

        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decryptOtbas(str);
            finputfile << str;
        }
        break;
    }
}
