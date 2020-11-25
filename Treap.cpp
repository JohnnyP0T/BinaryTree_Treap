#include <exception>

#include "Treap.h"


void InitializeTree(Treap* treap)
{
	treap->Root = nullptr;
}


TreapNode* Find(TreapNode* node, const int value)
{
	if (node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	if (node->Key == value)
	{
		return node;
	}

	if (node->Key > value)
	{
		return Find(node->Left, value);
	}

	return  Find(node->Right, value);
}


void Split(TreapNode* node, const int key, TreapNode*& left, TreapNode*& right)
{
	if(node == nullptr)
	{
		left = right = nullptr;
	}
	else if(node->Key < key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}


TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if(left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}

	if(left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	
	right->Left = Merge(left, right->Left);
	return right;
}


void InsertNotOptimized(TreapNode*& node, int key, int priority)
{
	TreapNode* newTreapNode = new TreapNode;
	TreapNode* less = nullptr;
	TreapNode* greater = nullptr;
	newTreapNode->Key = key;
	newTreapNode->Priority = priority;
	Split(node, key, less, greater);
	node = Merge(Merge(less, newTreapNode), greater);
}


void RemoveNotOptimized(TreapNode*& node, int key)
{
	TreapNode* less = nullptr;
	TreapNode* equal = nullptr;
	TreapNode* greater = nullptr;
	Split(node, key, less, greater);
	Split(greater, key + 1, equal, greater);
	node = Merge(less, greater);
	delete equal;
}


void Insert(TreapNode*& node, int key, int priority)
{
	if (node == nullptr)
	{
		node = new TreapNode;
		node->Key = key;
		node->Priority = priority;
		return;
	}
	
	if (node->Priority > priority)
	{
		if (key < node->Key)
		{
			Insert(node->Left, key, priority);
		}
		else
		{
			Insert(node->Right, key, priority);
		}
		return;
	}
	
	TreapNode* newTreapNode = new TreapNode;
	newTreapNode->Key = key;
	newTreapNode->Priority = priority;
	Split(node, key, newTreapNode->Left, newTreapNode->Right);
	node = newTreapNode;
}


void Remove(TreapNode*& node, int key)
{
	if(node == nullptr)
	{
		return;
	}
	
	if (key < node->Key)
	{
		Remove(node->Left, key);
	}
	else if (key > node->Key)
	{
		Remove(node->Right, key);
	}
	else
	{
		TreapNode* current = node;
		node = Merge(node->Left, node->Right);
		delete current;
	}
}


void FreeTree(TreapNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	FreeTree(node->Left);
	FreeTree(node->Right);
	delete node;
}



