#pragma once
#include "ListNode.h"
template<typename Type> class SingleList {
public:
	SingleList():head(new ListNode<Type>()){}
	~SingleList() {
		makeEmpty();
		delete head;
	}

public:
	void makeEmpty();
	int length();
	ListNode<Type>* find(Type value, int n);
	ListNode<Type>* find(int n);//find the nth data
	bool insert(Type item, int n = 0);
	Type remove(int n = 0);
	bool removeAll(Type item);
	Type get(int n);
	void print();

private:
	ListNode<Type> *head;
};

template<typename Type>
inline void SingleList<Type>::makeEmpty()
{
	ListNode<Type>* pdel;
	while (head->_next!=nullptr)
	{
		pdel = head->_next;
		head->_next = pdel->_next;
		delete pdel;
	}
}

template<typename Type>
inline int SingleList<Type>::length()
{
	ListNode<Type>* pmove = head->_next;
	int count = 0;
	while (pmove != nullptr) {
		pmove = pmove->_next;
		count++;
	}
	return count;
}

template<typename Type>
inline ListNode<Type>* SingleList<Type>::find(Type value, int n)
{
	if (n < 1) {
		std::cout << "the n is illegal" << std::endl;
		return nullptr;
	}
	ListNode<Type>* pmove = head;
	int count = 0;
	while (count!=n&&pmove)
	{
		pmove = pmove->_next;
		if (pmove->_data == value) {//ÖØÔØ²Ù×÷·û
			count++;
		}
	}
	if (pmove == nullptr) {
		std::cout << "cannot find the element" << std::endl;
		return nullptr;
	}
	return pmove;
}

template<typename Type>
inline ListNode<Type>* SingleList<Type>::find(int n)
{
	if (n < 0) {
		std::cout << "the n is out of boundary" << std::endl;
		return nullptr;
	}
	ListNode<Type>* pmove = head->_next;
	for (int i = 0; i < n && pmove; i++) {
		pmove = pmove->_next;
	}
	if (pmove == nullptr) {
		std::cout << "the n is out of boundary" << std::endl;
		return nullptr;
	}
	return pmove;
}

template<typename Type>
inline bool SingleList<Type>::insert(Type item, int n)
{
	if (n < 0)return 0;
	ListNode<Type>* pmove = head;
	ListNode<Type>* pnode = new ListNode<Type>(item);
	if (pnode == nullptr) {
		return 0;
	}
	for (int i = 0; i < n && pmove; i++) {
		pmove = pmove->_next;
	}
	if (pmove == nullptr)return 0;
	pnode->_next = pmove->_next;
	pmove->_next = pnode;
	return 1;
}

template<typename Type>
inline Type SingleList<Type>::remove(int n)
{
	if (n < 0) {
		exit(1);
	}
	ListNode<Type>* pmove = head, * pdel;
	for (int i = 0; i < n && pmove->_next; i++) {
		pmove = pmove->_next;
	}
	if (pmove->_next == NULL)exit(1);
	pdel = pmove->_next;
	pmove->_next = pdel->_next;
	Type temp = pdel->_data;
	delete pdel;
	return temp;
}

template<typename Type>
inline bool SingleList<Type>::removeAll(Type item)
{
	ListNode<Type>* pmove = head;
	ListNode<Type>* pdel = head->_next;
	while (pdel!=nullptr)
	{
		if (pdel->_data == item) {
			pmove->_next = pdel->_next;
			delete pdel;
			pdel = pmove->_next;
			continue;
		}
		pmove = pmove->_next;
		pdel = pdel->_next;
	}
	return 1;
}

template<typename Type>
inline Type SingleList<Type>::get(int n)
{
	if (n < 0)exit(1);
	ListNode<Type>* pmove = head->_next;
	for (int i = 0; i < n; i++) {
		pmove = pmove->_next;
		if (nullptr == pmove)exit(1);
	}
	return pmove->_data;
}

template<typename Type>
inline void SingleList<Type>::print()
{
	ListNode<Type>* pmove = head->_next;
	std::cout << "head";
	while (pmove) {
		std::cout << "->" << pmove->_data;
		pmove = pmove->_next;
	}
	std::cout << "->over" << std::endl << std::endl;
}

