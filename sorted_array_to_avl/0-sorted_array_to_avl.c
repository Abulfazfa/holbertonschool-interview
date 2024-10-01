#include "binary_trees.h"
/**
 * ArrayToAVL - sort array
 *
 * @array: sorted array to be converted to a binary tree.
 * @start: start node.
 * @end: end node.
 * @parent: parent node.
 * Return: AVL tree
 */

avl_t *ArrayToAVL(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;

	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);
	root->n = array[mid];
	root->parent = parent;
	root->left = ArrayToAVL(array, start, mid - 1, root);
	root->right = ArrayToAVL(array, mid + 1, end, root);
	return (root);

}
/**
 * sorted_array_to_avl - Prints a binary tree
 *
 * @array: sorted array to be converted to a binary tree
 * @size: size of the array
 * Return: AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);
	return (ArrayToAVL(array, 0, size - 1, NULL));
}
