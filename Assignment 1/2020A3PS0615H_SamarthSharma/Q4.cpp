//SAMARTH SHARMA 2020A3PS0615H

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,ListNode *next) : val(x), next(next){}
};

ListNode* func(ListNode* head)
{

	if (head == NULL || head->next == NULL)
		return NULL;

	ListNode *slow = head, *fast = head;

	slow = slow->next;
	fast = fast->next->next;

	while (fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow != fast)
		return NULL;

	slow = head;
	while (slow != fast) 
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}


int main()
{
	ListNode* head= new ListNode(0);
	ListNode* t1=new ListNode(1);
	ListNode* t2=new ListNode(2);
	ListNode* t3=new ListNode(3);
	ListNode* t4=new ListNode(4);
	ListNode* t5=new ListNode(5);
	ListNode* t6=new ListNode(6);
	ListNode* t7=new ListNode(7);
	ListNode* t8=new ListNode(8);
	

	head->next=t1;
	t1->next=t2;
	t2->next=t3;
	t3->next=t4;
	t4->next=t5;
	t5->next=t6;
	t6->next=t7;
	t7->next=t8;
	t8->next=t4;

	ListNode* res = func(head);
	if (res == NULL)
		cout << "No Node which corresponds to Harshit"<< endl;
	else
		cout << "Node " << res->val << " corresponds to Harshit" << endl;
	return 0;
}
