#include <iostream>
using namespace std;

int Sum(int number...)
{
	int sum = 0;
	//Вычисление суммы:
	int* pnumber = &number;
	while (*pnumber)
	{
		sum += (*pnumber);
		//cout << pnumber << "\t" << *pnumber << endl;
		pnumber++;
	}
	return sum;
}

void main()
{
	setlocale(LC_ALL, "");
	cout << Sum(3, 5, 8, 13, 21, 34, 55, 0) << endl;
}