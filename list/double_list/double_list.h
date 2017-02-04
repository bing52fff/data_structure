#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

typedef int ElemType;
typedef enum { false, true } bool;

struct DLinkNode
{
    ElemType            m_tData;
    struct DLinkNode*   m_pPrev;
    struct DLinkNode*   m_pNext;
};

bool DListInsert(struct DLinkNode** pHead, int nPos, ElemType x);

bool DListDelete(struct DLinkNode* pHead, int nPos, ElemType* pOut);

void DListShow(struct DLinkNode* pHead);

#endif  //_DOUBLE_LIST_H