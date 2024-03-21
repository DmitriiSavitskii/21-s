/*------------------------------------
    Здравствуй, человек!
    Чтобы получить ключ
    поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input (int *buffer, int *length);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int* numbers);

/*------------------------------------
    Функция получает массив данных
    через stdin.
    Выдает в stdout особую сумму
    и сформированный массив
    специальных элементов
    (выбранных с помощью найденной суммы):
    это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX], data2[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    }
	int res = sum_numbers(data, n);
	int n2 = find_numbers(data, n, res, data2);
	printf("%d\n", res);
    output(data2, n2);

    return 0;
}

int input (int *buffer, int *length) {
    scanf("%d", length);
    if (getchar() == '\n' && *length > 0 && *length <= 10) {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (!scanf("%d", p)) {
                return 1;
            }
        }
        if (getchar() != '\n') {
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}

/*------------------------------------
    Функция должна находить
    сумму четных элементов
    с 0-й позиции.
-------------------------------------*/

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int* i = buffer; i - buffer < length; i++) {
        if (*i % 2 == 0) {
            sum += *i;
        }
    }
    return sum;
}

/*------------------------------------
    Функция должна находить
    все элементы, на которые нацело
    делится переданное число и
    записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers)
{   *numbers = 0;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if(buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        } else{
            numbers[i] = 0;
        }
    }
    return count;
}


void output (int *buffer, int length) {
    for (int i = 0; i < length; i++) {
		printf("%d ", buffer[i]);
    }
}


#include <stdio.h>
#include <stdlib.h>

int input(int *size, int *data);
void swap(int *arr, int i, int j);
void bubbleSort(int *arr, int n);
void output(int *arr, int n);

int main() {
    int n;
    int *data = NULL;

    char ch;
    if (scanf("%d%c", &n, &ch) != 2 || ch != '\n') {
        printf("n/a");
        return 1;
    }
    
    data = (int*) malloc(n * sizeof(int));
    if (input(&n, data) == 1) {
        printf("n/a");
        return 1;
    }
    bubbleSort(data, n);
    output(data, n);
    free(data);
    
    return 0;
}

int input(int *size, int *data) {
    //char ch;
    int flag = 0;

    for (int i = 0; i < *size; i ++) {
        scanf("%d", &data[i]);
    }


    return flag;
}

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr, j, j + 1);
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
}

