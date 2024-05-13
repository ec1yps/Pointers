#include <iostream>
using namespace std;

#define tab "\t"

int e_size = 0, o_size = 0;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Split(int arr[], int arr_chet[], int arr_nech[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int* arr = new int[n];
	int* even = new int[n];
	int* odd = new int[n];
	FillRand(arr, n);
	cout << "Исходный массив: ";
	Print(arr, n);
	Split(arr, even, odd, n);
	cout << "Массив с четными элементами: ";
	Print(even, e_size);
	cout << "Массив с нечетными элементами: ";
	Print(odd, o_size);
	delete[] arr;
	delete[] even;
	delete[] odd;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tab << arr[i];
	}
	cout << endl;
}

void Split(int arr[], int arr_chet[], int arr_nech[], const int n)
{
	int chet = 0, nech = 0;
	for (int i = 0; i < n; i++)
	{
		int buffer = arr[i];
		while (buffer)
		{
			buffer %= 2;
			if (buffer == 1) break;
		}
		if (buffer == 1)
		{
			arr_nech[nech] = arr[i];
			++nech;
		}
		else
		{
			arr_chet[chet] = arr[i];
			++chet;
		}
	}
	e_size = chet;
	o_size = nech;
}