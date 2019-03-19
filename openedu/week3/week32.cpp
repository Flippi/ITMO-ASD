#include <fstream>
#include <string>
#include "edx-io.hpp"
using namespace std;


int main() {
	long n, m, k;
	io >> n >> m >> k;

	string *A = new std::string[m];
	for (long i = 0; i < m; i++) {
		io >> A[i];
	}

	long *Pos = new long[n];
	long *Pos2 = new long[n];
	//������ ��� ������� ������� ���� ��� �������� ������� � ����������
	long *pointer[2] = { Pos, Pos2 };
	//������������� ����� ����
	int swtch = 0;
	for (long i = 0; i < n; i++) {
		Pos[i] = i;
	}

	int *count = new int[123];
	//�������� ����������
	for (int j = m - 1; m - j <= k; j--) {
		//���������� ���������
		for (int i = 97; i < 123; i++) {
			count[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			//j - ������, ������ ������ - ������� � �������� ������
			count[A[j][pointer[swtch][i]]]++;
		}

		for (int i = 98; i < 124; i++) {
			count[i] += count[i - 1];
		}

		for (int i = n - 1; i >= 0; i--) {
			//�� ������ ������ �� ����� ������� ��������������� ����� �������� � ������ �������
			pointer[1 - swtch][--count[A[j][pointer[swtch][i]]]] = pointer[swtch][i];
		}
		//����������� �������
		swtch = ~swtch & 1;

	}

	for (long i = 0; i < n; i++) {
		io << pointer[swtch][i] + 1 << ' ';
	}
	return 0;
}