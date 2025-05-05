#include <iostream>
using namespace std;

class disjointset{
public:
    int djset[20];

    disjointset(int v){
        for(int i=0;i<=v;i++){
            djset[i] = i;
        }
    }

    int find_root(int v){
        while(v != djset[v]){
            v = djset[v];
        }
        return v;
    }

    void take_union(int v1, int v2){
        int r1 = find_root(v1);
        int r2 = find_root(v2);

        if(v1 == r1 && v2 == r2){
            djset[v1] = v2;
        }
        else if(v1 != r1 && v2 == r2){
            djset[v2] = v1;
        }
        else if(v1 == r1 && v2!= r2){
            djset[v1] = v2;
        }
        else if(v1 != r1 && v2 != r2){
            djset[r1] = r2;
        }
    }
};

class edge{
public:
    int v1;
    int v2;
    int wt;
};

class graph{
public:
    int v;
    int e;
    edge ed[20];

    graph(int vertices, int edges){
        v = vertices;
        e = edges;
    }

    void accept_graph();
    void display_graph();
    void kruskal_mst();
    void sort_edges();
};

void graph::sort_edges(){
    edge temp;
    for(int i=0;i<e;i++){
        for(int j=0;j<e-i-1;j++){
            if(ed[j].wt > ed[j+1].wt){
              temp.v1 = ed[j].v1;
              temp.v2 = ed[j].v2;
              temp.wt = ed[j].wt;

              ed[j].v1 = ed[j+1].v1;
              ed[j].v2 = ed[j+1].v2;
              ed[j].wt = ed[j+1].wt;

              ed[j+1].v1 = temp.v1;
              ed[j+1].v2 = temp.v2;
              ed[j+1].wt = temp.wt;
            }
        }
    }
}

void graph::kruskal_mst(){
    edge mst[20];
    int mst_ctr = 0;
    int mst_cost = 0;
    disjointset dj(v);
    sort_edges();
    cout<<"\n Edges after sorting: ";
    display_graph();
    cout<<"\n";

    for(int i=0;i<e;i++){
        int r1 = dj.find_root(ed[i].v1);
        int r2 = dj.find_root(ed[i].v2);
        if(r1 != r2){
            mst[mst_ctr].v1 = ed[i].v1;
            mst[mst_ctr].v2 = ed[i].v2;
            mst[mst_ctr].wt = ed[i].wt;
            mst_ctr++;
            mst_cost = mst_cost + ed[i].wt;
            dj.take_union(ed[i].v1,ed[i].v2);
        }
    }

    cout<<"\n MST is : ";
    for(int i=0;i<mst_ctr;i++){
        cout<<"\n   "<<mst[i].v1<<"     "<<mst[i].v2<<"     "<<mst[i].wt;
    }
    cout<<"\n Total cost of MST is: "<<mst_cost;

}

void graph::accept_graph(){
    for(int i=0;i<e;i++){
        cout<<"\n Enter v1 :";
        cin>>ed[i].v1;
        cout<<"\n Enter v2 :";
        cin>>ed[i].v2;
        cout<<"\n Enter weight :";
        cin>>ed[i].wt;
    }
}

void graph::display_graph(){
    for(int i=0;i<e;i++){
        cout<<"\n   "<<ed[i].v1<<"     "<<ed[i].v2<<"     "<<ed[i].wt;
    }
}

int main(){

    int v, e;
    cout<<"\n Enter the number of vertics : ";
    cin>>v;
    cout<<"\n Enter the number of edges : ";
    cin>>e;

    graph g(v, e);
    g.accept_graph();
    g.display_graph();
    g.kruskal_mst();
}
// Output - 

// Enter the number of vertics : 7

//  Enter the number of edges : 9

//  Enter v1 :1

//  Enter v2 :2

//  Enter weight :28

//  Enter v1 :2

//  Enter v2 :3

//  Enter weight :16

//  Enter v1 :3

//  Enter v2 :4

//  Enter weight :12

//  Enter v1 :4

//  Enter v2 :5

//  Enter weight :22

//  Enter v1 :5

//  Enter v2 :6

//  Enter weight :25

//  Enter v1 :6

//  Enter v2 :1

//  Enter weight :10

//  Enter v1 :2

//  Enter v2 :7

//  Enter weight :14

//  Enter v1 :7

//  Enter v2 :5

//  Enter weight :24

//  Enter v1 :7

//  Enter v2 :4

//  Enter weight :18

//    1     2     28
//    2     3     16
//    3     4     12
//    4     5     22
//    5     6     25
//    6     1     10
//    2     7     14
//    7     5     24
//    7     4     18
//  Edges after sorting:
//    6     1     10
//    3     4     12
//    2     7     14
//    2     3     16
//    7     4     18
//    4     5     22
//    7     5     24
//    5     6     25
//    1     2     28

//  MST is :
//    6     1     10
//    3     4     12
//    2     7     14
//    2     3     16
//    4     5     22
//    5     6     25
//  Total cost of MST is: 99
