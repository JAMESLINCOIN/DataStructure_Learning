#pragma once
#include <iostream>
typedef struct LNode
{//!单链表
    unsigned int data;//!数据域
    LNode* next;//!指针域
}LNode,*LinkList;//Link_list为指向结构体的指针类型，LNode表示链表节点

//注意区分头结点与头指针
//头结点包含指针域和数据域，指针域指向首元结点，数据域可以不存储数据；
//头指针为指向链表第一个结点（头结点或者首元结点）的指针
//单链表可以没有头结点


/*		单链表初始化
* 说明:  ①生成新结点为头结点，用头指针L指向头结点
        ②头结点的指针域置为空
* params: list_sq:线性表的引用，init_size:初始存储容量
* outputs: true:成功，false:失败
*/
bool InitList_link(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return true;
}

/*		获取单链表中的第i个结点的元素的值
* 说明:  i>=1,从首元结点开始算
* params: L:链表指针，nIndex:位置索引（从1开始）,value:取出的值
* outputs: true:成功，false:失败
*/
bool GetItem_link(LinkList L,int nIndex,unsigned int &value)
{
    if(nIndex <= 0)
        return false;
    LinkList tmp;//定义遍历用的指针
    int count = 0;//当前所在结点
    tmp = L->next;//首先指向首元结点
    count ++;
    while (tmp != NULL)
    {
        if(count == nIndex)
        {
            value = tmp->data;
            return true;
        }
        tmp = tmp->next;
        count ++;       
    }
    return false;
    
}

/*		单链表的按值查找
* 说明:  
* params: L:链表指针，value:查找的值
* outputs: LNode*:查找到的链表结点指针，失败则会返回空指针
*/
LNode* LocateItem_link(LinkList L,unsigned int value)
{
    LNode* tmp;
    tmp = L->next;
    while (tmp!= NULL  && tmp->data != value)
    {
        tmp = tmp->next;
    }
    return tmp;
}

/*		单链表的插入
* 说明:  在第nIndex个结点处插入值为value的新结点，即插入到a（i-1）和ai之间
* params: L:链表指针，nIndex:位置索引（从1开始）,value:插入的值
* outputs: true:成功，false:失败
*/
bool ListInsert_link(LinkList L,int nIndex,unsigned int value)
{
    //①查找第i-1个结点
    LNode* tmp = L->next;
    int count = 0;
    if(nIndex == 1)
    {
        LNode* pNode = new LNode;
        pNode->data = value;
        pNode->next = L->next;
        L->next = pNode;
        return true;
    }
    while (tmp != NULL  &&  count < (nIndex-1))
    {
        tmp = tmp->next;
        count ++;
    }
    if(tmp == NULL || count > (nIndex-1))
        return false;
    //②生成新结点
    LNode* pNode = new LNode;
    //③新结点的数据域置为待插入值
    pNode->data = value;
    //④新结点的指针域指向ai
    pNode->next = tmp->next;
    //⑤a(i-1)的指针域指向新结点
    tmp->next = pNode;
    return true;
}


/*		单链表的删除
* 说明:  删除第nIndex个结点
* params: L:链表指针，nIndex:位置索引（从1开始）
* outputs: true:成功，false:失败
*/
bool ListDelete_link(LinkList L,int nIndex)
{
    //①查找第i-1个结点
    LNode* tmp = L->next;
    int count = 0;
    while (tmp->next != NULL  &&  count < (nIndex-1))
    {
        tmp = tmp->next;
        count ++;
    }
    if(tmp->next == NULL || count > (nIndex-1))
        return false;
    LNode* tmp2 = tmp->next;
    //②将ai-1指针域指向ai+1
    tmp->next = tmp2->next;
    //③删除ai,释放空间
    delete tmp2;
}

/*		前插法创建单链表
* 说明:  将新节点依次插入链表的头部（头结点后面）来创建链表
* params: L:链表指针，nNodeNum:结点个数
* outputs: true:成功，false:失败
*/
bool CreateLinkList_front(LinkList &L,int nNodeNum)
{
    if(nNodeNum <= 0)
        return false;
    //①创建一个只有头结点的空链表
    L = new LNode;
    L->next = NULL;
    //②根据输入的值插入新结点
    for (int i = 0; i < nNodeNum; ++i)
    {
        LNode* p = new LNode;
        std::cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
    
}

/*		后插法创建单链表
* 说明:  将新节点依次插入链表的尾部来创建链表
* params: L:链表指针，nNodeNum:结点个数
* outputs: true:成功，false:失败
*/
bool CreateLinkList_back(LinkList &L,int nNodeNum)
{
    if(nNodeNum <= 0)
        return 0;
    //①创建一个只有头结点的空链表
    L = new LNode;
    L->next = NULL;    
    //②尾指针初始化，指向头结点
    LNode* pTail = L;
    //③依次插入结点,将新结点插到尾结点之后，然后尾指针指向最新结点
    for (int i = 0; i < nNodeNum; ++i)
    {
        LNode* p = new LNode;
        std::cin>>p->data;
        p->next = NULL;
        pTail->next = p;
        pTail = p;
    }
}

//打印单链表所有元素
void printList_link(LinkList L)
{
    LNode* p = L->next;
    while (p)
    {
        std::cout<<p->data;
        if (p->next)
        {
            std::cout<<",";
        }
        p = p->next;
    }
    std::cout<<std::endl;
}




//合并有序链表
void MergeSqList_link(LinkList &LA,LinkList &LB,LinkList &LC)
{
    //①初始化LC，头结点为LA的头结点
    LC = LA;
    //②初始化指针pa，pb分别指向LA,LB的首元结点，pc指向LC的头结点
    LNode *pa,*pb,*pc;
    pa = LA->next;
    pb = LB->next;
    pc = LC;
    //③当pa，pb均未到达队尾时，比较pa，pb数值域大小，将较小者对应结点插入到LC后面
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pa = pa->next;
            pc = pc->next;
        }
        else
        {
            pc->next = pb;
            pb = pb->next;
            pc = pc->next;
        }
    }
    //④当pa或pb一方到达队尾时，将剩余的一方的当前结点插入LC后面即可
    // while (pa)
    // {
    //     pc->next = pa;
    // }
    // while (pb)
    // {
    //     pc->next = pb;
    // }
    pc->next = pa?pa:pb;
    //⑤释放LB的头结点
    delete LB;
}