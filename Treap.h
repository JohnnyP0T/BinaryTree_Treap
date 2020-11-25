#pragma once

#ifndef _TREAP_H_
#define _TREAP_H_

#include "TreapNode.h"

/// @brief Декартово дерево.
struct Treap
{
	TreapNode* Root;
};

/// @brief Инициализация дерева.
/// @param treap Указатель на дерево.
void InitializeTree(Treap* treap);

/// @brief Поиск элемента по значению.
/// @param node		Указатель на узел кореня.
/// @param value	Значение для поиска.
/// @return			Указатель на узел найденного элемента.
TreapNode* Find(TreapNode* node, const int value);

/// @brief Разрезание дерева.
/// @param node		Указатель на узел корня.
/// @param key		Ключ по которому производить разрезание.
/// @param left		Полученный указатель на узел левого корня.
/// @param right	Полученный указатель на узел правого корня.
void Split(TreapNode* node, const int key, TreapNode*& left, TreapNode*& right);

/// @brief Слияние двух деревьев.
/// @param left		Левый указатель узла дерева.
/// @param right	Правый указатель узла дерева.
/// @return			Указатель на узел соедененного дерева.
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// @brief Вставка элемента(не оптимизирована, тк использует Merge и Split).
/// @param node		Указатель на узел корня.
/// @param key		Значение для вставки.
/// @param priority Приоритет(рандомный по умолчaнию).
void InsertNotOptimized(TreapNode*& node, int key, int priority = rand());

/// @brief Удаление элемента(не оптимизирована, тк использует Merge и Split).
/// @param node Указатель на узел корня.
/// @param key	Удаляемое значение.
void RemoveNotOptimized(TreapNode*& node, int key);

/// @brief Вставка элемента.
/// @param node		Указатель на узел корня.
/// @param key		Значение для вставки.
/// @param priority Приоритет(рандомный поумолчянию).
auto Insert(TreapNode*& node, int key, int priority = rand()) -> void;

/// @brief Удаление элемента.
/// @param node Указатель на узел корня.
/// @param key	Удаляемое значение.
void Remove(TreapNode*& node, int key);

/// @brief Очистка памяти.
/// @param node Укзатель на узел корня.
void FreeTree(TreapNode* node);

#endif //_BINARYTREE_H_
