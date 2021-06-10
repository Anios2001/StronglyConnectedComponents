

void reverse_graph(Graph& graph){
    for(auto& x: graph.vertices){
        x.isReversed=false;
    }
    for(auto& x:graph.edges){
        Vertex& start= *x.ver1;
        Vertex& end= *x.ver2;
        if(!start.isReversed){
         start.pointers.clear();
         start.isReversed=true;
        }
        if(!end.isReversed){
            end.pointers.clear();
            end.isReversed=true;
        }
        end.pointers.push_back(&start);
        Vertex *tmp= x.ver1;
        x.ver1=x.ver2;
        x.ver2=tmp;
    }
}
