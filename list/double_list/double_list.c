#include "double_list.h"

#include <stdio.h>
#include <stdlib.h>

bool DListInsert(struct DLinkNode** pHead, int nPos, ElemType x)
{
    if (pHead == NULL || nPos < 0)
    {
        return false;
    }
    if (*pHead == NULL)
    {
        *pHead = (struct DLinkNode*) malloc(sizeof(struct DLinkNode));
        if (*pHead == NULL)
        {
            return false;
        }
        (*pHead)->m_pPrev = (*pHead)->m_pNext = *pHead;
    }
    int i = 0;
    struct DLinkNode* p = *pHead;
    for (; i < nPos; i ++)
    {
        p = p->m_pNext;
        if (p == *pHead)
        {
            return false;
        }
    }
    struct DLinkNode* pNewNode = (struct DLinkNode*) malloc(sizeof(struct DLinkNode));
    if (pNewNode == NULL)
    {
        return false;
    }
    pNewNode->m_tData = x;
    pNewNode->m_pPrev = p;
    pNewNode->m_pNext = p->m_pNext;
    p->m_pNext = pNewNode;
    pNewNode->m_pNext->m_pPrev = pNewNode;
    return true;
}

bool DListDelete(struct DLinkNode* pHead, int nPos, ElemType* pOut)
{
    if (pOut == NULL || pHead == NULL || nPos < 0 || pHead->m_pPrev == pHead->m_pNext)
    {
        return false;
    }
    int i = 0;
    struct DLinkNode* p = pHead;
    for (; i < nPos; i ++)
    {
        p = p->m_pNext;
        if (p == pHead)
        {
            return false;
        }
    }
    if (p->m_pNext == pHead)
    {
        return false;
    }
    struct DLinkNode* q = p->m_pNext;
    p->m_pNext = q->m_pNext;
    q->m_pNext->m_pPrev = p;
    *pOut = q->m_tData;
    free(q);
    return true;
}

void DListShow(struct DLinkNode* pHead)
{
    if (pHead == NULL)
    {
        return ;
    }
    struct DLinkNode* p = pHead->m_pNext;
    while (p->m_pNext != pHead)
    {
        printf("%d ==> ", p->m_tData);
        p = p->m_pNext;
    }
    printf("%d\n", p->m_tData);
}
