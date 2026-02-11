#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int carry = 0;
    struct ListNode *head = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    struct ListNode *current = head;

    do
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        current->val = sum % 10;
        if (l1 != NULL || l2 != NULL || carry > 0)
        {
            current->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
            current = current->next;
        }
    } while (l1 != NULL || l2 != NULL || carry > 0);

    return head;
}
