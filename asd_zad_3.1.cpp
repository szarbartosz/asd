#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void print(int t[], int n){
	for(int i=0; i<n; i++){
		cout<<t[i]<<" ";
	}
}

void bubble_sort(int t[], int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N-i-1; j++){
			if(t[j]>t[j+1]){
				swap(t[j],t[j+1]);
			}
		}
	}
}

bool exist(int t[],int N, int x){
	int left=0;
	int right=N-1;
	while(left!=right){
		if(t[left]+t[right]==x){
			return true;
		}
		if(t[left]+t[right]<x){
			left++;
		}
		else{
			right--;
		}
	}
	return false;
}

int main (){
	srand(time(NULL));
	int x;
	int N=10;
	int t[N];
	for(int i=0; i<N; i++){
		t[i]=rand()%N;
	}
	bubble_sort(t,N);
	print(t,N);
	cout<<endl;
	cout<<"enter the number: ";
	cin>>x;
	if(exist(t,N,x)){
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
	cout<<endl;
}
