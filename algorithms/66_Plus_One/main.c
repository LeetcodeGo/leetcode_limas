/*
* Source : https://leetcode.com/problems/plus-one/description/
*
* Author : Jackal Lin
*
* Description:
*   Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
*   The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
*   You may assume the integer does not contain any leading zero, except the number 0 itself.
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i;
    int *arr;
    int *ptr;

    digits[digitsSize-1] += 1;

    for(i=digitsSize-1; i>0; i--)
    {
        if(digits[i] <= 9)
            break;

        digits[i-1] += 1;
        digits[i] = 0;
    }

    if(digits[0] == 10)
    {
        arr = (int *)malloc((digitsSize+1)*sizeof(int));
        arr[0] = 1;
        ptr = arr+1;
        digits[0] = 0;
        *returnSize = (digitsSize+1);
    }
    else
    {
        arr = (int *)malloc((digitsSize)*sizeof(int));
        ptr = arr;
        *returnSize = (digitsSize);
    }

    for(i=0; i<digitsSize; i++)
        ptr[i] = digits[i];

    return arr;
}
