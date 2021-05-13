#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int,list<int> > l;
  public: 
  	Graph(int v){
  		this->V = v;
  	}

  	void addEdge(int x,int y,bool directed = true){
  		l[x].push_back(y);
  		if(!directed) l[y].push_back(x);
  	}
    
    cycle_helper(int node,map<int,bool> &visited,int parent){
  		 visited[node] = true;
  		 for(auto nbr:l[node]){
  		 	if(!visited[nbr]){
  		 		return cycle_helper(nbr,visited,node);
  		 	}
  		 	else if(parent != nbr) return true;
  		 }
  	   return false;
    }

  	bool cycle(){
  		map<int,bool> visited;
  		return cycle_helper(0,visited,-1);
  	}
};
int main(){
   Graph g(4);
   g.addEdge(0,1);
   g.addEdge(1,2);
   g.addEdge(2,3);
   g.addEdge(3,4);
   //g.addEdge(4,1);

   if(g.cycle()) cout << "YES\n";
   else cout << "No\n";
}