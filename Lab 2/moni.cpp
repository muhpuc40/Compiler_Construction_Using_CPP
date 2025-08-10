#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int N,K,L,temp;
cout<<" Enter the number of elements:<<end1";
    cin>>N;
    int PTR[N];
    cout<<" Enter "<<N<<" elements" <<endl;
    for(K=0;K<N;K++)
    {
        cin>>PTR[K];
    }
    {
        for(K=0;K<N-1;K++)
        for(L=0;L<N-K-1;L++)
        if (PTR[L] >PTR [L+1])
        {
            temp=PTR[L];
            PTR[L]=PTR[L+1];
            PTR[L+1]=temp;
        }
        for(K=0;K<N;K++)
        {
            cout<<PTR[K]<<" ";
        }
    }
    getch ();
}
