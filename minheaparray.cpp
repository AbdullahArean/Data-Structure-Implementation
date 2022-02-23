#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 10

//building a min-heap
typedef struct heap{
	int data[HEAP_SIZE + 1];  //the body of the heap
	int total_elements; //the current number of elements in the heap
}heap;

void heap_insert(heap *heap, int x);
void heap_init(heap *heap);
void make_heap(heap *heap, int s[], int n);
void print_heap(heap *heap);
int get_minimum(heap *heap);
int get_parent(int n);
int young_child(int n);
int remove_minimum(heap *heap);
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
void make_heap(heap *heap, int s[], int n){
	int i; //counter
	//initialize the heap
	heap_init(heap);
	//insert the elements into the heap
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

int get_minimum(heap *heap){
	return heap -> data[1];
}

//returns the index of the parent (if any) of the index n
int get_parent(int n){
	return n == 1 ? -1 : (int)(n/2);

}
//returns the index of the younger child
int young_child(int n){
	return 2*n;
}

int remove_minimum(heap *heap){
	int min = -1;

	if(heap -> total_elements <= 0)
		printf("EMPTY HEAP!");

	else{
		//the root is the minimum element
		min = heap -> data[1];
		//replace the element at the top with last element in the heap
		heap -> data[1] = heap -> data[heap -> total_elements];
		//reduce the total elements in the heap
		heap -> total_elements -= 1;
		bubble_down(heap,1);
	}
	return min;
}

//bubbles down an element into it's proper place in the heap
void bubble_down(heap *heap, int p){
	int c; //child index
	int i; //counter
	int min_index; //index of lightest child

	c = young_child(p);
	min_index = p;

	for(i = 0; i < 2; i++){
		if(c + i <= heap -> total_elements){
			//check to see if the data at min_index is larger than the data at the child
			if(heap -> data[min_index] > heap -> data[c+i]){
				min_index = c + i;
			}
		}
	}

	if(min_index != p){
		//swap the elements
		int temp_variable = heap -> data[p];
		heap -> data[p] = heap -> data[min_index];
		heap -> data[min_index] = temp_variable;
		//call bubble down
		bubble_down(heap, min_index);
	}
}

//bubbles up the last element of the heap to maintain heap structure
/**
* *heap: pointer to the heap
* total_elements: the total elements in the heap
**/
void bubble_up(heap *heap, int index){
	//if we are at the root of the heap, no parent
	if(get_parent(index) == -1)
		return;

	//if the parent node has a larger data value, we need to bubble up
	if(heap -> data[get_parent(index)] > heap -> data[index]){
		//swap the elements
		int temp_variable = heap -> data[get_parent(index)];
		heap -> data[get_parent(index)] = heap -> data[index];
		heap -> data[index] = temp_variable;
		//call the bubble up function to the new parent
		bubble_up(heap, get_parent(index));
	}
}

void heap_insert(heap *heap, int x){
	//if the heap is already full
	if(heap -> total_elements >= HEAP_SIZE)
		printf("WARNING: HEAP OVERFLOW ERROR!\n");

	else{
		//increment the number of elements in the heap
		heap -> total_elements += 1;
		//insert the data value into the left most position in the heap
		heap -> data[heap -> total_elements] = x;
		//put in appropriate position by bubbling up
		bubble_up(heap, heap -> total_elements);

	}
}
void heap_sort(heap *heap)
{
	int range = heap->total_elements;
	for(int i=0; i<range; i++)
	{
		int temp= get_minimum(heap);
		remove_minimum(heap);
		print_heap(heap);
		heap->data[heap->total_elements]=temp;
	}

}
int main(int argc, char const *argv[]){
	heap *my_heap = new heap();

	heap_init(my_heap);

	int my_elements[] = {7,34,31,49};

	make_heap(my_heap,my_elements,4);
	print_heap(my_heap);
	heap_sort(my_heap);
	// printf("%d\n",get_minimum(my_heap));
	// remove_minimum(my_heap);
	for(int i=0; i<4; i++) printf("%d\n",my_heap->data[i]);
	// print_heap(my_heap);
	// printf("%d\n",my_heap -> total_elements);
	// free(my_heap);
}
