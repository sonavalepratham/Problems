#include<bits/stdc++.h>
using namespace std;

class node{

public:
	int data;
	node *left, *right;
	node(){
		data=0;
		left=right=NULL;
	}
	node(int data){
		this->data=data;
		left=right=NULL;
	}
};

class tree{
	
public:
	node* head;
	tree(){
		head=NULL;
	}
	void insert_by_array(){
		int x; cin>>x;
		head=new node(x);
		queue<node*> q;
		node*ptr=head;
		q.push(head);
		while(!q.empty()){
			cin>>x;
			ptr=q.front();
			q.pop();
			if(x!=-1){
				ptr->left= new node(x);
				q.push(ptr->left);
			}
			cin>>x;
			if(x!=-1){
				ptr->right= new node(x);
				q.push(ptr->right);
			}
			
		}
	}
	void insert_by_array(vector<int> a){
		
		head=new node(a[0]);
		queue<node*> q;
		int i=0;
		node*ptr=head;
		q.push(head);
		while(!q.empty()){
			i++;
			ptr=q.front();
			q.pop();
			if(i<a.size())
			if(a[i]!=-1){
				ptr->left= new node(a[i]);
				q.push(ptr->left);
			}
			i++;
			if(i<a.size())
			if(a[i]!=-1){
				ptr->right= new node(a[i]);
				q.push(ptr->right);
			}
			
		}
	}
	void pre_order(node *rt){
		if(rt==NULL) return;
		pre_order(rt->left);
		cout<<rt->data<<" ";
		
		pre_order(rt->right);
	}
};

int main(){
	tree t;
	t.insert_by_array({10, 20, 30, 40, 50, 60, 70, -1, -1, -1, -1, -1, -1, -1, -1});
	t.pre_order(t.head);
	return 0;
}