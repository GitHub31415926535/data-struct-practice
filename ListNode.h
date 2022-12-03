#pragma once
#include <iostream>

template<typename Type> class SingleList;

template<typename Type> class ListNode {
private:
	friend typename SingleList<Type>;

	ListNode():_next(NULL){}
	ListNode(const Type item, ListNode<Type> *next = nullptr):_data(item), _next(next){}
	~ListNode() {
		_next = nullptr;
	}
public:
	Type getData();
	friend std::ostream & operator<< (std::ostream& os, ListNode<Type>& out);

private:
	Type _data;
	ListNode *_next;
};

template<typename Type>
inline Type ListNode<Type>::getData()
{
	return this->_data;
}

//template<typename Type>
//std::ostream& operator<< (std::ostream& os, ListNode<Type>& out){
//	os << out._data;
//	return os;
//}
