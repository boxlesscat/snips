// refer to https://algs4.cs.princeton.edu/15uf/

#ifndef UNION_FIND
#define UNION_FIND

#include <vector>

using namespace std;


//! items can be numbered from 0 to N (both inclusive)

//! join(p, q) joins the two components of the items p and q
 // connected(p, q) returns whether the two items are in the same component
 // find(i) returns the greatest ancestor of the item i in the component tree
 // comp(i) returns the no of items in the component containing the item i


// >>>>>>>>>>>>>

class UnionFind {

    vector<int> id;
    vector<int> sz;

public:

    UnionFind(const int N) : id(N + 1), sz(N + 1, 1) {
        for (int i = 0; i < N; i++)
            id[i] = i;
    }

    void join(const int p, const int q) {
        const int i = find(p);
        const int j = find(q);
        if (i == j)
            return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }

    bool connected(const int p, const int q) {
        return find(p) == find(q);
    }

    int find(int i) {
        while (i != id[i])
            i = id[i] = id[id[i]];
        return i;
    }

    int comp(const int i) {
        return sz[find(i)];
    }

};

// <<<<<<<<<<<<<


#endif
