#pragma once
#include <iostream>
//顺序表
const int DefaultSize = 100;

template <class T> class Seqlist
{
public:
	Seqlist(int sz = DefaultSize)
		:_max_size(sz), _cur_size(0) {
		if (sz > 0)
			_elements = new T[_max_size];
	}

	~Seqlist() {
		delete[] _elements;
	}

	int length() const {
		return _cur_size;
	}

	int find(T x) const;

	int isElement(T x) const;

	int insert(T x, int i);

	bool remove(T x);

	bool isEmpty() {
		return _cur_size == 0;
	}

	int isFull() {
		return _cur_size == _max_size;
	}

	T get(int x) {//get element whose pos is i
		return (x<0 || x>= _cur_size)? (std::cout << "cann't find the element" << std::endl, 0): _elements[x];
	}

	void print();

private:
	T* _elements;
	const int _max_size;
	int _cur_size;

	std::string _cannot_find{ "cann't find the element" };
};

template<class T>
int Seqlist<T>::find(T x) const
{
	for (int i = 0; i < _cur_size; i++) {
		if (_elements[i] == x)return i;
	}
	std::cout << "cann't find the element" << std::endl;
	return -1;
}

template<class T>
int Seqlist<T>::isElement(T x) const
{
	if (find(x) == -1)return 0;
	return 1;
}

template<class T>
int Seqlist<T>::insert(T x, int i)
{
	if (i<0 || i>_cur_size || _cur_size == _max_size - 1) {
		std::cout << "the operate is illegal" << std::endl;
		return 0;
	}
	_cur_size++;
	for (int j = _cur_size; j > i; j--) {
		_elements[j] = _elements[j - 1];
	}
	_elements[i] = x;
	return 1;
}

template<class T>
bool Seqlist<T>::remove(T x) {//删除首次出现的元素,返回bool
	if (find(x) != -1) {
		for (int i = find(x); i < _cur_size; i++) {
			_elements[i] = _elements[i + 1];
		}
		_cur_size--;
		return true;
	}
	return false;
}

template<class T>
void Seqlist<T>::print()
{
	for (int i = 0; i <= _cur_size - 1; i++) {
		std::cout << i + 1 << ":\t" << _elements[i] << std::endl;
	}
	std::cout << std::endl << std::endl;
}