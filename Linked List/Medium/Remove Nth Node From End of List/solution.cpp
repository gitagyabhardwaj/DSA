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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head->next;
        std::vector<ListNode*> hist;
        hist.push_back(head);
        while(curr!= NULL && curr->next !=NULL){
            hist.push_back(curr);
            curr = curr->next;
        }
        curr != NULL?hist.push_back(curr):void(0);
        
        curr = hist[hist.size()-n];
        if(n == 1 && n<hist.size()){
            hist[hist.size()-n-1]->next = NULL;
        }
        else if(n==hist.size()){
            head = head->next;
        }
        else{
            hist[hist.size()-n-1]->next = curr->next;
        }

        return head;



    }
};