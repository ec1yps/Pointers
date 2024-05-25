#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

void Print(int arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

//void push_back(int* &arr, int &n, const int value);
int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int index, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);

//int** Allocate(const int rows, const int cols);
template<typename T> void Allocate(T**& arr, const int rows, const int cols);
template<typename T> void Clear(T** arr, const int rows);

template<typename T> T** push_row_back(T** arr, int &rows, const int cols);
template<typename T> T** push_row_front(T** arr, int &rows, const int cols);
template<typename T> T** insert_row(T** arr, int &rows, const int cols, const int index);

template<typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index);

template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void push_col_front(T** arr, const int rows, int& cols);
template<typename T> void insert_col(T** arr, const int rows, int& cols, const int index);

template<typename T> void pop_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_front(T** arr, const int rows, int& cols);
template<typename T> void erase_col(T** arr, const int rows, int& cols, const int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define I_ARR_2
//#define D_ARR_2
#define C_ARR_2

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
	
	int index;

#ifdef I_ARR_2
	int** i_arr_2;
	Allocate(i_arr_2, rows, cols);

	FillRand(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	//работа со строками

	i_arr_2 = push_row_back(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	i_arr_2 = push_row_front(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	cout << "Введите индекс добавляемой строки: "; cin >> index;
	i_arr_2 = insert_row(i_arr_2, rows, cols, index);
	Print(i_arr_2, rows, cols);

	i_arr_2 = pop_row_back(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	i_arr_2 = pop_row_front(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	i_arr_2 = erase_row(i_arr_2, rows, cols, index);
	Print(i_arr_2, rows, cols);

	//работа со столбцами

	push_col_back(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	push_col_front(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(i_arr_2, rows, cols, index);
	Print(i_arr_2, rows, cols);

	pop_col_back(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	pop_col_front(i_arr_2, rows, cols);
	Print(i_arr_2, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(i_arr_2, rows, cols, index);
	Print(i_arr_2, rows, cols);
	
	Clear(i_arr_2, rows);
#endif // I_ARR_2

#ifdef D_ARR_2
	double** d_arr_2;
	Allocate(d_arr_2, rows, cols);

	FillRand(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	//работа со строками

	d_arr_2 = push_row_back(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	d_arr_2 = push_row_front(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	cout << "Введите индекс добавляемой строки: "; cin >> index;
	d_arr_2 = insert_row(d_arr_2, rows, cols, index);
	Print(d_arr_2, rows, cols);

	d_arr_2 = pop_row_back(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	d_arr_2 = pop_row_front(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	d_arr_2 = erase_row(d_arr_2, rows, cols, index);
	Print(d_arr_2, rows, cols);

	//работа со столбцами

	push_col_back(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	push_col_front(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(d_arr_2, rows, cols, index);
	Print(d_arr_2, rows, cols);

	pop_col_back(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	pop_col_front(d_arr_2, rows, cols);
	Print(d_arr_2, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(d_arr_2, rows, cols, index);
	Print(d_arr_2, rows, cols);

	Clear(d_arr_2, rows);
#endif // D_ARR_2

#ifdef C_ARR_2
	char** c_arr_2;
	Allocate(c_arr_2, rows, cols);

	FillRand(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	//работа со строками

	c_arr_2 = push_row_back(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	c_arr_2 = push_row_front(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	cout << "Введите индекс добавляемой строки: "; cin >> index;
	c_arr_2 = insert_row(c_arr_2, rows, cols, index);
	Print(c_arr_2, rows, cols);

	c_arr_2 = pop_row_back(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	c_arr_2 = pop_row_front(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	c_arr_2 = erase_row(c_arr_2, rows, cols, index);
	Print(c_arr_2, rows, cols);

	//работа со столбцами

	push_col_back(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	push_col_front(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(c_arr_2, rows, cols, index);
	Print(c_arr_2, rows, cols);

	pop_col_back(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	pop_col_front(c_arr_2, rows, cols);
	Print(c_arr_2, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(c_arr_2, rows, cols, index);
	Print(c_arr_2, rows, cols);

	Clear(c_arr_2, rows);
#endif // C_ARR_2


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
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << tab;
	cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
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

template<typename T> void Allocate(T**& arr, const int rows, const int cols)
{
	arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
}
template<typename T> void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T*[++rows];

	for (int i = 0; i < rows; i++)
		i == rows - 1 ? buffer[i] = new T[cols]{} : buffer[i] = arr[i];

	delete[]arr;
	return buffer;
}
template<typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [++rows];

	for (int i = 0; i < rows; i++)
		i == 0 ? buffer[i] = new T[cols]{} : buffer[i] = arr[i - 1];

	delete[] arr;
	return buffer;
}
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [++rows];

	for (int i = 0; i < rows; i++)
		i == index ? buffer[i] = new T[cols]{} : buffer[i] = arr[i < index ? i : i - 1];

	delete[] arr;
	return buffer;
}

template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];

	delete[] arr[0];
	delete[] arr;
	return buffer;
}
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; i++)
			buffer[i] = arr[i < index ? i : i + 1];

	delete[] arr[index];
	delete[] arr;
	return buffer;
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index + 1; j < cols + 1; j++) buffer[j] = arr[i][j - 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template<typename T> void erase_col(T** arr, const int rows, int& cols, const int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j < index ? j : j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}