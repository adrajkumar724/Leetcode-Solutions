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
    private:
    int findgcd(int x,int y){
        if(y==0){
            return x;
        }
        return gcd(y,x%y);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p=head;
        ListNode* q=head->next;
        while(p !=NULL && q!=NULL){
            int val1=p->val;
            int val2=q->val;
            int gcd=findgcd(val1,val2);
            
            ListNode* temp=new ListNode(gcd);
            
            temp->next=p->next;
            p->next=temp;
            
            p=q;
            
            q=q->next;
            
            
        }
        return head;
        
        
        
    }
};