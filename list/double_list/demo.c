#include <stdio.h>
#include <stdlib.h>

#include "double_list.h"

void Test1()
{
    struct DLinkNode* pList;
    DListInsert(&pList, 0, 5);
    DListInsert(&pList, 0, 4);
    DListInsert(&pList, 0, 3);
    DListInsert(&pList, 0, 2);
    DListInsert(&pList, 0, 1);
    DListShow(pList);
}

void Test2()
{
    struct DLinkNode* pList;
    DListInsert(&pList, 0, 5);
    DListInsert(&pList, 0, 4);
    DListInsert(&pList, 0, 3);
    DListInsert(&pList, 0, 2);
    DListInsert(&pList, 0, 1);
    DListShow(pList);
    int x = 0;
    DListDelete(pList, 2, &x);
    DListShow(pList);
}

int main()
{
    printf("====================TEST1=================\n");
    Test1();
    printf("====================TEST2=================\n");
    Test2();
    return 0;
}