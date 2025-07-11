#include "single_linked_list.h"

int main() {
    Node* head = NULL;

    // insert 0,1,4,5,6
    Node* n6 = create_node(6);
    insert_head(&head, n6);

    Node* n5 = create_node(5);
    insert_head(&head, n5);

    Node* n4 = create_node(4);
    insert_head(&head, n4);

    Node* n1 = create_node(1);
    insert_head(&head, n1);

    Node* n0 = create_node(0);
    insert_head(&head, n0);

    print_list_msg(head, "insert 0,1,4,5,6");

    // search value 2
    printf("查找值2是否存在：%s\n", search(head, 2) ? "存在" : "不存在");
    Node* prev = search_node(head, 2);
    insert(prev, create_node(2));
    print_list_msg(head, "insert 2");

    // reverse list
    reverse_list(&head);
    print_list_msg(head, "reverse list");
    
    free_list(&head);
    return 0;
}