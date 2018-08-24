/*
* Source : https://leetcode.com/problems/pascals-triangle/description/
*
* Author : Jackal Lin
*
* Description:
*   Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
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
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes)
{
    int i;
    int j;
    int **triangle;
    int *size;

    size = (int *)malloc(sizeof(int)*numRows);
    triangle = (int **)malloc(sizeof(int *)*numRows);

    for(i=0; i<numRows; i++)
    {
        size[i] = i+1;
        triangle[i] = (int *)malloc(sizeof(int)*size[i]);

        triangle[i][0]=1;
        triangle[i][i]=1;
        for(j=1; j<i; j++)
            triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
    }

    *columnSizes = size;
    return triangle;
}

