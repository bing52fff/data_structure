#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>

static void Test1()
{
    int data[5] = { 0, 1, 2, 3, 4 };
    struct SLinkNode* pHead = CreateSList(data, sizeof(data) / sizeof(int));
    SListShow(pHead);
    SListInsert(pHead, 5, 5);
    int x = 0;
    SListDelete(pHead, 0, &x);
    SListShow(pHead);
    SListReverse(pHead);
    SListShow(pHead);
}

int main()
{
    printf("==============test1===============\n");
    Test1();
    return 0;
}