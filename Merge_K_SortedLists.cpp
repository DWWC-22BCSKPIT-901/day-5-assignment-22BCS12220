//Merge k sorted lists(hard)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
    for (ListNode* list : lists) {
        if (list != nullptr) {
            minHeap.push(list);
        }
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top();
        minHeap.pop();
        tail->next = smallest;
        tail = tail->next;
        if (smallest->next != nullptr) {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    int k;
    cout << "Enter the number of linked lists: ";
    cin >> k;
    vector<ListNode*> lists(k);
    for (int i = 0; i < k; ++i) {
        int n;
        cout << "Enter the number of elements in list " << i + 1 << ": ";
        cin >> n;
        vector<int> values(n);
        cout << "Enter the elements: ";
        for (int j = 0; j < n; ++j) {
            cin >> values[j];
        }
        lists[i] = createList(values);}
    ListNode* mergedList = mergeKLists(lists);
    cout << "Merged List: ";
    printList(mergedList);
    return 0;}
