#ifndef LINKEDLIST_EXT_H
#define LINKEDLIST_EXT_H

// 24 Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
ListNode* swapPairsIterative(ListNode* head);
ListNode* swapPairsRecursive(ListNode* head);

ListNode* reverseLinkedList(ListNode* head);
ListNode* reverseKGroup(ListNode* head, int k);
#endif
