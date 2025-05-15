#include<iostream>

const double EPSILON = 0.00001;

template<typename T>
void sort(T* arr, size_t size);

template<>
void sort<int>(int* arr, size_t size) {
	int lastSwapIndex, right = size - 1;
	while (right > 0) {
		lastSwapIndex = 0;
		for (int i = 0; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				lastSwapIndex = i;
			}
		}
		right = lastSwapIndex;
	}
}

template<>
void sort<double>(double* arr, size_t size) {
	size_t minIndex;
	double min;

	for (size_t i = 0; i < size - 1; ++i) {
		minIndex = i;
		min = arr[minIndex];
		for (size_t j = i + 1; j < size; ++j) {
			if (arr[j] < min - EPSILON) {
				minIndex = j;
				min = arr[minIndex];
			}
		}
		arr[minIndex] = arr[i];
		arr[i] = min;
	}
}

template<>
void sort<unsigned int>(unsigned int* arr, size_t size) {
	for (int i = 1; i < size; ++i) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

template<typename T>
void printArrs(T* arr, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

int main() {
	int arrInt[5] = { 1,5,3,6,2 };
	double arrDouble[6] = { 5.10,6.2,3.2,4.5,1,2 };
	unsigned int arrUnsInt[3] = { 3,2,1 };

	sort(arrInt, 5);
	sort(arrDouble, 6);
	sort(arrUnsInt, 3);

	printArrs(arrInt, 5);
	printArrs(arrDouble, 6);
	printArrs(arrUnsInt, 3);

	return 0;
}