#include <iostream>
using namespace std;

void disp(int sub[], int size) {
   for(int i = 0; i < size; i++) {
      cout <<sub[i] << "  ";
   }
   cout << endl;
}

void solve(int a[],int b[],int j,int i,int n,int total,int sum){
    if(total<sum){
        b[i]=a[j];
        total+=b[i];
        solve(a,b,j+1,i+1,n,total,sum);
        if(j+1<n){
            total-=b[i];
            solve(a,b,j+1,i,n,total,sum);
        }
    }
    else{
        if(total==sum){
            disp(b,i);
        }
        return;
    }
}


int main() {
    int sub[7];

   int weights[] = {10, 7, 5, 18, 12, 20, 15};
   int size = 7;
   int sum=35;

//   int weights[] = {3,5,21,78};
//   int size = 4;
//   int sum=15;
   solve(weights,sub,0,0, size,0,sum);
}
