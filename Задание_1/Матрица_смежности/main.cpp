#include <iostream>
#include <fstream>
 // FOO_HPP

using namespace std;

class MyGraph{
    int graph_count;
    int *data;
    public:
        MyGraph();
        ~MyGraph();
        void print_data();
        void read_graph(string filename);
        void min_road(int start);
};

int main()
{
    MyGraph gr;
    int start;
    gr.read_graph("input.txt");
    //gr.print_data();
    setlocale(LC_ALL, "Rus");
    cout << "Стартовая вершина >> ";
    cin >> start;
    gr.min_road(start);
    return 0;
}

MyGraph::MyGraph(){
    graph_count = 0;
    data = NULL;
}

MyGraph::~MyGraph(){
    delete[] data;
}

void MyGraph::read_graph(string filename){
    ifstream in(filename);
    int N = 0;
    string s;
    if(in.is_open()){
        while(getline(in, s))
            N++;
        this->data = new int[N*N];
        this->graph_count = N;
        in.close();
        ifstream in(filename);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int b;
                in >> b;
                *(data+i*N+j) = b;

            }
        }
    }
    in.close();
}

void MyGraph::print_data(){
    int N = this->graph_count;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << data[i*N+j] << " ";
        }
        cout << endl;
    }
}

void MyGraph::min_road(int start){
    int N = this->graph_count;
    int distance[N], count_d, index, i, u;
    bool visited[N];
    for (i=0; i<N; i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[start]=0;
    for (count_d=0; count_d<N-1; count_d++){
        int min_d=INT_MAX;
        for (i=0; i<N; i++)
            if (!visited[i] && distance[i]<=min_d){
                min_d=distance[i]; index=i;
            }
        u=index;
        visited[u]=true;
        for (i=0; i<N; i++)
            if (!visited[i] && data[u*N+i] && distance[u]!=INT_MAX && distance[u]+data[u*N+i]<distance[i])
                distance[i]=distance[u]+data[u*N+i];
    }
    for (i=0; i<N; i++)
        if (distance[i]==INT_MAX)
            cout<<start<<" > "<<i<<" - "<<"маршрут недоступен"<<endl;
}
