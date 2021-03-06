#include <fstream>
using namespace std;


int main() {
	int n, m;

	ifstream input("input.txt");
	input >> n >> m;

	long *A = new long[n];
	long *B = new long[m];
	long *C = new long[n * m];

	long maxA = 0;
	for (int i = 0; i < n; i++) {
		input >> A[i];
		//Max в А массиве
		if (A[i] > maxA) {
			maxA = A[i];
		}
	}
	long maxB = 0;
	long pos;

	for (int i = 0; i < m; i++) {
		input >> B[i];
		//Заполнсяем массив С
		for (int j = 0; j < n; j++) {
			pos = (i * n) + j;
			C[pos] = B[i] * A[j];
		}
		//Max в B массиве
		if (B[i] > maxB) {
			maxB = B[i];
		}
	}
	input.close();

	long maxValue = maxA * maxB;
	int dig = 1;
	//Считаем количество битов в максимальном числе
	while (maxValue >> dig > 0) {
		dig++;
	}
	dig--;

	radixSort(C, n*m, dig);



	long long sum = 0;
	for (int i = 0; i < n * m; i += 10) {
		sum += C[i];
	}
	ofstream output("output.txt");
	output << sum;
	output.close();

	return 0;
}

//Цифровая сортировка, разряд = 1 байт
void radixSort(long *arr, int size, int dig) {
	long *output = new long[size];
	long *count = new long[256];
	//Сортируем побайтово начиная с правого байта
	for (int byte = 0; byte <= dig; byte += 8) {
		//Сортировка подсчётом

		for (int i = 0; i < 256; i++) {
			count[i] = 0;
		}
		// Для каждого элемента (байта) считаем количество в исходном массиве
		for (int i = 0; i < size; i++) {
			count[(arr[i] >> byte) & 255]++;
		}
		//Увеличиваем каждый следующий элемент вспомогательного массива на предыдущий,
		//в итоге под каждым элементом (байтом) хранится его позиция в отсортированном массиве
		for (int i = 1; i < 256; i++) {
			count[i] += count[i - 1];
		}
		//Заполняем новый массив проходя вспомоготельный с конца, при этом уменьшая количество равных элементов
		//чтобы корректно записывать одинаковые элементы
		for (int i = size - 1; i >= 0; i--) {
			output[count[(arr[i] >> byte) & 255] - 1] = arr[i];
			count[(arr[i] >> byte) & 255]--;
		}

		for (int i = 0; i < size; i++) {
			arr[i] = output[i];
		}
	}
}