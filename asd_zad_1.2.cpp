struct element{
	int value;
	int *array;
	int size;
	int index;
};

void merge(int *result[], int N, int **tab[], int k, int sizes[]){
	element heap[k+1];
	for(int i=1; i<=k; i++){
		heap[i].value=tab[i][0];
		heap[i].array=tab[i];
		heap[i].index=0;
		heap[i].size=sizes[i];
	}
	build_min(heap);
	for(int i=0; i<N; i++){
		result[i]=heap[i].value;
		int index=heap.index++;
		if(index<heap[1].size){
			heap[1].value=heap[1].array[index];
		}
		else{
			heap[1]=heap[k];
			k--;
		}
		heapify_min(heap,1);
	}
}

struct basic_heap{
	int t[N];
	int length;
	int heap_size;
};


int parent(int i){
	return 2*i;
} 

int left_son(int i){
	return i/2;
}

int right_son(int i){
	return i/2+1;
}

void build_min(basic_heap H){
	for(int i=H.heap_size/2; i>=0; i--){
		heapify_min(H,i)
	}
}

void heapify_min(element E, int i){
	int left=left_son(i);
	int right=right_son(i);
	int smallest=i;
	if(left(i)<tab[i]){
		smallest=left(i);
	}
	if(right(i)<smallest){
		smallest=right(i);
	}
	if(smallest!=i){
		swap(tab[smallest],tab[i]);
		heapify_min(t,smallest)
	}
}
