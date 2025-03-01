
// Reverse linked list using function

#include <iostream>
#include <vector>
using namespace std;

class NODE
{
public:
    int data;
    NODE *next;

    NODE(int value)
    {
        data = value;
        next = NULL;
    }
};

// function to create linked list
NODE *createlinkedlist(vector<int> &a, int index, int size)
{
    if (size == index) // for the last node
        return NULL;

    NODE *temp = new NODE(a[index]);
    temp->next = createlinkedlist(a, index + 1, size); // using recursive call to create linked list
    return temp;
}

// function to reverse linked list
void reverse(NODE *HEAD)
{
    vector<int> temp;

    while (HEAD != NULL) // copy the data part into the vector till the last node
    {
        temp.push_back(HEAD->data);
        HEAD = HEAD->next;
    }

    int n = temp.size();
    for (int i = n - 1; i >= 0; --i)
        cout << temp[i] << " ";
}

// function to display linked list
void display(NODE *HEAD)
{
    while (HEAD) // HEAD!=NULL, until head is not null
    {
        cout << HEAD->data << " ";
        HEAD = HEAD->next; // head points to the next of the head
    }
}
int main()
{
    NODE *HEAD = NULL;
    vector<int> a = {1, 2, 3, 4, 5};

    int size = a.size();
    int index = 0;

    // create a linked list if list is not existing
    if (HEAD == NULL)
        HEAD = createlinkedlist(a, index, size);

    reverse(HEAD); // call to reverse the linked list and display

    // display(HEAD); // call to display linked list
    return 0;
}
