/*
* Source : https://leetcode.com/problems/array-partition-i/description/
*
* Author : Jackal Lin
*
* Description:
*   Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
*
*   Note:
*   n is a positive integer, which is in the range of [1, 10000].
*   All the integers in the array will be in the range of [-10000, 10000].
*
* Complexity:
*   Time:O(N)
*   Space:O(1)
*
* Beats: 56.79%
*
* Approach:
*
*/

#define min(a,b) ((a>b)?(b):(a))

/* copy from wikipedia */
static void merge_sort(int *arr, int len)
{
    int* a = arr;
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

int arrayPairSum(int* nums, int numsSize)
{
    int i;
    int sum = 0;

    merge_sort(nums, numsSize);

    for(i=0; i<numsSize; i+=2)
    {
        sum += nums[i];
    }

    return sum;
}

