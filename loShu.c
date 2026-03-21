#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void printSquare(int square[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        printf("[");
        for (j = 0; j < SIZE; j++)
        {
            printf("%d", square[i][j]);
            if (j < SIZE - 1)
                printf(" ");
        }
        printf("]\n");
    }
}

int containsAllNumbers1to9(int square[SIZE][SIZE])
{
    int seen[10] = {0};
    int i, j, value;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            value = square[i][j];

            if (value < 1 || value > 9)
                return 0;

            if (seen[value] == 1)
                return 0;

            seen[value] = 1;
        }
    }

    return 1;
}

int isLoShuMagicSquare(int square[SIZE][SIZE])
{
    int i, j;
    int targetSum;
    int rowSum, colSum;
    int diag1 = 0, diag2 = 0;

    if (!containsAllNumbers1to9(square))
        return 0;

    targetSum = square[0][0] + square[0][1] + square[0][2];

    for (i = 0; i < SIZE; i++)
    {
        rowSum = 0;
        for (j = 0; j < SIZE; j++)
        {
            rowSum += square[i][j];
        }
        if (rowSum != targetSum)
            return 0;
    }

    for (j = 0; j < SIZE; j++)
    {
        colSum = 0;
        for (i = 0; i < SIZE; i++)
        {
            colSum += square[i][j];
        }
        if (colSum != targetSum)
            return 0;
    }

    for (i = 0; i < SIZE; i++)
    {
        diag1 += square[i][i];
        diag2 += square[i][SIZE - 1 - i];
    }

    if (diag1 != targetSum || diag2 != targetSum)
        return 0;

    return 1;
}

void generateRandomSquare(int square[SIZE][SIZE])
{
    int nums[9] = {1,2,3,4,5,6,7,8,9};
    int i, j, temp, index = 0;

    for (i = 8; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            square[i][j] = nums[index++];
        }
    }
}

int main()
{
    int validSquare[SIZE][SIZE] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    int invalidSquare[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int randomSquare[SIZE][SIZE];
    long long count = 0;

    srand((unsigned int)time(NULL));

    printf("=== TEST 1: VALID SQUARE ===\n");
    printSquare(validSquare);
    if (isLoShuMagicSquare(validSquare))
        printf("This is a Lo Shu Magic Square.\n");
    else
        printf("This is NOT a Lo Shu Magic Square.\n");

    printf("\n=== TEST 2: INVALID SQUARE ===\n");
    printSquare(invalidSquare);
    if (isLoShuMagicSquare(invalidSquare))
        printf("This is a Lo Shu Magic Square.\n");
    else
        printf("This is NOT a Lo Shu Magic Square.\n");

    printf("\n=== RANDOM GENERATION UNTIL SUCCESS ===\n");

    do
    {
        generateRandomSquare(randomSquare);
        count++;
    }
    while (!isLoShuMagicSquare(randomSquare));

    printf("Total number of squares generated and tested before success: %lld\n", count);
    printf("Successful Lo Shu Magic Square:\n");
    printSquare(randomSquare);

    return 0;
}