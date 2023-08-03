#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int is_bt_complete(const binary_tree_t *tree, int index, int size);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if true, 0 if false or tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = 0, index = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	return (is_bt_complete(tree, index, size));
}

/**
 * is_bt_complete - recursive function to check if a binary tree is complete
 * @tree: pointer to root node of the binary tree
 * @index: starting index
 * @size: number of nodes in the binary tree
 * Return: 1 if complete, 0 if false
 */
int is_bt_complete(const binary_tree_t *tree, int index, int size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (is_bt_complete(tree->left, 2 * index + 1, size) &&
			is_bt_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure size
 * Return: size of tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count_r = 0, count_l = 0;

	if (tree == NULL)
		return (0);
	count_l = binary_tree_size(tree->left);
	count_r = binary_tree_size(tree->right);
	return (count_l + count_r + 1);
}
