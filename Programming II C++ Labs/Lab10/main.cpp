/* 
 * Project: 
 * Author: Zack Fravel
 *
 * Created on April 4, 2016, 1:59 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


int binarySearch(int* a, int left, int right, int x)
{
    if(left == right)
    {
        if (a[left] == x)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid = (left + right)/2;
        if(a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            //return a binary search of the left half
            return binarySearch(a, left, a[mid], x);
        }
        else
        {
            //return a binary search of the right half
            return binarySearch(a, a[mid], right, x);
        }
    }
}

int mss(int* a, int left, int right)
{
    if(left == right)
        return a[left];
    else
    {
        int mid = (right+left)/2;
        // case 1: sum crosses the boundary
        //Left Side
        int leftSum = a[mid];
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum = sum + a[i];
            if (sum > leftSum)
                leftSum = sum;
        }
        // Right Side
        int rightSum = a[mid + 1];
        sum = 0;
        for (int i = mid+1; i <= right; i++)
        {
            sum = sum + a[i];
            if (sum > rightSum)
                rightSum = sum;
        }
        
        int boundaryMaxSum = leftSum + rightSum;
        
        // case 2: sum only on left
        int leftMaxSum = mss(a, left, mid);
        
        // case 3: sum only on right
        int rightMaxSum = mss(a, mid+1, right);
        
        // Compare final values
        if (boundaryMaxSum > leftMaxSum && boundaryMaxSum > rightMaxSum)
            return boundaryMaxSum;
        else if(leftMaxSum > rightMaxSum)
            return leftMaxSum;
        else
            return rightMaxSum;
    }
}

int main() 
{
    int array1[10];
    int array2[6] = {2, -1, 5, -3, -12, 5};
    for(int i = 0; i < 10; i++)
    {
        array1[i] = i;
    }
    
    // Binary Search
    cout << binarySearch(array1, 0, 9, 7) << endl;      // 7 
    // Maximum Sub Sequence
    cout << mss(array2, 0, 5) << endl;                  // 6
    
    
    return 0;
}

