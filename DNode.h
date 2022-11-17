#ifndef DNode_h
#define DNode_h

#include "Node.h"

template <typename T>
class DNode: public Node<T>{
public:

	T value;
	DNode<T>* prev_node;
	DNode<T>* next_node;

	DNode(T value_) : value(value_),prev_node(nullptr), next_node(nullptr),Node(value_) {}
	DNode(DNode<T>* prev, DNode<T>* next) :prev_node(prev), next_node(next) , Node(nullptr) {}
	DNode<T>* get_next() {
		return next_node;
	}
};

#endif

