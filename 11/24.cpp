#include <iostream>

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* next;
};

template <class T>
class List {
private:
	Node<T>* head;
public:
	List() : head(NULL) { };
	~List(); //free resources
	List(T* arr, int n_nodes); //create a list with n_nodes
	void insert_at(int idx, const T& data) const;
	void remove_at(int idx);
	void pop_back();
	void push_back(const T& val) const;
	void pop_front();
	void push_front(const T& val);
    template <class T_>
	friend ostream& operator<<(ostream& out, List<T_>& rhs); //print out nodes
};

template <class T>
List<T>::~List() {
	Node<T> *next = head;
  Node<T> *now = NULL;

  while(next != NULL) {
    now = next;
    next = next -> next;
    delete now;
  }
  delete next;
}

template <class T>
List<T>::List(T* arr, int n_nodes) {
  head = new Node<T>;
	Node<T>* node = this -> head;
	for (int i = 0; i < n_nodes; i++) {
		node -> data = arr[i];
		if (i == n_nodes - 1)
			node -> next = NULL;
		else {
			node -> next = new Node<T>;
			node = node -> next;
		}
	}
}

template <class T>
void List<T>::insert_at(int idx, const T& data) const {
	Node<T>* prev_node = head;
	Node<T>* node = new Node<T>;
	Node<T>* last_node = head;
	node -> data = data;
	for (int i = 0; i < idx - 1; i++) {
		prev_node = prev_node -> next;
		last_node = last_node -> next;
	}
	last_node = last_node -> next;
	prev_node -> next = node;
	node -> next = last_node;
}

template <class T>
void List<T>::remove_at(int idx) {
	Node<T>* temp_node = head;
	Node<T>* delete_node;
	Node<T>* swap_node;

	if (idx != 0) {
		for (int i = 0; i < idx - 1; i++)
		temp_node = temp_node -> next;
		delete_node = temp_node -> next;
		swap_node = delete_node -> next;
		temp_node -> next = swap_node;
	}
	else {
		head = temp_node -> next;
		delete_node = temp_node;
	}
	delete delete_node;
}

template <class T>
void List<T>::pop_back() {
	Node<T>* prev_node = this -> head;
	Node<T>* delete_node = this -> head;
	if (prev_node -> next == NULL)
		delete this -> head;
	else {
		while (delete_node -> next -> next) {
			prev_node = prev_node -> next;
			delete_node = delete_node -> next;
		}
		delete_node = delete_node -> next;
		prev_node -> next = NULL;
		delete delete_node;
	}
}

template <class T>
void List<T>::push_back(const T& val) const {
	Node<T>* new_node = new Node<T>;
	new_node -> data = val;
	new_node -> next = NULL;
	Node<T>* iter = this -> head;
	while (iter -> next)
		iter = iter -> next;
	iter -> next = new_node;
}

template <class T>
void List<T>::pop_front() {
	Node<T>* delete_node = this -> head;
	head = head -> next;
	delete delete_node;
}

template <class T>
void List<T>::push_front(const T& val) {
	Node<T>* new_node = new Node<T>;
	new_node -> data = val;
	new_node -> next = this -> head;
	this -> head = new_node;
}

template <class T>
ostream& operator<<(ostream& out, List<T>& rhs) {
  Node<T> *tmp = rhs.head;
  bool flag = 0;
  while (tmp != nullptr) {
    if(flag) out << ", ";
    out << tmp->data;
    tmp = tmp->next;
    flag = 1;
  }
  return out;
}

int main() {
	int array[5] = {12, 7, 9, 21, 13};
	List<int> li(array, 5);
	cout << li << endl; //12,7,9,21,13

	li.pop_back();
	cout << li << endl; //12,7,9,21

	li.push_back(15);
	cout << li << endl; //12,7,9,21,15

	li.pop_front();
	cout << li << endl; //7,9,21,15

	li.push_front(8);
	cout << li << endl; //8,7,9,21,15

	li.insert_at(4, 19);
	cout << li << endl; //8,7,9,21,19,15

	li.remove_at(1);
	cout << li << endl; //8,9,21,19,15
    
	return 0;
}