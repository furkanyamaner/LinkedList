#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {} // Constructor
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Sonucu tutacak başlatıcı düğüm
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // Bir üst basamağa taşı
            current->next = new ListNode(sum % 10); // Birler basamağı ekle
            current = current->next;
        }

        return dummyHead->next; // Sonuç listesi
    }
};

int main() {
    // Liste 1: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Liste 2: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Sonucu yazdır
    while (result != nullptr) {
        cout << result->val;
        if (result->next != nullptr) cout << " -> ";
        result = result->next;
    }

    return 0;
}
