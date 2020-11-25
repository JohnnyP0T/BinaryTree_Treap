#include <exception>

#include "BinaryTree.h"


void InitializeTree(BinaryTree* binaryTree)
{
	binaryTree->Root = nullptr;
}


BinaryTreeNode* Find(BinaryTreeNode* node, const int value)
{
	if(node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	if(node->Data == value)
	{
		return node;
	}

	if(node->Data > value)
	{
		return Find(node->Left, value);
	}

	return Find(node->Right, value);
}


BinaryTreeNode* FindMinimal(BinaryTreeNode* node)
{
	if(node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	while(node->Left != nullptr)
	{
		node = node->Left;
	}

	return node;
}


BinaryTreeNode* FindMaximal(BinaryTreeNode* node)
{
	if(node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	while(node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}


void Insert(BinaryTreeNode*& node, const int value)
{
	if(node == nullptr)
	{
		node = new BinaryTreeNode;
		node->Data = value;
		return;
	}

	if(node->Data > value)
	{
		Insert(node->Left, value);
		return;
	}
	
	Insert(node->Right, value);
	return;
}


/// @todo return void;
/// тут так и должно быть. это надо для рекурсии.
BinaryTreeNode* Remove(BinaryTreeNode*& node, const int value)
{
	if(node == nullptr)
	{
		return node;
	}

	if(value < node->Data)
	{
		node->Left = Remove(node->Left, value);
	}
	else if(value > node->Data)
	{
		node->Right = Remove(node->Right, value);
	}
	else if(node->Left != nullptr && node->Right != nullptr)
	{
		node->Data = FindMinimal(node->Right)->Data;
		node->Right = Remove(node->Right, node->Data);
	}
	else
	{
		BinaryTreeNode* current = nullptr;
		if(node->Left != nullptr)
		{
			current = node;
			node = current->Left;
			delete current;
		}
		else if(node->Right != nullptr)
		{
			current = node;
			node = current->Right;
			delete current;
		}
		else
		{
			delete node;
			node = nullptr;
		}
	}
	
	return node;
}


void FreeTree(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	FreeTree(node->Left);
	FreeTree(node->Right);
	delete node;
}
