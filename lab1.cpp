#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int Partition(int A[], int p, int r){
	int x = A[r];
	int i = p-1, j;

	for(j = p; j < r-1; j++){
    	cnt+=1;
    	if(A[j] <= x){
        	i++;
        	swap(A[i],A[j]);
    	}
	}
	swap(A[i+1], A[r]);
	return i+1;
}

int Randomized_Partition(int A[], int p, int r){
	srand(time(NULL));
	int i = p + (rand() % (r-p+1));
	swap(A[i],A[r]);
	return Partition(A,p,r);
}

void Randomized_Quick_Sort(int A[], int p, int r){
	if(p<r){
    	int q = Randomized_Partition(A,p,r);
    	Randomized_Quick_Sort(A,p,q);
    	Randomized_Quick_Sort(A,q+1,r);
	}
}
int main(){
	int A[10];
	for(int i = 0; i < 10; i++){
    	A[i] = i;
	}
	Randomized_Quick_Sort(A,0,10);
    
	for(int i = 0; i < 10; i++){
    	cout << A[i] << " ";
	}
	cout << cnt;
    }
