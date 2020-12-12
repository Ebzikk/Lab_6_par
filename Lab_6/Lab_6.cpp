#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

const int array_size = 1000;
const int threads = 5;

void array_generation(int *arr);
long array_sum_one(int *arr);
int array_sum_two(int *arr);
int halving_size_of_array(int half_size_of_arr);

int main()
{
	int arr[array_size];

	array_generation(arr);
	cout << "Array: ";
	for (int i = 0; i < array_size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Task one: " << array_sum_one(arr) << endl;
	cout << "Task two: " << array_sum_two(arr) << endl;
}

void array_generation(int *arr) {
	srand(time(NULL));
	for (int i = 0; i < array_size; i++) {
		arr[i] = rand() % 100;
	}
}

long array_sum_one(int *arr) {
	long sum_of_thread;
	long sum = 0;

	int elements_in_thread = ceil(array_size * 1.0 / threads);
	for (int i = 0; i < threads; i++) {
		sum_of_thread = 0;
		for (int j = i * elements_in_thread; j < (i + 1) * elements_in_thread; j++) {
			sum_of_thread += arr[j];
		}
		sum += sum_of_thread;
	}
	return sum;
}

int array_sum_two(int *arr) {
	int half_size_of_arr = array_size;
	int end_size_of_arr = array_size;

	do {
		half_size_of_arr = halving_size_of_array(half_size_of_arr);
		for (int i = 0; i < half_size_of_arr; i++) {
			int last_element_index = end_size_of_arr - i - 1;
			if (i != last_element_index) {
				arr[i] += arr[last_element_index];
				arr[last_element_index] = 0;
			}
		}
		end_size_of_arr = half_size_of_arr;
	} while (half_size_of_arr > 1);
	int sum = arr[0];
	return sum;
}

int halving_size_of_array(int half_size_of_arr) {
	if (half_size_of_arr % 2 == 0) {
		return half_size_of_arr / 2;
	}
	else {
		return (half_size_of_arr / 2) + 1;
	}
}