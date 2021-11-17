#include <stdio.h>

void printArray(const int* pArr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d", pArr[i]);
	printf("\n");
}

void printMatrix(int(*matrix)[4], int row, int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("%d", matrix[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int nums[] = { 1,2,3,4,5 };
	int matrix[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	printArray(nums, 5);
	printMatrix(matrix, 3, 4);
	printArray(&matrix[0][0], 3 * 4);
	printArray(matrix[0], 3 * 4);

	return 0;
}
