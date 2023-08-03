#include "binary_trees.h"

int is_bt_perfect(const binary_tree_t *tree, int depth, int level);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0, level = 0;
	const binary_tree_t *temp;

	if (tree == NULL)
		return (0);
	temp = tree;
	while (temp != NULL)
	{
		temp = temp->left;
		depth++;
	}

	return (is_bt_perfect(tree, depth, level));
}

/**
 * is_bt_perfect - recursively evaluates if a binary tree is perfect by:
 *	- checking if all internal nodes have two children
 *	- all leaves are at depth @depth
 * @tree: root of the binary tree to check
 * @depth: depth of the binary tree
 * @level: starting level for evaluation
 * Return: 1 if true, 0 if false
 */
int is_bt_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_bt_perfect(tree->left, depth, level + 1) &&
			is_bt_perfect(tree->right, depth, level + 1));
}
