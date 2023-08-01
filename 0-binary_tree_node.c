#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the new node being created
 * @value: value to put in the new node
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *bt;

	bt = malloc(sizeof(binary_tree_t));
	if (bt == NULL)
		return (NULL);

	bt->parent = parent;
	bt->n = value;
	bt->left = NULL;
	bt->right = NULL;

	return (bt);
}
