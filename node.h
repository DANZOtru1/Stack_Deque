#pragma once
//������ ������ � ��������� �� ���� �������
//������������ ��� ����� mstack � ������� mqueue
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename sTYPE>
class Node {
public:
	sTYPE data;
	Node *next;
	Node *prev; //������������ ��� ����
	Node(sTYPE value) : data(value), next(nullptr), prev(nullptr)
	{}
};

#endif // NODE_H