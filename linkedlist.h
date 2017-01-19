#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Build a linked list from a vector
ListNode* buildLinkedListFromVec(std::vector<int>& vec);

// delete a linked list
void deleteLinkedList(ListNode* head);

// display a linked list
void displayLinkedList(ListNode* head);
#endif
