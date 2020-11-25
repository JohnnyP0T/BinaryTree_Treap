#pragma once

#ifndef _TREAP_H_
#define _TREAP_H_

#include "TreapNode.h"

/// @brief ��������� ������.
struct Treap
{
	TreapNode* Root;
};

/// @brief ������������� ������.
/// @param treap ��������� �� ������.
void InitializeTree(Treap* treap);

/// @brief ����� �������� �� ��������.
/// @param node		��������� �� ���� ������.
/// @param value	�������� ��� ������.
/// @return			��������� �� ���� ���������� ��������.
TreapNode* Find(TreapNode* node, const int value);

/// @brief ���������� ������.
/// @param node		��������� �� ���� �����.
/// @param key		���� �� �������� ����������� ����������.
/// @param left		���������� ��������� �� ���� ������ �����.
/// @param right	���������� ��������� �� ���� ������� �����.
void Split(TreapNode* node, const int key, TreapNode*& left, TreapNode*& right);

/// @brief ������� ���� ��������.
/// @param left		����� ��������� ���� ������.
/// @param right	������ ��������� ���� ������.
/// @return			��������� �� ���� ������������ ������.
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// @brief ������� ��������(�� ��������������, �� ���������� Merge � Split).
/// @param node		��������� �� ���� �����.
/// @param key		�������� ��� �������.
/// @param priority ���������(��������� �� �����a���).
void InsertNotOptimized(TreapNode*& node, int key, int priority = rand());

/// @brief �������� ��������(�� ��������������, �� ���������� Merge � Split).
/// @param node ��������� �� ���� �����.
/// @param key	��������� ��������.
void RemoveNotOptimized(TreapNode*& node, int key);

/// @brief ������� ��������.
/// @param node		��������� �� ���� �����.
/// @param key		�������� ��� �������.
/// @param priority ���������(��������� �����������).
auto Insert(TreapNode*& node, int key, int priority = rand()) -> void;

/// @brief �������� ��������.
/// @param node ��������� �� ���� �����.
/// @param key	��������� ��������.
void Remove(TreapNode*& node, int key);

/// @brief ������� ������.
/// @param node �������� �� ���� �����.
void FreeTree(TreapNode* node);

#endif //_BINARYTREE_H_
