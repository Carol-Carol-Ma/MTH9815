#include <list>
using namespace std;

template <typename k>
class Hasher
{
public:
	virtual unsigned int hash(k key) = 0;
};


template <typename k>
class EqualityPredicate
{
public:
	virtual bool isEqual(k left, k right) = 0;
};


template <typename k, typename v> struct HashNode {
	k key; v value;
	HashNode(k k = k(), v v = v()) : key(k), value(v) {};
	HashNode(HashNode<k, v> const& e) : key(e.key), value(e.value) {};
};



template <typename K, typename V>
class HashTable
{
private:
	int capacity;
	
	list<HashNode<K, V> >** arr;
	Hasher<K>* hasher;
	EqualityPredicate<K>* equalityPredicate;

public:
	//constructor
	HashTable(int capacity, Hasher<K>* hasher, EqualityPredicate<K>* equalityPredicate): capacity(capacity)
	{
		this->hasher = hasher;
		this->equalityPredicate = equalityPredicate;

		arr = new list<HashNode<K, V> >*[capacity];

		//Initialise with empty list
		for (auto i = 0; i < capacity; i++) {
			arr[i] = new list<HashNode<K, V>>(0);
		}
	}


	// destructior
	~HashTable()
	{
		for (int i = 0; i < capacity; i++)
			delete arr[i];
	}

	// return the iterator of the matching key
	// if not find, return ending iter
	auto find(K key, list<HashNode<K, V>>* ls)
	{
		auto iter = ls->begin();
		while (iter != ls->end()) {
			// cout << iter->key;
			if (equalityPredicate->isEqual(iter->key, key)) {
				return iter;
			}
			iter++;

		};

		return iter;
	}


	void insert(K key, V value)
	{
		HashNode<K, V> tempNode = HashNode<K, V>(key, value);
		int index = this->hasher->hash(key) % capacity;


		list<HashNode<K, V>>* ls = arr[index]; // use hash value to match
		auto iter = find(key, ls);

		
		if (iter == ls->end()) {
			//new key case: insert at the back
			ls->push_back(tempNode);
		}
		else {
			//duplication case: update value
			iter->value = value;
		}

	}

	V get(K key)
	{
		int index = this->hasher->hash(key) % capacity;
		list<HashNode<K, V> >* ls = arr[index];


		auto iter = find(key, ls);
		if (iter == ls->end()) {
			throw "Index error";
		}
		else {
			return iter->value;
		}
		
	}

	void remove(K key) 
	{
		int index = this->hasher->hash(key) % capacity;
		list<HashNode<K, V> >* ls = arr[index];


		auto iter = find(key, ls);
		if (iter == ls->end()) {
			throw "Index error";
		}
		else {
			ls->erase(iter);
		}
		
	}
};