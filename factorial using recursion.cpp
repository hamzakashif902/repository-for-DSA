#include<iostream>
using namespace std;
int fact(int n);
int fact(int n)
{
    if(n > 1)
        return n * fact(n - 1);
    else
        return 1;

}
int main()
{
	int num;
	coout<<"Enter any integer"<< endl;
	cin>>num;
	cout<<endl;
	cout<<"factorial of number is  "<<fact(num);
	return 0;
}
