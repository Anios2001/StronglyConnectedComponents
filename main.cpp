/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
#include "DirectedGraph.cpp"
//  #include "TopologicalOrdering"
//#include "DFS"
#include "StronglyConnectedComponent.cpp"
#include <fstream>
#include<sstream>
#include<utility>
#include<vector>
void findNoOfSCCS(Graph graph,vector<pair<int,int>> &ansVec){
 for(auto& x: graph.vertices){
    bool IS_FOUND=false;
    for(auto& y: ansVec){
     if(y.first==x.leader){
      y.second++;
      IS_FOUND=true;
      }}
      if(!IS_FOUND)
       {
       pair<int,int> myp;
       myp.first=x.leader;
       myp.second=1;
       ansVec.push_back(myp);
       }
     
 }
}
int main()
{
    string inputLine;
   Graph graph;
  ifstream fileinput;
  fileinput.open("DataPart1.txt");
  cout<<"Enter the number of nodes and denomination upper bound from 1"<<endl;
  int NO_OF_NODES=0;
  cin>>NO_OF_NODES;
  for(int i=1;i<=NO_OF_NODES;i++){
  Vertex v1(i); 
  graph.vertices.push_back(v1);
  }
  //cout<<"Enter the no. of edges to add"<<endl;
  //int NO_OF_EDGES=0;
  //cin>>NO_OF_EDGES;
  while(getline(fileinput,inputLine)){
    int start_v;
    int end_v;
    istringstream iss(inputLine);
    iss>>start_v;
    iss>>end_v;
    graph.addEdge(start_v,end_v);
    
  }
  cout<<"DATA INPUT DONE"<<endl;
 //graph.print();
//   cout<<"GRAPH REVERSED AND THIS IS IT"<<endl;
   vector<pair<int,int>> answers;
  KosarajuSCCS(graph);
  //findNoOfSCCS(graph,answers);
  //cout<<"Size of answers"<<answers.size()<<endl;
  
  //for(auto& x: answers){
   //cout<<x.first<<x.second<<endl;
  //}
// graph.printGroups();
 // TopologicalOrdering(graph);
//   graph.printOrder();
  //DFS(graph,6);
 
    return 0;
}
