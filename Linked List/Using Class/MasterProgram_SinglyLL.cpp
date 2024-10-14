class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    private:
    Node *head;
    public:
    LinkedList();
    LinkedList(int data);
    void Display();
    void Delete(int pos);
    int count();
    void InsertNode(int index, int value);
    void ReverseLL_Array();
    void ReverseLL_Pointer();
    void ReverseLL_Recursion();
    bool isSorted();
    int min();
    int max();
    int sum();
    void RemoveDuplicates();
    void MergeLL(LinkedList &T);
    void Concatinate(LinkedList &T);
};

