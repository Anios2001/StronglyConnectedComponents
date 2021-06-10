#include<list>
using namespace std;
typedef struct Vertex{
    list<int> data;
    list<Vertex*> pointers;
    int distance;
    int label;
    bool isVisited;
    bool isReversed=false;
    int leader;
    int finishingtime;
    Vertex(){
    }
    Vertex& operator=(const Vertex& a){
        data.clear();
        pointers.clear();
        for(auto& x: a.data){
            data.push_back(x);
        }
        for(auto& y: a.pointers)
        {
            pointers.push_back(y);
        }
        return *(this);
    }
     Vertex(int data_){
         data.push_back(data_);
     }
    void print(){
        
        cout<<"Vertex ";
        for(auto& Y:data)
         cout<<Y<<",";
        cout<<endl; 
        cout<<"Adj Vertices ";
        for(auto& X: pointers )
         cout<<(X->data).front()<<",";
        cout<<endl; 
    } 
} Vertex;

typedef struct Edge{
    Vertex* ver1;
    Vertex* ver2;
    Edge(Vertex& v1,Vertex& v2):ver1(&v1),ver2(&v2){}
    void print(){
        cout<<"{"<<(ver1->data).front()<<","<<(ver2->data).front()<<"}"<<endl;
        
    }
}Edge;