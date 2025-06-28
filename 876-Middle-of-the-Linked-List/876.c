#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode * backup = calloc(1,sizeof(struct ListNode));
    backup = head;
    int count = 0;
    int splitter = 0;

    while (head){
        printf("%d ", head->val);
        head = head->next;
        count++;
    }

    splitter = count / 2;
    while (splitter > 0){
        backup = backup->next;
        splitter--;
    }
    
    return backup;
}
