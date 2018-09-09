#include<iostream>
using namespace std;

struct node{
    int value;
    struct node *next;
};

class List
{
  struct node*head;
  struct node*tail;
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
          newItm->next=NULL;
      }
      else
      {
          tail->next=newItm;
          newItm->next=NULL;
          tail=newItm;
      }
  }
  void displayList()
  {
      node *prev=new node;
      prev=head;
      cout<<"Value of the Node "<<"\tAddress of the Node "<<"\tAddress of the Next Node "<<endl;
      while(prev!=NULL)
      {
          cout<<"\t"<< prev->value <<"\t\t"<< prev <<"\t\t"<< prev->next <<endl;
          prev=prev->next;
      }
  }
    void average()
    {
        node *prev=new node;
        int sum=0;
        int cnt=0;
        prev=head;
        while(prev!=NULL)
        {
            sum+=prev->value;
            cnt++;
            prev=prev->next;
        }
        float avg=sum/cnt;
        cout<<"Average is: "<<avg<<endl;
    }
    int occurSearch(int x)
    {
        node *prev=new node;
        int cnt=0;
        prev=head;
        int flag=0;
        while(prev!=NULL)
        {

            if(prev->value==x)
            {
                cnt++;
                cout<<x<<" is found in The Addresss: ";
                cout<<prev<<endl;
                flag=1;
            }
            prev=prev->next;
        }
        if(flag)
            cout<<x<<" is found "<<cnt<<" times."<<endl;
        else
            cout<<x<<" is not found "<<endl;

    }
};


int main()
{
    List l1;
    int inf=1;
    while(inf)
    {
        cout<<"\na. Insert."<<endl;
        cout<<"b. Display."<<endl;
        cout<<"c. Average."<<endl;
        cout<<"d. Search and Occurance."<<endl;
        cout<<"e. Quit."<<endl;

        char ch;
        cin>>ch;
        if(ch=='a')
        {
            int val;
            cin>>val;
            l1.createList(val);
        }
        else if(ch=='b')
        {
            l1.displayList();

        }
        else if(ch=='c')
        {
            l1.average();
        }
        else if(ch=='d')
        {
            int s;
            cin>>s;
            l1.occurSearch(s);
        }
        else if(ch=='e')
        {
            inf=0;
            break;
        }

    }

}
