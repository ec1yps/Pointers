#include <iostream>
using namespace std;

#define tab "\t"

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);
//void push_back(int* &arr, int &n, const int value);
int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int index, const int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите элемент массива: "; cin >> n;
	int* arr = new int[n];

	Fillrand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите значение, добавляемое в конец : "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите значение, добавляемое в начало: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите значение: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);	
	
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}

void Fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		*(arr + i) = rand() % 100;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << tab;
	cout << endl;
}

/*void push_back(int*& arr, int& n, const int value)
{
	int* new_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[n++] = value;
	delete[] arr;
	arr = new_arr;
}*/

int* push_back(int arr[], int& n, const int value)
{
	int* new_arr = new int[n + 1];
	for (int i = 0; i < n; i++) 
		new_arr[i] = arr[i];
	new_arr[n++] = value;
	delete[] arr;
	return new_arr;
}

int* push_front(int arr[], int& n, const int value)
{
	int* new_arr = new int[n + 1];
	for (int i = 0; i < n; i++) 
		new_arr[i + 1] = arr[i];
	new_arr[0] = value;
	n++;
	delete[] arr;
	return new_arr;
}

int* insert(int arr[], int& n, const int index, const int value)
{
	int* new_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		//i < index ? new_arr[i] = arr[i] : new_arr[i + 1] = arr[i];
		new_arr[i < index ? i : i + 1] = arr[i];
	}
	new_arr[index] = value;
	n++;
	delete[] arr;
	return new_arr;
}

int* pop_back(int arr[], int& n)
{
	int* new_arr = new int[--n];
	for (int i = 0; i < n; i++) 
		new_arr[i] = arr[i];
	delete[] arr;
	return new_arr;
}

int* pop_front(int arr[], int& n)
{
	int* new_arr = new int[--n];
	for (int i = 0; i < n; i++) 
		new_arr[i] = arr[i + 1];
	delete[] arr;
	return new_arr;
}

int* erase(int arr[], int& n, const int index)
{
	int* new_arr = new int[--n];
	for (int i = 0; i < n; i++)
	{
		//i < index ? new_arr[i] = arr[i] : new_arr[i] = arr[i + 1];
		new_arr[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return new_arr;
}