#include <stdio.h>
#include <iostream>

#include "Linear_list.h"
#include "Link_list.h"
void Linear_List_operation();
void Link_list_operation();

int main()
{
    printf("Hello, from DataStructure!\n");
    //Linear_List_operation();//!顺序表基本操作
    Link_list_operation();
    return 0;
}


//线性表操作
void Linear_List_operation()
{
    Linear_list list1;
	InitList_Sq(list1,100);
	std::cout<<list1.length<<std::endl<<list1.listSize<<std::endl;   
    // unsigned int value1;
    // std::cin>>value1;
    // ListInsert_Sq(list1,1,value1);
    // std::cout<<"list.first="<<list1.elem[0]<<std::endl;
    // std::cout<<list1.length<<std::endl<<list1.listSize<<std::endl;
    // std::cout<<"the index of value "<<value1<<" is: "<<LocateItem_Sq(list1,value1)<<std::endl;

    //合并两个顺序表·
    Linear_list list2;
	InitList_Sq(list2,100);
	std::cout<<list2.length<<std::endl<<list2.listSize<<std::endl;
    Linear_list list3;

    for (int i = 0; i < 10; i++)
    {
        ListInsert_Sq(list1,i+1,i+1);
        ListInsert_Sq(list2,i+1,i+5);
    }
    std::cout<<"before merge,list1:";
    PrintList_sq(list1);
    std::cout<<"list2:";
    PrintList_sq(list2);
    //MergeList_sq(list1,list2);//无序
    MergeSqList_sq(list1,list2,list3);//非递减有序
    std::cout<<"after merge,list1:";
    PrintList_sq(list1);
    std::cout<<"list2:";
    PrintList_sq(list2);
    std::cout<<"list3:";
    PrintList_sq(list3);
    system("pause");
}


//链表操作
void Link_list_operation()
{
    //合并链表
    LinkList LA,LB;
    CreateLinkList_back(LA,5);
    CreateLinkList_back(LB,5);
    std::cout<<"LA:";
    printList_link(LA);
    std::cout<<"LB:";
    printList_link(LB);
    LinkList LC;
    MergeSqList_link(LA,LB,LC);
    std::cout<<"LC:";
    printList_link(LC);
    system("pause");
}