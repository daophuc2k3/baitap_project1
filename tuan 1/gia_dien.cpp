//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
	int n;
	double tong1, tong2;
	cin>>n;
	if(n<=50) tong1 = n*1728;
	else if(n<=100) tong1 = 50*1728 + (n-50)*1786;
	else if(n<=200) tong1 = 50*1728 + 50*1786 + (n-100)*2074;
	else if(n<=300) tong1 = 50*1728 + 50*1786 + 100*2074 + (n-200)*2612;
	else if(n<=400) tong1 = 50*1728 + 50*1786 + 100*2074 + 100*2612 + (n-300)*2919;
	else tong1 = 50*1728 + 50*1786 + 100*2074 + 100*2612 + 100*2919 + (n-400)*3015;
	
	if(n<=100) tong2 = n*1728;
	else if(n<=200) tong2 = 100*1728 + (n-100)*2074;
	else if(n<=400) tong2 = 100*1728 + 100*2074 + (n-200)*2612;
	else if(n<=700) tong2 = 100*1728 + 100*2074 + 200*2612 + (n-400)*3111;
	else tong2 = 100*1728 +  100*2074 + 200*2612 + 300*3111 + (n-700)*3457;
	
	double chenhlech = tong2 - tong1;
	
	cout<< fixed << setprecision(2) <<chenhlech*1.1<<endl;
	return 0;
}  
