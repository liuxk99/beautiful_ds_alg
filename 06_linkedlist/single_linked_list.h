// linked_list.h

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* create_node(int data);

// 头插法插入节点
void insert_head(Node** list, Node* node);

// 尾插法插入节点
void insert_tail(Node** list, Node* node);

// 在指定位置 index 插入节点（从0开始）
void insert_at_index(Node** list, int index, Node* node);

// insert a node(new_node) after specified node(p)
void insert(Node* p, Node* new_node);

// 删除指定值的第一个节点
void delete_node(Node** list, int key);

// 查找某个值是否存在
int search(Node* list, int key);

// search a node with specified value, return previous node when it's not found
Node* search_node(Node* list, int key);

// 反转链表
void reverse_list(Node** list);

// 打印链表
void print_list(Node* list);

void print_list_msg(Node* list, char* msg);

// 释放整个链表
void free_list(Node** list);

#endif // SINGLE_LINKED_LIST_H