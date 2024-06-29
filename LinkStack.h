#pragma once
#include <iostream>

typedef struct StackNode
{//链式栈数据结构
    unsigned int data;
    struct  StackNode* next;
}StackNode,*LinkStack;


/*		链栈初始化
* 说明:  构造空栈，直接将栈顶指针置为空
* params: sqS:线性栈的引用
* outputs: true:成功，false:失败
*/
bool InitLinkStack(LinkStack L)
{
    L = NULL;
    return true;
}

/*		入栈
* 说明:  不存在栈满的情况，构造插入的节点，并将栈顶指针改为新节点即可
* params: lS:链栈的引用
* outputs: true:成功，false:失败
*/
bool Push_linkStack(LinkStack &lS,unsigned int value)
{
    //在栈顶插入元素e
    StackNode* p = new StackNode;
    p->data = value;
    //前插
    p->next = lS;
    //更新栈顶指针
    lS = p;
}


/*		出栈
* 说明:  ①判断栈空
        ②将栈顶元素赋给value
        ③临时保存栈顶元素的空间以备释放
        ④修改栈顶指针
        ⑤释放原栈顶元素指针
* params: lS:链栈的引用
* outputs: true:成功，false:失败
*/
bool Pop_linkStack(LinkStack &lS,unsigned int &value)
{
    if(!lS)
        return NULL;
    value = lS->data;
    StackNode* p = lS;
    lS = lS->next;
    delete p;
    return true;
}


/*		取栈顶元素
* 说明:  当栈非空时，取栈顶元素的值，但不改变栈顶指针
* params: lS:链栈的引用
* outputs: true:成功，false:失败
*/
unsigned int GetTop_lStack(LinkStack lS)
{
    if(!lS)
        return 0;
    return lS->data;
}