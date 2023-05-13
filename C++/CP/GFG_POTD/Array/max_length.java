



class max_length
{ 
    long maxPossibleValue(int N, int A[] ,int B[]) { 
        long length=0;
        int minlength  = Integer.MAX_VALUE;
        long  total =0;
        for(int i =0;i<N;i++)
        {
            if(B[i]>1)
            {
                int maxc = B[i]/2;
                
                length += maxc*2*A[i];
                
                if(A[i]<minlength)
                {
                    minlength= A[i];
                }
                total +=maxc;
                
            }
            
            
        }
        
        if(total%2==1)
        {
            length-=minlength*2;
        }
        
        return length;
    }



    public static void main(String args[])
    {
        System.out.println("this is first program running in vs code of the java language");
    }
     
} 

/*

Given two arrays A[] and B[] of same length N. There are N types of sticks of lengths specified. 
Each stick of length A[i] is present in B[i] units (i=1 to N). You have to construct the squares 
and rectangles using these sticks. Each unit of a stick can be used as length or breadth of a 
rectangle or as a side of square. A single unit of a stick can be used only once.

Let S be the sum of lengths of all sticks that are used in constructing squares and rectangles. 
The task is to calulate the maximum possible value of S.

Note: The element in array A[] is always unique.

    Input:
        N = 4
        A[] = {3,4,6,5}
        B[] = {2,3,1,6}
        Output: 
        38
        Explanation: 
        There are 2 sticks of length 3.
        There are 3 sticks of length 4.
        There is a 1 stick of length 6.
        There are 6 sticks of length 5.
        One square can be made using 4 sticks of
        4th kind (5*4=20)
        A rectangle can be made using 2 sticks of 
        4th kind and 2 sticks of 2nd kind (5*2+4*2=18)
        S = 20 + 18 = 38

    Example 2:

    Input:
        N = 1
        A[] = {3}
        B[] = {2}
        Output: 
        0
        Explanation: 
        There are only 2 sticks of length 3 which are 
        not enough to make the square or rectangle.
        */