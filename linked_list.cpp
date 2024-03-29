
#include "linked_list.h"
#include <stdexcept>
#include <iostream>

template <typename T> 
void LinkedList<T>::push_back(T item){
	Node<T> *n = new Node<T>;
	n->data = item;
	numItems++;
	
	if(head == nullptr){
		head = n;
		tail = n;
		return;
	}

	tail->next = n;
	n->prev = tail;
	tail = n;	
}


template <typename T>
void LinkedList<T>::push_front(T item){
	Node<T> *n = new Node<T>;
	n->data = item;
	numItems++;

	if(head == nullptr){
		head = n;
		tail = n;
		return;
	}

	head->prev = n;
	n->next = head;
	head = n;
}


template <typename T>
T LinkedList<T>::at(size_t idx){
	if(idx >= numItems){
		throw std::invalid_argument("List index out of range: " + std::to_string(idx));
	}

	Node<T> *n = get_node(idx);
	return n->data;
}

template <typename T>
Node<T> *LinkedList<T>::get_node(size_t idx){

	size_t i = 0;
	Node<T> *cur = head;
	while(i < idx){
		cur = cur->next;
		i++;
	}

	return cur;
}

template <typename T>
void LinkedList<T>::insert(size_t pos, T item){

	Node<T> *n = get_node(pos);
	Node<T> *newNode = new Node<T>;
	
	newNode->data = item;

	if (n == head){
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else if (n == tail){
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else{
		newNode->prev = n->prev;
		newNode->next = n;
		n->prev = newNode;
	}

}


