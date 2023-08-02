#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the binary tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	if (height_l > height_r)
		return (height_l + 1);
	else
		return (height_r + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the binary tree or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	return (height_l - height_r);
}
