#include"Caesar.h"

using namespace std;
Caeser::Caeser()
{
    int mode = 0;
    this->mode = mode;

}
Caeser::Caeser(string filename) {
    int mode = 1;
    this->mode = mode;

    this->inputfile = filename;
    finputfile.open(inputfile,fstream::in|fstream::out|fstream::app);
    
    chekfile();
}
Caeser::Caeser(string inputfile, string outputfile) {
    int mode = 2;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
    this->outputfile = outputfile;
    finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
    chekfile();
}
Caeser::Caeser(string inputfile, string outputfile, string keyfile) {
    int mode = 3;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
    this->outputfile = outputfile;
    finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
    this->keyfile = keyfile;
    fkeyfile.open(keyfile,fstream::in | fstream::out | fstream::app);
    chekfile();
}
Caeser::~Caeser()
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
bool Caeser::deleteFile(string filePath) {
    if (remove(filePath.c_str()) != 0) {
        cerr << "Error deleting file: " << filePath << "\n";
        return false;
    }
    else {
        return true;
    }
}

string Caeser::setword(string str) {
	this->str = str;
	return str;
}
int Caeser::read_Datafile(int cryptomode) {
    if (mode == 3) {
        if (cryptomode == 0) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), buffer.end());
            key = atoi(keystr.c_str());
            encript(str, key);
            foutputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), keybuffer.end());
            key = atoi(keystr.c_str());
            decript(str, key);
            foutputfile << str;
            return 0;
        }
    }
    else {


        cerr << "ошибка слишком мало аргументов в функции!\n";
        return 1;
    }

}
int Caeser::read_Datafile(int cryptomode, int key) {

    switch (mode)
    {
    case 1:
        if (cryptomode == 0) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            encript(str, key);
            finputfile.close();
            deleteFile(inputfile);
            finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
            finputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decript(str, key);
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
            encript(str, key);
            foutputfile << str;
            
        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decript(str, key);
            finputfile << str;
        }
        break;
    case 3:
        cerr << "ошибка слишком много аргументов в функции!\n";
        break;
    }

    return 0;
}








int Caeser::chekfile() {
    
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

int Caeser::chekkey(int key) {
    setlocale(LC_ALL, "RUS");
   
const char* type = typeid(key).name();
if (type == "i") {
    if (key != 0) {
        return 0;
    }
    else if (key == 0) {
        cerr << "переменная не может быть равна 0!\n";
        return 1;
    }
}
else if (type != "i") {

    cerr << "переменная должна быть целым числом!\n";
    return -1;
}

}
int Caeser::setkey(int key) {

	this->key = key;
  chekkey(key);
    return key;
}
string Caeser::encript(string str, int key) {
    int length = str.length();
    std::string encryptedStr = "";
    for (int i = 0; i < length; i++)
    {
        char c = str[i];

        if (isalpha(c))
        {
            int new_shift = key % 26;
            if (islower(c))
            {
                char base = 'a';
                c = (c - base + new_shift) % 26 + base;
            }
            else
            {
                char base = 'A';
                c = (c - base + new_shift) % 26 + base;
            }
        }

        encryptedStr += c;
    }

    return encryptedStr;
}



string Caeser::decript(string str, int key) {
    int n = str.length();
    std::string decryptedStr = "";

    for (int i = 0; i < n; i++) {
        char decryptedChar = str[i] - key;
        if (isalpha(str[i])) {
            if (islower(str[i]) && decryptedChar < 'a') {
                decryptedChar = decryptedChar + 26;
            }
            else if (isupper(str[i]) && decryptedChar < 'A') {
                decryptedChar = decryptedChar + 26; 
            }
        }

        decryptedStr += decryptedChar;
    }

    return decryptedStr;
    
}
