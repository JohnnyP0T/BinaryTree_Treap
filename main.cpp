#include "iostream"
#include "Menu.h"


int main()
{
	int valueForMenu;
	for(;;)
	{
		std::cout << "1 - Binary Search Tree\n"
			<< "2 - Treap\n"
			<< "0 - Exit\n";
		valueForMenu = GetElementConsole();
		switch (valueForMenu)
		{
			case 1:
			{
				BinaryTree* binaryTree = new BinaryTree;
				Menu(binaryTree);
				delete binaryTree;
				break;
			}
			case 2:
			{
				Treap* treap = new Treap;
				Menu(treap);
				delete treap;
				break;
			}
			case 0:
			{
				return 0;
			}
			default:
			{
				std::cout << "Invalid value\n";
				system("pause");
				break;
			}
		}
	}
}