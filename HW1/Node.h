#ifndef Node_h
#define Node_h
#define NULL 0
template <typename T>
class Node {
public:

	T value;
	Node<T>* next_node;

	Node(Node<T>* next_node_) : next_node(next_node_) {}
	Node(T value_, Node<T>* next_node_ = NULL) : value(value_), next_node(next_node_) {}
	virtual Node<T>* get_next() {
		return next_node;
	}
};

#endif
