
 class Solution {
   public static int solve(int i,int j,int [][]grid,int arr[][])
   {
       int r = grid.length;
       int c = grid[0].length;

       if(i<0 || i>=r ||j>=c||j<0)return -1;

       if(i==r-1 && j == c-1)return grid[i][j];
       
        if(arr[i][j]!=-1)return arr[i][j];
       int up     = solve(i,j+1,grid,arr);
       int right  = solve(i+1,j,grid,arr);

       if(up >0 && right>0)
       {
           int ans= grid[i][j];

           if(up>right)
           {
               ans=ans+right;
           }
           else
           {
               ans=ans+up;
           }

           return arr[i][j]= ans;
       }
       else if(up<0 && right<0)
       {
           return arr[i][j]=  -1;
       }
       else if(up<0)
       {
           return arr[i][j]=  grid[i][j]+right;
       }
       else
       {
           return arr[i][j]=  grid[i][j]+up;
       }
       

   }
    public static int minSumPath(int[][] grid) {
    	// Write your code here.

       int r = grid.length;
       int c = grid[0].length;
        int arr[][] = new int[r][c];

        for(int i =0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                arr[i][j]=-1;
            }
        }
        return solve(0,0,grid,arr);
    }
}