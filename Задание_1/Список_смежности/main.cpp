#include <iostream>
#include <fstream>

using namespace std;

class MyGraph{
    int graph_count;
    int *data;
    public:
        MyGraph();
        ~MyGraph();
        void print_data();
        void read_graph(string filename);
};

int main()
{
    MyGraph gr;
    gr.read_graph("input.txt");
    gr.print_data();
    return 0;
}

MyGraph::MyGraph(){
    graph_count = 0;
    data = NULL;
}

MyGraph::~MyGraph(){
    delete[] this->data;
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
            cout << *(data+i*N+j) << " ";
        }
        cout << endl;
    }
}
