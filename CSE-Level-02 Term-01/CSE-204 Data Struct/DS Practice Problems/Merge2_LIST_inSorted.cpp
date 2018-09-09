#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class List
{
    struct node *head;
    struct node *tail;
public:
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void createList(int x)
    {
        node *newNode=new node;
        newNode->data=x;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    void displayList()
    {
        node *prev=new node;
        prev=head;
        if(head==NULL)
        {
            cout<<"List is Empty!!"<<endl;
            return;
        }
        while(prev != NULL)
        {
            cout<<prev->data<<" ";
            prev=prev->next;
        }
    }
    /*void merge_2List_InSorted(List l2)
    {
        merge_2List(l2);
        List_Sort();
    }*/
    void merge_2List(List l2)
    {
        this->tail->next = l2.head;
        this->tail = l2.tail;
    }
    void List_Sort()
    {
        node *prev1=new node;
        node *prev2=new node;
        int temp;

        prev1=prev2=head;

        while(prev1!=NULL)
        {
            while(prev2!=NULL)
            {
                if(prev1->data < prev2->data)
                {
                    temp=prev1->data;
                    prev1->data=prev2->data;
                    prev2->data=temp;
                }
                prev2=prev2->next;
            }
            prev2=head;
            prev1=prev1->next;
        }



    }


};

int main()
{
    List l1;
    l1.createList(10);
    l1.createList(20);
    l1.createList(30);
    l1.createList(40);
    l1.createList(50);
    l1.createList(60);

    cout<<"L1==>>   ";
    l1.displayList();

    cout<<endl;

    List l2;
    l2.createList(20);
    l2.createList(30);
    l2.createList(40);
    l2.createList(50);
    l2.createList(60);
    l2.createList(70);

    cout<<"L2==>>   ";
    l2.displayList();

    cout<<endl;

    cout<<"MergedWithSort:";
    l1.merge_2List(l2);
    l1.displayList();

    l1.List_Sort();
    cout<<"L1==>>   ";
    l1.displayList();

}
