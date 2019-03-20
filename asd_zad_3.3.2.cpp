#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void print_array(int t[], int N){
	for(int i=0; i<N; i++){
		cout<<t[i]<<" ";
	}
}

int repeat(int t[], int N){
	int counter=1;
	int element=t[0];
	for(int i=1; i<N; i++){
		if(element==t[i]){
			counter++;
		}
		else{
			counter--;
		}
		if(counter==0){
			element=t[i];
			counter++;
		}
	}
	counter=0;
	for(int i=0; i<N; i++){
		if(t[i]==element){
			counter++;
		}
	}
	if(counter>N/2){
		return element;
	}
	else{
		return -1;
	}
}



int main(){
	srand(time(NULL));
	int N=11;
	int t[N]={2,1,2,1,2,1,2,1,2,1,2};
//	for(int i=0; i<N; i++){
//		t[i]=rand()%N;
//	}
	print_array(t,N);
	cout<<endl;
	cout<<"number that repeats more than "<<N/2<<" times: "<<repeat(t,N);
}
