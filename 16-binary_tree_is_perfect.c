#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0, is_full = 0;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	is_full = binary_tree_is_full(tree);

	return (height_l == height_r && is_full);
}

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
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full, 0 if not full or tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && tree->right)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		return (left && right);
	}

	return (0);
}
