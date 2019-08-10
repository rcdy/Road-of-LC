/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        const int len = lists.size();
        for(int i=0;i<len;++i){
            if(lists[i]!=NULL){
                pq.push(lists[i]);    
            }
        }
        ListNode* result=new ListNode(-1),*p=result;
        while(!pq.empty()){
            ListNode* min = pq.top();
            pq.pop();
            p->next=min;
            p=p->next;
            min=min->next;
            if(min!=NULL){
                pq.push(min);
            }
        }
        p->next=NULL;
        return result->next;
    }
    struct cmp{
        bool operator () (ListNode* l1,ListNode* l2){
            return l1->val > l2->val;
        }
    };
};

class Solution1 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = new ListNode(-1), *p, *q;
        p = head;
        int qi;
        const int len = lists.size();
        int nEmpty = len;
        for (int i = 0; i < len; ++i) {
            if (lists[i] == NULL) nEmpty--;
        }
        int isEnd = 0;
        while (isEnd < nEmpty) {
            q = NULL;
            for (int i = 0; i < len; ++i) {
                if (q == NULL && lists[i] != NULL) {
                    q = lists[i];
                    qi = i;
                } else if (q != NULL && lists[i] != NULL && lists[i]->val < q->val) {
                    q = lists[i];
                    qi = i;
                }
            }
            p->next = q;
            lists[qi] = lists[qi]->next;

            p = p->next;
            p->next = NULL;
            // printf("%d ##",p->val);

            if (lists[qi] == NULL) {
                isEnd++;
            }
        }
        return head->next;
    }
};
/*
1.考虑到堆排序可以简化运算，使用优先队列
2.普通方法也可以AC，详见Solution1，但时间效率较差
*/
