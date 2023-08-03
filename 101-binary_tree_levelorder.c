#include "binary_trees.h"

int bt_height(const binary_tree_t *tree);
void traverse_level(const binary_tree_t *tree, int level, void (*func)(int));

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node, which takes the
 *	value of the node a parameter
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0, level;

	if (tree == NULL || func == NULL)
		return;
	height = bt_height(tree);
	for (level = 0; level < height; level++)
		traverse_level(tree, level, func);
}

/**
 * traverse_level - goes through all nodes in a given level, and performs a
 *	function call on the node data
 * @tree: binary tree to go through
 * @level: current level where traversal is taking place
 * @func: function call to perform on the node
 */
void traverse_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		traverse_level(tree->left, level - 1, func);
		traverse_level(tree->right, level - 1, func);
	}
}

/**
 * bt_height - gets the height of the binary tree
 * @tree: pointer to root of the binary tree
 * Return: height of the binary tree
 */
int bt_height(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);
	height_l = bt_height(tree->left);
	height_r = bt_height(tree->right);

	if (height_l > height_r)
		return (height_l + 1);
	else
		return (height_r + 1);
}
