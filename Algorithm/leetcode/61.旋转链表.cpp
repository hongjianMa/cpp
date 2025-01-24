/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==nullptr) return head;
        
        ListNode *p = head;
        ListNode *q = head;
        int n = 0;
        for(ListNode *m = head;m!=nullptr;m = m->next)
        {
            n++;
        }
        k = k % n;
        for(int i = 0;i<k;i++)
        {
            p = p->next;
        }
        while(p->next!=nullptr)
        {
            p = p->next;
            q = q->next;
        }
        p ->next = head;
        head = q ->next;
        q->next =nullptr;
        return head;
        
    }
};
// @lc code=end

