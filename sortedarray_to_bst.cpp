#include<iostream>
using namespace std;
#include<queue>
template <typename t>
class binarytree{
	public:
		t data;
		binarytree* left;
		binarytree* right;
		binarytree(t data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~binarytree()
		{
			delete left;
			delete right;
		}
		
};

void print(binarytree<int>* root)
{
	queue<binarytree<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<front->data<<":";
		if(front->left!=NULL)
		{
			cout<<"L"<<front->left->data;
			q.push(front->left);
		}
		
		if(front->right)
		{
			cout<<"R"<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	} 
}

binarytree<int>* create(int *arr, int si , int ei)
{
	int mid=(si+ei)/2;
	
	if(ei==-1||si>ei)
	{
		return NULL;
	}
	else if(arr[mid]==-1)
	{
		return NULL;
	}
	binarytree<int>* root=new binarytree<int>(arr[mid]);
	binarytree<int>* left1=create(arr,si,mid-1);
	binarytree<int>* right1=create(arr,mid+1,ei);
	root->left=left1;
	root->right=right1;
	return root;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int si=0;
	int ei=6;
	binarytree<int>* root2=create(arr,si,ei);
	cout<<"Created bst is "<<endl;
	print(root2); cout<<endl;
	return 0;
}
