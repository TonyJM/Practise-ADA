#include <iostream>
#include <time.h>
using namespace std;

void Merge(int b[],int p,int c[],int q,int a[]){
	int i=0,j=0,k=0;
	while(i<p && j<q && k<p+1){
		if(b[i]<=c[j]){
			a[k]=b[i];
			i++;
		}
		else{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	if(i==p){
        a[k]=c[j];
	}
	else{
        a[k]=b[i];
	}
	cout<<float(a[p-1]+a[p])/2;
}



int main(){
	int n,i;
	clock_t start,end;
	double time;

	start=clock();
	cout<<"\nMedian:\n";
    int b[]={1,12,15,26,28};
    int c[]={2,13,16,30,45};
    int a[5];
    Merge(b,5,c,5,a);
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";

}
