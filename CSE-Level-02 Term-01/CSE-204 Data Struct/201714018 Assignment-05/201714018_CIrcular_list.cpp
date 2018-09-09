#include<iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
};

class CircularList
{
    struct node *last;
public:
    CircularList()
    {
        last=NULL;
    }
    void emptyList(int x)
    {
        if(last!=NULL)
            return;
        node *newNode=new node;
        newNode->value=x;
        newNode->next=NULL;

        last=newNode;
        last->next=last;
    }
    void insertFirst(int x)
    {
        if(last==NULL)
            return emptyList(x);
        node *newNode=new node;

        newNode->value=x;
        newNode->next=NULL;

        newNode->next = last->next;
        last->next=newNode;
    }
    void insertLast(int x)
    {
        if(last==NULL)
            return emptyList(x);
        node *newNode=new node;
        newNode->value=x;
        newNode->next=NULL;

        newNode->next=last->next;
        last->next=newNode;
        last=newNode;
    }
    void insertMiddle(int aftr,int x)
    {
        if(last==NULL)
            return emptyList(x);

        node *prev=new node;
        prev=last->next;
        do
        {
            if(prev->value==aftr)
            {
                node *newNode=new node;
                newNode->value=x;
                newNode->next=NULL;

                newNode->next=prev->next;
                prev->next=newNode;

                if(prev==last)
                    last=newNode;
                return;
            }
            prev=prev->next;
        }while(prev!=last->next);
        cout<<"Element is not in the LIST!!"<<endl;
        return;
    }
    void deleteFirst()
    {
        if(last==NULL)
            return;
        if(last->next != last)
            last->next=last->next->next;
        else if(last->next == last)
            last=NULL;
    }
    void deleteLast()
    {
        if(last==NULL)
            return;
        node *prev=new node;
        prev=last->next;
        if(last->next != last)
        {
            do
            {
                prev=prev->next;
            }while(prev->next != last);
            prev->next=last->next;
            last=prev;
        }
        else if(last->next != last)
        {
            last=NULL;
        }

    }
    void deleteMiddle(int aftr)
    {
        if(last==NULL)
            return;
        node *prev=new node;
        prev=last->next;

        do
        {
            if(prev->value==aftr)
            {
                prev->next=prev->next->next;
                return;
            }
            prev=prev->next;
        }while(prev!=last->next);
        cout<<"Element is not in the LIST!!"<<endl;
        return;
    }
    void displayCircularList()
    {
        if(last==NULL)
        {
            cout<<"List is Empty!!"<<endl;
            return;
        }
        node *prev=new node;
        prev=last->next;
        do
        {
            cout<<prev->value<<" ";
            prev=prev->next;
        }while(prev!=last->next);
    }
};


int main()
{
    CircularList cl1;
    int inf=1;
    while(inf)
    {
        cout<<"\nMenu: "<<endl;
        cout<<endl;
        cout<<"1. Create Circular Link List."<<endl;
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

            cl1.emptyList(val);
        }else if(choice==2){
            cout<<"Your List is: "<<endl;
            cl1.displayCircularList();

        }else if(choice==3){
            cout<<"Enter a node to insert First: "<<endl;
            int val;
            cin>>val;

            cl1.insertFirst(val);

        }else if(choice==4){
            cout<<"Enter a node to insert Last: "<<endl;
            int val;
            cin>>val;

            cl1.insertLast(val);

        }else if(choice==5){
            cout<<"Enter the node value to insert After: "<<endl;
            int aftr;
            cin>>aftr;

            cout<<"Enter a node to insert After: "<<endl;
            int val;
            cin>>val;

            cl1.insertMiddle(aftr,val);


        }else if(choice==6){
            cl1.deleteFirst();

        }else if(choice==7){
            cl1.deleteLast();

        }else if(choice==8){
            cout<<"Enter the value to delete After: "<<endl;
            int aftr;
            cin>>aftr;

            cl1.deleteMiddle(aftr);

        }else if(choice==9){
            inf=0;
        }
    }
}
