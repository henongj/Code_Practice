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
/*
  1. node 의 val을 비교한다.
  2. this리스트보다 next가 작으면 다음 원소로
  3. 크면 그 위치에서 스왑
  4. 스왑하면 다시 head부터
*/
class Solution {
public:
    void swap(ListNode* node1, ListNode* node2)
    {
        int val = node1->val;
        node1->val = node2->val;
        node2->val = val;
    }
    // 첫 번째 리스트의 포인터
    ListNode* insertionSortList(ListNode* head) {
        for(auto thisNode = head; thisNode; thisNode = thisNode -> next) 
            for(auto nextNode = head; nextNode != thisNode; nextNode = nextNode -> next) 
                if(nextNode -> val > thisNode -> val) 
                    swap(nextNode , thisNode);
        return head;    
    }
};


