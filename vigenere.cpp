#include "Vigenere.h"

using namespace std;

VigenereCipher::VigenereCipher()
{
    int mode = 0;
    this->mode = mode;

}

VigenereCipher::VigenereCipher(string inputfile)
{
    int mode = 1;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);

    chekfile();
}

VigenereCipher::VigenereCipher(string inputfile, string outputfile)
{
    int mode = 2;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
    this->outputfile = outputfile;
    finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
    chekfile();
}

VigenereCipher::VigenereCipher(string inputfile, string outputfile, string keyfile)
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

void VigenereCipher::setkey(string key) {
    transform(key.begin(), key.end(), key.begin(), [](unsigned char c) {return toupper(c); });
    this->key = key;
}

string VigenereCipher::encrypt(const string& text) {
    string output;
    //шифрование текста
    string effectiveKey = getKey(text, key);
    for (size_t i = 0; i < text.size(); i++) {
        output += cipherChar(text[i], effectiveKey[i], true);
    }
    return output;
}

string VigenereCipher::decrypt(const string& text) {
    string output;
    //Дешифрование текста
    string effectiveKey = getKey(text, key);
    for (size_t i = 0; i < text.size(); i++) {
        output += cipherChar(text[i], effectiveKey[i], false);
    }
    return output;
}

VigenereCipher::~VigenereCipher()
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

int VigenereCipher::read_Datafile(int cryptomode, string key)
{
    switch (mode)
    {
    case 1:
        if (cryptomode == 0) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            setkey(key);
            encrypt(str);
            finputfile.close();
            deleteFile(inputfile);
            finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
            finputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            setkey(key);
            decrypt(str);
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
            setkey(key);
            encrypt(str);
            foutputfile << str;

        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            setkey(key);
            decrypt(str);
            finputfile << str;
        }
        break;
    case 3:
        cerr << "ошибка слишком много аргументов в функции!\n";
        break;
    }
}

int VigenereCipher::read_Datafile(int cryptomode)
{
    if (mode == 3) {
        if (cryptomode == 0) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), buffer.end());
            setkey(keystr);
            encrypt(str);
            foutputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), keybuffer.end());
            setkey(keystr);
            decrypt(str);
            foutputfile << str;
            return 0;
        }
    }
    else {


        cerr << "ошибка слишком мало аргументов в функции!\n";
        return 1;
    }

}

string VigenereCipher::getKey(const string& text, const string& key) {
    //Получать ключ
    string resultKey = key;
    while (resultKey.size() < text.size()) {
        resultKey += key;
    }
    //Обрезаем ключ
    resultKey = resultKey.substr(0, text.size());
    return resultKey;
}

char VigenereCipher::cipherChar(char c, char key, bool encode) {
    //Шифрование/Дешифрование символа

    if (!isalpha(c)) return c;

    char base = islower(c) ? 'a' : 'A';
    char keyBase = islower(key) ? 'a' : 'A';
    int offset = key - keyBase;

    if (encode) {
        //Шифрование символа
        return base + (c - base + offset) % 26;
    }
    else {
        //Дешифврование символа
        return base + (26 + c - base + offset) % 26;
        // тут нужно добавить проверку на диапазон
    }
}

bool VigenereCipher::deleteFile(string filePath)
{
    if (remove(filePath.c_str()) != 0) {
        cerr << "Error deleting file: " << filePath << "\n";
        return false;
    }
    else {
        return true;
    }
}

int VigenereCipher::chekfile()
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
