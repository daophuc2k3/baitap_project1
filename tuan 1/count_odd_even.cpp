//C/C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int le = 0, chan = 0;
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0) chan++;
        else le++;
    }
    cout<<le<<" "<<chan;
    return 0;
}
