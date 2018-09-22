#include<iostream>
using namespace std;
const int n=7;
struct hnode
{
	char data;
	int f;
	struct hnode *lchild;
	struct hnode *rchild;
};
int min(struct hnode *a[],int j)
{
	int min=a[0]->f;
	int m=0;
	for(int k=1;k<j; k++)
	{
		if(a[k]->f<min)
		{
			min=a[k]->f;
			m=k;
		}
	}
	return m;
}

void preorder(hnode *q)
{
		if(q!=NULL)
		{
			
			preorder(q->lchild);
			cout<<q->data<<" "<<q->f<<endl;
			preorder(q->rchild);
		}
}

void encode(struct hnode *q,char ch, char b[],int k)
	{
		if(q->data!=ch)
		{
			if(q->data=='*')
			{
			b[k]='0';
			encode(q->lchild,ch,b,k+1);
			b[k]='1';
			encode(q->rchild,ch,b,k+1);
		    }
		     else return;
	    }
	     else if(q->data==ch)
		{
			for(int i=0; i<k; i++)
			{
				cout<<b[i];
			}
			return;
		}
	}

int main()
{
	struct hnode *a[n];
	char c[n];
	char ch;
	int k;
	for(int i=0;i<n;i++)
	{
		a[i]=new(struct hnode);
		cout<<"enter the character"<<endl;
		cin>>ch;
		c[i]=ch;
		a[i]->data=ch;
		cout<<"enter the corresponding frequency"<<endl;
		cin>>k;
		a[i]->f=k;
		a[i]->rchild=NULL;
		a[i]->lchild=NULL;
	}
	int j=n;
	for(int k=0;k<n;k++)
	{
		 int m=min(a,j);
	     struct hnode *x; 
	     x=a[m];
	    
	    for(int n=m; n<j-1; n++)
		a[n]=a[n+1];
	    j--;
	    m=min(a,j);
	    struct hnode *y;
	    y=a[m];
	    for(int n=m; n<j-1; n++)
		a[n]=a[n+1];

     	struct hnode *t1;
	    t1=new(struct hnode);
	    t1->data='*';
	    t1->f=x->f+y->f;
	    t1->lchild=x;
	    t1->rchild=y;
	    a[j-1]=t1;
	}
		struct hnode *q=NULL;
		 q=a[0];
		 preorder(q);
		 cout<<"successfully constructed a huffman code tree"<<endl;
		 for(int i=0;i<n;i++)
		 {
		 char b[10];
		 ch=c[i];
		 cout<<"the code for "<<c[i]<<" is ";
		 encode(q,ch,b,0);
		 cout<<endl;
	     }
	     //decoding starts...
	     cout<<"enter any code you want to decode"<<endl;
	     char b[20];
	     cout<<"enter * at the end of input"<<endl;
cin>>ch;
int l=0;
while(ch!='*')
{
	b[l]=ch;
	cin>>ch; 
	l++;
}
k=0;
 struct hnode *p=NULL;
 p=q;
while(k<l)
{
   if(b[k]=='0')
  {
   p=p->lchild;	
    if(p->data!='*')  {  cout<<p->data;  p=q; }
  }
  else if(b[k]=='1')
  {
	p=p->rchild;
	if(p->data!='*')  {	cout<<p->data; p=q;  }
  }
   k++;
}	
return 0;
}
