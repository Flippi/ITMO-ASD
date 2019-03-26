#include "edx-io.hpp"
using namespace std;


int main() {

	long N;
	io >> N;
	char action;

	long* stack = new long[N];
	long top = -1;
	long head = 0;

	for (long i = 0; i < N; i++) {
		io >> action;
		if (action == '+') {
			top++;
			io >> stack[top];
		}
		else {
			io << stack[head] << '\n';
			head++;
		}
	}

	return 0;
}