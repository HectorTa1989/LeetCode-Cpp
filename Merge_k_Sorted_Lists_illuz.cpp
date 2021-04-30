// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int sz = lists.size();
        if (sz == 0)
            return NULL;

        while (sz > 1) {
            int k = (sz + 1) / 2;
            for (int i = 0; i < sz / 2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            sz = k;
        }
        return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *start, *p1;

        if (l1->val < l2->val) {
            p1 = start = l1;
            l1 = l1->next;
        } else {
            p1 = start = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p1->next = l1;
                p1 = l1;
                l1 = l1->next;
            } else {
                p1->next = l2;
                p1 = l2;
                l2 = l2->next;
            }
        }
        if (l1 != NULL)
            p1->next = l1;
        else
            p1->next = l2;
        return start;
    }
};

int main() {

    return 0;
}

//Method 2----------------------
ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return MergeSort(lists, 0, lists.size() - 1);
    }
    
    ListNode* MergeSort(vector<ListNode*>& lists, int left, int right) {
        if (left >= right) {
            return lists[left];
        }
        auto mid = (left + right) / 2;
        auto l1 = MergeSort(lists, left, mid);
        auto l2 = MergeSort(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode* pl = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pl->next = l1;
                l1 = l1->next;
            } else {
                pl->next = l2;
                l2 = l2->next;
            }
            pl = pl->next;
            pl->next = nullptr;
        }
        if (l1) {
            pl->next = l1;
        }
        if (l2) {
            pl->next = l2;
        }
        return dummy.next;
    }