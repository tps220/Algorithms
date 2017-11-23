#include "stdio.h"
#include "stdlib.h"



int main(int argc, char** argv) {
  FILE* fp = fopen("problem81.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open file\n");
    return 1;
  }

  const int SIZE = 80;
  int** matrix = (int**)malloc(SIZE * sizeof(int*));
  for (int i = 0; i < SIZE; i++) {
    matrix[i] = (int*)malloc(SIZE * sizeof(int));
  }

  char* temp = (char*)malloc(sizeof(char));
  for (int i = 0; i < SIZE; i++) {
    for (int k = 0; k < SIZE - 1; k++) {
      fscanf(fp, "%d %c", &matrix[i][k], temp);
    }
    fscanf(fp, "%d", &matrix[i][SIZE - 1]);
  }
  free(temp);


  for (int i = 1; i < SIZE; i++) {
    matrix[i][0] += matrix[i - 1][0];
    matrix[0][i] += matrix[0][i - 1];
  }

  for (int i = 1; i < SIZE; i++) {
    for (int k = 1; k < SIZE; k++) {
      if (matrix[i - 1][k] < matrix[i][k - 1]) {
        matrix[i][k] += matrix[i - 1][k];
      }
      else {
        matrix[i][k] += matrix[i][k - 1];
      }
    }
  }

  fprintf(stdout, "Answer: %d\n", matrix[SIZE - 1][SIZE - 1]);
  for (int i = 0; i < SIZE; i++) {
    free(matrix[i]);
  }
  free(matrix);
  fclose(fp);
}
