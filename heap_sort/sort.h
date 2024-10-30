#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers.
 * @array: Pointer to the array to print.
 * @size: Number of elements in the array.
 */
void print_array(const int *array, size_t size);

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * @array: Pointer to the array containing the integers.
 * @n: Size of the array.
 */
void swap(int *a, int *b, int *array, size_t n);

/**
 * heap_root - Maintains the heap property of a subtree rooted at index i.
 * @array: Pointer to the array.
 * @n: Size of the heap.
 * @i: Index of the root element of the subtree.
 */
void heap_root(int *array, int n, int i);

/**
 * heap_sort - Sorts an array of integers in ascending order using the heap sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size);

#endif /* _SORT_H_ */
