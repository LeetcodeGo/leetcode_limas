/*
* Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*
* Author : Jackal Lin
*
* Description:
*   Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
*   The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
*
* Note:
*   Your returned answers (both index1 and index2) are not zero-based.
*   You may assume that each input would have exactly one solution and you may not use the same element twice.
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

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *ret;
    int left=0;
    int right=numbersSize-1;
    int mid;

    ret = (int *)malloc(sizeof(int)<<1);

    while(1)
    {
        if((numbers[left]+numbers[right]) == target)
            break;

        mid = (right+left)>>1;
        if((numbers[left]+numbers[right]) > target)
        {
            if((numbers[left]+numbers[mid]) > target)
                right = mid-1;
            else
                right--;
        }
        else
        {
            if((numbers[mid]+numbers[right]) < target)
                left = mid+1;
            else
                left++;
        }
    }

    ret[0] = left+1;
    ret[1] = right+1;
    *returnSize = 2;

    return ret;
}

