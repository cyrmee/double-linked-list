#include <iostream>
#include <new>
using namespace std;

template <typename type>
struct node {
	type data;
	node<type> * prev;
	node<type> * next;
};

template <typename type>
class List {
public:
	List (); // default constructor
	// List (bool sorted); // other constructor
	List (node<type> * srcHead); // copy constructor. it is used when you create a new object from existing List object
	virtual ~List (); //destructor

	bool isEmpty ();
	void display ();
	void insertFirst (type data);
	void insertLast (type data);

	void removeFirst ();
	void removeLast ();
	void empty ();

	node<type> * find (type data);
	List<type> copy (List<type> src);
	node<type> * getHead () { return head; }
	node<type> * getTail () { return tail; }

	int count;
protected:
	node<type> * head;
	node<type> * tail;
private:
	bool sorted; //whether the list is sorted or not
};

template <typename type>
List<type>::List () {
	count = 0;
}

template <typename type>
List<type>::List (node<type> * srcHead) {
	while (srcHead != NULL) {
		insertLast (srcHead->data);
		srcHead = srcHead->next;
	}
}

// Checks if a List is Empty
template <typename type>
bool List<type>::isEmpty () {
	return head == NULL;
}

// Makes a List Empty
template <typename type>
void List<type>::empty () {
	node<type> * p;
	while (head != NULL) {
		p = head;
		head = head->next;
		delete p;
	}
	head = tail = NULL;
}

// List Destructing Function
template <typename type>
List<type>::~List () {
	List<type>::empty ();
}

// List Displaying Fuction
template <typename type>
void List<type>::display () {
	node<type> * p;
	p = head;
	while (p) {
		cout << p->data;
		p = p->next;
	}
}

template <typename type>
void List<type>::insertFirst (type data) {
	node<type>* p, *before;
	p = new node<type>;
	if (!p) return; //no memory for the new node
	p->data = data;
	p->next = p->prev = NULL;
	if (head == NULL) {
		//list is empty. inset the node as the the only node
		head = tail = p;
		count++;
	}
	else {
		before = head;
		p->next = before;
		head = before->prev = p;
		count++;
	}
}

template <typename type>
void List<type>::insertLast (type data) {
	node<type>* p;
	p = new node<type>;
	if (!p) return; //no memory for the new node
	p->data = data;
	p->next = p->prev = NULL;
	if (head == NULL) {
		//list is empty. inset the node as the the only node
		head = tail = p;
		count++;
	}
	else {
		p->prev = tail;
		tail = tail->next = p;
		count++;
	}
}

template <typename type>
void List<type>::removeFirst () {
	if (head == NULL) return;
	node<type> * p; //node to delete
	p = head;
	if (p == NULL) return;
	if (head == tail) { //removing only node
		head = tail = NULL;
		count = 0;
	}
	else { //removing first node
		p->next->prev = NULL;
		head = p->next;
		count--;
	}
	delete p;
}

template <typename type>
void List<type>::removeLast () {
	if (head == NULL) return;
	node<type> * p; //node to delete
	p = tail;
	if (p == NULL) return;
	if (head == tail) { //removing only node
		head = tail = NULL;
		count = 0;
	}
	else { //removing first node
		p->prev->next = NULL;
		tail = p->prev;
		count--;
	}
	delete p;
}

template <typename type>
node<type> * List<type>::find (type data) {
	node<type> * p;
	p = head;
	while (head != NULL) {
		if (p->data == data) break;
		p = p->next;
	}
	return p;
}

//template <typename type>
//List<type> List<type>::copy () {
//	List<type> temp;
//	while (head != NULL) {
//		temp.insertLast (head->data);
//		head = head->next;
//	}
//	return temp;
//}

int main () {
	List<char> list;
	list.insertLast ('1');
	list.insertLast ('2');
	list.insertLast ('3');
	list.display ();

	cout << endl;
	List<char> lst (list.getHead ());
	lst.display ();

	cout << endl;
	system ("pause");
}