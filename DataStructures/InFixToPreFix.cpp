#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define pf printf
#define sf scanf
int precedence(char x)
{
	if(x=='^')
		return 3;
	else if(x=='*' || x=='/')
		return 2;
	else if(x=='+' || x=='-')
		return 1;
	else
		return 0;
}
int main(int argc, char const *argv[]){
	string input,output="";
	cin>>input;
	int i=0,len=input.size();
	stack<char> st;
	reverse(input.begin(),input.end());
	while(i<len){
		char x=input[i];
		if((x>='a' && x<='z') || (x>='A' && x<='Z')){//directly print them
			cout<<x;
			output+=x;
		}
		else{
			if(st.empty() || x=='(')//this has to be in the stack whenever required
				st.push(x);
			else if(x==')'){
				char m=st.top();
				while(m!='('){//no need of checking empty.there must be '('
					cout<<m;
					output+=m;
					st.pop();
					m=st.top();
					// cout<<"In loop\n";
				}//cout<<m;
				st.pop();
			}
			else{
				while(!st.empty() && precedence(x)<=precedence(st.top())){
					char m=st.top();
					output+=m;
					cout<<m;st.pop();
				}
				st.push(x);
			}
		}
		++i;
	}
	char m;
	while(!st.empty()){
		m=st.top();
		cout<<m;
		output+=m;
		st.pop();
	}
	reverse(output.begin(), output.end());
	cout<<"\n"<<output<<"\n";
	return 0;
}