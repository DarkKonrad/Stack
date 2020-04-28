// Stack_UnOrganized.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

#include "DynamicArrayStack.h"
#include "LinkedListStack.h"
#include "iStack.h"


#ifdef _DEBUG
#define Write(element) std::cout << element << std::endl;
#define Write_ex(message, element) std::cout << message << " " <<element <<std::endl;

#else // DEBUG
#define Write(element) 
#define Write_ex(message, element) 

#endif

using namespace std;


// Strange Behaviour. Observed that typeid in void simpleTest(iStack<int>* st) 
// works only with void simpleTest(iStack<int>& st) conterpount. 

void simpleTest(iStack<int>& st)
{
	/*string message("SimpleTest for: ");
	message += typeid(st).name();

	Write(message);*/

	Write_ex("SimpleTest for: ", typeid(st).name());

	Write(st.isEmpty());
	//Write(st.HasConstSize());
	Write_ex("Size: ", st.size());
	st.push(4);
	st.push(9);
	st.push(1);

	Write_ex("Size: ", st.size());
	Write_ex("Peek: ", st.peek());
	st.push(0);

	Write_ex("Size: ", st.size());
	Write_ex("Peek: ", st.peek());
	Write_ex("Pop: ", st.pop()); //0
	Write_ex("Pop: ", st.pop()); // 1
	Write_ex("Pop: ", st.pop()); // 9
	Write_ex("Size: ", st.size());
	Write_ex("Pop: ", st.pop()); //4
	Write_ex("Size: ", st.size());
}


void simpleTest(iStack<int>* st)
{


	Write_ex("SimpleTest for: ", typeid(*st).name());

	Write(st->isEmpty());
	//Write(st->HasConstSize());
	Write_ex("Size: ", st->size());
	st->push(4);
	st->push(9);
	st->push(1);

	Write_ex("Size: ", st->size());
	Write_ex("Peek: ", st->peek());
	st->push(0);

	Write_ex("Size: ", st->size());
	Write_ex("Peek: ", st->peek());
	Write_ex("Pop: ", st->pop()); //0
	Write_ex("Pop: ", st->pop()); // 1
	Write_ex("Pop: ", st->pop()); // 9
	Write_ex("Size: ", st->size());
	Write_ex("Pop: ", st->pop()); //4
	Write_ex("Size: ", st->size());
}


template<class Type>
void addElement_testMethod(iStack<Type>* st, Type element, unsigned int* outPutBuffer = nullptr)
{
	st->push(element);
	if (outPutBuffer != nullptr)
		(*outPutBuffer)++;
}


void measureMaxElements_IntTest(iStack<int>* st)
{
	unsigned int result = 0;

	Write_ex("MeasureMaxElements_IntTest for: ", typeid(*st).name());
	
	for (unsigned int i=0 ;; i++)
	{
		try
		{
			addElement_testMethod<int>(st, i, &result);
			Write_ex("Element pushed: ", st->peek());
		}
		catch (exception & ex)
		{
			Write_ex("Exception Occured", ex.what());
			return;
		}

	}


}

void stackOperationEffectivity_Test(iStack<int>* st, unsigned int maxNumber)
{
	unsigned int result = 0;
	chrono::steady_clock::time_point begin,end,overallBegin;

	Write_ex("stackOperationEffectivity_Test for: ", typeid(*st).name());

	overallBegin = chrono::steady_clock::now();
	begin = chrono::steady_clock::now();
	for (unsigned int i = 0;i < maxNumber; i++)
	{
		try
		{
			st->push(i);
		}
		catch (exception & ex)
		{
			Write_ex("Exception Occured", ex.what());
			return;
		}

	}

	end = chrono::steady_clock::now();
	auto timeDifference = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
	Write_ex("Push Operations have taken: " + to_string(timeDifference), "milliseconds");

	begin = chrono::steady_clock::now();
	for (unsigned int i = 0; i < maxNumber; i++)
	{
		try
		{
			st->pop();
		}
		catch (exception & ex)
		{
			Write_ex("Exception Occured", ex.what());
			return;
		}

	}
	end = chrono::steady_clock::now();
    timeDifference = chrono::duration_cast<chrono::microseconds>(end - begin).count();
	Write_ex("Pop Operations have taken: " +  to_string(timeDifference), "milliseconds");

	end = chrono::steady_clock::now();
	timeDifference = chrono::duration_cast<chrono::microseconds>(end - overallBegin).count();
	Write_ex("Overall time for both push and pop opertaions have taken: " + to_string(timeDifference), "milliseconds");
}

void stdStackOperationEffectivity_Test(unsigned int maxNumber)
{
	stack<int>* st = new stack<int>();
	unsigned int result = 0;
	chrono::steady_clock::time_point begin, end, overallBegin;

	Write("stackOperationEffectivity_Test for: std::stack");

	overallBegin = chrono::steady_clock::now();
	begin = chrono::steady_clock::now();
	for (unsigned int i = 0; i < maxNumber; i++)
	{
		try
		{
			st->push(i);
		}
		catch (exception & ex)
		{
			Write_ex("Exception Occured", ex.what());
			return;
		}

	}

	end = chrono::steady_clock::now();
	auto timeDifference = chrono::duration_cast<chrono::microseconds>(end - begin).count();
	Write_ex("Push Operations have taken: " + to_string(timeDifference), "milliseconds");

	begin = chrono::steady_clock::now();
	for (unsigned int i = 0; i < maxNumber; i++)
	{
		try
		{
			st->pop();
		}
		catch (exception & ex)
		{
			Write_ex("Exception Occured", ex.what());
			return;
		}

	}
	end = chrono::steady_clock::now();
	timeDifference = chrono::duration_cast<chrono::microseconds>(end - begin).count();
	Write_ex("Pop Operations have taken: " + to_string(timeDifference), "milliseconds");

	end = chrono::steady_clock::now();
	timeDifference = chrono::duration_cast<chrono::microseconds>(end - overallBegin).count();
	Write_ex("Overall time for both push and pop opertaions have taken: " + to_string(timeDifference), "milliseconds");

	delete st;
}

int main()
{
#ifdef _DEBUG

	unsigned int testElementNumber = 100000;

	DynamicArrayStack<int>* dynArrStack = new DynamicArrayStack<int>();
	LinkedListStack<int>* listStack = new LinkedListStack<int>();

	simpleTest(dynArrStack);
	Write("");
	simpleTest(listStack);

	dynArrStack->clear();
	listStack->clear();

	//measureMaxElements_IntTest(dynArrStack);
	Write("");
	stackOperationEffectivity_Test(dynArrStack, testElementNumber);
	Write("");
	stackOperationEffectivity_Test(listStack, testElementNumber);
	Write("");
	stdStackOperationEffectivity_Test(testElementNumber);
	Write("");

	Write("Press any key to terminate program");
	getchar();

	delete dynArrStack, listStack;

#endif // DEBUG


	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
