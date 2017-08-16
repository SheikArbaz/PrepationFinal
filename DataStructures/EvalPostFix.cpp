#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
#define pf printf
#define sf scanf
int main(int argc, char const *argv[]){
	char str[1000000];
	sf("%[^\n]s",str);
	int i=0,len=strlen(str);
	stack<int> s;
	i=0;
	while(str[i]!='\0'){
		if(str[i]>='0' && str[i]<='9')
			s.push(str[i]-'0');
		else if (str[i]==' '){i++;continue;}
		else {
			int x=s.top();s.pop();
			int y=s.top();s.pop();
			if(str[i]=='*')	s.push(y*x);
			else if(str[i]=='+')	s.push(y+x);
			else	s.push(y-x);
		}
		i++;
	}
	printf("%d\n",s.top());s.pop();
	return 0;
}