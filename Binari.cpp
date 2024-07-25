#include<iostream>
#include"Binari.h"
Binari::Binari()
{
    int mode = 0;
    this->mode = mode;

}
Binari::Binari(string inputfile)
{
    int mode = 1;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);

    chekfile();
}
Binari::Binari(string inputfile, string outputfile)
{
    int mode = 2;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
    this->outputfile = outputfile;
    finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
    chekfile();
}
Binari::Binari(string inputfile, string outputfile, string keyfile)
{
    int mode = 3;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
    this->outputfile = outputfile;
    finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
    this->keyfile = keyfile;
    fkeyfile.open(keyfile, fstream::in | fstream::out | fstream::app);
    chekfile();
}
Binari::~Binari()
{
    switch (mode) {
    case 1:
        finputfile.close();
    case 2:
        finputfile.close();
        foutputfile.close();
    case 3:
        finputfile.close();
        foutputfile.close();
        fkeyfile.close();


    }
}
string  Binari::encrypt(int key,string text) {
    string encryptedText = "";
    
    switch (key)
    {

    case 2:
        for (char& c : text) {
            encryptedText += bitset<2>(c).to_string();
        }
        break;
    case 4:
        for (char& c : text) {
            encryptedText += bitset<4>(c).to_string();
        }
        break;
    case 8:
        for (char& c : text) {
            encryptedText += bitset<8>(c).to_string();
        }
        break;
    case 16:
        for (char& c : text) {
            encryptedText += bitset<16>(c).to_string();
        }
        break;
    case 32:
        for (char& c : text) {
            encryptedText += bitset<32>(c).to_string();
        }
        break;
    case 64:
        for (char& c : text) {
            encryptedText += bitset<64>(c).to_string();
        }
        break;


    default:
        cerr << "error:not saported sistem!\n";
        break;
    }
    
    
  
   

    return encryptedText;
}

string  Binari::decrypt(int key,string text) {
    string decryptedText = "";
    switch (key)
    {

    case 2:

        for (size_t i = 0; i < text.length(); i += 2) {
            string byte = text.substr(i, 2);
            decryptedText += char(stoi(byte, nullptr, 2));
        }
        break;
    case 4:

        for (size_t i = 0; i < text.length(); i += 4) {
            string byte = text.substr(i, 4);
            decryptedText += char(stoi(byte, nullptr, 2));
        }
        break;
    case 8:

        for (size_t i = 0; i < text.length(); i += 8) {
            string byte = text.substr(i, 8);
            decryptedText += char(stoi(byte, nullptr, 2));
        }
        break;
    case 16:

        for (size_t i = 0; i < text.length(); i += 16) {
            string byte = text.substr(i, 16);
            decryptedText += char(stoi(byte, nullptr, 2));
        }
        break;
    case 32:

        for (size_t i = 0; i < text.length(); i += 32) {
            string byte = text.substr(i, 32);
            decryptedText += char(stoi(byte, nullptr, 2));
        }
        break;
    case 64:

        for (size_t i = 0; i < text.length(); i += 64) {
            string byte = text.substr(i, 64);
            decryptedText += char(stoi(byte, nullptr, 2));
        }
        break;


    default:
        cerr << "error:not saported sistem!\n";
        break;
    }



    return decryptedText;
}

int Binari::read_Datafile(int cryptomode, int key)
{
    switch (mode)
    {
    case 1:
        if (cryptomode == 0) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            encrypt(key, str);
            finputfile.close();
            deleteFile(inputfile);
            finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
            finputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decrypt(key, str);
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
            encrypt(key, str);
            foutputfile << str;

        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decrypt(key, str);
            finputfile << str;
        }
        break;
    case 3:
        cerr << "ошибка слишком много аргументов в функции!\n";
        break;
    }

    return 0;
}

int Binari::read_Datafile(int cryptomode)
{
    if (mode == 3) {
        if (cryptomode == 0) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), keybuffer.end());
            key = atoi(keystr.c_str());
            encrypt(key, str);
            foutputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), keybuffer.end());
            key = atoi(keystr.c_str());
            decrypt(key, str);
            foutputfile << str;
            return 0;
        }
    }
    else {


        cerr << "ошибка слишком мало аргументов в функции!\n";
        return 1;
    }

}

bool Binari::deleteFile(string filePath)
{
    if (remove(filePath.c_str()) != 0) {
        cerr << "Error deleting file: " << filePath << "\n";
        return false;
    }
    else {
        return true;
    }

}

int Binari::chekfile()
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
    case 3:
        if (finputfile.is_open()) {
            if (foutputfile.is_open()) {

                if (fkeyfile.is_open()) {

                    return 0;

                }
                else
                {
                    cerr << "error opened file\n";
                    return 3;
                }
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
