#include "ListNode.h"

template<typename Type>
std::ostream& operator<< (std::ostream& os, ListNode<Type>& out){
	os << out._data;
	return os;
}