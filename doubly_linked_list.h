// 双向链表
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "dsa_common.h"

typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* initList();
void insertAtHead(Node* head, ElementType data);
void traverseList(Node* head);
Node* getTail(Node* head);
void insertAtTail(Node* head, ElementType e);
void insertAtPosition(Node* head, ElementType e, int position);
void deleteNode(Node* head, ElementType e);

#endif // DOUBLY_LINKED_LIST_H
