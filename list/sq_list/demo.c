#include "sq_list.h"
#include <stdio.h>
#include <stdlib.h>

static void Test1()
{
    struct SqNode sqList;
    SqInit(&sqList, 0);
    SqInsert(&sqList, 1, 1);
    SqInsert(&sqList, 0, 1);
    SqInsert(&sqList, 1, 2);
    SqInsert(&sqList, 1, 3);
    SqShow(&sqList);
}

static void Test2()
{
    struct SqNode sqList;
    SqInit(&sqList, 0);
    SqInsert(&sqList, 1, 1);
    SqInsert(&sqList, 0, 1);
    SqInsert(&sqList, 1, 2);
    SqInsert(&sqList, 1, 3);
    SqDelete(&sqList, 2);
    SqFind(&sqList, 3);
    SqShow(&sqList);
}

static void Test3()
{
    struct SqNode sqList1, sqList2;
    SqInit(&sqList1, 0);
    SqInit(&sqList2, 0);
    SqInsert(&sqList1, 0, 6);
    SqInsert(&sqList1, 0, 3);
    SqInsert(&sqList2, 0, 12);
    SqInsert(&sqList2, 0, 9);
    SqInsert(&sqList2, 0, 2);

    struct SqNode sqOut;
    SqMerge(&sqList1, &sqList2, &sqOut);
    SqShow(&sqOut);
}

int main()
{
    printf("==============test1===============\n");
    Test1();
    printf("==============test2===============\n");
    Test2();
    printf("==============test3===============\n");
    Test3();
    return 0;
}