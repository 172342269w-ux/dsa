// 双向链表
#include "doubly_linked_list.h"
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
//尾插法
//先获取尾节点
Node*getTail(Node*head){
    Node*current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    return current;
}
void insertAtTail(Node* head,ElementType e){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=e;
    newnode->next=NULL;
    Node* tail=getTail(head);
    tail->next=newnode;
    newnode->prev=tail;
}
//指定位置插入
void insertAtPosition(Node* head,ElementType e,int position){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=e;
    Node* current=head;
    int index=0;
    while(current!=NULL&&index<position-1){
        current=current->next;
        index++;
    }
    if(current!=NULL){
        newnode->next=current->next;
        newnode->prev=current;
        if(current->next!=NULL){
            current->next->prev=newnode;
        }
        current->next=newnode;
    }
}
//删除节点
void deleteNode(Node* head, ElementType e) {
    Node* current = head->next;
    while (current != NULL) {
        Node* next = current->next; // 提前保存，防止 free 后访问野指针
        if (current->data == e) {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
        }
        current = next;
    }
}
int main(){
    Node*list=initList();
    insertAtHead(list,10);
    insertAtHead(list,20); 
    insertAtHead(list,30);
    traverseList(list);
    insertAtTail(list,40);
    insertAtTail(list,50);
    traverseList(list);
    insertAtPosition(list,60,3);
    traverseList(list);
    deleteNode(list, 20);
    traverseList(list);
    free(list);
    return 0;
}