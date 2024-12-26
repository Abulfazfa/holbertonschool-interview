#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @temp: Temporary array to hold sorted elements
 * @left: Left subarray
 * @mid: Middle point
 * @right: Right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}

	while (i < mid)
	{
		temp[k++] = array[i++];
	}

	while (j < right)
	{
		temp[k++] = array[j++];
	}

	for (i = left; i < right; i++)
	{
		array[i] = temp[i];
	}

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Helper function to implement merge sort recursively
 * @array: The array to be sorted
 * @temp: Temporary array to hold sorted elements
 * @left: Left index
 * @right: Right index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (right - left > 1)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid, right);
		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
