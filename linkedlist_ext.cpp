#include <vector>
#include "linkedlist.h"

// 24 Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

// This is an iterative implementation of the swap node in pairs algorithm
ListNode* swapPairsIterative(ListNode* head) {
    ListNode fakeHead = ListNode(0);
    fakeHead.next = head;
    ListNode* node = &fakeHead;
    while (nullptr != node->next && nullptr != node->next->next) {
        ListNode* nodeSwap = node->next;
        ListNode* nodeNextPair = node->next->next->next;

        node->next = node->next->next;
        node->next->next = nodeSwap;
        node->next->next->next = nodeNextPair;

        node = node->next->next;
    }
    return fakeHead.next;
}

// This is a recursive implementation of the swap node in pairs algorithm
ListNode* swapPairsRecursive(ListNode* head) {
    if (nullptr == head || nullptr == head->next) return head;

    ListNode* nextNode = head->next;
    head->next = swapPairsRecursive(head->next->next);
    nextNode->next = head;

    return nextNode;
}
