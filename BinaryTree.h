#pragma once

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "BinaryTreeNode.h"

/// @brief Бинарное дерево.
struct BinaryTree
{
	BinaryTreeNode* Root;
};

/// @brief Инициализация дерева.
/// @param binaryTree Указатель на узел корня.
void InitializeTree(BinaryTree* binaryTree);

/// @brief Поиск элемента.
/// @param node  Указатель на узел корня.
/// @param value Значение которое надо найти.
/// @return		 Указатель на узел найденного элемента.
BinaryTreeNode* Find(BinaryTreeNode* node, const int value);

/// @brief Посик минимального элемента.
/// @param node Указатель на узел корня.
/// @return		Указатель на узел найденного элемента.
BinaryTreeNode* FindMinimal(BinaryTreeNode* node);

/// @brief Посик максимального элемента.
/// @param node Указатель на узел корня.
/// @return		Указатель на узел найденного элемента.
BinaryTreeNode* FindMaximal(BinaryTreeNode* node);

/// @brief Вставка элемета.
/// @param node  Указатель на узел корня.
/// @param value Значение которое надо вставить.
void Insert(BinaryTreeNode*& node, const int value);

/// @brief Удаление элемента.
/// @param node		Указатель на узел корня.
/// @param value	Значение которое надо удалить.
BinaryTreeNode* Remove(BinaryTreeNode*& node, const int value);

/// @brief Очистка памяти.
/// @param node Укзатель на узел корня.
void FreeTree(BinaryTreeNode* node);


#endif //_BINARYTREE_H_
