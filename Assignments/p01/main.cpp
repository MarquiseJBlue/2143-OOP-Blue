///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Marquise Blue
// Email:            mjblue0512@my.msutexas.edu
// Label:            P01
// Title:            Array Based Stack
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       implementation of an array based stack that holds integers.
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

/**
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *
 */
class Stack {
private:
	int* S;       //array pointer
	int capacity; //max stack size
	int top;      //current top (index)
	int size;     //current num items

public:

	/**
	 * Stack:
	 *    Constructor.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     Void
	 */
	Stack() {
		capacity = 10;          // set array size
		S = new int[capacity];  // allocate new memory
		top = -1;               // initialize top of stack
		size = 0;               // set stack to empty
	}

	/**
	 * Stack:
	 *    Constructor.
	 * Params:
	 *    int : capacity
	 *
	 * Returns:
	 *     Void
	 */
	Stack(int cap) {
		capacity = cap;         // set array size      
		S = new int[capacity];  // allocate new memory
		top = -1;               // initialize top of stack
		size = 0;               // set stack to empty
	}

	/**
	 * Push:
	 *    Push item onto stack.
	 * Params:
	 *    int : data
	 *
	 * Returns:
	 *     Void
	 */
	void Push(int data) {
		top++;              // move top of stack up
		size++;             // increment size
		S[top] = data;      // add item to array
	}

	/**
	 * Pop:
	 *    remove item from stack.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     int
	 */
	int Pop() {
		int data = S[top];  // pull item from stack
		top--;              // shrink the stack
		size--;             // update our size
		return data;        // send item back
	}

	/**
	 * Empty:
	 *    is the stack empty?
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     bool : true == stack is empty
	 */
	bool Empty() {
		if (Pop() == -1)
		{
			cout << "Error:Stack empty!\n";
		}

		return top == -1;

	}

	/**
	 * Full:
	 *    is the stack full?
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     bool : true == stack is full
	 */

	bool Full() {
		//giving s2 list a 2x the capacity size as the first one

		if (top == capacity - 1)
		{
			int* S2 = new int[2 * capacity];


			for (int i = 0; i < size; i++)
			{
				S2[i] = S[i];
			}

			delete[] S;    //delete the old array (S)
		}

		return top == capacity - 1;
	}

	/**
	 * Print:
	 *    Used so we can inspect our stack.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     void
	 */
	void Print() {
		for (int i = top; i >= 0; i--) {
			cout << S[i] << endl;

		}
	}


	int count()
	{
		return (top + 1);
	}
};


int main() {
	Stack S1;           // calls default constructor
	Stack S2(25);       // calls overloaAded constructor
	int max_size = -INT64_MAX;
	int starting = S2.count();
	string command;
	int value;
	ifstream infile;
	infile.open("input.txt");

	cout << "Name: Marquise Blue" << endl;
	cout << "Program: P01" << endl;
	cout << "Date: 9/11/2020\n";


	while (!infile.eof()) {
		infile >> command;           // read push or pop  
		//cout << command << " ";


		if (command == "push") {  // if command is a push we need
			infile >> value;      // to read a value in as well
			//cout << value;
			S2.Push(value);
		}
		else {
			S2.Pop();
		}

		max_size = max(max_size, S2.count());
		cout << endl;
	}
	cout << "The counting functions:\n";
	cout << "Starting  " << starting << endl;
	cout << "Max  " << max_size << endl;
	cout << "Current " << S2.count() << endl;

	system("pause");
	return 0;
}
