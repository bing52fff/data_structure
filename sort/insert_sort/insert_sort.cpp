#include <stdio.h>
#include <stdlib.h>

static void InsertSort(int* pArray, int len)
{
    if (pArray == NULL || len <= 0)
    {
        return ;
    }
    int key = 0;
    int i, j;
    for (i = 1; i < len; i ++)
    {
        key = pArray[i];
        for (j = i - 1; j >= 0; j --)
        {
            if (key >= pArray[j])
            {
                break;
            }
            pArray[j + 1] = pArray[j];
        }
        pArray[j + 1] = key;
    }
}

static void PrintArray(int* pArray, int len)
{
    if (pArray == NULL || len <= 0)
    {
        return ;
    }
    for (int ix = 0; ix < len - 1; ix ++)
    {
        printf("%d, ", pArray[ix]);
    }
    printf("%d\n", pArray[len - 1]);
}

static void Test1()
{
    int array[] = { 3, 4, 7, 1, 6, 2, 5, 8 };
    int arLen = sizeof(array) / sizeof(int);
    printf("Before sort: ");
    PrintArray(array, arLen);
    InsertSort(array, arLen);
    printf("After sort: ");
    PrintArray(array, arLen);
}

int main()
{
    Test1();
    return 0;
}