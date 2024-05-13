#include <iostream>
using namespace std;

#define tab "\t"

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите элемент массива: "; cin >> n;
	int* arr = new int[n];

	Fillrand(arr, n);
	Print(arr, n);

	delete[] arr;
}

void Fillrand(int arr[], const int n)
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
		cout << arr[i] << tab;
	}
}