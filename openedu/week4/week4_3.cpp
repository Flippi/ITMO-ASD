#include "edx-io.hpp"
#include <string>
using namespace std;


string parse(string str, char *stack, long top) {
	for (int j = 0; j < str.size(); j++) {
		switch (str[j]) {
		case '(':
			stack[++top] = str[j];
			continue;
		case '[':
			stack[++top] = str[j];
			continue;
		case ')':
			if ( stack[top] != '(' || top < 0 ) {
				return "NO\n";
			}
			top--;
			continue;
		case ']':
			if (stack[top] != '[' || top < 0  ) {
				return "NO\n";
			}
			top--;
			continue;
		}
	}
	if (top == -1) {
		return "YES\n";
	}
	return "NO\n";
}

int main() {

	long N;
	string str;
	io >> N;
	char* stack = new char[10000];


	for (long i = 0; i < N; i++) {
		long top = -1;
		io >> str;
		io << parse(str, stack, top);
	}

	return 0;
}