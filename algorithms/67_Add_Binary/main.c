/*
* Source : https://leetcode.com/problems/add-binary/description/
*
* Author : Jackal Lin
*
* Description:
*   Given two binary strings, return their sum (also a binary string).
*   The input strings are both non-empty and contains only characters 1 or 0.
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

char* addBinary(char* a, char* b)
{
    int strlen_a = strlen(a);
    int strlen_b = strlen(b);
    char *ptr_a;
    char *ptr_b;
    char *ret;

    if(strlen_a < strlen_b)
    {
        ptr_b = a;
        a = b;
        b = ptr_b;

        strlen_a ^= strlen_b;
        strlen_b ^= strlen_a;
        strlen_a ^= strlen_b;
    }

    ptr_a = &a[strlen_a-1];
    ptr_b = &b[strlen_b-1];

    *ptr_a += (*ptr_b - '0');
    ptr_a--;
    ptr_b--;

    while(ptr_b >= b)
    {
        if(*(ptr_a+1) > '1')
        {
            *(ptr_a+1) -= 2;
            *ptr_a += (*ptr_b - '0' + 1);
        }
        else
        {
            *ptr_a += (*ptr_b - '0');
        }

        ptr_a--;
        ptr_b--;
    }

    while(ptr_a >= a)
    {
        if(*(ptr_a+1) > '1')
        {
            *(ptr_a+1) -= 2;
            *ptr_a += 1;
        }
        else
        {
            break;
        }

        ptr_a--;
    }

    if(*a > '1')
    {
        ret = (char *)malloc(strlen_a+2);
        ret[0] = '1';
        a[0] -= 2;
        memcpy(&ret[1], a, strlen_a+1);
    }
    else
    {
        ret = (char *)malloc(strlen_a+1);
        memcpy(&ret[0], a, strlen_a+1);
    }

    return ret;
}

