#include <vector>
#include <iostream>
#include "linkedlist.h"

using namespace std;

// Recursively building a linked list from a vector
ListNode* buildLinkedListSub(std::vector<int>&vec, int i) {
    if (i >= vec.size()) return nullptr;
    else {
        ListNode *node = new ListNode(vec[i]);
        node->next = buildLinkedListSub(vec, i+1);
        return node;
    }
}
ListNode* buildLinkedListFromVec(std::vector<int>& vec) {
    return buildLinkedListSub(vec, 0);
}

// Recursively delete a linked list
void deleteLinkedList(ListNode *head) {
    if (nullptr == head) return;
    else {
        deleteLinkedList(head->next);
        delete head;
    }
}

// Recursively display a linked list
void displayLinkedList(ListNode* head) {
    if (NULL == head) {
        cout << "null" << endl;
    } else {
        cout << head->val << "->";
        displayLinkedList(head->next);
    }
}
