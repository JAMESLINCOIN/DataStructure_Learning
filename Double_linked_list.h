typedef struct DuLNode
{
    unsigned int data;//数据域
    DuLNode* prior;//直接后继
    DuLNode* next;//直接前驱
}DuLNode,*DuLinkList;
