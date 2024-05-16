#include <iostream>
using namespace std;

#define tab "\t"

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);
void Add(int* &arr, int &n, const int value);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите элемент массива: "; cin >> n;
	int* arr = new int[n];

	Fillrand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	Add(arr, n, value);

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
	cout << endl;
}

void Add(int *&arr, int &n, const int value)
{
	int* new_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[n++] = value;
	delete[] arr;
	arr = new_arr;
}