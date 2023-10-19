#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>

using namespace std;

void acosTaylor(double mini, double maxi, double step, double absError, double numberMax)
{
	cout << "------------------------------------------------------------\n";
	cout << "|    x    |   arccos(x)   |   Количество элементов ряда:   |\n";

	for (double i = mini; i <= maxi; i += step)
	{
		int count = 1, m = 0, k = 1;
		double acosx1 = M_PI / 2, acosx2 = 0, d = i;
		long long int f = 1;

		while (abs(acosx1 - acosx2) > absError)
		{
			acosx2 = acosx1;
			acosx1 = acosx1 - (d / f);
			d = d * i * i * k;
			k = k * (k + 2);
			f = f * (static_cast<long long>(m) + 2) * (static_cast<long long>(m) + 3) / (static_cast<long long>(m) + 1);
			m = m + 2;
			count++;
		}

		if (numberMax < count)
		{
			cout << "------------------------------------------------------------\n";
			cout << "|" << setw(6) << i << setw(4) << "|" << "     Error     |                                |\n";
			cout << "------------------------------------------------------------";
			throw 1;
		}

		else
		{
			if (abs(i) < (1e-12))
			{
				i = 0;
				cout << "------------------------------------------------------------\n";
				cout << "|" << setw(6) << i << setw(4) << "|" << setw(11) << acosx1 << setw(5) << "|" << setw(16) << count - 1 << setw(18) << "|\n";
			}
			else
			{
				cout << "------------------------------------------------------------\n";
				cout << "|" << setw(6) << i << setw(4) << "|" << setw(11) << acosx1 << setw(5) << "|" << setw(16) << count - 1 << setw(18) << "|\n";
			}

		}
		count = 1;

	}

	cout << "------------------------------------------------------------";
}

int main()
{
	setlocale(LC_ALL, "RU");
	double mx = 0, mn = 0, absError = 0, step = 0;
	int numberMax = 0;

	cout << "Введите границы для x\n";
	cout << "|x| <= 1\n";

	try
	{
		cout << "Минимально возможное значение x: \n";
		cin >> mn;
		if ((cin.fail()) || ((mn > 1) || (mn < -1)) || ((mx < -1) || (mx > 1)))
		{
			throw 1;
		}
		cout << "Максимально возможное значение x: \n";
		cin >> mx;
		if ((cin.fail()) || ((mn > 1) || (mn < -1)) || ((mx < -1) || (mx > 1)))
		{
			throw 1;
		}
		cout << "Введите шаг интервала: \n";
		cin >> step;
		if ((cin.fail()) || ((mn > 1) || (mn <-1)) || ((mx < -1) || (mx > 1)))
		{
			throw 1;
		}
		cout << "Введите значение абсолютной погрешности: \n";
		cin >> absError;
		if ((cin.fail()) || ((mn > 1) || (mn < -1)) || ((mx < -1) || (mx >1)))
		{
			throw 1;
		}
		cout << "Введите максимальное количество слагаемых в последовательности: \n";
		cin >> numberMax;
		if ((cin.fail()) || ((mn > 1) || (mn < -1)) || ((mx < -1) || (mx > 1)))
		{
			throw 1;
		}

	}
	catch (int thr)
	{
		cerr << "Error " << thr << "! Вы ввели ошибочные данные, попробуйте еще раз!\n";
		return 1;
	}

	try
	{
		acosTaylor(mn, mx, step, absError, numberMax);
	}
	catch (...)
	{
		cerr << "";
	}


	return 0;
}
	{
		cerr << "";
	}


	return 0;
}
