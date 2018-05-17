#pragma once
#ifndef MSTACK_H
#define MSTACK_H

#include "node.h"

template <typename sTYPE>
class mstack {
private:
	Node<sTYPE> *top; //указатель на низ стека
public:
	int size = 0;
	mstack() : top(nullptr)
	{}
	void push(sTYPE);
	void pop(); //удаление эл из стека
	void print();
	sTYPE r_end();
	~mstack();
};

template <typename sTYPE>
void mstack<sTYPE>::push(sTYPE value) {
	if (top == nullptr) {
		top = new Node<sTYPE>(value);
	}
	else {
		Node<sTYPE>* q = new Node<sTYPE>(value);
		q->next = top;
		top = q;
	}
	size++;
}

template <typename sTYPE>
void mstack<sTYPE>::pop() {
	if (top == nullptr) {
		std::cout << "\n ERROR: Stack is empty " << "\n";
		return;
	}
	Node<sTYPE>* q = top;
	top = top->next;
	size--;
	delete q;
}

template <typename sTYPE>
sTYPE mstack<sTYPE>::r_end() {
	return top->data;
}

template <typename sTYPE>
void mstack<sTYPE>::print() {
	Node<sTYPE>* q = top;
	while (q) {
		std::cout << " " << q->data;
		q = q->next;
	}
	std::cout << "\n Stack size is " << size << "\n";
}


template <typename sTYPE>
mstack<sTYPE>::~mstack() {
	while (size>0) {
		pop();
	}
}
#endif // MSTACK_H