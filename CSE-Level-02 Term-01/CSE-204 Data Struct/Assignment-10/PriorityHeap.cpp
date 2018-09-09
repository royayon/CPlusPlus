#include<iostream>
#include<cstdlib>
using namespace std;
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinPriorityQueue
{
    int *harr;
    int capacity;
    int heap_sz;
public:
    MinPriorityQueue(int _capacity)
    {
        capacity = _capacity;
        heap_sz = 0;
        harr = new int[_capacity];
    }

    void printPQ()
    {
        for(int i=0; i<heap_sz; i++)
        {
            cout<<harr[i]<<" ";
        }
    }

    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }


    void enqueue(int k)
    {
        if(heap_sz == capacity)
        {
            cout<<"Overflowed!!"<<endl;
            return;
        }

        heap_sz++;
        int i = heap_sz-1;
        harr[i] = k;

        while(i!=0 && harr[i] < harr[parent(i)])
        {
            swap(&harr[i] , &harr[parent(i)]);
            i = parent(i);
        }
    }

    int dequeue()
    {
        if(heap_sz == 1)
        {
            heap_sz--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_sz-1];
        heap_sz--;
        MinHeapify(0);

        return root;
    }

    void MinHeapify(int k)
    {
        int l = left(k);
        int r = right(k);
        int smallest = k;

        if(l<heap_sz && harr[l]<harr[k])
        {
            smallest = l;
        }
        if(r<heap_sz && harr[r]<harr[k])
        {
            smallest = r;
        }


        if(smallest != k)
        {
            swap(&harr[smallest],&harr[k]);
            MinHeapify(smallest);
        }
    }

    void heapsort()
    {
        int n=heap_sz;
        for(int i=heap_sz/2-1;i>=0;i--)
        {
            MinHeapify(i);
        }

        for(int i=n-1 ;i>=0;i--)
        {
            swap(&harr[0] , &harr[i]);
            heap_sz--;
            MinHeapify(0);
        }
        heap_sz = n;

    }
};

int main()
{
    int cap;
    cin>>cap;
    MinPriorityQueue minPQ1(cap);


    while(1)
    {
        system("CLS");
        minPQ1.printPQ();
        cout<<endl<<endl;
        cout<<"Menu: 1. EnQueue    2. DeQueue    3.Print    4.Exit.    5.HeapSort"<<endl;
        cout<<"Enter a choice: ";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int k;
            cin>>k;
            minPQ1.enqueue(k);
        }
        else if(ch==2)
        {
            minPQ1.dequeue();
        }
        else if(ch==3)
        {
            minPQ1.printPQ();
        }
        else if(ch==4)
        {
            break;
        }
        else if(ch==5)
        {
            minPQ1.heapsort();
        }

    }
}
