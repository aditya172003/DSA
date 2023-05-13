#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;

/*

// Q 1 ] bubble sort


void bubble_sort(int *arr,int n)
{
	int flag=0;
	
	for(int i =1;i<n&&flag==0;i++)
	{   flag=1;
		for(int j=0;j<n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=0;
			}
		}
	}
}

// Q 2 ] insertion sort 


void insertion_sort(int * arr,int n)
{
	for(int i =1;i<n;i++)
	{
		int temp =arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			
				arr[j+1]=arr[j];
				j--;
				
		}
		arr[j+1]=temp;
	}
}

///             main function for Q 1 and Q 2 

int main()
{
	int n =75000;
	
	int *arr=new int[n];
	srand(time(NULL));
	for(int i =0;i<n;i++)
	{
		//arr[i]=n-i;
		//arr[i]=rand()%100;
		arr[i]=i;
	}
     	
 //bubble_sort(arr,n);
 
 cout<<endl;
 insertion_sort(arr,n);
 

 cout<<endl;
    cout<<"Done"<<endl;
    
    return 0;
}
 

*/




/*


1.Create an array of n integers.Sort it in acending order using modified bubble sort.
Test it for best,average and worst case for following values of n.
n=10000
n=25000
n=50000
n=75000



2.
Create an array of n integers.Sort it in acending order using insertion sort.
Test it for best,average and worst case for following values of n.
n=10000
n=25000
n=50000
n=75000

*/




/*

3.
Scan 8 citynames from user.Sort these citynames in descending order using any of the 3 sorts.
(selection,bubble or insertion).
(Use 2-D array of characters to store 8 citynames or you can use array of pointers).


4.  

Scan 8 students names from user.Scan one more name from user.Check if that name is present in 
the list of names.


*/



/*
void char_sort_selection(char *arr[],int n)
{
	for(int i =0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{ 
			if(strcmp((arr[i]),(arr[j]))==1)
			{
				
				char *p=new char[30];
				strcpy(p,(arr[i]));
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],p);
				
			}
		}
	}

//    char * p=new char[30];
//    strcpy(p,arr[1]);
//    cout<<p;
//    cout<<strcmp((arr[1]),(arr[2]))<<endl;
//  
    
}

int search_name(char *name,char*arr[],int n)
{
	for(int i =0;i<n;i++)
	{
		if(strcmp(arr[i],name)==1)
		{
			return 0;
		}
		if(strcmp(arr[i],name)==0)
		{
			return 1;
		}
	}
	return 0;
}





  // Main function for  Q 3 ] and Q 4 ]  



int main()
{  
    int n=5;
    
    
	char *arr[n];

	
	for(int i =0;i<n;i++)
	{
		arr[i]=new char [30];
		cin>>arr[i];
		
	}
	
	char_sort_selection(arr,n);
	
	for(int i =0;i<n;i++)
	{
		cout<<arr[i]<<" ";
		
	}

char * p =new char[30];
cin>>p;
cout<<search_name(p,arr,n);
	cout<<endl;
}


*/


/*

 5 . WAP to search a number from an array of n integers using binary search.
6.WAP to search a number from an array of n integers using recursive binary search.
7.Create an array of n integers.Search a number given by user in an array using sentinel search.
8.Compare the time required to search an element in an array of n integers by using binary search 
and by using linear search in sorted array.(use worst case.Note time required to search for
different values of n.n = 10000,25000,50000).
 
 
*/ 



 int binary_search(int *arr,int low,int high ,int key)
 {
 	while(low<=high)
 	{
 		int mid=(low+high)/2;
 		
 		if(arr[mid]<key)
 		{
 			low=mid+1;
		 }
	   else	if(arr[mid]>key)
		
		{
			high=mid-1;
		}
		else
		{
			return 1;
		}
	 }
	 return 0;
 }


