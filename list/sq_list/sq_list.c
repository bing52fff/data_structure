#include "sq_list.h"
#include <stdlib.h>
#include <stdio.h>

bool SqInit(struct SqNode* pHead, int nSize)
{
    if (pHead == NULL)
    {
        return false;
    }
    int nInitSize = nSize < INIT_SIZE ? INIT_SIZE : nSize;
    pHead->m_pElem = (ElemType*) malloc(nInitSize * sizeof(ElemType));
    if (pHead->m_pElem == NULL)
    {
        return false;
    }
    pHead->m_nSize = 0;
    pHead->m_nCapacity = nInitSize;
    return true;
}

bool SqInsert(struct SqNode* pHead, int nPos, ElemType x)
{
    if (pHead == NULL || pHead->m_pElem == NULL || nPos < 0 || nPos > pHead->m_nSize)
    {
        return false;
    }
    if (pHead->m_nSize >= pHead->m_nCapacity)
    {
        pHead->m_pElem = (ElemType*) realloc(pHead->m_pElem, pHead->m_nCapacity + INCREASEMENT_SIZE);
        if (pHead->m_pElem == NULL)
        {
            return false;
        }
        pHead->m_nCapacity += INCREASEMENT_SIZE;
    }
    int i = pHead->m_nSize;
    while (i > nPos)
    {
        pHead->m_pElem[i] = pHead->m_pElem[i - 1];
        i --;
    }
    pHead->m_pElem[nPos] = x;
    pHead->m_nSize ++;
    return true;
}

bool SqDelete(struct SqNode* pHead, int nPos)
{
    if (pHead == NULL || pHead->m_pElem == NULL || nPos >= pHead->m_nSize || nPos < 0)
    {
        return false;
    }
    for (; nPos < pHead->m_nSize - 1; nPos ++)
    {
        pHead->m_pElem[nPos] = pHead->m_pElem[nPos + 1];
    }
    pHead->m_nSize --;
    return true;
}

int SqFind(struct SqNode* pHead, ElemType x)
{
    int pos = -1;
    if (pHead == NULL || pHead->m_pElem == NULL)
    {
        return pos;
    }
    for (pos = 0; pos < pHead->m_nSize; pos ++)
    {
        if (pHead->m_pElem[pos] == x)
        {
            break;
        }
    }
    if (pos >= pHead->m_nSize)
    {
        pos = -1;
    }
    return pos;
}

//ordered sqlist merge
bool SqMerge(struct SqNode* pList1, struct SqNode* pList2, struct SqNode* pListOut)
{
    if (pList1 == NULL || pList1->m_pElem == NULL || pList2 == NULL || 
        pList2->m_pElem == NULL || pListOut == NULL)
    {
        return false;
    }
    int nTotalSize = pList1->m_nSize + pList2->m_nSize;
    if (!SqInit(pListOut, nTotalSize))
    {
        return false;
    }
    int i, j, k;
    for (i = 0, j = 0, k =0; i < pList1->m_nSize && j < pList2->m_nSize; k ++)
    {
        if (pList1->m_pElem[i] <= pList2->m_pElem[j])
        {
            pListOut->m_pElem[k] = pList1->m_pElem[i ++];
        }
        else
        {
            pListOut->m_pElem[k] = pList2->m_pElem[j ++];
        }
    }
    while (i < pList1->m_nSize)
    {
        pListOut->m_pElem[k ++] = pList1->m_pElem[i ++];
    }
    while (j < pList2->m_nSize)
    {
        pListOut->m_pElem[k ++] = pList2->m_pElem[j ++];
    }
    pListOut->m_nSize = nTotalSize;
    return true;
}

void SqShow(struct SqNode* pHead)
{
    int i = 0;
    for (; i < pHead->m_nSize - 1; i ++)
    {
        printf("%d ==> ", pHead->m_pElem[i]);
    }
    printf("%d\n", pHead->m_pElem[i]);
}