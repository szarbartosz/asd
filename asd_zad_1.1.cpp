struct node{
	int value;
	node *next;
};

void merge_sort(node *&head){
	if(head==NULL or head->next==NULL){
		return;
	}
	node *left;
	node *right;
	split(head,left,right);
	merge_sort(left);
	merge_sort(right);
	head=merge(left,right);
}

void split(node *split_list, node *&list1, node *&list2){
	list1=NULL;
	list2=NULL;
	node tmp;
	bool flag=true;
	while(split_list!=NULL){
		if(flag){
			list1=tmp;
			list1=head;
			head=head->next;
			list1->next=tmp;
		}
		else{
			list2=tmp;
			list2=head;
			head=head->next;
			list2->next=tmp;			
		}
	}
	
}

node *merge(node *list1, node *list2){
	node *head=NULL;
	node *tmp;
	while(list1!=NULL and list2!=NULL){
		if(list1->value<=list2->value){
			tmp=head;
			head=list1;
			list1=list1->next;
			head->next=tmp;
		}
		else{
			tmp=head;
			head=list2;
			list2=list2->next;
			head->next=tmp;
		}
	}
	while(list1!=NULL){
		tmp=head;
		head=list1;
		list1=list1->next;
		head->next=tmp;
	}
	while(list2!=NULL){
		tmp=head;
		head=list2;
		list2=list2->next;
		head->next=tmp;
	}
	return head;
}
