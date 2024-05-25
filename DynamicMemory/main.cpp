#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

//void push_back(int* &arr, int &n, const int value);
int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int index, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);

int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows);

int** push_row_back(int** arr, int &rows, const int cols);
int** push_row_front(int** arr, int &rows, const int cols);
int** insert_row(int** arr, int &rows, const int cols, const int index);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, const int index);

void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, const int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define WORKING_WITH_ROWS
#define WORKING_WITH_COLS

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
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
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	int index;
#ifdef WORKING_WITH_ROWS
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
#endif // WORKING_WITH_ROWS

#ifdef WORKING_WITH_COLS
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);	
	
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
#endif // WORKING_WITH_COLS


	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		*(arr + i) = rand() % 100;
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << tab;
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//cout << arr[i][j] << tab;
			cout << *(*(arr + i) + j) << tab;
		}
		cout << endl;
	}
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

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int**& arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[++rows];

	for (int i = 0; i < rows; i++)
		i == rows - 1 ? buffer[i] = new int[cols] {} : buffer[i] = arr[i];

	delete[]arr;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [++rows];

	for (int i = 0; i < rows; i++)
		i == 0 ? buffer[i] = new int[cols] {} : buffer[i] = arr[i - 1];

	delete[] arr;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [++rows];

	for (int i = 0; i < rows; i++)
		i == index ? buffer[i] = new int[cols] {} : buffer[i] = arr[i < index ? i : i - 1];

	delete[] arr;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];

	delete[] arr[0];
	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++)
			buffer[i] = arr[i < index ? i : i + 1];

	delete[] arr[index];
	delete[] arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index + 1; j < cols; j++) buffer[j] = arr[i][j - 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
void erase_col(int** arr, const int rows, int& cols, const int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j < index ? j : j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}