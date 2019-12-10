
#include"priority_queue.h"

class Edge{
    int32_t p1, p2;
    int32_t val;

public:
    Edge(int32_t pi, int32_t pj, int32_t v):p1(pi), p2(pj), val(v){};
    Edge() = default;
    ~Edge() = default;
    bool operator < (const Edge e) const{
        return val > e.val;
    }
    bool operator == (const Edge e) const{
        return val == e.val;
    }
    void operator = (const Edge e) {
        p1 = e.p1;
        p2 = e.p2;
        val = e.val;
    }
    const int32_t& get_ori() const{return p1;}
    const int32_t& get_tar() const{return p2;}
    const int32_t& get_len() const{return val;}
};

class MST{

private:
    Vector<int> used;
    Priority_queue<Edge> pq;
    Vector<Edge> mst;
    Vector<Vector<Edge> > all_edges;
    int32_t quaitity;

public:
    MST(int32_t n): quaitity(n){
        used.resize(n);
        all_edges.resize(n);
    };
    ~MST() = default;
    void input(int32_t ori, int32_t tar, int32_t len);

    void generate();
    const Vector<Edge>& get_mst()const{return mst;}
};


void MST::input(int32_t ori, int32_t tar, int32_t len){
    Edge edge_ori = Edge(ori, tar, len);
    Edge edge_tar = Edge(tar, ori, len);
    all_edges[ori].push_back(edge_ori);
    all_edges[tar].push_back(edge_tar);
}

void MST::generate(){
    int cur = 0;
    int cnt = 1;
    while(cnt < quaitity){
        used[cur] = 1;
        for(int32_t i = 0; i < all_edges[cur].get_len(); i++){
            if(!used[all_edges[cur][i].get_tar()]){
               pq.push(all_edges[cur][i]);

            }
        }
        Edge shortest_edge;
        while(!pq.empty()){
            shortest_edge = pq.top();
            pq.pop();
            if(!used[shortest_edge.get_tar()]) break;
        }   
        mst.push_back(shortest_edge);
        cnt++;
        cur = shortest_edge.get_tar();
    }
}
