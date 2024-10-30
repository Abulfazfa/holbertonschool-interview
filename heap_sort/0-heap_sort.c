#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the heap sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size == 0)
        return;

    /* Build max heap */
    for (i = size / 2; i > 0; i--)
        heap_root(array, size, i - 1);

    /* Heap sort */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i], array, size);

        /* Heapify root element to get the highest element at root again */
        heap_root(array, i, 0);
    }
}

/**
 * heap_root - Maintains the heap property of a subtree rooted at index i.
 * @array: Pointer to the array.
 * @n: Size of the heap.
 * @i: Index of the root element of the subtree.
 */
void heap_root(int *array, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    /* Find largest among root, left child, and right child */
    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    /* Swap and continue heapifying if root is not largest */
    if (largest != i)
    {
        swap(&array[i], &array[largest], array, n);
        heap_root(array, n, largest);
    }
}

/**
 * swap - Swaps the values of two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */
void swap(int *a, int *b, int *array, size_t size)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    print_array(array, size);  // Print the array after swap
}
