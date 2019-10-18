#include <iostream>
#include <time.h>
using namespace std;

int partition(int a[],int low,int high){
	int i,j,pivot;
	pivot=a[low];
	i=low+1;
	j=high;
	while(1){
		while(a[i]<=pivot && i<=high){i++;}
		while(a[j]>pivot && j>=low){j--;}
		if(i<j){
			a[i]=a[i]+a[j];
			a[j]=a[i]-a[j];
			a[i]=a[i]-a[j];
		}
		else{
			a[low]=a[j];
			a[j]=pivot;
			return j;
		}
	}
}

void quickSort(int a[],int low,int high,int k){
	if(low<high){
		int pivot_pos=partition(a,low,high);
		if (pivot_pos>=k)
            cout<<"\nKth smallest = "<<a[k];
		quickSort(a,low,pivot_pos-1,k);
		quickSort(a,pivot_pos+1,high,k);
	}
}

int main(){
	int a[100],low=0,high,i;
	clock_t start,end;
	int s,e,k;
	double time;
	cout<<"Enter no. of elements: ";
	cin>>high;
	cout<<"Enter elements: ";
	for(i=0;i<high;i++)
		cin>>a[i];
    cout<<"Enter start,end,k: ";
    cin>>s>>e>>k;

	start=clock();
	quickSort(a,s-1,e-1,s+k-2);
	cout<<"\nQuick Sort:\n";
	for(i=0;i<high;i++)
		cout<<a[i]<<"\t";
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
}
