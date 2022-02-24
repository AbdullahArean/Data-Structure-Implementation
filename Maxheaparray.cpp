#include <bits/stdc++.h>
#include <vector>
#define HEAP_SIZE 10

using namespace std;
typedef struct heap{
	int data[HEAP_SIZE + 1];
	int total_elements;
}heap;
void heap_insert(heap *heap, int x);
void heap_init(heap *heap);
void make_heap(heap *heap, int s[], int n);
void print_heap(heap *heap);
int get_maximum(heap *heap);
int get_parent(int n);
int young_child(int n);
int remove_maximum(heap *heap);
void bubble_up(heap *heap, int total_elements);
void bubble_down(heap *heap, int index);

void heap_init(heap *heap){
	heap -> total_elements = 0;
	int i;
	int len = sizeof(heap -> data)/sizeof(int);

	for(i = 0; i < len; i++){
		heap -> data[i] = 0;
	}
}
void make_heap(heap *heap, vector<int> s){
	int n= s.size();
	int i; 
	heap_init(heap);
	for(i = 0; i < n; i++){
		heap_insert(heap,s[i]);
	}
}
void print_heap(heap *heap){
	int i;
	int elements = heap -> total_elements;

	for(i = 1; i <= elements; i++){
		printf("ELEMENT[%d]: %d\n",i,heap -> data[i]);
	}
}
int get_maximum(heap *heap){
	return heap -> data[1];
}
int get_parent(int n){
	return n == 1 ? -1 : (int)(n/2);

}
int young_child(int n){
	return 2*n;
}
int remove_maximum(heap *heap){
	int max = -1;

	if(heap -> total_elements <= 0)
		printf("EMPTY HEAP!");

	else{
		max = heap -> data[1];
		heap -> data[1] = heap -> data[heap -> total_elements];
		heap -> total_elements -= 1;
		bubble_down(heap,1);
	}
	return max;
}
void bubble_down(heap *heap, int p){
	int c; 
	int i; 
	int max_index; 
	c = young_child(p);
	max_index = p;

	for(i = 0; i < 2; i++){
		if(c + i <= heap -> total_elements){
			if(heap -> data[max_index] < heap -> data[c+i]){
				max_index = c + i;
			}
		}
	}
	if(max_index != p){
		int temp_variable = heap -> data[p];
		heap -> data[p] = heap -> data[max_index];
		heap -> data[max_index] = temp_variable;
		bubble_down(heap, max_index);
	}
}
void bubble_up(heap *heap, int index){
	if(get_parent(index) == -1)
		return;
	if(heap -> data[get_parent(index)] < heap -> data[index]){
		int temp_variable = heap -> data[get_parent(index)];
		heap -> data[get_parent(index)] = heap -> data[index];
		heap -> data[index] = temp_variable;
		bubble_up(heap, get_parent(index));
	}
}
void heap_insert(heap *heap, int x){
	if(heap -> total_elements >= HEAP_SIZE)
		printf("WARNING: HEAP OVERFLOW ERROR!\n");

	else{
		heap -> total_elements += 1;
		heap -> data[heap -> total_elements] = x;
		bubble_up(heap, heap -> total_elements);

	}
}


int main(int argc, char const *argv[]){
	heap *my_heap = new heap();

	heap_init(my_heap);

	vector<int>  my_elements;
	my_elements = {7,34,31,49};

	make_heap(my_heap,my_elements);
	print_heap(my_heap);

}
