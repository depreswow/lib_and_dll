#include "pch.h"
#include "DynamicFunctions.h"

namespace sorting_algorithms {
	void bubble_sort(int* array, int size) {
		int buffer;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1 - i; j++) {
				if (array[j] > array[j + 1]) {
					buffer = array[j];
					array[j] = array[j + 1];
					array[j + 1] = buffer;
				}
			}
		}
	}

	void insertion_sort(int* array, int size) {
		int buffer, j;
		for (int i = 1; i < size; i++) {
			buffer = array[i];
			j = i - 1;
			while (j >= 0 && array[j] > buffer) {
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = buffer;
		}
	}
}