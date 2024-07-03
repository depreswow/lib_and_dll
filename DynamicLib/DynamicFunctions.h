#ifndef DYNAMIC_FUNCTIONS_H
#define DYNAMIC_FUNCTIONS_H

#if defined(DYNAMICLIB_EXPORTS)
#define LIBSPEC extern "C" __declspec(dllexport)
#else
#define LIBSPEC extern "C" __declspec(dllimport)
#endif

namespace sorting_algorithms {
	LIBSPEC void bubble_sort(int* array, int size);
	LIBSPEC void insertion_sort(int* array, int size);
}

#endif
