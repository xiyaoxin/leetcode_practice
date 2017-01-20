#include <vector>
#include <iostream>
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

// Reverse a linked list
ListNode* reverseLinkedListSub(ListNode* head, ListNode* newHead) {
    if (nullptr == newHead) return head;
    ListNode* next = newHead->next;
    newHead->next = head;
    return reverseLinkedListSub(newHead, next);
}

ListNode* reverseLinkedList(ListNode* head) {
    return reverseLinkedListSub(nullptr, head);
}

// reverse k-group
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode fakeHead = ListNode(0);
    fakeHead.next = head;
    ListNode* prev = &fakeHead;

    ListNode* node = head;
    for(int i = 0; i < k; i++) {
        if (nullptr == node) return head;
        prev = node;
        node = node->next;
    }
    prev->next = nullptr;
    ListNode* newHead = reverseLinkedList(head);
    head->next = reverseKGroup(node, k);
    return newHead;
}
