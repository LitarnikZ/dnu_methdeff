#include <iostream>
#include <math.h>
#include <time.h>


int nod(int K, int E)
{
	while (K > 0)
	{
		long int myTemp;

		myTemp = K;
		K = E % K;
		E = myTemp;
	}

	return E;
}

long int calculate_open_key(int fi)
{
	int K;

	for (K = 2; K < fi; ++K)
	{
		if (nod(K, fi) == 1)
		{
			return K;
		}
	}

	return -1;
}

int calculate_locked_key(int K, int E)
{
	int d;
	int k = 1;

	while (1)
	{
		k = k + E;

		if (k % K == 0)
		{
			d = (k / K);
			return d;
		}
	}
}


int main()
{
	srand(time(0));
	int p, q;	
	int N;
	int fi; // eiler function
	int open_key, locked_key;

	bool check = true;
	do
	{
		printf_s("Write Q ->");
		scanf_s("%d", &q);

		if (q > 0)
			check = false;

	} while (check == true);

	check = true;
	do
	{
		printf_s("Write P ->");
		scanf_s("%d", &p);

		if (p > 0)
			check = false;

	} while (check);

	N = p * q; // module

	fi = (p - 1) * (q - 1); // function by Eiler

			/* FORMING OPEN KEY */
	open_key = calculate_open_key(fi);
	printf_s("Open key: {%d; %d}\n", open_key, N);
	/*-----------------------------------------------*/

	int message;
	printf_s("Write message for encrypt: ");
	scanf_s("%d", &message);

			/* ENCRYPT PROCCESS */
	int encrypt = 1;

	for (int i = 0; i < open_key; ++i)
	{
		encrypt = encrypt * message;
		encrypt = encrypt % N;
	}

	printf_s("Encrypt code: %d\n", encrypt);
	/*----------------------------------------------*/

			/* FORMING LOCK KEY */	
	locked_key = calculate_locked_key(open_key, fi);
	printf_s("Locked key: {%d; %d}\n", locked_key, N);
	/*----------------------------------------------*/

			/* DECRYPT PROCCESS */
	int decrypt = 1;

	for (int i = 0; i < locked_key; ++i)
	{
		decrypt = decrypt * encrypt;
		decrypt = decrypt % N;
	}
	/*----------------------------------------------*/

	printf_s("Decrypt code: %d\n", decrypt);

	return 0;
}