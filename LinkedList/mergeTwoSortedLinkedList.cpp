#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    for (; head; head = head->next)
        cout << head->data << "->";
    cout << "NULL" << endl;
}

Node *solve(Node *first, Node *second)
{
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    Node *curr1 = first;
    Node *curr2 = second;
    Node *forward1 = first->next;
    Node *forward2 = second->next;

    while (forward1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= forward1->data)
        {
            curr1->next = curr2;
            forward2 = curr2->next;
            curr2->next = forward1;
            curr1 = curr2;
            curr2 = forward2;
        }
        else
        {
            curr1 = forward1;
            forward1 = forward1->next;
            if (forward1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node *mergeTwoSortedLinkedList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data <= head2->data)
        return solve(head1, head2);
    else
        return solve(head2, head1);
}

int main()
{
    Node *head1 = new Node(1);
    Node *tail1 = head1;
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 4);
    print(head1);

    Node *head2 = new Node(1);
    Node *tail2 = head2;
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);
    print(head2);

    Node *head = mergeTwoSortedLinkedList(head1, head2);
    print(head);
    return 0;
}