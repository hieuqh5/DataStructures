#include <bits/stdc++.h>

using namespace std;

typedef struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
}Tree;

Tree* create(int data){
	Tree* t = new Tree();
	t -> data = data;
	t -> left = NULL;
	t -> right = NULL;
	return t;
	}

void Free(Tree* node){
	if(node == NULL){
		return;
		}
	free(node);
	free(node -> left);
	free(node -> right);
}

Tree* add_child(int data, Tree* tr){
	if(tr == NULL){
		tr = create(data);
		return tr;
		}
	if(tr -> data > data){
		tr -> left = add_child(data, tr -> left);
		}
	if(tr -> data < data){
	   tr -> right = add_child(data, tr -> right);
		}
	return tr;
}

void inorder_traversal(Tree* tr){
	if(tr == NULL){
	   return;
	   }
	inorder_traversal(tr -> left);
	cout << tr -> data << " ";
	inorder_traversal(tr -> right);
}

void postorder_traversal(Tree* tr){
	if(tr == NULL){
		return;
		}
	postorder_traversal(tr -> left);
	postorder_traversal(tr -> right);
	cout << tr -> data << " ";
}

void preorder_traversal(Tree* tr){
	if(tr == NULL){
		return;
		}
	cout << tr -> data << " ";
	preorder_traversal(tr -> left);
	preorder_traversal(tr -> right);
}

Tree *min_node(Tree * tr){
	Tree * current = tr;
	while(current && current -> left != NULL){
		current = current -> left;
		}
	return current;
}

Tree *del_node(Tree* tr, int data){
	if(tr == NULL){
		return tr;
		}
	if(tr -> data > data){
		tr -> left = del_node(tr -> left, data);
		}
	else if(tr -> data < data){
		tr -> right = del_node(tr -> right, data);
		}
	else{
		if(tr -> left == NULL && tr -> right == NULL){
			return NULL;
			}
		else if(tr -> left ==NULL){
			Tree* temp = tr -> right;
			free(tr);
			return temp;
			}
		else if(tr -> right == NULL){
			Tree* temp = tr -> left;
			free(tr);
			return temp;
			}
		Tree * temp = min_node(tr -> right);
	    tr -> data = temp -> data;
	    tr -> right = del_node(tr -> right, temp -> data);
	}
	return tr;
	

	}

int main(){
	Tree* t1 = create(5);
	t1 = add_child(2, t1);
	t1 = add_child(8, t1);
	inorder_traversal(t1);
    t1 = add_child(9, t1);
    t1 = add_child(3, t1);
    t1 = add_child(1, t1);
    t1 = del_node(t1, 2);
    inorder_traversal(t1);
    cout << min_node(t1) -> data;
	return 0;
	}
