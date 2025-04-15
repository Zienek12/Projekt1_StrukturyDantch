#include "libraries.h" 

int main() {
    DynamicArray arr;
    LinkedList list;
    short int choice;

    while (true) {
        std::cout << "Choose data structure:\n1. Dynamic Array\n2. Linked List\n3. Perform benchmark for dynamic array\n4. Perform benchmark for linked list\n5. Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            short int operation = 0;
            while (operation != 8) {
                std::cout << "Choose operation:\n"
                    "1. Add Front\n"
                    "2. Add Back\n"
                    "3. Add on Index\n"
                    "4. Remove Front\n"
                    "5. Remove Back\n"
                    "6. Remove Index\n"
                    "7. Print\n"
                    "8. Exit\n";
                std::cin >> operation;

                switch (operation) {
                case 1: {
#ifdef _MSC_VER  
                    std::cout << "Kompilator MSVC, wersja: " << _MSC_VER << std::endl;
#endif 
                    int value;
                    std::cout << "Enter value to add at front: ";
                    std::cin >> value;
                    arr.addFront(value);
                    break;
                }
                case 2: {
                    int value;
                    std::cout << "Enter value to add at back: ";
                    std::cin >> value;
                    arr.addBack(value);
                    break;
                }
                case 3: {
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
                case 4: {
                    try {
                        arr.removeFront();
                    }
                    catch (const std::out_of_range& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 5: {
                    try {
                        arr.removeBack();
                    }
                    catch (const std::out_of_range& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 6: {
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
                case 7: {
                    arr.print();
                    break;
                }
                case 8: {
                    std::cout << "Returning to main menu...\n";
                    break;
                }
                default: {
                    std::cout << "Invalid operation. Please try again.\n";
                    break;
                }
                }
                system("pause");
                system("cls");
            }
            break;
        }
        case 2: {
            short int operation = 0;
            while (operation != 8) {
                std::cout << "Choose operation:\n"
                    "1. Add Front\n"
                    "2. Add Back\n"
                    "3. Add on Index\n"
                    "4. Remove Front\n"
                    "5. Remove Back\n"
                    "6. Remove Index\n"
                    "7. Print\n"
                    "8. Exit\n";
                std::cin >> operation;

                switch (operation) {
                case 1: {
                    int value;
                    std::cout << "Enter value to add at front: ";
                    std::cin >> value;
                    list.addFront(value);
                    break;
                }
                case 2: {
                    int value;
                    std::cout << "Enter value to add at back: ";
                    std::cin >> value;
                    list.addBack(value);
                    break;
                }
                case 3: {
                    int index, value;
                    std::cout << "Enter index and value to add: ";
                    std::cin >> index >> value;
                    try {
                        list.addIndex(index, value);
                    }
                    catch (const std::out_of_range& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 4: {
                    try {
                        list.removeFront();
                    }
                    catch (const std::out_of_range& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 5: {
                    try {
                        list.removeBack();
                    }
                    catch (const std::out_of_range& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 6: {
                    int index;
                    std::cout << "Enter index to remove: ";
                    std::cin >> index;
                    try {
                        list.removeIndex(index);
                    }
                    catch (const std::out_of_range& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 7: {
                    list.print();
                    break;
                }
                case 8: {
                    std::cout << "Returning to main menu...\n";
                    break;
                }
                default: {
                    std::cout << "Invalid operation. Please try again.\n";
                    break;
                }
                }
                system("pause");
                system("cls");
            }
            break;

            }
        case 3: {
            benchmarkDynamicArray();
            break;
        }
		case 4: {
			benchmarkLinkedList();
			break;
		}
        case 5: {
            std::cout << "Exiting...\n";
            return 0;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
              system("pause");
              system("cls");
        }

        return 0;
    }
