// single_linked_list.c
#include "single_linked_list.h"

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_head(Node** list, Node* node) {
    if (node == NULL) return;
    node->next = *list;
    *list = node;
}

void insert_tail(Node** list, Node* node) {
    if (node == NULL) return;

    if (*list == NULL) {
        *list = node;
        return;
    }

    Node* p = *list;
    while (p->next != NULL)
        p = p->next;

    p->next = node;
}

void insert_at_index(Node** list, int index, Node* node) {
    if (index < 0 || node == NULL) {
        printf("Invalid input.\n");
        return;
    }

    if (index == 0) {
        insert_head(list, node);
        return;
    }

    Node* p = *list;
    for (int i = 0; p != NULL && i < index - 1; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Index out of bounds.\n");
        return;
    }

    node->next = p->next;
    p->next = node;
}

// implement insert()
void insert(Node* p, Node* new_node) {
    if (p == NULL) {
        printf("Invalid input.\n");
        return;
    }

    new_node->next = p->next;
    p->next = new_node;
}

void delete_node(Node** list, int key) {
    Node* p = *list;
    Node* prev = NULL;

    while (p != NULL && p->data != key) {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
        return;

    if (prev == NULL) {
        *list = p->next;
    } else {
        prev->next = p->next;
    }

    free(p);
}

int search(Node* list, int key) {
    Node* p = list;
    while (p != NULL) {
        if (p->data == key)
            return 1;
        p = p->next;
    }
    return 0;
}

Node *search_node(Node *list, int key) {
    Node* p = list;
    Node* prev = list;
    while (p != NULL) {
        if (p->data < key) {
            prev = p;
            p = p->next;
        }
        else {
            break;
        }
    }
    
    return prev;
}

void reverse_list(Node** list) {
    Node *prev = NULL, *p = *list, *next = NULL;

    while (p != NULL) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }

    *list = prev;
}

void print_list(Node* list) {
    Node* p = list;
    int idx = 0;
    while (p != NULL) {
        printf("[%02d]: %08d\n", idx++, p->data);
        p = p->next;
    }
}

// implement print_list_msg()
void print_list_msg(Node* list, char* msg) {
    static int idx = 0;
    printf("=> %d.%s: \n", ++idx, msg);
    print_list(list);
}

void free_list(Node** list) {
    Node* p = *list;
    Node* tmp;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    *list = NULL;
}