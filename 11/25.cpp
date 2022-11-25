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
public:
	Node<T>* head;
	List() : head(NULL) {};
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
void List<T>::insert_at(int idx, const T& data) const{
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
void List<T>::push_back(const T& val) const{
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
    out << tmp -> data;
    tmp = tmp -> next;
    flag = 1;
  }
  return out;
}

int main() {
int array[5] = {1, 2, 4, 5, 6};
int array2[4] = {1, 3, 5, 7};


List<int> li(array, 5);
List<int> li2(array2, 4);
	
//implement here
int li_size = sizeof(array)/sizeof(array[0]);
int li2_size = sizeof(array2)/sizeof(array[0]);

int arr[1] = {0};
List<int> res(arr, 1);
	
int li_idx = 0, li2_idx = 0;
while(true) {
	if(li_idx == li_size && li2_idx == li2_size) break;
	else if(li_idx == li_size && li2_idx < li2_size) {
		res.push_back(array2[li2_idx]);
		li2_idx++;
	}
	else if(li_idx < li_size && li2_idx == li2_size) {
		res.push_back(array[li_idx]);
		li_idx++;
	}
	else if(array[li_idx] <= array2[li2_idx]) {
		res.push_back(array[li_idx]);
		li_idx++;
	}
	else if(array[li_idx] > array2[li2_idx]) {
		res.push_back(array2[li2_idx]);
		li2_idx++;
	}
}
  res.pop_front();

  cout << res << endl; // 1,1,2,3,4,5,5,6,7

  return 0;
}