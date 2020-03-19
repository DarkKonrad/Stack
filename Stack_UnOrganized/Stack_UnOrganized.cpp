// Stack_UnOrganized.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"
#include "iStack.h"

#ifdef _DEBUG
#define Write(element) std::cout << element << std::endl;
#define Write_ex(message, element) std::cout << message << element <<std::endl;

#else // DEBUG
#define Write(element) 
#define Write_ex(message, element) 

#endif

using namespace std;
int main()
{
	/*Stack<int> st;*/
	
	//Write(st.isEmpty());
	//Write(st.HasConstSize());
	//Write_ex("Size: ", st.size());
	//st.push(4);
	//st.push(9);
	//st.push(1);
	//Write_ex("Size: ",st.size());
	//Write_ex("Peek: ",st.peek());
	//st.push(0);
	//Write_ex("Size: ", st.size());
	//Write_ex("Peek: ", st.peek());
	//Write_ex("Pop: ",st.pop()); //0
	//Write_ex("Pop: ", st.pop()); // 1
	//Write_ex("Pop: ", st.pop()); // 9
	//Write_ex("Size: ", st.size());
	//Write_ex("Pop: ", st.pop()); //4
	//Write_ex("Size: ", st.size());

	
	Stack<int> st(5, true);
	Write(st.isEmpty());
	Write(st.HasConstSize());
	Write_ex("Size: ", st.size());
	st.push(4);
	st.push(9);
	st.push(1);
	Write_ex("Size: ",st.size());
	Write_ex("Peek: ",st.peek());
	st.push(0);
	Write_ex("Size: ", st.size());
	Write_ex("Peek: ", st.peek());
	Write_ex("Pop: ",st.pop()); //0
	Write_ex("Pop: ", st.pop()); // 1
	Write_ex("Pop: ", st.pop()); // 9
	Write_ex("Size: ", st.size());
	Write_ex("Pop: ", st.pop()); //4
	Write_ex("Size: ", st.size());

	getchar();
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
