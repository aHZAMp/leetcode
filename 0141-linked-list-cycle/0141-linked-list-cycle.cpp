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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode* temp=head;
        map<ListNode*,int>m;bool b=false;
        while(temp!=NULL)
        {
            if(m.find(temp)!=m.end()){
                b=true;break;}
            m[temp]++;
            temp=temp->next;
        }
        return b;
    }
};