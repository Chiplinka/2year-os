#include <stdio.h>

struct node{
    struct node *p;
    int value;
};

void print_list(struct node *head){
    struct node *cur =  head;
    while(cur != 0){
        printf("%d\n", cur->value);
        cur = cur->p;
    }
    //  printf("%s", "\n");
}

void insert_node(struct node *head, struct node *newnode, struct node *prevnode){
    struct node *cur = head;
    while(cur != 0){
        if(cur == prevnode){
            struct node* t = cur->p;
            cur->p = newnode;
            newnode->p = t;
        }
        cur = cur->p;
    }
}
void delete_node(struct node *head, struct node *delnode){
    struct node *cur = head;
    if(head == delnode){
        *head = *head->p;
        return;
    }
    while(cur->p != 0){
        if(cur->p == delnode){
            cur->p = cur->p->p;
        }
        cur = cur->p;
    }
}




int main() {
    struct node node1;
    node1.p = NULL;
    node1.value = 1;

    struct node node2;
    node2.p = NULL;
    node2.value = 2;

    struct node node3;
    node3.p = NULL;
    node3.value = 3;

    struct node node4;
    node4.p = NULL;
    node4.value = 4;

    insert_node(&node1, &node2, &node1);
    insert_node(&node1, &node3, &node2);
    printf("%s", "Initial structure: \n");
    print_list(&node1);
    insert_node(&node1, &node4, &node1);
    printf("%s", "Insert node4 after node1: \n");
    print_list(&node1);
    delete_node(&node1, &node1);
    printf("%s", "Delete node1: \n");
    print_list(&node1);
    delete_node(&node1, &node2);
    printf("%s", "Delete node2: \n");
    print_list(&node1);

    return 0;
}
