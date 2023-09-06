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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*>ans;
        ListNode* t=head;
        int c=0;
        while(t!=NULL)
        {
            t=t->next;
            c++;
        }
        t= head;
        while(t!=NULL)
        {
            int r=c%k;
            int d=c/k;
            if(r==0)
            {
                ListNode* temp=new ListNode(-1);
                ListNode* temp2=temp;
                while(d--)
                {
                    temp2->next=t;
                    t=t->next;
                    temp2=temp2->next;
                    c--;
                }
                temp2->next=NULL;
                ans.push_back(temp->next);
                k--;
            }
            else
            {
                int d1=ceil((double)c/(double)k);
                 ListNode* temp=new ListNode(-1);
                ListNode* temp2=temp;
                while(d1--)
                {
                    temp2->next=t;
                    t=t->next;
                    temp2=temp2->next;
                    c--;
                }
                temp2->next=NULL;
                ans.push_back(temp->next);
                k--;
                
            }
            
        }
        if(k>0)
        {
            for(int i=0;i<k;i++)
            {
                ListNode* fake=NULL;
                ans.push_back(fake);
            }
        }
        
        return ans;
    }
};