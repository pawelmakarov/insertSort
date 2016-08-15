#include <stdio.h>

void sliceShiftRight(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[end];
        
        for ( int i = end; i > start; i-- ) {
            array[i] = array[i-1];
        }
        array[start] = temp;
    }
}


void insertSort(int array[], int len) {
    for ( int i = 1, k = 0; i < len; i++, k++ ) {
        if ( array[k] > array[i] ) {
            int start = k;
            
            if ( k != 0 ) {
                for ( int j = i, index = k - 1; index >= 0; index-- ) {
                    if ( array[j] < array[index] ) {
                        start = index;
                    }
                }
            }
            sliceShiftRight(array, start, i);
        }
    }
}

void print(int array[], int size) {
    int index = size - 1;

    for ( int j = 0; j < index; j++ ) {
        printf("%d ", array[j]);
    }
    printf("%d\n", array[index]);
}


int main() {
	int array[] = {90, 40, 20, 70, 30, 50, 60, 80, 100, 10};
	int size = 10;

    print(array, size);
	insertSort(array, size);
    print(array, size);

}