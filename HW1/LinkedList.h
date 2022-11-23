#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
#include "ListIterator.h"
#define NULL 0
template <typename T>
class LinkedList {
private:

	int size;
	Node<T>* head;

public:

	LinkedList() : size(0), head(new Node<T>(NULL)) {}

	// Add the specified element at the end of the list
	void Add(T& value) {
		Node<T>* running_node = head;
		while (running_node->next_node != NULL) {
			running_node = running_node->next_node;
		}
		running_node->next_node = new Node<T>(value, NULL);
		size++;
	}

	// Add the specified element at the specified index
	// If index > size, add to end
	void Insert(T& value, int index) {

		Node<T>* running_node = head;
		while (index != 0 && running_node->next_node != NULL) {
			running_node = running_node->next_node;
			index--;
		}
		running_node->next_node = new Node<T>(value, running_node->next_node);
		size++;
	}

	// Get the element at the specified index
	// Assumes index exists
	T& Get(int index) {

		Node<T>* running_node = head;
		while (index != 0 && running_node->next_node != NULL) {
			running_node = running_node->next_node;
			index--;
		}
		return running_node->next_node->value;
	}

	// Retrieve the index of the specified element (-1 if it does not exist in the list
	int IndexOf(T& value) {
		Node<T>* running_node = head;
		int index = 0;
		while (running_node->next_node != NULL) {
			running_node = running_node->next_node;
			if (running_node->value == value) {
				return index;
			}
			index++;
		}
		return -1;
	}

	// Remove the element at the specified index and return it
	// Assumes index exists
	T& Remove(int index) {
		Node<T>* running_node = head;
		while (index != 0 & running_node->next_node != NULL) {
			running_node = running_node->next_node;
			index--;
		}
		Node<T>* delete_node = running_node->next_node;
		T return_value = delete_node->value;
		running_node->next_node = delete_node->next_node;
		size--;
		delete delete_node;
		return return_value;
	}

	// Return the size of the list
	int Size() {
		return size;
	}

	// Return an iterator on this list
	ListIterator<T> Iterator() {
		return ListIterator<T>(head);
	}


};

#endif
