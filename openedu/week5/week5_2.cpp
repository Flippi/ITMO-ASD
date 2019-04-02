#include "edx-io.hpp"
using namespace std;


struct number {
	long value;
	long input_time;	
};

void swop(number* a, number* b) {
	number temp = *a;
	*a = *b;
	*b = temp;
}


void heapifyUp(number* array, long i, long* array_of_positions) {

	long parent = i / 2 - (1 - i % 2);

	while (i != 0 && array[i].value < array[parent].value) {
		
		array_of_positions[array[i].input_time] = parent;
		array_of_positions[array[parent].input_time] = i;
		swop(&array[i], &array[parent]);
		i = parent;
		parent = i / 2 - (1 - i % 2);
	}
}


void heapifyDown(number* array, long tail, long* array_of_positions) {
	
	long position = 0;
	
	long left = 2 * (position + 1) - 1;
	long right = 2 * (position + 1);
	
	while (position != tail && ((array[position].value > array[left].value && left <= tail) || (array[position].value > array[right].value && right <= tail))) {
		
		if (array[right].value < array[left].value && right <= tail) {
			
			array_of_positions[array[position].input_time] = right;
			array_of_positions[array[right].input_time] = position;
			swop(&array[right], &array[position]);
			
			position = right;
		}
		else {
			array_of_positions[array[position].input_time] = left;
			array_of_positions[array[left].input_time] = position;
			swop(&array[left], &array[position]);
			position = left;
		}
		
		left = 2 * (position + 1) - 1;
		right = 2 * (position + 1);
	}
}


int main() {
	long N;
	io >> N;
	
	number* Queue = new number[N];
	long head = 0;
	long tail = -1;

	long* array = new long[N];
	
	char action;
	long a, temp;


	for (long i = 0; i < N; i++) {
		io >> action;
		switch (action)
		{
		case 'A':
			io >> a;
			
			Queue[++tail] = number{ a, i };
			array[i] = tail;
			heapifyUp(Queue, tail, array);
			break;
		case 'X':
			if (head > tail) {
				io << '*' << '\n';
			}
			else {
				array[Queue[head].input_time] = tail;
				array[Queue[tail].input_time] = head;
				swop(&Queue[head], &Queue[tail]);

				io << Queue[tail--].value << '\n';

		
				heapifyDown(Queue, tail, array);
			}
			break;
		case 'D':
			io >> a;
			io >> temp;
			Queue[array[a - 1]].value = temp;
			heapifyUp(Queue, array[a - 1], array);
			break;
		default:
			break;
		}

	}ч

	return 0;
}