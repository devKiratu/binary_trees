#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to root node of the binary tree
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	delete_right(tree->right);
	delete_left(tree->left);
	free(tree);
}

/**
 * delete_right - recursively deletes nodes on the right of the binary tree
 * @parent: parent node
 * Return: void
 */
void delete_right(binary_tree_t *parent)
{
	if (parent == NULL)
		return;
	delete_right(parent->right);
	delete_left(parent->left);
	free(parent);
}

/**
 * delete_left - recursively deletes nodes on the left of the binary tree
 * @parent: parent node
 * Return: void
 */
void delete_left(binary_tree_t *parent)
{
	if (parent == NULL)
		return;
	delete_right(parent->right);
	delete_left(parent->left);
	free(parent);
}
