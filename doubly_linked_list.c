// 双向链表
#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node* prev;
    struct Node* next;
} Node;
//初始化链表
Node* initList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0; // 可以根据需要初始化数据
    head->prev = NULL;
    head->next = NULL;
    return head;
}
//头插法
void insertAtHead(Node* head, ElementType data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev=head;
    newNode->next=head->next;
    if(head->next!=NULL){
        head->next->prev=newNode;
    }
 head->next=newNode;
}
//遍历链表
void traverseList(Node* head) {
    Node* current = head->next; // 跳过头节点
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");

}
int main(){
    Node*list=initList();
    insertAtHead(list,10);
    insertAtHead(list,20); 
    insertAtHead(list,30);
    traverseList(list);
    return 0;
}