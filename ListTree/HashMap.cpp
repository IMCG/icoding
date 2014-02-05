#include<iostream>
using namespace std;
template <typename Key,typename Value>
class HashMap{
public:
	HashMap(int sizeHint = 10001);
	~HashMap();

	bool isEmpty() const{ return size()==0； }
	int size() const{ return count; }

	bool containsKey(const Key& key) const;
	void put(const Key& key, const Value&value);
	Value get(const Key&key) const;
	Value& operator[](const Key& key);

private:
	struct node{
		Key key;
		Value value;
		node*next;
	};
	node **buckets;
	int numBuckets;
	int count;
	int hash(const Key& key) const;
	node*ensureNodeExists(const Key&key);
	const node*findNode(const Key&key)const;
};
template<typename Key,typename Value>
HashMap<Key, Value>::HashMap(int sizeHint){
	if (sizeHint <= 0)
		error("size hint passed to HashMap constructor");
	const = 0;
	numBuckets = sizeHint;
	buckets = new node*[numBuckets];
	for (int i = 0; i < numBuckets; i++)
		buckets[i] = NULL;
}
template<typename Key,typename Value>
HashMap<Key, Value>::~HashMap(){
	for (int i = 0; i < numBuckets; i++)
	{
		node*curr = buckets[i];
		while (curr！ = NULL)
		{
			node*next = curr->next;
			delete curr;
			curr = next;
		}
	}
}
template<typename Key,typename Value>
bool HashMap<Key, Value>::containsKey(const Key& key) const
{
	return findNode(key) != NULL;
}
template<typename Key, typename Value>
void HashMap<Key, Value>::put(const Key&key, const Value&value)
{
	ensureNodeExists(key)->value = value;
}
template<typename Key, typename Value>
Value HashMap<Key, Value>::get(const Key&key)const
{
	const node*found = findNode(key);
	return found == NULL ? Value() : found->value;
}
template<typename Key, typename Value>
Value& HashMap<Key, Value>::operator[](const Key&key)
{
	return ensureNodeExists(key)->value;
}
template<typename Key, typename Value>
int HashMap<Key, Value>::hash(const Key&key)const
{

}
template<typename Key, typename Value>
typename HashMap<Key,Value>::node*
HashMap<Key, Value>::ensureNodeExists(const Key&key)
{
	int hashcod = hash(key);
	node*bucket = buckets[hashcode];
	node*found = const_cast<node*>(findNode(key));
	if (found == NULL)
	{
		found = new node;
		found->key = key;
		found->value = Value();
		fount->next = bucket;
		buckets[hashcode] = found;
		count++;
	}
	return found;
}
template<typename Key, typename Value>
const typename HashMap<Key,Value>::node*
HashMap<Key, Value>::findNode(const Key&key)const{
	int hashcode = hash(key);
	const node*curr = buckckets[hashcode];
	while (curr != NULL && !(curr->key == key))
	{
		curr = curr->next;
	}
	return curr;
}