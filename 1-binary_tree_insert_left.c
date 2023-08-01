#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to node to insert left child in
 * @value: value of the left child
 * Return: Pointer to created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *bt, *temp;

	if (parent == NULL)
		return (NULL);

	bt = malloc(sizeof(binary_tree_t));
	if (bt == NULL)
		return (NULL);

	bt->n = value;
	bt->parent = NULL;
	bt->right = NULL;
	bt->left = NULL;

	if (parent->left == NULL)
	{
		parent->left = bt;
		bt->parent = parent;
	}
	else
	{
		temp = parent->left;
		parent->left = bt;
		bt->parent = parent;
		bt->left = temp;
		temp->parent = bt;
	}
	return (bt);
}
