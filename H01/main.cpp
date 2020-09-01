/*
Name:       Marquise Blue
Course:     CMPS 21433 OOP
Date:       8/29/20
Professor:  Dr. Griffin
Assignment: Going over this cpp file and putting your own             comments where it is neccessary
*/

#include <iostream>

using namespace std;
//global variable/array type
int A[100];

//struct called Node and its for the pointers
struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};
//class called List
class List
{
  //acces speciifer only used in the class
  private:
    Node *Head;
    Node *Tail;
    int Size;
  //access specifier that can be used outside of the class
  public:
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val)
    {
        // allocate new memory and new node
        Node *Temp = new Node(val);

        //temp will go to the head of the list then it will count how many integers are in the list

        Temp->next = Head;
        Head = Temp;

        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
	//void function to print to tail
    void PrintTail()
    {
        cout << Tail->x << endl;
    }
	//printing the entire list
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented 
    int Pop()
    {
        Size--;
        return 0; // didnt implement but always good to have
    }

    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }
	//printing the list to the screen
    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

//main function
int main(int argc, char **argv)
{
	//two different lists
    List L1;
    List L2;

    for (int i = 0; i < 25; i++)
    {
		//pushing numbers less than 25 to the list
        L1.Push(i);
    }
	//pushing 50 to 99 into the second list
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

	//making a 3rd list and adding List 1 and list 2
    List L3 = L1 + L2;
    cout << L3 << endl;

	//printing out the the array 5th selection of list 3
    cout << L3[5] << endl;
    return 0;
}
