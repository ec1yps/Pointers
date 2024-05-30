#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols);

template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

//void push_back(int* &arr, int &n, const int value);
template<typename T> T* push_back(T arr[], int& n, const T value);
template<typename T> T* push_front(T arr[], int& n, const T value);
template<typename T> T* insert(T arr[], int& n, const int index, const T value);

template<typename T> T* pop_back(T arr[], int& n);
template<typename T> T* pop_front(T arr[], int& n);
template<typename T> T* erase(T arr[], int& n, const int index);

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
//#define I_ARR
//#define D_ARR
//#define C_ARR

#define DYNAMIC_MEMORY_2
#define I_ARR_2
//#define D_ARR_2
//#define C_ARR_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите элемент массива: "; cin >> n;
	
#ifdef I_ARR
	int* i_arr = new int[n];
	FillRand(i_arr, n);
	Print(i_arr, n);

	int value;
	cout << "Введите значение, добавляемое в конец : "; cin >> value;
	i_arr = push_back(i_arr, n, value);
	Print(i_arr, n);

	cout << "Введите значение, добавляемое в начало: "; cin >> value;
	i_arr = push_front(i_arr, n, value);
	Print(i_arr, n);

	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите значение: "; cin >> value;
	i_arr = insert(i_arr, n, index, value);
	Print(i_arr, n);

	i_arr = pop_back(i_arr, n);
	Print(i_arr, n);

	i_arr = pop_front(i_arr, n);
	Print(i_arr, n);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	i_arr = erase(i_arr, n, index);
	Print(i_arr, n);

	delete[] i_arr;
#endif // I_ARR

#ifdef D_ARR
	double* d_arr = new double[n];
	FillRand(d_arr, n);
	Print(d_arr, n);

	double value;
	cout << "Введите значение, добавляемое в конец : "; cin >> value;
	d_arr = push_back(d_arr, n, value);
	Print(d_arr, n);

	cout << "Введите значение, добавляемое в начало: "; cin >> value;
	d_arr = push_front(d_arr, n, value);
	Print(d_arr, n);

	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите значение: "; cin >> value;
	d_arr = insert(d_arr, n, index, value);
	Print(d_arr, n);

	d_arr = pop_back(d_arr, n);
	Print(d_arr, n);

	d_arr = pop_front(d_arr, n);
	Print(d_arr, n);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	d_arr = erase(d_arr, n, index);
	Print(d_arr, n);

	delete[] d_arr;
#endif // D_ARR

#ifdef C_ARR
	char* arr = new char[n];
	FillRand(arr, n);
	Print(arr, n);

	char value;
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
#endif // C_ARR

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
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
		*(arr + i) = rand();
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = (rand() % (maxRand - minRand) + minRand);
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

template<typename T> void Print(T arr[], const int n)
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
template<typename T> T* push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) 
		buffer[i] = arr[i];
	buffer[n++] = value;
	delete[] arr;
	return buffer;
}
template<typename T> T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) 
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T> T* insert(T arr[], int& n, const int index, const T value)
{
	if (index >= n) return arr;
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		//i < index ? new_arr[i] = arr[i] : new_arr[i + 1] = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	buffer[index] = value;
	n++;
	delete[] arr;
	return buffer;
}

template<typename T> T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T> T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) 
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T> T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		//i < index ? new_arr[i] = arr[i] : new_arr[i] = arr[i + 1];
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buffer;
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
	return push_back(arr, rows, new T[cols]{});
}
template<typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	return push_front(arr, rows, new T[cols]{});
}
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	return insert(arr, rows, index, new T[cols]{});
}

template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	return pop_back(arr, rows);
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	delete[] arr[0];
	return pop_front(arr, rows);
}
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	delete[] arr[index];
	return erase(arr, rows, index);
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T> void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols, index, T());
		cols--;
	}
	cols++;
}

template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_front(arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T> void erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = erase(arr[i], cols, index);
		cols++;
	}
	cols--;
}