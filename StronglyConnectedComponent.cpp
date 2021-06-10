#include "ReverseGraph.cpp"
#include <stack>
int FINISHING_TIME;
Vertex s;
stack<Vertex*> TRAVERSE_ORDER;
void DFS(Graph& gh, Vertex& startVertex ){
    startVertex.isVisited=true;
    // cout<<"DFS RAN"<<endl;
    //  cout<<"("<<startVertex.data.front()<<","<<s.data.front()<<")"<<endl;
    startVertex.leader=s.data.front();
    for(auto& x: startVertex.pointers){
        if(!(*x).isVisited){
            DFS(gh,*x);
        }
    }
    FINISHING_TIME++;
    startVertex.finishingtime=FINISHING_TIME;
    TRAVERSE_ORDER.push(&startVertex);
}
void DFS_Loop(Graph& graph){
    FINISHING_TIME=0;
  
    list<Vertex>::reverse_iterator reverse_begin= graph.vertices.rbegin();
    while(reverse_begin!=graph.vertices.rend()){
        s=*(reverse_begin);
        if(!((*reverse_begin).isVisited))
          DFS(graph,*(reverse_begin));
        reverse_begin++;
    }
}
void DFS_Loop_queue(Graph& graph){
    Vertex* it;
    while(!TRAVERSE_ORDER.empty()){
        it=TRAVERSE_ORDER.top();
        s=(*it);
        if(!(*it).isVisited)
         DFS(graph,(*it));
        TRAVERSE_ORDER.pop();
    }
}
void KosarajuSCCS(Graph& graph){
    reverse_graph(graph);
    DFS_Loop(graph);
    reverse_graph(graph);
   
    graph.refreshVertices();
    // cout<<"START NEXT DFS HERE"<<endl;
     DFS_Loop_queue(graph);
}
