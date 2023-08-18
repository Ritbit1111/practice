//{ Driver Code Starts
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    void printList(Node *n)
    {
        while (n)
        {
            cout << n->data << " -> ";
            n = n->next;
        }
        cout << endl;
    }
    struct Node *makeUnion(struct Node *head1, struct Node *head2)
    {
        // code here
        return mergeSortedInPlaceLL(head1, head2);
    }

    struct Node *mergeSortedLL(struct Node *head1, struct Node *head2)
    {
        struct Node *n1 = head1;
        struct Node *n2 = head2;
        struct Node *ans = NULL;
        if (n1->data > n2->data)
        {
            ans = new Node(n2->data);
            n2 = n2->next;
        }
        else
        {
            ans = new Node(n1->data);
            n1 = n1->next;
        }
        struct Node *ansHead = ans;
        while (n1 && n2)
        {
            int d1 = n1->data;
            int d2 = n2->data;
            if (d1 < d2)
            {
                n1 = n1->next;
                if (ans->data < d1)
                {
                    ans->next = new Node(d1);
                    ans = ans->next;
                }
            }
            else
            {
                n2 = n2->next;
                if (ans->data < d2)
                {
                    ans->next = new Node(d2);
                    ans = ans->next;
                }
            }
            printList(ansHead);
        }
        if (n1)
            ans->next = n1;
        if (n2)
            ans->next = n2;
        return ansHead;
    }

    struct Node *mergeSortedInPlaceLL(struct Node *head1, struct Node *head2)
    {
        struct Node *ans = new Node(0);
        struct Node *ansHead = ans;
        while (head1 && head2)
        {
            int d1 = head1->data;
            int d2 = head2->data;
            if (d1 < d2)
            {
                ans->next = head1;
                head1 = head1->next;
            }
            else
            {
                ans->next = head2;
                head2 = head2->next;
            }
            ans = ans->next;
        }
        if (head1)
            ans->next = head1;
        if (head2)
            ans->next = head2;
        return ansHead->next;
    }
};


struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n = 4, m = 3;

        // cin>>n;
        Node *first = buildList(n);

        // cin>>m;
        Node *second = buildList(m);
        Solution obj;
        Node *head = obj.makeUnion(first, second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends