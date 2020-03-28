#include <bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n);
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define clear(a) memset(a,0,sizeof(a))
using namespace std;
struct process{
	int pid;
	int priority;
	int brustTime;
	int waiting,processStarting;
	
	process(){
		waiting=0;
		processStarting=0;
	}
	
	void getData(){
		cin>>pid>>priority>>brustTime;
	}
	
	void printData(){
		cout<<"P"<<pid<<"\t   "<<brustTime<<"\t    "<<priority<<endl;
	}
	
	bool operator<(const process &p)const{
		return priority<p.priority;
	}
};
int main(int argc, char *argv[])
{
	process processList[100];
	int total,i;
	double avgWait;
	cout<<"Total: "<<endl;
	cin>>total;
	for(i=0;i<total;i++){
		processList[i].getData();
	}
	
	sort(processList,processList+total);
	cout<<"Process  Priority  CPU Brust\n";
	
	for(i=0;i<total;i++){
		processList[i].printData();
	}
	processList[0].waiting=0;
	processList[0].processStarting=0;
	for(i=1;i<total;i++){
		processList[i].waiting=processList[i-1].brustTime+processList[i-1].waiting;
	}
	avgWait=0;
	for(i=0;i<total;i++){
		avgWait+=processList[i].waiting;
	}
	cout<<"Average Waiting Time: "<<avgWait/double(total)<<" ms"<<endl;
	
	return 0;
}
