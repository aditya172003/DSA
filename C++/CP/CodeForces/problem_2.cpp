#include<iostream>
#include<queue>

using namespace std;

#define ll long long  int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll ans =0;
        priority_queue<ll>pq;

        ll n;
        cin>>n;
        for(int i =0;i<n;i++)
        {
                ll d;
                cin>>d;
                if(d==0)
                {
                    if(!pq.empty())
                    {
                        ans +=pq.top();
                        pq.pop();
                    }
                }else{
                    pq.push(d);
                }
                

        }
        cout<<ans<<endl;
    }
}

/*
    There is a deck of n
    cards, each of which is characterized by its power. There are two types of cards:

    a hero card, the power of such a card is always equal to 0
    ;
    a bonus card, the power of such a card is always positive.
    You can do the following with the deck:

    take a card from the top of the deck;
    if this card is a bonus card, you can put it on top of your bonus deck or discard;
    if this card is a hero card, then the power of the top card from your bonus deck is added to his power (if it is not empty), after that the hero is added to your army, and the used bonus discards.
    Your task is to use such actions to gather an army with the maximum possible total power.

    Input
    The first line of input data contains single integer t
    (1≤t≤104
    ) — the number of test cases in the test.

    The first line of each test case contains one integer n
    (1≤n≤2⋅105
    ) — the number of cards in the deck.

    The second line of each test case contains n
    integers s1,s2,…,sn
    (0≤si≤109
    ) — card powers in top-down order.

    It is guaranteed that the sum of n
    over all test cases does not exceed 2⋅105
    .

    Output
    Output t
    numbers, each of which is the answer to the corresponding test case — the maximum possible total power of the army that can be achieved.

*/