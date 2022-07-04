#include <bits/stdc++.h>

using namespace std;


class ListNode {
    public:
        int data;
        ListNode * next;
        
        ListNode(){
        	data = 0;
        	next = NULL;
		}
		
		ListNode(int data){
			this -> data = data;
			this -> next = NULL;
		}
};

class LinkedList {
	ListNode* head;
	
	public:
		LinkedList(){
			head = NULL;
		}
		void insert_last(int data){
			ListNode* new_node = new ListNode(data);
			
			if(head == NULL){
				head = new_node;
				return;
			}
			
			ListNode * temp = head;
			while(temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> next = new_node;
		}
		
		void insert_first(int data){
			ListNode * new_node = new ListNode(data);
			if(head == NULL){
				head = new_node;
				return;
			}
			new_node -> next = head;
			head = new_node;
		}
		
		void insert_position(int data, int pos){
			cout << "We insert the value " << data << " at the position " << pos << endl;
			ListNode * new_node = new ListNode(data);
            if(head == NULL){
				head = new_node;
				return;
			}
			int i = 1;
			ListNode* temp = head;
			while(i < pos){
				temp = temp -> next;
			    i++;
				if(temp -> next == NULL){
					temp -> next = new_node;
					break;
				}
			}
			new_node -> next = temp -> next;
			temp -> next = new_node; 
			
		}

		
		void print_list(){
			cout << "The list: " << endl;
			ListNode * temp = head;
			if(temp == NULL){
			   cout << "There's no node in linked list, go insert the fucking one!!!" << endl;
			}
			while(temp != NULL){
				cout << temp -> data << " ";
				temp = temp -> next;
			}
			
		}
		void del_node(int data){
			if(head == NULL){
				cout << "This is a null pointer, no node to delete u dumb ??" << endl;
				
			}
			ListNode* temp1 = head;
			ListNode* temp2 = NULL;
			if(temp1 != NULL && temp1 -> data == data){
				head = temp1 -> next;
				delete temp1;
				return;
			}
			while(temp1 != NULL && temp1 -> data != data){
				temp2 = temp1;
				temp1 = temp1 -> next;
				if(temp1 -> data == data){
					temp2 -> next = temp1 -> next;
					delete temp1;
					return;
				}
				if(temp1 == NULL){
					cout << "There's no node with that data in this linked list, try another data";
				}
			 }
		}
			
		
};

int main(){
	LinkedList l1 ;
	bool flag = true;
	do{
		cout << "*********************************************************" << endl;
		cout << "Select one of the options below: " << endl;
		cout << "1. Create a new linked list" << endl;
		cout << "2. Insert the value at the first position" << endl;
		cout << "3. Insert the value at the last position" << endl;
		cout << "4. Input a position and insert the value at that position" << endl;
		cout << "5. Print the list" << endl;
		cout << "6. Delete the node" << endl;
		cout << "0. Exit the program" << endl;
		cout << "*********************************************************" << endl;
		int sel;
		do{
			cin >> sel;
			if(sel < 0 || sel > 6){
				cout << "Invalid option, please choose again !!" << endl;
				}
			
		}while(sel < 0 || sel > 6);
		
		switch(sel){
			case 1:
				cout << "The new linked list has been created !" << endl;
				break;
			case 2:
				int a;
				cout << "Input the value: ";
				cin >> a;
				l1.insert_first(a);
				break;
			case 3:
				int b;
				cout << "Input the value: ";
				cin >> b;
				l1.insert_last(b);
				break;
		    case 4:
		    	int c, pos;
		    	cout << "Input the value: ";
		    	cin >> c;
		    	cout << endl << "Input the position: ";
		    	cin >> pos;
		    	l1.insert_position(c, pos);
		    	break;
		    case 5:
		        l1.print_list();
		        break;
		    case 6:
		    	int d;
		    	cout << "Input the data that you want to delete the node with that data" << endl;
		    	cin >> d;
		    	l1.del_node(d);
		    	break;
		    case 0:
		    	flag = false;
		    	break;
		    }
	}while(flag);
	return 0;
}
