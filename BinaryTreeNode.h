#pragma once

#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_

/// @brief Узел бинарного дерева
struct BinaryTreeNode
{
	BinaryTreeNode* Left = nullptr;
	BinaryTreeNode* Right = nullptr;
	int Data;
};

#endif //_BINARYTREENODE_H_