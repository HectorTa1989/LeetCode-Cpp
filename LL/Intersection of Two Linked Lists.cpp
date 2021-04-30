/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        ListNode *ret = NULL;
        int len1 = 0;
        int len2 = 0;
        while(p1 != NULL) {
            len1++;
            p1 = p1->next;
        }
        while(p2 != NULL) {
            len2++;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        if(len1 > len2) {
            int diff = len1 - len2;
            for(int i = 0;i < diff;i++) {
                p1 = p1->next;
            }
        }else {
            int diff = len2 - len1;
            for(int i = 0;i < diff;i++) {
                p2 = p2->next;
            }
        }
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
            
    }
};

//
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *hA = headA, *hB = headB;
    while (hA && hB) {
        if (hA == hB)
            return hA;
        hA = hA->next;
        hB = hB->next;
        if (!hA && !hB)
            return NULL;
        if (!hA) 
            hA = headB;
        if (!hB)
            hB = headA;
    }
    return NULL;
}
//
class Solution {
public:
    
    int len (ListNode* a) {
        if (!a) return 0;
        int cnt=0;
        while (a){
            cnt++;
            a = a->next;
        }
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA && !headB) return NULL; 
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        int di = len(headA) - len(headB);
        
        while (di > 0) {
            a = a->next;
            di--;
        }
        while (di < 0) {
            b = b->next;
            di++;
        }
        while (a && b) {
            if(a == b) return a;
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
};
//
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = 0, lenB = 0;
        ListNode *tailA = headA, *tailB = headB;
        
        while(tailA->next) {
            tailA = tailA->next;
            lenA++;
        }
        while(tailB->next) {
            tailB = tailB->next;
            lenB++;
        }
        if(tailA!=tailB) return NULL;
        
        if(lenA>lenB) {
            for(int i=0; i<lenA-lenB; i++)
                headA = headA->next;
        }
        else {
            for(int i=0; i<lenB-lenA; i++)
                headB = headB->next;
        }
        
        while(headA!=headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};

//
class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
int countA = 1;
int countB = 1;
ListNode* tmpA = headA;
ListNode* tmpB = headB;
if (tmpA == NULL || tmpB == NULL)
return NULL;
while(tmpA->next != NULL){
countA++;
tmpA = tmpA->next;
}
while(tmpB->next != NULL){
countB++;
tmpB = tmpB->next;
}
tmpA = headA;
tmpB = headB;
int diff = abs(countA — countB);
if (countA > countB) {
for (int i = 0; i < diff; i++)
tmpA = tmpA->next;
} else {
for (int i = 0; i < diff; i++)
tmpB = tmpB->next;
}

while (tmpA != NULL) {
if (tmpA == tmpB)
return tmpA;
tmpA = tmpA->next;
tmpB = tmpB->next;
}
return NULL;
}
};

//Approach 1: Brute Force (527ms)
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pa = headA, pb;
        while (pa != null) {
            for (pb = headB; pb != null; pb = pb.next) {
                if (pa == pb) {
                    return pa;
                }
            }
            pa = pa.next;
        }
        return null;
    }
}
Approach 2: Hash Table (10ms)
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> nodes = new HashSet<>();
        ListNode pa = headA;
        while (pa != null) {
            nodes.add(pa);
            pa = pa.next;
        }
        if (nodes.isEmpty()) {
            return null;
        }
        ListNode pb = headB;
        while (pb != null) {
            if (nodes.contains(pb)) {
                return pb;
            }
            pb = pb.next;
        }
        return null;
    }
}
Approach 3: Two Pointers (1ms)
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pa = headA, pb = headB;
        while (pa != pb) {
            pa = (pa != null) ? pa.next : headB;
            pb = (pb != null) ? pb.next : headA;
        }
        return pa;
    }
}