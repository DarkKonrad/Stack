#pragma once
#include "iStack.h"
#include <stdexcept>

#define DllExport   __declspec( dllexport )

template <class Type>
class Stack : public iStack<Type>
{
	static const unsigned int oneElement;
	Type* arrayOfElements;

	// Size - eg. size may be equal to 20 and elements count be 5
	// therafore we can store 15 more elements 

	unsigned int _size;
	unsigned int elementsCount;

	bool constSize;

	void ResizeAlloc(unsigned int newSize);
	void InitStack();

public:

	Stack();
	Stack(unsigned int size, bool constSize = false);
	~Stack() { delete[] arrayOfElements; }

	bool HasConstSize();
	
	//Overrides
	int size() override;

	void clear() override;

	void push(Type item) override;
	bool isEmpty() override;

	Type pop() override;
	Type peek() override;

};


template<class Type>
inline int Stack<Type>::size()
{
	return this->_size;
}

template<class Type>
inline void Stack<Type>::clear()
{
	delete[] arrayOfElements;
	InitStack();
}

template<class Type>
inline void Stack<Type>::push(Type item) 
{
	if (HasConstSize() )
	{
		if( _size < (elementsCount + oneElement))
			throw std::out_of_range("Stack Overflow");

		this->arrayOfElements[elementsCount++] = item;
	}
	else
	{
		if (_size < (elementsCount + oneElement))
			ResizeAlloc(elementsCount + oneElement);

		this->arrayOfElements[elementsCount++] = item;
	}

}

template<class Type>
inline bool Stack<Type>::isEmpty()
{
	return (this->elementsCount == 0);
}

template<class Type>
inline Type Stack<Type>::pop()
{
	if (elementsCount <= 0)
		throw std::out_of_range("There are no elements in the stack");
	
	Type itemToReturn;

	if (HasConstSize())
	{
		itemToReturn = this->arrayOfElements[--elementsCount];
	}
	else
	{
		itemToReturn = this->arrayOfElements[--elementsCount];
		ResizeAlloc(elementsCount);
	}
	
	return itemToReturn;
}

template<class Type>
inline Type Stack<Type>::peek() 
{
	if (elementsCount <= 0)
		throw std::out_of_range("There are no elements in the stack");

	return this->arrayOfElements[elementsCount - 1];
}

template<class Type>
void Stack<Type>::InitStack()
{
	this->constSize = false;
	this->_size = 0;
	this->arrayOfElements = nullptr;
	this->elementsCount = 0;
}

template<class Type>
Stack<Type>::Stack() 
{
	InitStack();
}

template<class Type>
Stack<Type>::Stack(unsigned int size, bool constSize) : _size(size), constSize(constSize), elementsCount(0)
{
	if (size <= 0)
		throw std::out_of_range("Size of Stack cannot be less than '1' ");

	this->arrayOfElements = new Type[size];
}

template<class Type>
void Stack<Type>::ResizeAlloc(unsigned int newSize)
{
	if (newSize <= 0)
	{
		delete[] this->arrayOfElements;
		this->arrayOfElements = nullptr;
		this->_size = 0;
	}


	Type* arOfElBuff = this->arrayOfElements;
	this->arrayOfElements = new Type[newSize];
	
	unsigned int elementsToCopyCount = 0;

	if (this->elementsCount <= newSize)
		elementsToCopyCount = this->elementsCount;
	else
		elementsToCopyCount = newSize;

	for (unsigned int i = 0; i < elementsToCopyCount; i++)
	{
		this->arrayOfElements[i] = arOfElBuff[i];
	}

	this->_size = newSize;

	// Warning 
	delete[] arOfElBuff;
}

template<class Type>
bool Stack<Type>::HasConstSize()
{
	return this->constSize;
}

template<class Type>
const unsigned int Stack<Type>::oneElement = 1;
