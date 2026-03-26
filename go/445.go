package main

import "fmt"

//  Definition for singly-linked list.
type ListNode struct {
    Val int;
    Next *ListNode;
};


func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    buf1 := []int{}
	buf2 := []int{}
	bufres := []int{}


	// for whatever reason the buffers are in reverse order on leetcode
	// so versions differ on leetcode and locally, but the logic is the same
	// it does not reverse the list because its funnier that way and the followup was 
	// "Follow up: Could you solve it without reversing the input lists?"
	// and yes although performance is worse with this approach

	for i := l1; i != nil; {
		buf1 = append(buf1, i.Val)
		i = i.Next
	}

	for i := l2; i != nil; {
		buf2 = append(buf2, i.Val)
		i = i.Next
	}

	var takeover int = 0

	for i := 0; i < max(len(buf1), len(buf2)); i++ {
		
		n1 := 0
		n2 := 0

		if i < len(buf1) {
			n1 = buf1[i]
		}

		if i < len(buf2) {
			n2 = buf2[i]
		}
		bufres = append(bufres, (n1 + n2 + takeover) % 10)
		takeover = (n1 + n2 + takeover) / 10
	}

	if takeover == 1 {
		bufres = append(bufres, 1)
	}

	var lres *ListNode = nil

	for i := range bufres {
		node := &ListNode{Val: bufres[i]}
		node.Next = lres
		lres = node
	}
	return lres;
}

func toListNode(nums []int) *ListNode {
	var head *ListNode

	for i := range nums {
		node := &ListNode{Val: nums[i]}
		node.Next = head
		head = node
	}

	return head
}

func run445() {
	l1 := toListNode([]int{9,9})
	l2 := toListNode([]int{1})

	res := addTwoNumbers(l1, l2)

	for res != nil {
		fmt.Printf("%d", res.Val)
		res = res.Next
	}
	println()
}