#pragma once

#ifndef _MENU_H_
#define _MENU_H_

#include "BinaryTree.h"
#include "Treap.h"

/// @brief Перечисление для меню бинарого дерева
enum class MenuTreeOption
{
	Add = 1,
	Remove = 2,
	Find = 3,
	FindMinimal = 4,
	FindMaximal = 5,
	Show = 6,
	Exit = 7
};

/// @brief Перечисление для меню Декартового дерева
enum class MenuTreapOption
{
	AddNotOptimized = 1,
	RemoveNotOptimized = 2,
	Add = 3,
	Remove = 4,
	Find = 5,
	Show = 6,
	Exit = 7
};

/// @brief Получение целочисленного элемента с консоли
/// @return Полученный элемет
int GetElementConsole();

/// @brief Печать дерева
/// @param binaryTreeNode Указатель на узел корня
/// /// @param indent Отступ
void PrintTree(BinaryTreeNode* node, int indent);

/// @brief Меню для бинарого дерева
/// @param binaryTree Указатель на узел корня
void Menu(BinaryTree* binaryTree);

/// @brief Меню для Декартового дерева
/// @param binaryTree Указатель на узел корня
void Menu(Treap* treap);

#endif //_MENU_H_