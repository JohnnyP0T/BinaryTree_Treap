#pragma once

#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_

/// @brief ���� ��������� ������
struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left = nullptr;
	BinaryTreeNode* Right = nullptr;
};


#endif //_BINARYTREENODE_H_