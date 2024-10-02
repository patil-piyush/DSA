#include <iostream>
using namespace std;

class Node
{
    int data;

public:
    Node *next;
    Node()
    {
        next = 0;
    }
    Node(int d)
    {
        data = d;
        next = 0;
    }
    void read()
    {
        cout << "data: ";
        cin >> data;
    }
    void display()
    {
        cout << "data: " << data << " " << "next: " << next << endl;
    }

    int getdata()
    {
        return data;
    }
};

class list
{
    Node *head;

public:
    list()
    {
        head = nullptr;
    }

    void addAtLast(int d)
    {
        Node *cn;
        Node *nn = new Node(d);
        if (!head)
        {
            head = nn;
        }
        else
        {
            for (cn = head; cn->next != 0; cn = cn->next)
                ;
            cn->next = nn;
        }
    }

    void addAtStart(int d)
    {
        Node *nn = new Node(d);
        if (!head)
        {
            head = nn;
        }
        else
        {
            nn->next = head;
            head = nn;
        }
    }

    void addBet(int d, int pos)
    {
        Node *cn;
        Node *nn = new Node(d);
        cn = head;
        for (int i = 1; i < pos - 1 && cn != nullptr; i++)
        {
            cn = cn->next;
        }
        if (pos == 1)
        {
            nn->next = head;
            head = nn;
        }
        else if (cn == nullptr)
        {
            cout << "Position out of bounds!" << endl;
        }
        else
        {
            nn->next = cn->next;
            cn->next = nn;
        }
    }

    void displayLL()
    {
        Node *cn;
        for (cn = head; cn != 0; cn = cn->next)
        {
            cn->display();
        }
    }

    int countNode()
    {
        int c = 0;
        if (!head)
        {
            return 0;
        }
        else
        {
            Node *cn;
            for (cn = head; cn != 0; cn = cn->next)
                c++;
            return c;
        }
    }

    void insertSortedLL(int d)
    {
        Node *nn = new Node(d);
        Node *cn, *prev;

        if(!head || d < head->getdata()){
            nn->next =head;
            head = nn;
            return;
        }
        else
        {
            for (cn = head; cn != 0; cn = cn->next)
            {
                if(!cn->next){
                    cn->next=nn;
                    return;
                }
                else if (d < cn->getdata())
                {
                    nn->next = prev->next;
                    prev->next = nn;
                    return;
                }
                else{
                    prev = cn;
                }
            }
        }
    }

    int deleteNode(int pos){
        Node *p,*q;
        int x=-1,i;
        if(pos==1){
            p=head;
            head=head->next;
            x=p->getdata();
            return x;
        }
        else{
            p=head;
            q=0;
            for(i=0;i<pos-1;i++){
                
            }
        }
    }
};

int main()
{
    list t;
    t.addAtLast(1);
    t.addAtLast(2);
    t.addAtLast(3);
    t.addAtLast(4);
    t.addAtLast(5);
    t.addAtLast(6);
    t.addAtLast(7);
    
    
    t.displayLL();

    cout << t.countNode() << endl;

    t.insertSortedLL(7);
    t.insertSortedLL(3);
    t.insertSortedLL(3);
    


    t.displayLL();

    return 0;
}