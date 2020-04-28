#pragma once

/// Interface Stack 
template <class Type>
class iStack
{
	
	//Methods
public:
	virtual	unsigned int size()=0;

	virtual	void clear()=0;

	virtual void push(Type item)=0;
	virtual bool isEmpty()=0;

	virtual Type pop()=0;
	virtual Type peek()=0;

};