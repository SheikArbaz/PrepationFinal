#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi visited,dist;
vector<vii> adjList;

void dfs(int u){
	// cout<<u<<" ";
	visited[u]=1;
	int l=adjList[u].size();
	for(int i=0;i<l;++i){
		int v=adjList[u][i].first;
		if(visited[v]==-1)
			dfs(v);
	}
}
void bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		cout<<u<<" ";
		int l=adjList[u].size();
		for(int i=0;i<l;++i){
			int v=adjList[u][i].first;
			if(visited[v]==-1){
				visited[v]=1;
				q.push(v);
			}
		}
	}
}
void zeroOnebfs(int s){
	queue<int> q;
	q.push(s);
	visited[s]=1;
	dist[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		cout<<u<<" ";
		int l=adjList[u].size();
		for(int i=0;i<l;++i){
			int v=adjList[u][i].first,w=adjList[u][i].second;
			if(visited[v]==-1){
				visited[v]=1;
				q.push(v);
				if((dist[u]+w)<dist[v])
					dist[v]=dist[u]+w;
			}
		}
	}
}
int main(int argc, char const *argv[]){
	int n;
	cin>>n;
	adjList.assign(n+1,vii());
	visited.assign(n+1,-1);//-1 not visited
	int e;
	cin>>e;
	while(e--){
		int x,y,w;
		cin>>x>>y>>w;
		adjList[x].push_back(ii(y, w));
		adjList[y].push_back(ii(x, w));
	}
	int source;
	// cin>>source;
	// dfs(source);cout<<"\n";
	// for(int u=0;u<n;++u){
	// 	int l=adjList[u].size();
	// 	cout<<u<<"->"<<" ";
	// 	for(int i=0;i<l;++i){
	// 		cout<<adjList[u][i].first<<" ";
	// 	}cout<<"\n";
	// }
	int cc=0;
	for(int i=0;i<n;++i){
		if(visited[i]==-1){
			dfs(i);//cout<<"\n";
			++cc;
		}
	}
	cout<<"#connected components: "<<cc<<"\n";
	visited.assign(n+1,-1);
	dist.assign(n+1,INT_MAX);
	// for(int i=0;i<visited.size();++i)
	// 	cout<<visited[i]<<"vis ";
	// cout<<"\n";
	zeroOnebfs(0);cout<<"\n";
	cout<<dist[n-1]<<"\n";
	return 0;
}
/*
6
6
0 1
0 2
1 3
2 3
2 4
3 5

*/