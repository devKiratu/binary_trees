#include "binary_trees.h"
#include <stdio.h>

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
