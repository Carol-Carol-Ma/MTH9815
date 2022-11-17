#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include "DNode.h"
#include "ListIterator.h"

template <typename T>
class DLinkedList:public LinkedList<T> {
private:

	int size;
	DNode<T>* head;
	DNode<T>* tail;
public:

	DLinkedList() : size(0), head(new DNode<T>(nullptr,nullptr)), tail(new DNode<T>(nullptr, nullptr)){
		head->next_node = tail;
		tail->prev_node = head;
	}

	// Add the specified element at the end of the list
	void Add(T& value) {
		DNode<T>* tmp = new DNode<T>(value);
		tmp->next_node = tail;
		tmp->prev_node = tail->prev_node;
		tail->prev_node->next_node = tmp;
		tail->prev_node = tmp;
		size++;
	}

	// Add the specified element at the specified index
	// If index > size, add to end
	void Insert(T& value, int index) {
		DNode<T>* tmp = new DNode<T>(value);
		DNode<T>* running_node = head;
		while (index != 0 && running_node->next_node != tail) {
			running_node = running_node->next_node;
			index--;
		}
		tmp->prev_node = running_node;
		tmp->next_node = running_node->next_node;
		running_node->next_node = tmp;
		tmp->next_node->prev_node = tmp;
		size++;
	}

	// Get the element at the specified index
	// Assumes index exists
	T& Get(int index) {

		DNode<T>* running_node = head;
		while (index != 0 && running_node->next_node != tail) {
			running_node = running_node->next_node;
			index--;
		}
		return running_node->next_node->value;
	}

	// Retrieve the index of the specified element (-1 if it does not exist in the list
	int IndexOf(T& value) {
		DNode<T>* running_node = head;
		int index = 0;
		while (running_node->next_node != tail) {
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
		DNode<T>* running_node = head;
		while (index != 0 & running_node->next_node != tail) {
			running_node = running_node->next_node;
			index--;
		}
		running_node = running_node->next_node;
		T return_value = running_node->value;
		running_node->next_node->prev_node = running_node->prev_node;
		running_node->prev_node->next_node = running_node->next_node;
		delete running_node;
		size--;
		return return_value;
	}

	// Return the size of the list
	int Size() {
		return size;
	}

	// Return an iterator on this list
	ListIterator<T> Iterator() {
		return ListIterator<T>(head, tail);
	}


};

#endif