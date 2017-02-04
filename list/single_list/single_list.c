#include "single_list.h"
#include <stdlib.h>
#include <stdio.h>

struct SLinkNode* CreateSList(ElemType* pData, int nLen)
{
    struct SLinkNode* pHead = (struct SLinkNode*) malloc(sizeof(struct SLinkNode));
    if (pHead == NULL)
    {
        return NULL;
    }
    pHead->m_pNext = NULL;
    if (pData == NULL || nLen <= 0)
    {
        return pHead;
    }
    struct SLinkNode* pPrev = pHead;
    int i;
    for (i = 0; i < nLen; i ++)
    {
        struct SLinkNode* pCur = (struct SLinkNode*) malloc(sizeof(struct SLinkNode));
        if (pCur == NULL)
        {
            return NULL;
        }
        pCur->m_tData = pData[i];
        pCur->m_pNext = NULL;
        pPrev->m_pNext = pCur;
        pPrev = pPrev->m_pNext;
    }
    return pHead;
}

bool SListInsert(struct SLinkNode* pHead, int nPos, ElemType x)
{
    if (pHead == NULL || nPos < 0)
    {
        return false;
    }
    int i = 0;
    struct SLinkNode* p = pHead;
    for (; i < nPos; i ++)
    {
        p = p->m_pNext;
        if (p == NULL)
        {
            return false;
        }
    }
    struct SLinkNode* s = (struct SLinkNode*) malloc(sizeof(struct SLinkNode));
    if (s == NULL)
    {
        return false;
    }
    s->m_tData = x;
    s->m_pNext = p->m_pNext;
    p->m_pNext = s;
    return true;
}

bool SListGetElem(struct SLinkNode* pHead, int nPos, ElemType* outX)
{
    if (pHead == NULL || nPos < 0 || outX == NULL)
    {
        return false;
    }
    int i = 0;
    struct SLinkNode* p = pHead;
    for (; i < nPos; i ++)
    {
        p = p->m_pNext;
        if (p == NULL)
        {
            return false;
        }
    }
    *outX = p->m_tData;
    return true;
}

bool SListDelete(struct SLinkNode* pHead, int nPos, ElemType* outX)
{
    if (pHead == NULL || nPos < 0 || outX == NULL)
    {
        return false;
    }
    int i = 0;
    struct SLinkNode* p = pHead;
    for (; i < nPos; i ++)
    {
        p = p->m_pNext;
        if (p == NULL)
        {
            return false;
        }
    }
    struct SLinkNode* q = p->m_pNext;
    if (q == NULL)
    {
        return false;
    }
    p->m_pNext = q->m_pNext;
    *outX = q->m_tData;
    return true;
}

void SListReverse(struct SLinkNode* pHead)
{
    if (pHead == NULL || pHead->m_pNext == NULL)
    {
        return ;
    }
    //regard as no head list
    struct SLinkNode* pBegin = pHead->m_pNext;
    struct SLinkNode* pAhead = pHead->m_pNext;
    struct SLinkNode* p = NULL;
    do 
    {
        p = pAhead->m_pNext;
        if (p == NULL)
        {
            break;
        }
        pAhead->m_pNext = p->m_pNext;
        p->m_pNext = pBegin;
        pBegin = p;
    } while (true);
    ////////////////////
    pHead->m_pNext = pBegin;
}

void SListShow(struct SLinkNode* pHead)
{
    struct SLinkNode* pCur = pHead->m_pNext;
    while (pCur->m_pNext)
    {
        printf("%d ==> ", pCur->m_tData);
        pCur = pCur->m_pNext;
    }
    printf("%d\n", pCur->m_tData);
}