#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//public
typedef struct linked_list_node {
    struct linked_list_node* next;
    struct linked_list_node* prev;
    void* data;
} linked_list_node;

typedef struct linked_list {
    size_t length;
    size_t dataSize;
    linked_list_node* head;
    linked_list_node* tail;
} linked_list;

// Create a linked list on the heap and return a pointer to it.
linked_list* linked_list_create(size_t dataSize);

// Pop head of a linked list and free unused memory
void linked_list_pop_left(linked_list* ll);

// Pop tail of a linked list and free unused memory
void linked_list_pop(linked_list* ll);

// Append data to a linked list.
void linked_list_append(linked_list* l, void* data);

// Free a linked list.
void linked_list_free(linked_list* ll);

//private
// Free a linked list node.
void _linked_list_node_free(linked_list_node* ln);


/*
    IMPLEMENTATION
*/
linked_list* linked_list_create(size_t dataSize) {
    linked_list* ll_ptr = malloc(sizeof(linked_list));
    ll_ptr -> length = 0;
    ll_ptr -> dataSize = dataSize;
    ll_ptr -> head = NULL;
    ll_ptr -> tail = NULL;
    return ll_ptr;
}

void linked_list_append(linked_list* l, void* data) {
    linked_list_node* new_node = malloc(sizeof(linked_list_node));
    new_node -> next = NULL;
    new_node -> prev = NULL;
    new_node -> data = data;
    if (l -> length == 0){
        l -> head = new_node;
        l -> tail = new_node;
    }
    else {
        l -> tail -> next = new_node;
        new_node -> prev = l -> tail;
        l -> tail = l -> tail -> next;
    }
    l -> length += 1;
}

void linked_list_pop(linked_list* ll){
    linked_list_node* node = ll -> tail;
    if (node != NULL){
        if (ll -> length == 1){
            ll -> head = NULL;
            ll -> tail = NULL;
        }
        else {
            ll -> tail = ll -> tail -> prev;
        }
        _linked_list_node_free(node);
        ll -> length -= 1;
    }
}

void linked_list_pop_left(linked_list* ll) {

}

void _linked_list_node_free(linked_list_node* ln) {
    free(ln);
}

void linked_list_free(linked_list* ll) {
    for (int i = 0; i < ll -> length; i++){
        linked_list_node* node = ll -> head;
        ll -> head = ll -> head -> next;
        _linked_list_node_free(node);
    }
    free(ll);
}