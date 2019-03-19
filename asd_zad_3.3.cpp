#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void print_array(int t[], int N){
	for(int i=0; i<N; i++){
		cout<<t[i]<<" ";
	}
}

void insertion_sort(int t[], int N, int left, int right){
	int j, tmp;
	for(int i=1; i<N; i++){
		j=i-1;
		tmp=t[i];
		while(j>=left and t[j]>tmp){
			t[j+1]=t[j]; 
			j--;
		}
		t[j+1]=tmp;
	}
}

int  median(int t[], int N){
	if(N==1){
		return t[0];
	}
	int size = N/5;
	if(N%5!=0){
		size++;
	}
	int med[size];
	int i;
	int j=0;
	for(i=0; i+4<N; i+=5){
		insertion_sort(t,N,i,i+4);
		med[j]=t[(2*i+4)/2];
		j++;
	}
	if(i<N){
		insertion_sort(t,N,i,N-1);
		med[j]=t[(i+N-1)/2];		
	}
	return median(med,size);		
}

int main(){
	int N=10;
	int t[N]={1,2,1,2,1,1,1,2,1,2};
	int element;
	int counter=0;
	/*
	srand(time(NULL));
	for(int i=0; i<N; i++){
		t[i]=rand()%10;
	}
	*/
	print_array(t,N);
	element=median(t,N);
	for(int i=0; i<N; i++){
		if(t[i]==element){
			counter++;
		}
	}
	cout<<endl;
	if(counter>N/2){
		cout<<"TAK"<<endl;
	}
	else{
		cout<<"NIE"<<endl;
	}
	insertion_sort(t,N,0,N-1);
	print_array(t,N);
}
