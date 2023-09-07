/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        left--;
        reverse(v.begin()+left,v.begin()+right);
        ListNode* res=new ListNode(0);
        ListNode* t=res;
        int i=0;
        while(i<v.size())
        {
            t->next=new ListNode(v[i]);
            t=t->next;
            i++;
        }
        return res->next;
        
    }
};