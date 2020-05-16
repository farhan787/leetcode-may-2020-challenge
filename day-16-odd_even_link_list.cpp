// Problem link: https://leetcode.com/problems/odd-even-linked-list

#include <iostream>
#include <vector>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Time complexity => O(n); n = number of nodes in list
// Space complexity => O(1)
ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) {
        return head;
    }

    ListNode* dummyNode = new ListNode(INT_MIN);
    ListNode* evenListHead = dummyNode;
    ListNode* evenListLastNode = evenListHead;

    ListNode* currNode = head;
    while (currNode != NULL && currNode->next != NULL) {
        evenListLastNode->next = currNode->next;
        evenListLastNode = evenListLastNode->next;

        if (currNode->next->next == NULL) {
            // because we don't want to make the last node's next point to null,
            // as we want it to point its next to the evenList that we've created by manipulating pointers
            break;
        }
        currNode->next = currNode->next->next;
        currNode = currNode->next;
    }
    evenListLastNode->next = NULL;
    currNode->next = evenListHead->next;

    delete dummyNode;
    return head;
}

int main() {
}
