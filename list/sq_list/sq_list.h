#ifndef _SQ_LIST_H
#define _SQ_LIST_H

#define INIT_SIZE   100
#define INCREASEMENT_SIZE   10 

typedef enum { false, true } bool;
typedef int ElemType;

struct SqNode
{
    ElemType*       m_pElem;
    int             m_nSize;
    int             m_nCapacity;
};

bool SqInit(struct SqNode* pHead, int nSize);

bool SqInsert(struct SqNode* pHead, int nPos, ElemType x);

bool SqDelete(struct SqNode* pHead, int nPos);

int SqFind(struct SqNode* pHead, ElemType x);

bool SqMerge(struct SqNode* pList1, struct SqNode* pList2, struct SqNode* pListOut);

void SqShow(struct SqNode* pHead);

#endif  //_SQ_LIST_H