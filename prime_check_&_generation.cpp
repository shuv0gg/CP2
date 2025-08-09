#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if(n<2)return false;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    cout<<"Enter the number to check prime:";
    cin>>n;
    if (is_prime(n)) cout << n << " is Prime\n";
    else cout << n << " is Not Prime\n";
    cout<<"Primes up to"<<n<<":";
    for(int i=2;i<=n;i++)
    {
        if(is_prime(i))
        {
            cout<<i<<" ";
        }
    }

}
