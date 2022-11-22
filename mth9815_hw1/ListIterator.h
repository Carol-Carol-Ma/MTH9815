#ifndef ListIterator_h
#define ListIterator_h

#include "Node.h"

template <typename T>
class ListIterator {
private:

	Node<T>* node;
	Node<T>* tail;
public:

	ListIterator(Node<T>* node_, Node<T>* tail_ = nullptr) : node(node_), tail(tail_){}

	// Return whether there is another element to return in this iterator
	bool HasNext() {
		return node->get_next() != tail;
	}

	// Return the next element in this iterator
	T& Next() {
		return node->get_next() ->value;
	}

	// Return whether there is another element to return in this iterator
	void Advance() {
		if (HasNext()) {
			node = node->get_next();
		}
	}
};

#endif