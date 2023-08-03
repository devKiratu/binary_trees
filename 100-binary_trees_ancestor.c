#include "binary_trees.h"

const binary_tree_t *bt_ancestor(const binary_tree_t *root,
		const binary_tree_t *first, const binary_tree_t *second);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *root;

	if (first == NULL || second == NULL)
		return (NULL);
	root = first;
	while (root->parent)
		root = root->parent;
	return ((binary_tree_t *)bt_ancestor(root, first, second));
}

/**
 * bt_ancestor - recursive function to determine the lowest common ancestor
 * @root: pointer to root of the binary tree
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to ancestor node or NULL
 */
const binary_tree_t *bt_ancestor(const binary_tree_t *root,
		const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (root == first || root == second)
		return (root);
	left = bt_ancestor(root->left, first, second);
	right = bt_ancestor(root->right, first, second);

	if (left && right)
		return (root);
	if (left)
		return (left);
	else
		return (right);
}
