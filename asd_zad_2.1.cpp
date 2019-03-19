#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

struct node{
	int value;
	node *next;
};

void add_element(node *&head, int value){
	node *tmp=new node;
	tmp->value=value;
	tmp->next=head;
	head=tmp;
}

int random_number(int N){
	return rand()%N;
}

void print_list(node *head){
	while(head!=NULL){
		cout<<head->value<<" ";
		head=head->next;
	}
}

node *get_last(node *head){
	while(head!=NULL and head->next!=NULL){
		head=head->next;		
	}
	return head;
}

node *partition(node *head, node *end, node *&new_head, node *&new_end){
	node *pivot=end;
	node *prev=NULL;
	node *current=head;
	node *tail=pivot;
	while(current!=pivot){
		if(current->value<pivot->value){
			if(new_head==NULL){
				new_head=current;
			}
			prev=current;
			current=current->next;
		}
		else{
			if(prev!=NULL){
				prev->next=current->next;
			}
			node *tmp=current->next;
			current->next=NULL;
			tail->next=current;
			tail=current;
			current=tmp;	
		}
	}
	if(new_head==NULL){
		new_head=pivot;
	}
	new_end=tail;
	return pivot;
}

node *quick_sort(node *head, node *end){
	if(head==NULL or head==end){
		return head;
	}
	node *new_head=NULL;
	node *new_end=NULL;
	node *pivot=partition(head,end,new_head,new_end);
	if(new_head!=pivot){
		node *tmp=new_head;
		while(tmp->next!=pivot){
			tmp=tmp->next;
		}
		tmp->next=NULL;
		new_head=quick_sort(new_head,tmp);
		tmp=get_last(new_head);
		tmp->next=pivot;
	}
	pivot->next=quick_sort(pivot->next,new_end);
	return new_head;
}

int main (){
	srand(time(NULL));
	int N=20;
	node *list=NULL;
	for(int i=0; i<N; i++){
		add_element(list,random_number(N));
	}
	print_list(list);
	cout<<endl;
	list=quick_sort(list,get_last(list));
	print_list(list);
	cout<<endl;
	return 0;
}
