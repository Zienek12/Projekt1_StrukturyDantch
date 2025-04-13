#include <iostream>
#include "dynamicArray.h"
#include "linkedList.h"
#include <chrono>


int main() {
    
	DynamicArray arr;
    short int choice;
	
	while (1)
	{

		std::cout << "Choose data structure:\n1. Dynamic Array\n2. Linked List\n3. Exit\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::cout << "Choose operation:\n1. Add Front\n2. Add Back\n3. Add Index\n4. Remove Front\n5. Remove Back\n6. Remove Index\n7. Print\n8. Exit\n";
			short int operation;
			
			switch (operation)
			{

			case 1:
			{
				int value;
				std::cout << "Enter value to add at front: ";
				std::cin >> value;
				arr.addFront(value);
				break;
			}
			case 2:
			{
				int value;
				std::cout << "Enter value to add at back: ";
				std::cin >> value;
				arr.addBack(value);
				break;
			}
			case 3:
			{
				int index, value;
				std::cout << "Enter index and value to add: ";
				std::cin >> index >> value;
				try {
					arr.addIndex(index, value);
				}
				catch (const std::out_of_range& e) {
					std::cerr << e.what() << '\n';
				}
				break;
			}
			case 4:
			{
				try {
					arr.removeFront();
				}
				catch (const std::out_of_range& e) {
					std::cerr << e.what() << '\n';
				}
				break;
			}
			case 5:
			{
				try {
					arr.removeBack();
				}
				catch (const std::out_of_range& e) {
					std::cerr << e.what() << '\n';
				}
				break;
			}
			case 6:
			{
				int index;
				std::cout << "Enter index to remove: ";
				std::cin >> index;
				try {
					arr.removeIndex(index);
				}
				catch (const std::out_of_range& e) {
					std::cerr << e.what() << '\n';
				}
				break;
			}
			case 7:
			{
				arr.print();
				break;
			}
			case 8:
			{
				std::cout << "Exiting...\n";
				return 0;
			}


			break;
			
		}
		case 2:
		{
			std::cout << "Choose operation:\n1. Add Front\n2. Add Back\n3. Add Index\n4. Remove Front\n5. Remove Back\n6. Remove Index\n7. Print\n8. Exit\n";
			short int operation;

			break;
		}

		case 3:
		{
			std::cout << "Exiting...\n";
			return 0;
		}

		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}

	}



    return 0;
}
