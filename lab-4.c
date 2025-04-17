#include <stdio.h>

#define SIZE 15

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }
    return -1; 
}

int main() {
    system("chcp 65001");
    int X[SIZE];
    int A;
   
    printf("Введіть %d елементів масиву X:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("X[%d] = ", i);
        scanf("%d", &X[i]);
    }

    printf("Введіть значення цільового елемента A: ");
    scanf("%d", &A);

    int linearResult = linearSearch(X, SIZE, A);
    if (linearResult != -1) {
        printf("Лінійний пошук: Елемент %d знайдено на позиції %d\n", A, linearResult);
    } else {
        printf("Лінійний пошук: Елемент %d не знайдено\n", A);
    }

    bubbleSortDescending(X, SIZE);
    printf("Відсортований масив X за спаданням:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    int binaryResult = binarySearch(X, SIZE, A);
    if (binaryResult != -1) {
        printf("Бінарний пошук: Елемент %d знайдено на позиції %d\n", A, binaryResult);
    } else {
        printf("Бінарний пошук: Елемент %d не знайдено\n", A);
    }

    return 0;
}