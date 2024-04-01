//C++ 
#include <bits/stdc++.h> 
using namespace std;
int a(int n){
    if(n<=1) return n;
    return a(n-1) + a(n-2);
}
int main() 
{ 
    int n;
    cin>>n;
    cout<<a(n-1);
    return 0;
}
