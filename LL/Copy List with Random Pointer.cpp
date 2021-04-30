140ms using loop to hack this problem but due to frequent invoking of node_map.count, there is a dramatic performance decrease.

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> node_map;
        RandomListNode *p = head, *pre = NULL;
        while(p)
        {
            if(!node_map.count(p)) node_map[p] = new RandomListNode(p->label);
            if(p->random)
            {
                if(!node_map.count(p->random)) node_map[p->random] = new RandomListNode(p->random->label); 
                node_map[p]->random = node_map[p->random];
            }
            if(pre) pre->next = node_map[p];
            pre = node_map[p];
            p = p->next;
        }
        return node_map[head];
    }
};
Using 110ms to solve this, though traverse twice but it's more clean and easy-understanding.

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> node_map;
        RandomListNode *p = head, *pre = NULL, t(0);
        pre = &t;
        while(p)
        {
            pre->next = node_map[p] = new RandomListNode(p->label);
            p = p->next;
            pre = pre->next;
        }
        p = head;
        pre = t.next;
        while(p)
        {
            pre->random = node_map[p->random];
            pre = pre->next;
            p = p->next;
        }
        return t.next;
    }
};
Using 110ms without map, copy all the nodes just after its original position then the random pointer of the cloned node can be easily retrieved by the original nodes (since the original is just before its corresponding cloned nodes so the random) Check the code directly, quite simple.

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode *p = head, *next, *cloned, *pre;
        while(p)
        {
            cloned = new RandomListNode(p->label);
            next = p->next;
            p->next = cloned;
            cloned->next = next;
            p = next;
        }
        p = head;
        cloned = head->next;
        while(p)
        {
            if(p->random) cloned->random = p->random->next;
            if(cloned->next) cloned = cloned->next->next;
            else break;
            p = p->next->next;
        }
        RandomListNode t(0);
        p = head;
        pre = &t;
        while(p)
        {
            pre->next = p->next;
            p->next = p->next->next;
            p = p->next;
            pre = pre->next;
        }
        return t.next;
    }
};

//
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr) return head;
        Node* curr = head;
        Node* temp;
        
        while(curr)
        {
            temp = curr->next;
            curr->next = new Node(curr->val,nullptr, nullptr);
            curr->next->next = temp;
            curr = temp;
        }
        
        curr = head;
        while(curr)
        {
            if(curr->next && curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next ? curr->next->next : curr->next;
        }
        
        Node* original = head;
        Node* copy = head->next;
        temp = copy;
        
        while(original && copy)
        {
            original->next = original->next ? original->next->next : original->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            
            original = original->next;
            copy = copy->next;
        }
        return temp;
    }
};

//clone each node of the list and connect the cloned just after its original
//the random pointer of the cloned node can be easily fetched by its previous node p->random->next
//split the original node and its cloned collecting the odd and even nodes in a list

//Each new cloned nodes are just next to its previous originals so do the random ones;

//this operation is trying to connect to the randoms
//p is the original then p->next is the new cloned so the random of p is cloned and placed at p->random->next (since each new cloned are placed just after the original) 
//so at last p->next->random should be p->random->next right?
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        RandomListNode newHead(0), *p = head, *t = NULL;
        while(p)
        {
            RandomListNode *cloned = new RandomListNode(p->label);
            cloned->next = p->next;
            p->next = cloned;
            p = cloned->next;
        }
        
        p = head;
        while(p && p->next)
        {
            if(p->random) p->next->random = p->random->next;
            p = p->next->next;
        }
        
        p = head;
        t = &newHead;
        while(p && p->next)
        {
            t->next = p->next;
            p->next = p->next->next;
            t = t->next;
            p = p->next;
        }
        t->next = NULL;
        return newHead.next;
    }
};
