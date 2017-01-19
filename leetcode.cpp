#include <cstddef>
#include <vector>
#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head = buildLinkedListFromVec(vec);
    displayLinkedList(head);
    deleteLinkedList(head);
    return 0;
}
