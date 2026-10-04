
//   struct ListNode {
//       int val;
//       ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        ListNode* answer = new ListNode;
        
        ListNode* end = answer;
        bool carry=0;

        while(curr1!=nullptr&&curr2!=nullptr){
            
            

            ListNode* temp = new ListNode{curr1->val + curr2->val+carry, nullptr};
            end->next = temp;
            end = temp;
            curr1 = (*curr1).next;
            curr2 = (*curr2).next;

            if(temp->val>9){
                temp->val -=10;
                carry = 1;
            }
            else
                carry = 0;
        }
        while(curr1!=nullptr&&curr2==nullptr){
            ListNode* temp = new ListNode{curr1->val + 0+carry, nullptr};
            end->next = temp;
            end = temp;
            curr1 = curr1->next;
            if(temp->val>9){
                temp->val -=10;
                carry = 1;
            }
            else
                carry = 0;
        }      
        while(curr1==nullptr&&curr2!=nullptr){
            ListNode* temp = new ListNode{curr2->val + 0+carry, nullptr};
            end->next = temp;
            end = temp;
            curr2 = curr2->next;
            if(temp->val>9){
                temp->val -=10;
                carry = 1;
            }
            else
                carry = 0;
        }
        if(carry){
            ListNode* temp = new ListNode{carry, nullptr};
            end->next = temp;
            end = temp;
        }


        answer = answer->next;

        return answer;
    }
};
