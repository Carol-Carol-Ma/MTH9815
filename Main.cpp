#include "LinkedList.h"
#include "ListIterator.h"
#include <iostream>

#include <iostream>
#include <list>
#include <vector>
#include "Hashtable.h"
#include <string>
#include "DoubleLinkedList.h"
using namespace std;


class IntHasher : public Hasher<int>
{
public:
	unsigned int hash(int key)
	{
		return key;
	}
};


class IntEqualityPredicate : public EqualityPredicate<int>
{
public:
	bool isEqual(int left, int right)
	{
		return left == right;
	}
};

int main() {
	cout << "\n----------------- Exercise1 ---------------" << endl;
	//Linked List Test

	LinkedList<int> ll;

	for (int i = 0; i < 10; i++) {
		ll.Add(i);
	}

	ListIterator<int> iter = ll.Iterator();
	std::cout << "Initial Linked List: ";
	while (iter.HasNext()) {
		std::cout << iter.Next() << ", ";
		iter.Advance();
	}
	std::cout << std::endl;
	
	std::cout << "Created a linked list of size: " << ll.Size() << std::endl;

	std::cout << "Element at index 4: " << ll.Get(4) << std::endl;

	int insert_val = 100;
	std::cout << "Inserting 100 at index 7" << std::endl;
	ll.Insert(insert_val, 7);

	std::cout << "Removed element " << ll.Remove(3) << " from index 3." << std::endl;

	std::cout << "Index of element 100: "  << ll.IndexOf(insert_val) << std::endl;

	int missing_val = 1000;
	std::cout << "Index of element 1000: " << ll.IndexOf(missing_val) << std::endl;

	std::cout << "Final List:";

	iter = ll.Iterator();
	while (iter.HasNext()) {
		std::cout << iter.Next() << ", ";
		iter.Advance();
	}
	std::cout << std::endl;


	cout << "\n----------------- Exercise2 ---------------" << endl;
	//doubleLinked List Test

	DLinkedList<int> l2;

	for (int i = 0; i < 10; i++) {
		l2.Add(i);
	}

	iter = l2.Iterator();
	std::cout << "Initial DoubleLinked List: ";
	while (iter.HasNext()) {
		std::cout << iter.Next() << ", ";
		iter.Advance();
	}
	std::cout << std::endl;

	std::cout << "Created a Doublelinked list of size: " << l2.Size() << std::endl;

	std::cout << "Element at index 4: " << l2.Get(4) << std::endl;

	std::cout << "Inserting 100 at index 7" << std::endl;
	l2.Insert(insert_val, 7);

	std::cout << "Removed element " << l2.Remove(3) << " from index 3." << std::endl;

	std::cout << "Index of element 100: " << l2.IndexOf(insert_val) << std::endl;
	 

	std::cout << "Index of element 1000: " << l2.IndexOf(missing_val) << std::endl;

	std::cout << "Final List:";

	iter = l2.Iterator();
	while (iter.HasNext()) {
		std::cout << iter.Next() << ", ";
		iter.Advance();
	}
	std::cout << std::endl;







	cout << "\n----------------- Exercise3 ---------------" << endl;
	Hasher<int>* hasher = new IntHasher();
	EqualityPredicate<int>* equalityPredicate = new IntEqualityPredicate();

	HashTable<int, string>* table = new HashTable<int, string>(100, hasher, equalityPredicate);
	table->insert(1, "Tom");
	table->insert(101, "Jack");
	table->insert(201, "Bety");
	table->insert(25, "Joe");
	table->insert(22, "Laura");

	cout << "key 1 has value: " << table->get(1) << endl;
	cout << "key 101 has value: " << table->get(101) << endl;
	cout << "key 201 has value: " << table->get(201) << endl;
	cout << "key 25 has value: " << table->get(25) << endl;
	cout << "key 22 has value: " << table->get(22) << endl;

	table->insert(22, "June");

	cout << "after another insertion, key 22 has an updated value: " << table->get(22) << endl;


	table->remove(201);

	cout << "after remove entry with key 201, key 101 has value: " << table->get(101) << endl;

	// cout << "try to get value without key:" << table->get(50) << endl;

	delete table;
	delete hasher;
	delete equalityPredicate;

	return 0;
}