#include <cstddef>
#include <vector>
#include <iostream>
#include "linkedlist.h"
#include "linkedlist_ext.h"
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    ListNode* head = buildLinkedListFromVec(vec);
    head = reverseKGroup(head, 4);
    displayLinkedList(head);
    deleteLinkedList(head);
    return 0;
}