int rec_binary_search(int *arr ,int l,int h,int k)
{
	if(l>h)
	{
		return 0;
		
	}
	int mid =(l+h)/2;
		int p=arr[mid];
	if(p==k)
	{
		return 1;
	}

	
	if(p>k)
	{
	return	rec_binary_search(arr,l,mid-1,k);
	}
	
	else
	{
	return	rec_binary_search(arr,mid+1,h,k);
	}
		
	
}

	int sentinal_search(int *arr,int n,int key)

	{
		int temp =arr[n-1];
		arr[n-1]=key;
		int i =0;
		while(arr[i]!=key)
		{
			i++;
		}
		
		arr[n-1]=temp;
		if(i<n-1||temp==key)
		{
			return 1;
			
		}
		
		return 0;
	}

	int linear_search(int *arr,int n,int k)
	{
		for(int i =0;i<n && arr[i]<=k ;i++)
		{
			if(arr[i]==k)
			{
				return 1;
			}
		}
		return 0;
	}


/*


// main function for  Q 5 ,6, 7 ;
int  main()
{   int n;
    cin>>n;
	int *arr=new int[n];
	for(int i =0;i<n;i++)
	{
		int p;
		cin>>p;
		arr[i]=p;
	}
	int z;
	cin>>z;
	cout<<binary_search(arr,0,n-1,z)<<endl;
	cout<<rec_binary_search(arr,0,n-1,z)<<endl;
	cout<<sentinal_search(arr,n,z)<<endl;
}


*/

/*

Q ] 8 


binary search 
10000 - 0.01 sec to search 5000 
25000 - 0.015 sec to search 20000
75000 - 0.015 to search 70000
*/

/*
linear search 

10000 - 0.015 sec  to search 5000
25000 - 0.016 to search 20000
75000 - 0.017 to search 70000
*/
/*

int main()
{
	int n=75000;
	int *arr=new int[n];
	for(int i =1;i<=n;i++)
   {
   	arr[i-1]=i;
   	
   }
 
	cout<<binary_search(arr,0,n-1,70000)<<endl;
	//cout<<linear_search(arr,n,70000)<<endl;
}
*/




/*

9.Create a database of 6 students containing name and roll number.Scan a name from user.
Check if that name is present in the array or not.Use linear search.
(Use array of objects here.Do not use linked list).

*/


/*

class Student
{
    public:
       char name[30];
       int roll;
    
};

int search(Student *arr,char*p)


{
     for(int i =0;i<6;i++)
     {
           if(strcmp(arr[i].name,p)==0)
           {
            return 1;
           }
     }

     return 0;
     
}

int main()
{
    Student st[6];
      
    for(int i =0;i<6;i++)
    {  cout<<"Enter the name :"<<endl;
        cin>>st[i].name;

        cout<<"Enter the roll number :"<<endl;
        cin>>st[i].roll;
        

    }


    cout<<"Enter the name to search "<<endl;
    char n[30];
    cin>>n;
    cout<<search(st,n)<<endl;
}



*/




/*
10.Create a database of Employee containing name,hometown and age.Sort it in descending order using
modified bubble sort.Print whole list of Employee.
*/


/*

class Employee
{
    public:
    char name[30];
    char home[30];
    int age;
};


void  bubble_sort(Employee *arr,int n)
{
    for(int i =1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j].age<arr[j+1].age)
            {
                Employee temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }

}


int main()
{  
    int n;
    cout<<"Enter the number of employee "<<endl;
    cin>>n;

    Employee *em=new Employee[n];


    for(int i =0;i<n;i++)
    {
        cout<<"Name of the employee"<<endl;
        cin>>em[i].name;
        cout<<"Enter the home town"<<endl;
        cin>>em[i].home;
        cout<<"Enter the age of employee"<<endl;
        cin>>em[i].age;
    }

    bubble_sort(em,n);

    
    for(int i =0;i<n;i++)
    {                                     
        cout<<"Name of the employee : "<<em[i].name<<endl;
                                        
        cout<<"Enter the home town : "<<em[i].home<<endl;
                                            
        cout<<"Enter the age of employee : "<<em[i].age<<endl;

        cout<<"________________________________________________"<<endl;                            
    }



}

*/