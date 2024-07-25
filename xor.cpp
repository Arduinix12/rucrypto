#include"xor.h"

string XOR::encrypt(string text, string key) {
	string encrypted_text;


		for (size_t i = 0; i < text.size(); ++i) {
			encrypted_text += text[i] ^ key[i % key.size()];
		}

	return encrypted_text;
}

int XOR::read_Datafile(int cryptomode, string key)
{
	switch (mode)
	{
	case 1:
		if (cryptomode == 0) {
			std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			encrypt(str,key);
			finputfile.close();
			deleteFile(inputfile);
			finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
			finputfile << str;
			return 0;
		}
		else if (cryptomode == 1) {
			std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			decrypt(str,key);
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
			encrypt(str,key);
			foutputfile << str;

		}
		else if (cryptomode == 1) {
			std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			decrypt(str,key);
			finputfile << str;
		}
		break;
	case 3:
		cerr << "ошибка слишком много аргументов в функции!\n";
		break;
	}
}

int XOR::read_Datafile(int cryptomode)
{
	if (mode == 3) {
		if (cryptomode == 0) {
			vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
			string keystr(keybuffer.begin(), keybuffer.end());
			encrypt(str,keystr);
			foutputfile << str;
			return 0;
		}
		else if (cryptomode == 1) {
			vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
			string keystr(keybuffer.begin(), keybuffer.end());
			decrypt(str,keystr);
			foutputfile << str;
			return 0;
		}
	}
	else {


		cerr << "ошибка слишком мало аргументов в функции!\n";
		return 1;
	}
}

bool XOR::deleteFile(string filePath)
{

	if (remove(filePath.c_str()) != 0) {
		cerr << "Error deleting file: " << filePath << "\n";
		return false;
	}
	else {
		return true;
	}
}

int XOR::chekfile()
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




XOR::XOR()
{
	int mode = 0;
	this->mode = mode;

}

XOR::XOR(string inputfile)
{
	int mode = 1;
	this->mode = mode;

	this->inputfile = inputfile;
	finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);

	chekfile();
}

XOR::XOR(string inputfile, string outputfile)
{
	int mode = 2;
	this->mode = mode;

	this->inputfile = inputfile;
	finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
	this->outputfile = outputfile;
	finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
	chekfile();
}

XOR::XOR(string inputfile, string outputfile, string keyfile)
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

XOR::~XOR()
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

string XOR::decrypt(string text,string key){
	string decrypted_text;

	
		
		for (size_t i = 0; i < text.size(); ++i) {
			decrypted_text += text[i] ^ key[i % key.size()];
		}

	return decrypted_text;
}