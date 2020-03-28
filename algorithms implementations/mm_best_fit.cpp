#include <bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n);
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define clear(a) memset(a,0,sizeof(a))
using namespace std;
struct process{
	int size;
	int pid;
	int hid;
	bool operator<(const process &p)const{
		return size<p.size;
	}
	void getData(){
		cin>>pid>>size;
	}
	void printData(){
		cout<<"Process ID: "<<pid<<" Process Size: "<<size<<endl;
	}
};

struct hole{
	int size;
	int hid,pid;
	bool allocated;
	int remainingSize=0;
	vector<int> processID;
	hole(){
		pid=-1;
	}
	void getData(){
		cin>>hid>>size;
		remainingSize=size;
	}
	void printData(){
		cout<<"Hole ID: "<<hid<<" Hole Size: "<<size<<endl;
	}
	
	bool operator<(const hole &h)const{
		return size>h.size;
	}
	
};

int main(int argc, char *argv[])
{
	int totalProcess,totalHole;
	process processList[100];
	hole holeList[100];
	cout<<"Total Process"<<endl;
	cin>>totalProcess;
	cout<<"Total Hole"<<endl;
	cin>>totalHole;
	
	cout<<"Process Entry\n";
	for(int i=0;i<totalProcess;i++){
		processList[i].getData();
	}
	cout<<"Hole Entry:\n";
	for(int i=0;i<totalHole;i++){
		holeList[i].getData();
	}
	
	sort(processList,processList+totalProcess);
	sort(holeList,holeList+totalHole);
	
	int min,minIndex=-1;
	cout<<"ProcessID   Located(HoleID)   HoleSize  RemainingSize\n";
	
	for(int i=0;i<totalProcess;i++){
		min=99999999;
		for(int j=totalHole-1;j>=0;j--){
			if(holeList[j].allocated==false && holeList[j].size-processList[i].size>=0){
				if(holeList[j].size-processList[i].size<min){
					min=holeList[j].size-processList[i].size;
					minIndex=j;
				}
			}
		}
		holeList[minIndex].allocated=true;
		processList[i].hid=minIndex;
		holeList[minIndex].pid=processList[i].pid;
		holeList[minIndex].remainingSize=holeList[minIndex].size-processList[i].size;
		cout<<"P"<<processList[i].pid<<"  \t  \t"<<"H"<<holeList[minIndex].hid<<"\t\t  "
		<<holeList[minIndex].size<<"\t     "<<holeList[minIndex].remainingSize
		<<endl;
	}
	return 0;
}
