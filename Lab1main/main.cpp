#include <iostream>

using namespace std;

#define STATIC_LIB 1
#define IMPLICIT_DYNAMIC_LIB 2
#define EXPLICIT_DYNAMIC_LIB 3

#define LIB_TYPE STATIC_LIB //    (STATIC_LIB, IMPLICIT_DYNAMIC_LIB  EXPLICIT_DYNAMIC_LIB)

void print_sorted_array(int* array, int size); //вывод массива в консоль
void fill_and_print_array(int* array, int size); //заполнение массива случайными целыми числами от -50 до 50 и вывод массива в консоль
#if (LIB_TYPE==STATIC_LIB) // Статическая библиотека

#include "StaticFunctions.h"
int main() {
	int n;
	srand(time(nullptr));
	cout << "Programm using Static Library" << endl << "Enter a size of an array:" << endl;
	cin >> n;
	int *array = new int[n];
	fill_and_print_array(array, n);
	sorting_algorithms::insertion_sort(array, n);
	print_sorted_array(array, n);
	delete[] array;
}



#elif (LIB_TYPE==IMPLICIT_DYNAMIC_LIB) //Динамическая библиотека (неявное связывание)

#include <DynamicFunctions.h>

int main() {
	int n;
	srand(time(nullptr));
	cout << "Programm using Implicit Dynamic Library" << endl << "Enter a size of an array:" << endl;
	cin >> n;
	int *array = new int[n];
	fill_and_print_array(array, n);
	sorting_algorithms::insertion_sort(array, n);
	print_sorted_array(array, n);
	delete[] array;
}

#elif (LIB_TYPE==EXPLICIT_DYNAMIC_LIB) //Динамическая библиотека (явное связывание)

#include <Windows.h>

int main() {
	int n;
	srand(time(nullptr));
	cout << "Programm using Implicit Dynamic Library" << endl << "Enter a size of an array:" << endl;
	cin >> n;
	int *array = new int[n];
	fill_and_print_array(array, n);
	typedef void (*FuncType) (int*, int); //указатель на функцию сортировки
	FuncType sort;
	HINSTANCE hdll = LoadLibrary(L"DynamicLib.dll"); //библиотека
	if (hdll == nullptr) cout << "Error occured while loading the library" << endl;
	else {
		FARPROC func_ptr = GetProcAddress(hdll, "insertion_sort"); //функция из библиотеки
		if (func_ptr == nullptr) cout << "Error occured while loading function" << endl;
		else {
			sort = (FuncType)func_ptr;
			sort(array, n);
			print_sorted_array(array, n);
		}
		FreeLibrary(hdll);
	}
	delete[] array;
}

#endif

void print_sorted_array(int* array, int size) {
	cout << "Sorted array:" << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void fill_and_print_array(int* array, int size) {
	cout << "Array:" << endl;
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100 - 50;
		cout << array[i] << " ";
	}
	cout << endl;
}