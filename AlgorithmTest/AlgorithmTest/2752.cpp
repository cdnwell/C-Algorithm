#include <stdio.h>

void bubbleSort(int* array) {
	int i, j, temp;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2 - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < 3; i++) {
		printf("%d ", array[i]);
	}
}

int main(void) {
	int array[3], i;
	for (i = 0; i < 3; i++) {
		scanf("%d", &array[i]);
	}
	
	bubbleSort(array);


	return 0;
}