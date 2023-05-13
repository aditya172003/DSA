#include<iostream>
#include<string>
#include<map>


using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        map<string,bool>mp;
        int ans =1;

         string sp;
        for(int i =2;i<n;i++)
        {
           if(s[i]!=s[i-2] || (s[i-1]!=s[i+1] && s[i]!=s[i-2]))
           {
               ans++;
           }
            

            
        }

        cout<<ans<<endl;
    }
}

/*
Dmitry has a string s
, consisting of lowercase Latin letters.

Dmitry decided to remove two consecutive characters from the string s
 and you are wondering how many different strings can be obtained after such an operation.

For example, Dmitry has a string "aaabcc". You can get the following different strings
: "abcc"(by deleting the first two or second and third characters), "aacc"(by deleting 
the third and fourth characters),"aaac"(by deleting the fourth and the fifth character) 
and "aaab" (by deleting the last two).


----------------------------------------------------------------------------------------\
=========================================================================================
Input
The first line of input data contains a single integer t
 (1≤t≤104
) — number of test cases.

The descriptions of the test cases follow.

The first line of the description of each test case contains an integer n
 (3≤n≤2⋅105
).

The second line of the description of each test case contains a string s
 of length n
 consisting of lowercase Latin letters.

It is guaranteed that the sum of n
 for all test cases does not exceed 2⋅105
.

Output
For each test case print one integer — the number of distinct strings that can be obtained by removing two consecutive letters.

*/