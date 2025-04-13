#pragma once
#include <iostream>
#include <stdexcept>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void addBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void addFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addOnIndex(int val, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of bounds");
        }

        if (index == 0) {
            addFront(val);
            return;
        }
        if (index == size) {
            addBack(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }

    void removeFront() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
        size--;
    }

    void removeBack() {
        if (!tail) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }

        delete temp;
        size--;
    }

    void removeAtIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        if (index == 0) {
            removeFront();
            return;
        }
        if (index == size - 1) {
            removeBack();
            return;
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        size--;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

	int search(int value) const {
		Node* current = head;
		int index = 0;
		while (current) {
			if (current->data == value) {
				return index;
			}
			current = current->next;
			index++;
		}
		return -1; 
	}

    void listInit(int givenSize) {
		for (int i = 0; i < givenSize; i++) {
			addBack(i);
		}

   
};
