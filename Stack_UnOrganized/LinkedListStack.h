#pragma once

#include <list>
#include "iStack.h"

template<class Type> 
class LinkedListStack : public iStack<Type>
{
private:
	std::list<Type> container;

public:

	LinkedListStack() {}

	unsigned int size() override;

	void clear() override;
	void push(Type item) override;
	
	bool isEmpty() override;

	Type pop() override;
	Type peek() override;

};

template<class Type>
inline unsigned int LinkedListStack<Type>::size()
{
	 return this->container.size();
}

template<class Type>
void LinkedListStack<Type>::clear()
{
	this->container.clear();
}

template<class Type> 
void LinkedListStack<Type>::push(Type type)
{
	this->container.push_back(type);
}

template<class Type>
bool LinkedListStack<Type>::isEmpty()
{
	return this->container.empty();
}

template<class Type>
Type LinkedListStack<Type>::pop()
{
	auto value = this->container.back();
	this->container.pop_back();

	return value;
}

template<class Type>
Type LinkedListStack<Type>::peek()
{
	 return this->container.back();	
}
