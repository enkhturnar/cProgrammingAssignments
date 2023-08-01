#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "linked_list.h"

void assert_true(bool a, char* msg) {
    if (!a) {
        printf("%s: %d != true\n", msg, a);
        assert(false);
    }
}

void assert_false(bool a, char* msg) {
    if (a) {
        printf("%s: %d != false\n", msg, a);
        assert(false);
    }
}

void assert_eq_size_t(size_t a, size_t b, char* msg) {
    if (a != b) {
        printf("%s: %ld != %ld\n", msg, a, b);
        assert(false);
    }
}
void assert_eq_int(int a, int b, char* msg) {
    if (a != b) {
        printf("%s: %d != %d\n", msg, a, b);
        assert(false);
    }
}

void assert_eq_string(char* a, char* b, char* msg) {
    if (strcmp(a, b) != 0) {
        printf("%s: %s != %s\n", msg, a, b);
        assert(false);
    }
}

void assert_int_array_eq(int* a, int* b, int len, char* msg) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            for (int i = 0; i < len; i++) {
                printf("%d ", a[i]);
            }
            printf("!= ");
            {
                for (int i = 0; i < len; i++) {
                    printf("%d ", b[i]);
                }
                printf("; %s\n", msg);
                assert(false);
            }
        }
    }
}



void testAppend();
void testLength();
// void testPopleft();
void testPop();
// void testContainingStruct();

void printLinkedList(linked_list* ll);
int main() {
    testAppend();
    testLength();
    testPop();
    // testPopleft();
    // testContainingStruct();

    printf("ALL PASS!!\n");
    return 0;
}

void testAppend() {
    {
        linked_list* ll = linked_list_create(sizeof(int));
        int* head;
        int* tail;

        int num1 = 5;
        linked_list_append(ll, &num1);

        head = ll->head->data; 
        tail = ll->tail->data;
        assert_eq_int(*head, 5, "incorrect data in head");
        assert_eq_int(*tail, 5, "incorrect data in tail");

        int num2 = 89;
        linked_list_append(ll, &num2);
        
        head = ll->head->data; 
        tail = ll->tail->data;
        assert_eq_int(*head, 5, "incorrect data in head");
        assert_eq_int(*tail, 89, "incorrect data in tail");

        linked_list_free(ll);
    }
    printf("testAppend pass!\n");

}

void testLength() {
    {
        linked_list* ll = linked_list_create(sizeof(int));

        int num1 = 5;
        linked_list_append(ll, &num1);
        assert_eq_size_t(ll->length, 1, "incorrect length");

        int num2 = 89;
        linked_list_append(ll, &num2);
        assert_eq_size_t(ll->length, 2, "incorrect length");

        linked_list_free(ll);
    }
    printf("testLength pass!\n");

}

void testPop() {
    {
        linked_list* ll = linked_list_create(sizeof(int));

        int num1 = 5;
        int num2 = 89;
        int num3 = 1231;
        linked_list_append(ll, &num1);
        linked_list_append(ll, &num2);
        linked_list_append(ll, &num3);

        int* tail;

        tail = ll->tail->data;
        assert_eq_int(*tail, num3, "incorrect data");

        linked_list_pop(ll);
        assert_eq_size_t(ll->length, 2, "incorrect length");
        
        tail = ll->tail->data;
        assert_eq_int(*tail, num2, "incorrect data");

        linked_list_pop(ll);
        assert_eq_size_t(ll->length, 1, "incorrect length");

        tail = ll->tail->data;
        assert_eq_int(*tail, num1, "incorrect data");

        linked_list_pop(ll);
        assert_eq_size_t(ll->length, 0, "incorrect length");

        linked_list_free(ll);
    }

    {
        linked_list* ll = linked_list_create(sizeof(int));
        for (int i = 0; i < 100; i++) {
            linked_list_append(ll, &i);
        }
        printLinkedList(ll);
        int* tail;
        for (int i = 99; i >= 0; i--) {
            tail = ll->tail->data;
            assert_eq_int(*tail, i, "incorrect data");
            linked_list_pop(ll);
        }

        linked_list_free(ll);
    }

    printf("testPop pass!\n");
}


void testPopleft() {
    {
        linked_list* ll = linked_list_create(sizeof(int));

        int num1 = 5;
        int num2 = 89;
        int num3 = 1231;
        linked_list_append(ll, &num1);
        linked_list_append(ll, &num2);
        linked_list_append(ll, &num3);

        int* head;

        head = ll->head->data;
        assert_eq_int(*head, num1, "incorrect data");

        linked_list_pop_left(ll);
        assert_eq_size_t(ll->length, 2, "incorrect length");

        head = ll->head->data;
        assert_eq_int(*head, num2, "incorrect data");

        linked_list_pop_left(ll);
        assert_eq_size_t(ll->length, 1, "incorrect length");

        head = ll->head->data;
        assert_eq_int(*head, num3, "incorrect data");

        linked_list_pop_left(ll);
        assert_eq_size_t(ll->length, 0, "incorrect length");

        linked_list_free(ll);
    }

    {
        linked_list* ll = linked_list_create(sizeof(int));
        for (int i = 0; i < 100; i++) {
            linked_list_append(ll, &i);
        }

        int* head;
        for (int i = 0; i < 100; i++) {
            head = ll->head->data;
            assert_eq_int(*head, i, "incorrect data");
            linked_list_pop_left(ll);
        }

        linked_list_free(ll);
    }

    printf("testPopleft pass!\n");

}

void testContainingStruct() {
    {
        typedef struct testStruct {
            int id;
            char word[9];
        } testStruct;

        linked_list* ll = linked_list_create(sizeof(testStruct));
        testStruct t = { 2, "abacus" };

        linked_list_append(ll, &t);

        testStruct* head = (ll->head->data);
        assert_eq_int(head->id, t.id, "wrong id");
        assert_eq_string(head->word, t.word, "wrong word");

        linked_list_free(ll);
    }
    printf("testStruct pass!\n");

}

void printLinkedList(linked_list* ll){
    printf("PRINTING LINKED LIST\n");
    
    linked_list_node *cur = ll->head;
    while (cur != NULL){
        for(size_t i = 0 ; i < ll->dataSize; i++){
            printf("%02x", ((unsigned char *) cur->data) [i]);
        }
        cur = cur->next;
        printf("\n");
    }

    printf("PRINTED LINKED LIST\n");
}