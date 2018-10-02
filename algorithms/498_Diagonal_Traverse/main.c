/*
* Source : https://leetcode.com/problems/diagonal-traverse/description/
*
* Author : Jackal Lin
*
* Description:
*   Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
*
* Complexity:
*   Time:O(N)
*   Space:O(1)
*
* Beats: 100%
*
* Approach:
*   The traveral has two directions, upper-right and bottom-left; each direction will have different x, y coordinate change when 
*   hit the boundary.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize)
{
    int i;
    int x=0;
    int y=0;
    int dir=0;
    int *zigzag;
    int ret_size = matrixRowSize * matrixColSize;

    zigzag = (int *)malloc(ret_size*sizeof(int));

    for(i=0; i<ret_size; i++)
    {
        zigzag[i] = matrix[y][x];
        if(dir == 0)
        {
            if(x == matrixColSize-1)
            {
                y += 1;
                dir = 1;
            }
            else if(y == 0)
            {
                x += 1;
                dir = 1;
            }
            else
            {
                x += 1;
                y -= 1;
            }
        }
        else
        {
            if(y == matrixRowSize-1)
            {
                x += 1;
                dir = 0;
            }
            else if(x == 0)
            {
                y += 1;
                dir = 0;
            }
            else
            {
                x -= 1;
                y += 1;
            }
        }
    }

    *returnSize = ret_size;
    return zigzag;
}

