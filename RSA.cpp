#include "RSA.h"
long RSA::e;
long RSA::n;
long RSA::d;
string RSA::encrypt(string msg)
{
	for (long int i = 0; i < msg.length(); i++)
	{
		encryptedText[i] = encryptions(msg[i], e, n);
	}

	cout << "\nTHE ENCRYPTED MESSAGE IS:" << "\n";

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

	cout << "\n\nTHE DECRYPTED MESSAGE IS:" << "\n";

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
		cout << "Enter a Prime number  p :" << "\n";
		cin >> p;
		flag = isPrime(p);

		if (!flag)
		{
			cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n\n";
		}
	} while (!flag);


	do
	{
		cout << "Enter a Prime number  q :" << "\n";
		cin >> q;

		flag = isPrime(q);

		if (!flag)
		{
			cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n\n";
		}
	} while (!flag);

	// 2. Вычисляется их произведение n = p ? q, которое называется модулем.
	n = p * q;
	cout << "\nResult of computing n = p*q = " << n << "\n";

	// 3. Вычисляется значение функции Эйлера от числа n: ?(n) = (p?1)?(q?1)
	t = (p - 1) * (q - 1);
	cout << "Result of computing Euler's totient function:\t t = " << t << "\n";

	// 4. Выбирается целое число e ( 1 < e < ?(n) ), взаимно простое со значением функции Эйлера (t)
	//    Число e называется открытой экспонентой
	e = calculateE(t);

	// 5. Вычисляется число d, мультипликативно обратное к числу e по модулю ?(n), то есть число, удовлетворяющее сравнению:
	//    d ? e ? 1 (mod ?(n))
	d = calculateD(e, t);

	// 6. Пара {e, n} публикуется в качестве открытого ключа RSA
	cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" <<"\n";

	// 7. Пара {d, n} играет роль закрытого ключа RSA и держится в секрете
	cout << "RSA private key is (n = " << n << ", d = " << d << ")" << "\n";



	cout << "\nEnter Message to be encryped:" << "\n";

	cin.ignore();

	getline(cin, msg);

	cout << "\nThe message is: " << msg << "\n";

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
