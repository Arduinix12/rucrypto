#include"3DES.h"

string threDES::encrypt(string k1, string k2, string k3, string word) {
	string encode_str = "";
	encode_str = des.encode(word, k1);
	word = encode_str;
	encode_str = des.decode(word, k2);
	word = encode_str;
	encode_str = des.encode(word, k3);
	return encode_str;
}
string threDES::decrypt(string k1, string k2, string k3, string word) {
	string decode_str = "";
	decode_str = des.decode(word, k3);
	word = decode_str;
	decode_str = des.encode(word, k2);
	word = decode_str;
	decode_str = des.decode(word, k1);
	return decode_str;

}

bool threDES::deleteFile(string filePath)
{
	if (remove(filePath.c_str()) != 0) {
		cerr << "Error deleting file: " << filePath << "\n";
		return false;
	}
	else {
		return true;
	}
}

int threDES::chekfile()
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

int threDES::get_fkey(vector<char> buffer)
{
    
    vector<char> key1(buffer.begin(), buffer.begin() + 64); // первые 8 символов
    string skey1(key1.begin(), key1.end());
    this->k1 = skey1;
    // Получаем второй ключ
    vector<char> key2(buffer.begin() + 64, buffer.begin() + 128); // следующие 8 символов
    string skey2(key2.begin(), key2.end());
    this->k2 = skey2;
    // Получаем третий ключ
    vector<char> key3(buffer.begin() + 128, buffer.begin() + 192); // следующие 8 символов
    string skey3(key3.begin(), key3.end());
    this->k3 = skey3;
    return 0;
}

threDES::threDES()
{
    int mode = 0;
    this->mode = mode;

}

threDES::threDES(string inputfile)
{
    int mode = 1;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);

    chekfile();
}

threDES::threDES(string inputfile, string outputfile)
{
    int mode = 2;
    this->mode = mode;

    this->inputfile = inputfile;
    finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
    this->outputfile = outputfile;
    finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
    chekfile();
}

threDES::threDES(string inputfile, string outputfile, string keyfile)
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

threDES::~threDES()
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

int threDES::read_Datafile(int cryptomode, string k1, string k2, string k3)
{
    switch (mode)
    {
    case 1:
        if (cryptomode == 0) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            encrypt(k1, k2, k3, str);
            finputfile.close();
            deleteFile(inputfile);
            finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
            finputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decrypt(k1, k2, k3, str);
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
            encrypt(k1, k2, k3, str);
            foutputfile << str;

        }
        else if (cryptomode == 1) {
            std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            decrypt(k1, k2, k3, str);
            finputfile << str;
        }
        break;
    case 3:
        cerr << "ошибка слишком много аргументов в функции!\n";
        break;
    }
}

int threDES::read_Datafile(int cryptomode)
{
    if (mode == 3) {
        if (cryptomode == 0) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), keybuffer.end());
            get_fkey(keybuffer);
           string key1 = k1;
           string key2 = k2;
           string key3 = k3;
           encrypt(key1, key2, key3, str);
            foutputfile << str;
            return 0;
        }
        else if (cryptomode == 1) {
            vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
            string str(buffer.begin(), buffer.end());
            vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
            string keystr(keybuffer.begin(), keybuffer.end());
            get_fkey(keybuffer);
            string key1 = k1;
            string key2 = k2;
            string key3 = k3;
            decrypt(key1, key2, key3, str);
            foutputfile << str;
            return 0;
        }
    }
    else {


        cerr << "ошибка слишком мало аргументов в функции!\n";
        return 1;
    }
}
