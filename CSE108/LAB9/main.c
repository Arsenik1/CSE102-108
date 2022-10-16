#include <stdio.h>
#include <stdlib.h>

int *findMaximumDistance(int distanceOfCities[], int start, int end, int result[]);

int main()
{
    int distanceOfCities[10] = {20,56,18,45,40};
    int *arr;
    int res[5];
    arr = findMaximumDistance(distanceOfCities, 0, 4, res);
    printf("%d, %d", arr[0], arr[1]);
    return 0;
}

int *findMaximumDistance(int distanceOfCities[], int start, int end, int result[])
{
    int arr1[2];
    int arr2[2];
    int arr3[2];
    int temp;
    if(start == end)
    {
        result[0] = distanceOfCities[start];            /*since there is only one value, it is being assigned to 2 places.*/
        result[1] = result[0];
        return result;
    }
    else if(start + 1 == end)
    {
        result[0] = distanceOfCities[start];            /*there are only 2 values left so each one is assigned to an index.*/
        result[1] = distanceOfCities[end];
        return result;
    }
    else if(end > start)
    {
        findMaximumDistance(distanceOfCities, start, (start + end) / 2, result);    /*first half*/
        arr1[1] = result[1];        /*results are being saved temporarily*/
        arr1[0] = result[0];
        findMaximumDistance(distanceOfCities, (start + end) / 2 + 1, end, result);  /*second half*/
        arr2[1] = result[1];
        arr2[0] = result[0];

        if(arr1[0] < arr1[1])       /*these ifs equalize arr1's zeroth index to the biggest and to the smallest.*/
            arr1[0] = arr1[1];
        if(arr1[0] < arr2[0])
            arr1[0] = arr2[0];
        if(arr1[0] < arr2[1])
            arr1[0] = arr2[1];
        temp = arr1[0];        
        arr3[0] = temp;         /*using a temp integer just for safety.*/
        if(arr1[0] > arr1[1])
            arr1[0] = arr1[1];
        if(arr1[0] > arr2[0])
            arr1[0] = arr2[0];
        if(arr1[0] > arr2[1])
            arr1[0] = arr2[1];
        temp = arr1[0];
        arr3[1] = temp;
        
        result[0] = arr3[0];    /*to carry out the values, result array is being assigned.*/
        result[1] = arr3[1];
        
        return result;
    }
        
}