#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
 };

/*
1 - to lists*
2 - combine lists to one*
3 - sort*
4 - convert sorted list to linked list
*/

int findSize(struct ListNode* core) {
    int size = 0;
    struct ListNode* c = core;
    while (c != NULL) {
        ++size;
        c = c->next;
    }
    return size;
}

int* toList(struct ListNode* core, int size) {
    int* list = (int*) malloc(size * sizeof(int));
    if (list == NULL) {
        exit(1);
    }

    int idx = 0;
    struct ListNode* c = core;

    while (c != NULL) {
        list[idx++] = c->val;
        c = c->next;
    }

    return list;
}

int* sort(int* list, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    return list;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    int s1 = findSize(list1);
    int s2 = findSize(list2);
    
    if (s1 == 0) {
        return list2;
    } else if (s2 == 0) {
        return list1;
    }

    int* f1 = toList(list1, s1);
    int* f2 = toList(list2, s2);
    int* main = (int*) malloc((s1 + s2) * sizeof(int));

    for (int i = 0; i < s1; ++i) {
        main[i] = f1[i];
    }

    for (int i = 0, j = s1; i < s2; ++i, ++j) {
        main[j] = f2[i];
    }

    int* sortedList = sort(main, s1 + s2);

    struct ListNode* result = malloc(sizeof(struct ListNode));
    struct ListNode* current = result;

    for (int i = 0; i < s1 + s2; ++i) {
        current->val = sortedList[i];
        if (i + 1 < s1 + s2) {
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
        } else {
            current->next = NULL;
        }
    }

    free(f1);
    free(f2);
    free(main);

    return result;
}

void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}   