#include <bits/stdc++.h>
using namespace std;
int n,t,b;
struct st{
	string pr;
	int ar,tm;
	bool operator<(const st &p)const{
		return ar<p.ar;
	}
}a[100];
int main(){
	cout<<"Number of Process : ";
	cin>>n;
	cout<<"ATime CPUtime"<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<<": ";
		cin>>t>>b;
		string s="p";
		int ii=i+1;
		s+=(ii+'0');
		a[i].pr=s;
		a[i].ar=t;
		a[i].tm=b;
	}
	sort(a,a+n);
	cout<<endl<<"Id\tATime\tCPUtime"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i].pr<<"\t"<<a[i].ar<<"\t"<<a[i].tm<<endl;
	}
	int nw=a[0].ar;
	double Ans=0;
	for(int i=0;i<n;i++){
		//~ cout<<nw<<endl;
		if(nw>a[i].ar) Ans+=(nw-a[i].ar);
		nw+=a[i].tm;
	}
	cout << fixed << setprecision(4) << "Average waiting time : "<<double(Ans/n*1.0) << endl;
	return 0;
}
