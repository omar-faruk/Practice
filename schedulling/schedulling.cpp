#include <bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n);
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define clear(a) memset(a,0,sizeof(a))
using namespace std;

struct process{
	string name;
	int brust_time;
	int arrival_time;

	bool operator<(const process &prs)const{
		return arrival_time<prs.arrival_time;
	}
	void getData(){
		cin>>name>>brust_time>>arrival_time;
	}

};

int main(int argc, char *argv[])
{
	int total_process;
	process processes[100];
	cin>>total_process;
	cout<<"Name\t"<<"Brust_time\t"<<"arrival_time"<<endl;
	for(int i=0;i<total_process;i++){
		processes[i].getData();
	}
	sort(processes,processes+total_process);
	
	for(int i=0;i<total_process;i++){
		cout<<processes[i].name<<"\t"<<processes[i].brust_time<<"\t"<<processes[i].arrival_time<<endl;
	}
	int nw=processes[0].arrival_time;
	double Ans=0;
	for(int i=0;i<total_process;i++){
		if(nw>processes[i].arrival_time) Ans+=(nw-processes[i].arrival_time);
		nw+=processes[i].brust_time;
	}
	cout << fixed << setprecision(4) << "Average waiting time : "<<double(Ans/total_process*1.0) << endl;



	
	return 0;
}
