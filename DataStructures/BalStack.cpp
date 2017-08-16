#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string input;
	cin>>input;
	stack<char> st;
	int f=0,i=0,l=input.size();
	while(i<l){
		char x=input[i];
		if((x>='a' && x<='z') || (x>='A' && x<='Z'))
			continue;
		if(x=='(' || x=='{' || x=='[')
			st.push(x);
		else{
			if(x==')'){
				if(!st.empty() && st.top()=='(')
					st.pop();
				else{
					cout<<"Invald\n"; f=1;break;
				}
			}
			else if(x==']'){
				if(!st.empty() &&st.top()=='[')
					st.pop();
				else{
					cout<<"Invald\n"; f=1;break;
				}
			}
			else if(x=='}'){
				if(!st.empty() &&st.top()=='{')
					st.pop();
				else{
					cout<<"Invald\n"; f=1;break;
				}
			}
		}
		++i;
	}
	if(f==0 && st.empty())
		cout<<"Valid\n";
	else if(f==0)
		cout<<"Invalid\n";

	return 0;
}