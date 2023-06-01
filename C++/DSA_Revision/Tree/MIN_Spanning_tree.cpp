// minimum spanning tree   Prims Algorithms 

#include<iostream>


#include<bits/stdc++.h>
using namespace std;





class Graph
{
    private:

        int vertices;
        int **adj_matrix;

    public:
        Graph()
        {
            vertices=0;
        }

        void Initialize(int n)
        {
            vertices =n+1;
            n++;
            adj_matrix = new int*[n];
            for(int i =0;i<n;i++)
            {
                adj_matrix[i] = new int[n];
            }
        }


        void create()
        {
            cout<<"Enter the connected vertices and weight"<<endl;
            // do changes here if graph is directed 

            // code is considering graph is undirected

            int u,v,w;
            int end =vertices*(vertices-1)/2;
            for(int i =0;i<end;i++)
            {
                cout<<"Enter -1 to stop"<<endl;
                cout<<"Enter node numbers :"<<endl;
                cout<<"u :";
                cin>>u;

                if(u==-1)
                {
                    return ;
                }

                cout<<"v :";
                cin>>v;
                cout<<"Enter the weight :";
                cin>>w;

                adj_matrix[u][v]=w;

                // add condition here if graph is directed 
                adj_matrix[v][u]=w;

            }
        }


        void ShowAdj_Matrix()
        {
            for(int  i = 0 ;i<vertices;i++)
            {   
                for(int j=0;j<vertices;j++)
                {
                    cout<<adj_matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }



        // PRIMS ALGORITHM

        
        int getSmaller(int **arr)
        {   
            int min  =INT_MAX;
            int index;
            for(int i =0;i<vertices;i++)
            {
                if(arr[i][0]==-1 && min >arr[i][1])
                {
                    index = i;
                    min = arr[i][1];
                }
                
            }


            return index;

            
        }

        void Prims()
        {
            int**ans;
            ans =new int*[vertices];
            // 0 - visitd : 1 - weight : 2 -parent :
            int**visited = new int*[vertices];
            for(int i =0;i<vertices;i++)
            {
                ans[i]=new int[vertices];
                visited[i]=new int[3];
                visited[i][0]=-1;
                visited[i][1]=INT_MAX;
            }


            int span_edg=0;
            // if you want to start from i th vertices then change 0 to i;
            visited[0][1]=0;
            
            while(span_edg<=vertices-1)
            {
                int ind = getSmaller(visited);
                visited[ind][0]=1;

                for(int i =0;i<vertices;i++)
                {
                    if(adj_matrix[ind][i]!=0 && visited[i][0]==-1 && visited[i][1]>adj_matrix[ind][i])
                    {
                        visited[i][1]=adj_matrix[ind][i];
                        visited[i][2]=ind;
                    }
                }
                span_edg++;

            }

            int wt=0;
            cout<<"Minimum spanning graph"<<endl;
            for(int i =0;i<vertices;i++)
            {
                wt+=visited[i][1];
                cout<<" u= "<<i<<" - v= "<<visited[i][2]<<" - w= "<<visited[i][1]<<endl;
            }

            cout<<" The Weight of minimum spanning tree = "<<wt<<endl;

        }





        void Kruskal_Algorithms()
        {
            vector<int>check(vertices,0);

            // This is the first step towards kruskals algorithm 
            // used to check loop in graph

            for(int i =0;i<vertices;i++)
            {
                check[i]=i;
            }

            vector<vector<int>>nodes;
             
            // 0 - weight : 1 - u  : 2 - j
             

            for(int i =0;i<vertices;i++)
            {   
                for(int j=0;j<vertices;j++)
                {
                      
                      if(adj_matrix[i][j]!=0)
                      {
                        vector<int>vec(3);
                        vec[1]=i;
                        vec[2]=j;
                        vec[0]=adj_matrix[i][j];
                        nodes.push_back(vec);


                      }
                  
                }
            }


            // 2nd step is to dort node array accordingly to the weight 
            vector<vector<int>>ans;
            sort(nodes.begin(),nodes.end());


            int n=0;


            // kruskaqls alforighm

            for(int k=0;k<nodes.size();k++)
            {
                if(check[nodes[k][1]] !=check[nodes[k][2]])
                {
                    if(n==vertices-1)return ;
                    ans.push_back(nodes[k]);
                      n++;
                    int chn = check[nodes[k][1]];
                  
                  // path compression 
                    for(int i =0;i<vertices;i++)
                    {
                        if(chn==check[i])check[i]=check[nodes[k][2]];
                    }

                }

            }



            for(int i =0;i<ans.size();i++)
            {
                cout<<" u= "<< ans[i][1]<<" "<<" v= " <<ans[i][2]<<" "<<" w= " <<ans[i][0]<<endl;
            }
        }




};







int main()
{
    Graph g;
    g.Initialize(5);
    g.create();
    g.ShowAdj_Matrix();
    g.Prims();
    g.Kruskal_Algorithms();
}   