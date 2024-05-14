#include <iostream>
using namespace std;

#define tab "\t"

//#define HOMEWORK

//int e_size = 0, o_size = 0;	VERY BAD!!!!!!!!!!!!!!!

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
//void Split(int arr[], int arr_chet[], int arr_nech[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0) even_count++;
		//else odd_count++;
		arr[i] % 2 == 0 ? even_count++ : odd_count++;
	}
	cout << "Количество четных элементов: " << even_count << endl;
	cout << "Количество нечетных элементов: " << odd_count << endl;

	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0) even_arr[j++] = arr[i];
		//else odd_arr[k++] = arr[i];
		//arr[i] % 2 == 0 ? even_arr[j++] = arr[i] : odd_arr[k++] = arr[i];
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}

	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

#ifdef HOMEWORK
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
#endif // HOMEWORK
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
		cout << arr[i] << tab;
	}
	cout << endl;
}

/*void Split(int arr[], int arr_chet[], int arr_nech[], const int n)
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
}*/