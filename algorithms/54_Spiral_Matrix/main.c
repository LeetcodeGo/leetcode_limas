/*
* Source : https://leetcode.com/problems/spiral-matrix/description/
*
* Author : Jackal Lin
*
* Description:
*   Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*
* Complexity:
*   Time:O(N)
*   Space:O(1)
*
* Beats: 100%
*
* Approach:
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    int i;
    int x=0;
    int y=0;
    int dir=0;
    int border=0;
    int *arr;

    arr = (int *)malloc(sizeof(int)*(matrixRowSize*matrixColSize));

    for(i=0; i<matrixRowSize*matrixColSize; i++)
    {
        arr[i] = matrix[y][x];

        if(dir == 0) //dir = right
        {
            if(x == (matrixColSize-1-border))
            {
                y += 1;
                dir = 1;
            }
            else
            {
                x += 1;
            }
        }
        else if(dir == 1) //dir = down
        {
            if(y == (matrixRowSize-1-border))
            {
                x -= 1;
                dir = 2;
            }
            else
            {
                y += 1;
            }
        }
        else if(dir == 2) //dir = left
        {
            if(x == border)
            {
                y -= 1;
                dir = 3;
                border++;
            }
            else
            {
                x -= 1;
            }
        }
        else //dir = up
        {
            if(y == border)
            {
                x += 1;
                dir = 0;
            }
            else
            {
                y -= 1;
            }
        }
    }

    return arr;
}

