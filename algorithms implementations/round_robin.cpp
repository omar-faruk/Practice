#include <bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n);
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define clear(a) memset(a,0,sizeof(a))
using namespace std;

struct process{
	int pid;
	int arrival;
	int brustTime;
	int waiting,processStarting;
	
	process(){
		waiting=0;
		processStarting=0;
	}
	
	void getData(){
		cin>>pid>>arrival>>brustTime;
	}
	
	void printData(){
		cout<<"P"<<pid<<"\t   "<<arrival<<"\t    "<<brustTime<<endl;
	}
	
	bool operator<(const process &p)const{
		return arrival<p.arrival;
	}
};

int main(int argc, char *argv[])
{
	process processList[100];
	int total,i,timeQuantum;
	double avgWait;
	cout<<"Total: "<<endl;
	cin>>total;
	for(i=0;i<total;i++){
		processList[i].getData();
	}
	cout<<"Time Quantum: "<<endl;
	cin>>timeQuantum;
	sort(processList,processList+total);
	cout<<"Process  Arrival  CPU Brust\n";
	
	for(i=0;i<total;i++){
		processList[i].printData();
	}
	
	
	return 0;
}
