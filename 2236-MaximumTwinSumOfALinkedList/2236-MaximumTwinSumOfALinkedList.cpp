// Last updated: 20/07/2026, 11:26:21
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
    int pairSum(ListNode* head) {
        vector<int>ans;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&slow->next){
            ans.push_back(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        int res=0;
        int i=ans.size()-1;
        while(slow){
            res=max(res,ans[i--]+slow->val);
            slow=slow->next;
        }
        return res;
    }
};