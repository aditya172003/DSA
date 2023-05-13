#include <bits/stdc++.h>

using namespace std;

class heap
{
private:
    int arr[100];
    int size;

public:
    heap()
    {
        size = 0;
    }

    void Insert_heap(int k)
    {
        size++;
        int index = size;
        arr[index] = k;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // downadjust function

    void downAdijust(int i)
    {
        while (2 * i <= size)
        {
            int j = 2 * i;
            if (2 * i + 1 <= size)
            {
                if (arr[j] < arr[j + 1])
                {
                    j++;
                }
            }
            //  j is now index of largest child  

            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
                i = j;
            }
            else
            {
                return ;
            }
        }
    }


    void Delete_first()
    {
        if(size==0)
        {
            cout<<"heap is empty"<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        downAdijust(1);
    }

    void Print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
};


// downAdjust function is a heapify function

void Heapify_max(int *arr,int i,int n)
{
    while(2*i<=n)
    {
        int j=2*i;
        if(j+1<=n)
        {
            if(arr[j]<arr[j+1])
            {
                j++;
            }
        }

        // j is index of largest child 

        if(arr[i]<arr[j])
        {
            swap(arr[i],arr[j]);
            i=j;
        }
        else
        {
            return;
        }
    }
}

// this is for 0 th indexing heap 

void heapify_min(int *arr,int i ,int n)
{
    
    while((2*i+1)<n)
    {
        int j=(2*i+1);
        if((j+1)<n)
        {
            if(arr[j]>arr[j+1])
            {
                j++;
            }
        }

        // j is index of largest child 

        if(arr[i]>arr[j])
        {
            swap(arr[i],arr[j]);
            i=j;
        }
        else
        {
            return;
        }
    }
    
}


void heap_sort(int *arr,int n)
{
    int a=n;
    for(int i=1;i<=n;i++)
    {
        swap(arr[1],arr[n]);
     
        n--;
        Heapify_max(arr,1,n);
    }
}



// is complete binary  tree or not 



int main()
{
    int a;
    heap h1;

    int arr[6];

    for (int i = 0; i < 5; i++)
    {
        cout << " : ";
        cin >> a;
        h1.Insert_heap(a);
    }
    
    h1.Print();
     cout<<endl;
    cout<<"Deletion "<<endl;
    h1.Delete_first();
    h1.Print();


    cout<<".............Heapify ................"<<endl;

    for(int i =1;i<=6;i++)
    {
        cout<<" :";
        cin>>a;
        arr[i]=a;
    }

    cout<<"array "<<endl;

       for(int i =1;i<=6;i++)
    {
        cout<<arr[i]<<" ";
       
    }
    cout<<endl;

    // convert it into heap

    for(int i =6/2;i>=1;i--)
    {
        Heapify_max(arr,i,6);
    } 
   
    heap_sort(arr,6);
    cout<<"array is converted into heap "<<endl;

        for(int i =1;i<=6;i++)
    {
        cout<<arr[i]<<" ";
       
    }

    cout<<endl;
}






void sub_array(vector<int>vec,vector<int>ans,priority_queue<int>&pq)
{
    
}