#include "RSA.h"
long RSA::e;
long RSA::n;
long RSA::d;
RSA::RSA()
{
	int mode = 0;
	this->mode = mode;

}
RSA::RSA(string inputfile)
{
	int mode = 1;
	this->mode = mode;

	this->inputfile = inputfile;
	finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);

	chekfile();
}
RSA::RSA(string inputfile, string outputfile)
{
	int mode = 2;
	this->mode = mode;

	this->inputfile = inputfile;
	finputfile.open(inputfile, fstream::in | fstream::out | fstream::app);
	this->outputfile = outputfile;
	finputfile.open(outputfile, fstream::in | fstream::out | fstream::app);
	chekfile();
}
RSA::RSA(string inputfile, string outputfile, string keyfile)
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
RSA::~RSA()
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
int RSA::read_Datafile(int cryptomode, int p, int q)
{
	switch (mode)
	{
	case 1:
		if (cryptomode == 0) {
			std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			genereytkey(p, q);
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
			genereytkey(p, q);
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
			genereytkey(p, q);
			encrypt(str);
			foutputfile << str;

		}
		else if (cryptomode == 1) {
			std::vector<char> buffer(std::istreambuf_iterator<char>(finputfile), (std::istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			genereytkey(p, q);
			decrypt(str);
			finputfile << str;
		}
		break;
	case 3:
		cerr << "ошибка слишком много аргументов в функции!\n";
		break;
	}
}
int RSA::read_Datafile(int cryptomode)
{
	
	if (mode == 3) {
		if (cryptomode == 0) {
			vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
			string keystr(keybuffer.begin(), keybuffer.end());
			get_fkey(keybuffer,p,q);
			genereytkey(p, q);
			encrypt(str);
			foutputfile << str;
			return 0;
		}
		else if (cryptomode == 1) {
			vector<char> buffer(istreambuf_iterator<char>(finputfile), (istreambuf_iterator<char>()));
			string str(buffer.begin(), buffer.end());
			vector<char> keybuffer(istreambuf_iterator<char>(fkeyfile), (istreambuf_iterator<char>()));
			string keystr(keybuffer.begin(), keybuffer.end());
			get_fkey(keybuffer, p, q);
			genereytkey(p, q);
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
string RSA::encrypt(string msg)
{
	for (long int i = 0; i < msg.length(); i++)
	{
		encryptedText[i] = encryptions(msg[i], e, n);
	}

	cout << "\nвведите сообщение которое надо зашифровать:" << "\n";

	for (long int i = 0; i < msg.length(); i++)
	{
		msg=printf("%c", static_cast<char>(encryptedText[i]));
	}
	return msg;
}

string RSA::decrypt(string msg)
{
	for (long int i = 0; i < msg.length(); i++)
	{
		decryptedText[i] = decryptions(encryptedText[i], d, n);
	}

	cout << "\n\nдешифрованое сообщение:" << "\n";

	for (long int i = 0; i < msg.length(); i++)
	{
		msg=printf("%c", static_cast<char>(decryptedText[i]));
	}

	cout << "\n\n";

	return msg;
}

int RSA::genereytkey(int p, int q)
{
	do
	{
		cout << "Введите простое число p :" << "\n";
		cin >> p;
		flag = isPrime(p);

		if (!flag)
		{
			cout << "\nНЕВЕРНО ВВЕДЕНО (это число не является простым. Простое число - это натуральное число, большее 1, у которого нет положительных делителей, кроме 1 и самого себя)\n\n";
		}
	} while (!flag);


	do
	{
		cout << "Введите простое число q :" << "\n";
		cin >> q;

		flag = isPrime(q);

		if (!flag)
		{
			cout << "\nНЕВЕРНО ВВЕДЕНО (это число не является простым. Простое число - это натуральное число, большее 1, у которого нет положительных делителей, кроме 1 и самого себя)\n\n";
		}
	} while (!flag);

	// 2. Вычисляется их произведение n = p ? q, которое называется модулем.
	n = p * q;
	

	// 3. Вычисляется значение функции Эйлера от числа n: ?(n) = (p?1)?(q?1)
	t = (p - 1) * (q - 1);
	

	// 4. Выбирается целое число e ( 1 < e < ?(n) ), взаимно простое со значением функции Эйлера (t)
	//    Число e называется открытой экспонентой
	e = calculateE(t);

	// 5. Вычисляется число d, мультипликативно обратное к числу e по модулю ?(n), то есть число, удовлетворяющее сравнению:
	//    d ? e ? 1 (mod ?(n))
	d = calculateD(e, t);

	// 6. Пара {e, n} публикуется в качестве открытого ключа RSA
	cout << "\n публичные ключи    (n = " << n << ", e = " << e << ")" <<"\n";

	// 7. Пара {d, n} играет роль закрытого ключа RSA и держится в секрете
	cout << "приватные ключи (n = " << n << ", d = " << d << ")" << "\n";



	cout << "\nВведите сообщение, которое будет зашифровано:" << "\n";

	cin.ignore();

	getline(cin, msg);

	cout << "\nваше собщение: " << msg << "\n";

	return 0;
}

bool RSA::isPrime(long int prime)
{
	if (prime <= 1) {
		return false;
	}
	for (long int i = 2; i * i <= prime; i++) {
		if (prime % i == 0) {
			return false;
		}
	}
	return true;
}
long int RSA::greatestCommonDivisor(long int e, long int t)
{
	while (e > 0)
	{
		long int myTemp;

		myTemp = e;
		e = t % e;
		t = myTemp;
	}

	return t;
}
long int RSA::calculateE(long int t)
{
	long int e;

	for (e = 2; e < t; e++)
	{
		if (greatestCommonDivisor(e, t) == 1)
		{
			return e;
		}
	}

	return -1;
}



long int RSA::calculateD(long int e, long int t)
{
	long int d;
	long int k = 1;

	while (1)
	{
		k = k + t;

		if (k % e == 0)
		{
			d = (k / e);
			return d;
		}
	}
	return 0;
}

long int RSA::encryptions(long int i, long int e, long int n)
{
	long int current, result;

	current = i - 97;
	result = 1;

	for (long int j = 0; j < e; j++)
	{
		result = result * current;
		result = result % n;
	}

	return result;
	
}

long int RSA::decryptions(long int i, long int d, long int n)
{
	long int current, result;

	current = i;
	result = 1;

	for (long int j = 0; j < d; j++)
	{
		result = result * current;
		result = result % n;
	}

	return result + 97;
}

bool RSA::deleteFile(string filePath)
{
	if (remove(filePath.c_str()) != 0) {
		cerr << "Error deleting file: " << filePath << "\n";
		return false;
	}
	else {
		return true;
	}
}

int RSA::chekfile()
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

int RSA::get_fkey(vector<char> buffer,int p,int q)
{
	int half_size = buffer.size() / 2;

	vector<int> first_half(buffer.begin(), buffer.begin() + half_size);
	vector<int> second_half(buffer.begin() + half_size, buffer.end());
	string pkps(first_half.begin(), first_half.end());
	p = stoi(pkps);
	string qkqs(first_half.begin(), first_half.end());
	q = stoi(pkps);
	return 0;
}

