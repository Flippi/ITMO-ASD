#include "edx-io.hpp"

using namespace std;


int main() {
	long N;
	io >> N;
	char action;
	//Очередь для чисел
	long* queue = new long[N];
	long top = -1;
	long head = 0;
	//Очередь для наименьших чисел
	long *minQueue = new long[N];
	long minTop = -1;
	long minHead = 0;

	for (long i = 0; i < N; i++) {
		io >> action;
		switch (action)
		{
		case '+':
			io >> queue[++top];
			while (minQueue[minTop] > queue[top] && minTop - minHead >= 0 ) {
				minTop--;
			}
			minQueue[++minTop] = queue[top];
			continue;
		case '-':
			if (queue[head] == minQueue[minHead]) {
				minHead++;
			}
			head++;
			continue;
		case '?':
			io << minQueue[minHead] << '\n';
			continue;
		}

	}
	return 0;
}