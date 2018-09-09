#include<iostream>
using namespace std;

struct node{
    int value;
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
        node *newItm=new node;
        newItm->value=x;
        newItm->next=NULL;

        if(head==NULL)
        {
            head=newItm;
            tail=newItm;
        }
        else
        {
            tail->next=newItm;
            tail=newItm;
        }
    }
    void displayList()
    {
        node *newItm=new node;
        newItm=head;
        if(head==NULL)
        {
            cout<<"List is Empty!!"<<endl;
            return;
        }
        while(1)
        {
            if(newItm->next!=NULL)
            {
                cout<<newItm->value<<" ";
                newItm=newItm->next;
            }
            else if(newItm->next==NULL)
            {
                cout<<newItm->value<<" ";
                break;
            }
        }
    }
    void insertFirst(int x)
    {
        node *newItm=new node;
        newItm->value=x;
        newItm->next=NULL;

        newItm->next=head;
        head=newItm;
    }
    void insertLast(int x)
    {
        node *newItm=new node;
        newItm->value=x;
        newItm->next=NULL;

        tail->next=newItm;
        tail=newItm;
    }
    void insertMiddle(int aftr,int x)
    {
        node *newItm=new node;
        newItm->value=x;
        newItm->next=NULL;

        node*prev=new node;
        prev=head;
        while(prev->value!=aftr)
        {
            if(prev->next==NULL)
            {
                cout<<"Element is not In the List!! "<<endl;
                break;
            }
            prev=prev->next;
        }


        newItm->next= prev->next;
        prev->next=newItm;
    }
    void deleteFirst()
    {
        if(head->next!=NULL)
            head=head->next;
        else
            head=NULL;
    }
    void deleteLast()
    {
        node *prev=new node;
        node *aftr=new node;
        aftr=head;
        prev->next=NULL;
        while(aftr->next!=NULL)
        {
            prev=aftr;
            aftr=aftr->next;
        }
        tail=prev;
        prev->next=NULL;
        aftr->next=NULL;

    }
    void deleteMiddle(int aftr)
    {
        node *prev=new node;
        prev=head;
        while(1)
        {
            if(prev->value!=aftr && prev->next!=NULL)
            {
                prev=prev->next;
            }
            else if(prev->value!=aftr &&prev->next==NULL)
            {
                cout<<"Element is not in the LIST!!"<<endl;
                return;
            }
            else if(prev->value==aftr)
            {
                break;
            }
        }
        prev->next = prev->next->next;
    }
};


int main()
{
    List l1;
    int inf=1;
    while(inf)
    {
        cout<<"\nMenu: "<<endl;
        cout<<endl;
        cout<<"1. Create Link List."<<endl;
        cout<<"2. Display List."<<endl;
        cout<<"3. Insert First."<<endl;
        cout<<"4. Insert Last."<<endl;
        cout<<"5. Insert Middle."<<endl;
        cout<<"6. Delete First."<<endl;
        cout<<"7. Delete Last."<<endl;
        cout<<"8. Delete Middle."<<endl;
        cout<<"9. Quit."<<endl;
        cout<<""<<endl;


        cout<<"Enter a Choice: "<<endl;
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Enter a node: "<<endl;
            int val;
            cin>>val;

            l1.createList(val);
        }else if(choice==2){
            cout<<"Your List is: "<<endl;
            l1.displayList();

        }else if(choice==3){
            cout<<"Enter a node to insert First: "<<endl;
            int val;
            cin>>val;

            l1.insertFirst(val);

        }else if(choice==4){
            cout<<"Enter a node to insert Last: "<<endl;
            int val;
            cin>>val;

            l1.insertLast(val);

        }else if(choice==5){
            cout<<"Enter the node value to insert After: "<<endl;
            int aftr;
            cin>>aftr;

            cout<<"Enter a node to insert After: "<<endl;
            int val;
            cin>>val;

            l1.insertMiddle(aftr,val);


        }else if(choice==6){
            l1.deleteFirst();

        }else if(choice==7){
            l1.deleteLast();

        }else if(choice==8){
            cout<<"Enter the value to delete After: "<<endl;
            int aftr;
            cin>>aftr;

            l1.deleteMiddle(aftr);

        }else if(choice==9){
            inf=0;
        }
    }
}
