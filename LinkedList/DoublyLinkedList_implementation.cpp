#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		int data;
		Node * prev;
		Node * next;
		
		Node() {
			data = 0;
			prev = NULL;
			next = NULL;
			}
		Node(int val){
			data = val;
			prev = NULL;
			next = NULL;
			}
		
};

class ListNode{
	Node * head;
	public:
		ListNode(){
			head = NULL;
			}
		
		
		Node * insert_last(int val){
			if(head == NULL){
			   head = new Node(val);
			   return head;
			}
			
			Node * new_node = head;
			while(new_node -> next != NULL){
				new_node = new_node -> next;
				
			}
			new_node -> next = new Node(val);
			return head;
		}
		
		Node * insert_first(int val){
			if(head == NULL){
				head = new Node(val);
				return head;
			}
			Node * new_node = new Node(val);
	        head -> prev = new_node;
	        new_node -> next = head;
	        head = new_node;
		}
		
		void insert_position(int val, int pos){
			if(pos == 0){
				insert_first(val);
			}
			Node * new_node = head;
			while(pos > 0){
				new_node = new_node -> next;
				pos--;
				if(new_node -> next == NULL){
					insert_last(val);
					break;
				}
			}
			Node * new_node2 = new_node -> next;
			new_node -> next = new Node(val);
			new_node -> next -> next = new_node2; 
		}
		
		
		void print_list(){
			Node * new_node = head;
			while(head != NULL){
				cout << head -> data << " ";
				head = head -> next;
			}
		}
		
		void print_list_reverse(){
			Node * new_node = head;
			stack<int> st;
			while(new_node != NULL){
				st.push(new_node -> data);
				new_node = new_node -> next;
			}
			while(!st.empty()){
				cout << st.top() << " ";
				st.pop();
			}
		}
 		
};

int main(){
	ListNode l1;
	l1.insert_last(5);
	l1.insert_last(6);
	l1.insert_last(7);
	l1.insert_first(4);
	l1.insert_position(3, 2);
	l1.print_list();
	return 0;
}
