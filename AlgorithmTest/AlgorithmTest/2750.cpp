#include <stdio.h>

int array[1001];

void selectionSort(int* array, int number) {
	int i, j, temp, index, min;
	for (i = 0; i < number; i++) {
		min = array[i];
		index = i;
		for (j = i+1; j < number; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	
	for (i = 0; i < number; i++) {
		printf("%d\n", array[i]);
	}

}

int main(void) {
	int number, i;

	scanf("%d", &number);

	for (i = 0; i < number; i++) {
		scanf("%d", &array[i]);
	}

	selectionSort(array, number);

	return 0;
}