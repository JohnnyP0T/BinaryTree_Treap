#include <iostream>
#include <string>
#include <exception>
#include <iomanip>

#include "Menu.h"


void PrintTree(TreapNode* node, int indent)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->Right) 
	{
		PrintTree(node->Right, indent + 4);
	}
	
	if (indent) 
	{
		std::cout << std::setw(indent) << ' ';
	}
	
	if (node->Right)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}
	
	std::cout << node->Key << "(" << node->Priority << ")" << "\n ";
	if (node->Left) 
	{
		std::cout << '\t' << ' ' << " \\\n";
		PrintTree(node->Left, indent + 4);
	}
}


void PrintTree(BinaryTreeNode* node, int indent)
{
	if (node != nullptr)
	{
		return;
	}
	
	if (node->Right) 
	{
		PrintTree(node->Right, indent + 4);
	}
	
	if (indent) 
	{
		std::cout << std::setw(indent) << ' ';
	}
	
	if (node->Right)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}
	
	std::cout << node->Data << "\n ";
	if (node->Left) 
	{
		std::cout << '\t' << ' ' << " \\\n";
		PrintTree(node->Left, indent + 4);
	}
	
}


int GetElementConsole()
{
	while (true)
	{
		std::string inputValue;
		std::cout << "Enter menu Value: ";
		std::getline(std::cin, inputValue);

		try
		{
			size_t length;
			const int number = stoi(inputValue, &length);
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


void Menu(BinaryTree* binaryTree)
{
	InitializeTree(binaryTree);
	int valueForMenu;
	int valueForTree;
	bool isValueForPrint = false;

	for(;;)
	{
		if(isValueForPrint)
		{
			PrintTree(binaryTree->Root, 3);
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
				Remove(binaryTree->Root, valueForTree);
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
				FreeTree(binaryTree->Root);
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
	int valueForMenu;
	int valueForTree;
	bool isValueForPrint = false;

	for (;;)
	{
		if (isValueForPrint)
		{
			PrintTree(treap->Root, 3);
		}

		std::cout << "\n+===============================Treap+===============================\n"
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
				FreeTree(treap->Root);
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
