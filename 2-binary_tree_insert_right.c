#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 *	If parent already has a right-child, the new node must take its place,
 *	and the old right-child must be set as the right-child of the new node.
 * @parent: pointer to the node to insert right child in
 * @value: value to store in the new node
 * Return: pointer to created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right == NULL)
	{
		parent->right = bt;
		bt->parent = parent;
	}
	else
	{
		temp = parent->right;
		parent->right = bt;
		bt->parent = parent;
		bt->right = temp;
		temp->parent = bt;
	}
	return (bt);
}
