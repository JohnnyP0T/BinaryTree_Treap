#include <iostream>
#include <string>
#include <exception>

#include "Menu.h"


int GetElementConsole()
{
	while (true)
	{
		std::string inputValue;
		size_t length;
		std::cout << "Enter menu Value: ";
		std::getline(std::cin, inputValue);

		try
		{
			int number = stoi(inputValue, &length);
			if (length == inputValue.length())
			{
				return number;
			}
		}
		catch (std::exception& e)
		{
			std::cout << inputValue << " is not a number! " << e.what() << std::endl;
		}
	}
}


void PrintTree(BinaryTreeNode* binaryTreeNode)
{
	if(binaryTreeNode == nullptr)
	{
		return;
	}
	
	PrintTree(binaryTreeNode->Left);
	std::cout << " " << binaryTreeNode->Data << " ";
	PrintTree(binaryTreeNode->Right);
}


void PrintTree(TreapNode* treapNode)
{
	if (treapNode == nullptr)
	{
		return;
	}

	PrintTree(treapNode->Left);
	std::cout << " " << treapNode->Key << " ";
	PrintTree(treapNode->Right);
}


void Menu(BinaryTree* binaryTree)
{
	InitializeTree(binaryTree);
	int valueForMenu = 0;
	int valueForTree = 0;
	bool isValueForPrint = false;

	for(;;)
	{
		if(isValueForPrint)
		{
			PrintTree(binaryTree->Root);
		}

		std::cout << "\n+===============================BinarySearchTree+===============================\n"
			<< "1 - Add\n"
			<< "2 - Remove\n"
			<< "3 - Find\n"
			<< "4 - Find Minimal\n"
			<< "5 - Find Maximal\n"
			<< "6 - Show\n"
			<< "7 - Exit\n";
		valueForMenu = GetElementConsole();
		switch (static_cast<MenuTreeOption>(valueForMenu))
		{
			case MenuTreeOption::Add:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				Insert(binaryTree->Root, valueForTree);
				break;
			}

			case MenuTreeOption::Remove:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				BinaryTreeNode* node = Remove(binaryTree->Root, valueForTree);
				break;
			}

			case MenuTreeOption::Find:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				try
				{
					std::cout << Find(binaryTree->Root, valueForTree)->Data << std::endl;
				}
				catch (std::exception& exceptionFind)
				{
					std::cout << exceptionFind.what();
				}
				system("pause");
				break;
			}

			case MenuTreeOption::FindMinimal:
			{
				try
				{
					std::cout << FindMinimal(binaryTree->Root)->Data << std::endl;
				}
				catch (std::exception& exceptionFindMinimal)
				{
					std::cout << exceptionFindMinimal.what();
				}
				system("pause");
				break;
			}

			case MenuTreeOption::FindMaximal:
			{
				try
				{
					std::cout << FindMaximal(binaryTree->Root)->Data << std::endl;
				}
				catch (std::exception& exceptionFindMaximal)
				{
					std::cout << exceptionFindMaximal.what();
				}
				system("pause");
				break;
			}

			case MenuTreeOption::Show:
			{
				isValueForPrint = true;
				break;
			}

			case MenuTreeOption::Exit:
			{
				return;
			}

			default:
			{
				std::cout << "Invalid Value\n";
				system("pause");
				break;
			}
		}
		system("cls");
	}
}


void Menu(Treap* treap)
{
	
	InitializeTree(treap);
	int valueForMenu = 0;
	int valueForTree = 0;
	bool isValueForPrint = false;

	for (;;)
	{
		if (isValueForPrint)
		{
			PrintTree(treap->Root);
		}

		std::cout << "\n+===============================BinarySearchTree+===============================\n"
			<< "1 - AddNotOptimized\n"
			<< "2 - RemoveNotOptimized\n"
			<< "3 - Add\n"
			<< "4 - Remove\n"
			<< "5 - Find\n"
			<< "6 - Show\n"
			<< "7 - Exit\n";
		valueForMenu = GetElementConsole();
		switch (static_cast<MenuTreapOption>(valueForMenu))
		{
			case MenuTreapOption::AddNotOptimized:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				InsertNotOptimized(treap->Root, valueForTree);
				break;
			}

			case MenuTreapOption::RemoveNotOptimized:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				RemoveNotOptimized(treap->Root, valueForTree);
				break;
			}

			case MenuTreapOption::Add:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				Insert(treap->Root, valueForTree);
				break;
			}

			case MenuTreapOption::Remove:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				Remove(treap->Root, valueForTree);
				break;
			}
			
			case MenuTreapOption::Find:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				try
				{
					std::cout << Find(treap->Root, valueForTree)->Key << std::endl;
				}
				catch (std::exception& exceptionFind)
				{
					std::cout << exceptionFind.what();
				}
				system("pause");
				break;
			}

			case MenuTreapOption::Show:
			{
				isValueForPrint = true;
				break;
			}

			case MenuTreapOption::Exit:
			{
				return;
			}

			default:
			{
				std::cout << "Invalid Value\n";
				system("pause");
				break;
			}
		}
		system("cls");
	}
}
