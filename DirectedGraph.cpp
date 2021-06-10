#include "Vertex.cpp"
using namespace std;
class Graph{
    public:
 list<Vertex> vertices;
 list<Edge> edges;
 void refreshVertices(){
     for(auto& x: vertices){
         x.isVisited=false;
     }
 }
  void printOrder(){
      for(auto&x: vertices){
          cout<<x.data.front()<<" "<<x.label<<",";
      }
  }
  void addEdge(int from,int to){
     list<Vertex>::iterator from_it=find(from);
     list<Vertex>::iterator to_it=find(to);
     Vertex& v1=*from_it;
     Vertex& v2=*to_it;
     Edge edge(v1,v2);
     edges.push_back(edge);
     (v1).pointers.push_back(&(v2));
  }
  
  list<Vertex>::iterator find(int data){
    list<Vertex>::iterator it= vertices.begin();
    while(it!=vertices.end()){
        list<int>::iterator it2=it->data.begin();
        while(it2!=it->data.end()){
        if(*it2==data)
         return it;
         it2++;
        }
        it++;
    }
   return it;
}


   void print(){
    list<Vertex>::iterator it=vertices.begin();
    cout<<"VERTICES"<<endl;
    while(it!=vertices.end()){
        (*it).print();
        it++;
    }
    list<Edge>::iterator it2=edges.begin();
    cout<<"EDGES"<<endl;
    while(it2!=edges.end()){
        (*it2).print();
        it2++;
    }
    cout<<endl;
  }
  void printGroups(){
      for(auto& x:vertices){
          cout<<x.data.front()<<" lead->"<<x.leader<<endl;
      }
  }
  
  int size(){
     return vertices.size(); 
  }
  
  int EdgeCount(){
      return edges.size();
  }
  
  
  void RemoveEdge(list<Edge>::iterator it){
      if(it!=edges.end())
        it=edges.erase(it);
  }
  
  void RemoveVertex(list<Vertex>::iterator it){
      vertices.erase(it);
  }
};
