/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


void View(int **arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row=1000, col=1000;
    

    // Выделение памяти под массив
    int **arr = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++)
        arr[i] = (int *)malloc(col * sizeof(int));

    // Присваивание случайных значений
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = (int) rand() % 100;
        }
    }

    // Отобразить исходный массив
    View(arr, row, col);

    // Сортировка выбором столбцов по убыванию
    int MinRow, Temp;
    for (int NumCol = 0; NumCol < col; NumCol++) {
        for (int NumRow = 0; NumRow < row - 1; NumRow++) { 
            MinRow = NumRow;
            for (int j = NumRow + 1; j < row; j++)
                if (arr[j][NumCol] > arr[MinRow][NumCol])
                   MinRow = j;
            Temp = arr[NumRow][NumCol];
            arr[NumRow][NumCol] = arr[MinRow][NumCol]; 
            arr[MinRow][NumCol] = Temp;
        }
    }

    // Вывод отсортированного массива
    printf("\n");
    View(arr, row, col);


}