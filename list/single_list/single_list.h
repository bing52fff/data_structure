#ifndef _SINGLE_LIST_H
#define _SINGLE_LIST_H

typedef int ElemType;
typedef enum { false, true } bool;

struct SLinkNode
{
    ElemType            m_tData;
    struct SLinkNode*    m_pNext;
};

struct SLinkNode* CreateSList(ElemType* pData, int nLen);

bool SListInsert(struct SLinkNode* pHead, int nPos, ElemType x);

bool SListGetElem(struct SLinkNode* pHead, int nPos, ElemType* outX);

bool SListDelete(struct SLinkNode* pHead, int nPos, ElemType* outX);

void SListReverse(struct SLinkNode* pHead);

void SListShow(struct SLinkNode* pHead);

#endif  //_SINGLE_LIST_H