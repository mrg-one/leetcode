#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

static inline int powerInt(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }

    return result;
}

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

int main(int argc, char const *argv[])
{

    struct ListNode *l1 = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    l1->val = 0;
    l1->next = NULL;

    struct ListNode *l2 = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    l2->val = 0;
    l2->next = NULL;

    const struct ListNode *result = addTwoNumbers(l1, l2);

    while (result != NULL)
    {
        printf("%d ", result->val);
        result = result->next;
    }

    printf("\n");

    // free all allocated memory
    free(l1);
    free(l2);

    // free the result list
    while (result != NULL)
    {
        struct ListNode *temp = (struct ListNode *)result;
        result = result->next;
        free(temp);
    }

    return 0;
}
