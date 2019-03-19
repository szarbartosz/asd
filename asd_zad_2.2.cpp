#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

void print(int t[], int N){
	for(int i=0; i<N; i++){
		cout<<t[i]<<" ";
	}
	cout<<endl;
}

int get_max(int t[], int N){
	int max=t[0];
	for(int i=1; i<N; i++){
		if(t[i]>max){
			max=t[i];
		}
	}
	return max;
}

void counting_sort(int t[], int N, int d){
	int k=10;
	int B[N];
	int C[k];
	d=pow(10,d);
	for(int i=0; i<k; i++){
		C[i]=0;
	}
	for(int i=0; i<N; i++){
		C[t[i]%d/(d/10)]++;
	}	
	for(int i=1; i<k; i++){
		C[i]+=C[i-1];
	}
	for(int i=N-1; i>=0; i--){
		B[C[t[i]%d/(d/10)]-1]=t[i];
		C[t[i]%d/(d/10)]--;
	}
	for(int i=0; i<N; i++){
		t[i]=B[i];
	}
}

void radix_sort(int t[], int N){
	int digit=0;
	int max=get_max(t,N);
	while(max>0){
		max/=10;
		digit++;
	}
	for(int i=1; i<=digit; i++){
		counting_sort(t,N,i);
	}
}

int main(){
	srand(time(NULL));
	int N=100;
	int t[N];
	for(int i=0; i<N; i++){
		t[i]=rand()%N^2;
	}
	print(t,N);
	cout<<endl;
	radix_sort(t,N);
	print(t,N);
	return 0;
}
