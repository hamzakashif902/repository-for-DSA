#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
#define size 1000
class node
	 {
	 public:
		char data;
		node*next;
};
class stack
{
	public:
		node*head;
		node*tail;
		public:
	stack()
{	
		head=NULL;
		tail=NULL;

}
    void push(char n);
    char pop ();
    char top ();
    void print();
	string postfix();
	int evaluator(string postfix); 	
};
void stack::push(char n)
{
   	node* tptr;
	tptr = head;

	node* nptr = new node();
	nptr->data = n;
	nptr->next =NULL;

	if (head == NULL)
	{
		head = nptr;
}
	
	else {
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			
     }
      tptr->next=nptr;
	}
}
char stack::pop()
{
	node*tptr=head;
	node*pptr=head;
	
	if(head==NULL)
	{
		return 'n';
	}
	else
	{
		int i=0;
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			i++;
		}
		
		if(tptr==head)
		{
			int n=tptr->data;
			head=head->next;
			return n; 
			
		}
		else 
		{
			while(i>1)
			{
				pptr=pptr->next;
				i--;
			}
			int n=tptr->data;
			pptr->next=tptr->next;
	    	return n ;
	}
		
	}
}
char stack::top()
{
	node*tptr=head;
	node*pptr=head;
	
	if(head==NULL)
	{
		//cout<<endl<<"There is nothing to pop in the stack"<<endl;	
		return 'n';
	}
	else
	{
		int i=0;
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			i++;
		}
		
		if(tptr==head)
		{
			char n=tptr->data;
			return n; 		
		}
		else 
		{
			while(i>1)
			{
				pptr=pptr->next;
				i--;
			}
			char n=tptr->data;
	    	return n ;
	}		
	}
}
class node1
	 {
	 public:
		int data;
		node1*next;
};
class stack2
{
	public:
		node1*head;
		node1*tail;
		public:
	stack2()
{	
		head=NULL;
		tail=NULL;
}
    void push(int n);
    int pop ();
    int top ();
};
void stack2::push(int n)
{
   	node1* tptr;
	tptr = head;

	node1* nptr = new node1();
	nptr->data = n;
	nptr->next =NULL;

	if (head == NULL)
	{
		head = nptr;
}
	
	else {
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;	
     }
      tptr->next=nptr;
	}
}
int stack2::pop()
{
	node1*tptr=head;
	node1*pptr=head;
	
	if(head==NULL)
	{
		return -1;
	}
	else
	{
		int i=0;
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			i++;
		}
		
		if(tptr==head)
		{
			int n=tptr->data;
			head=head->next;
			return n; 
			
		}
		else 
		{
			while(i>1)
			{
				pptr=pptr->next;
				i--;
			}
			int n=tptr->data;
			pptr->next=tptr->next;
	    	return n ;
	}
		
	}
}
int stack2::top()
{
	node1*tptr=head;
	node1*pptr=head;
	
	if(head==NULL)
	{
		//cout<<endl<<"There is nothing to pop in the stack"<<endl;	
		return -1;
	}
	else
	{
		int i=0;
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			i++;
		}		
		if(tptr==head)
		{
			int n=tptr->data;
			return n; 
			
		}
		else 
		{
			while(i>1)
			{
				pptr=pptr->next;
				i--;
			}
			int n=tptr->data;
	    	return n ;
	}
		
	}
}
int preseidence(char opera){
	if(opera == '(' || opera == ')'){
		return 0;
	}
	if(opera == '+' || opera == '-'){
		return 1;
	}
	if(opera == '*' || opera == '/'){
		return 2;
	}
	if(opera == '^'){
		return 3;
	}
	return 0;
}
 string stack::postfix(){
 	int bracketCount=0;
	int c = 0;
	char temp;
	int j = 0;
	char infix[size];
	char operand[size];
	cout << "Enter infix Expression: " << endl;
	cin >> infix;
	int length = strlen(infix);
	for(int i = 0; i < length; i++){
        if(infix[i]!='+' && infix[i]!='-' && infix[i]!='/' && infix[i]!='*' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')'){
        	operand[j] = infix[i];
        	j++;
		}
		else{
			if(head == NULL){
				push(infix[i]);
				c++;
			}
			else{
				if(infix[i] != '(' && infix[i] != ')'){
					if(preseidence(infix[i]) <= preseidence(top())){
						temp = pop();
						c--;
						operand[j++] = temp;
						push(infix[i]);
						c++;
					}
					else{
						push(infix[i]);
						c++;
					}
				}
				else{
					if(infix[i] == '('){
						push(infix[i]);
						bracketCount++;
						c++;
					}
					if(infix[i] == ')'){
						temp = pop();
						bracketCount++;
						c--;
						while(temp != '('){
							operand[j++] = temp;
							temp = pop();
							c--;
						}
					}
				}
			}
		}
	}
	int n = 0;
	while(n<c){
		operand[j++] = pop();
		n++;
	}
	string postFixResult = "";
	for(int i = 0; i<length-bracketCount ;i++){
	//	cout << operand[i];
		postFixResult = postFixResult + operand[i];
	}
	cout << endl << postFixResult << endl;
	return postFixResult;
}
int stack::evaluator(string postfix){
	stack2 s;
	int n;
	int i=0;
	while(i<postfix.length())
 	{
	 if(postfix[i]>='0'&&postfix[i]<='9')
	 {
	 	n=postfix[i]-48;
		 s.push(n);
	 	i++;
	 }
	 else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
	 {
	 	int a,b;
	 	a=s.pop();
	 	b=s.pop();
	 	
	 	if(postfix[i]=='+')
	 	{
	 		
	 		int d=a;
	 		int e=b;
	 		int c=e+d;
	 	
	 		s.push(c);
	 		i++;		
		 }
		 else if(postfix[i]=='-')
	 	{
	 		int d=a;
	 		int e=b;
	 		int c=e-d;
	 		s.push(c);
	 		i++;
		 }
		 else if(postfix[i]=='*')
	 	{
	 		int d=a;
	 		int e=b;
	 		int c=e*d;
	 		s.push(c);
	 		i++;
		 }
		 else if(postfix[i]=='/')
	 	{
	 		int d=a;
	 		int e=b;
	 		int c=e/d;
	 		s.push(c);
	 		i++;
		 }
		 else if(postfix[i]=='^')
		 {
		 	int d=a;
	 		int e=b;
	 		int c=pow(e,d);
	 		s.push(c);
	 		i++;
			  }	 
	}
}
int poped=s.pop();
	 return poped;
}
int main(){
	stack st;
	string str;
	string a;
	a = st.postfix();
 cout<<"\nThe Postfix is="<<a;
  int res= st.evaluator(a);
  cout<<"\nThe Result is="<<res;
	return 0;
}
