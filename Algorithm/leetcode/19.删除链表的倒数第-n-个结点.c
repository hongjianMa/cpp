/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    // 建一个头节点
    struct ListNode head_;
    head_.next = head;
    struct ListNode *p = &head_;
    struct ListNode *q = &head_;
    for (int i = 0; i < n; i++)
    {
        if (p == NULL)
            return head;
        p = p->next;
    }
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    struct ListNode *del = q->next;
    q->next = q->next->next;
    free(del);

    return head_.next;
}
// @lc code=end
