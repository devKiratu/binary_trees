#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node looking for its uncle
 * Return: pointer to the uncle node or NULL if node is NULL or has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *g_parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	g_parent = parent->parent;

	if (g_parent == NULL)
		return (NULL);
	if (g_parent->left == parent)
		return (g_parent->right);
	else
		return (g_parent->left);
}
