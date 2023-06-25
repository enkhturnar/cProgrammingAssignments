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

}

void linked_list_append(linked_list* l, void* data) {

}

void linked_list_pop(linked_list* ll){

}

void linked_list_pop_left(linked_list* ll) {

}

void _linked_list_node_free(linked_list_node* ln) {

}

void linked_list_free(linked_list* ll) {

}