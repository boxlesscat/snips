// refer to https://cp-algorithms.com/data_structures/segment_tree.html

#ifndef SEGTREE_SUM
#define SEGTREE_SUM

#include <iostream>
#include <vector>

using namespace std;


// 01. the 'in' vector is expected to be 0-indexed. everything else in the implementation is 1 indexed

// >>>>>>>>>>>>>

template <typename T = long long>
class SumSegTree {

    const vector<T>& in;
    const int size;
    vector<long long> seg;

    void build(const int node, const int il, const int ir) {
        if (il == ir) {
            seg[node] = in[il - 1];
        } else {
            const int im = il + ir >> 1;
            const int lnode = 2 * im + 0;
            const int rnode = 2 * im + 1;
            build(lnode, il, im + 0);
            build(rnode, im + 1, ir);
            seg[node] = seg[lnode] + seg[rnode];
        }
    }

    long long sum(const int node, const int il, const int ir, const int l, const int r) const {
        if (l > r) {
            return 0;
        }
        if (l == il and ir == r) {
            return seg[node];
        }
        const int im = il + ir >> 1;
        const int lnode = 2 * im + 0;
        const int rnode = 2 * im + 1;
        return sum(lnode, il, im + 0, l, min(r, im + 0))
             + sum(rnode, im + 1, ir, max(l, im + 1), r);
    }

    void update(const int pos, const long long val, const int node, const int il, const int ir) {
        if (il == ir) {
            seg[node] = val;
        } else {
            const int im = il + ir >> 1;
            const int lnode = 2 * im + 0;
            const int rnode = 2 * im + 1;
            if (pos <= im)
                update(pos, val, lnode, il, im + 0);
            else
                update(pos, val, rnode, im + 1, ir);
            seg[node] = seg[lnode] + seg[rnode];
        }
    }


public:

    SumSegTree(const vector<T>& in):
        in(in), size(in.size()), seg(size << 2) {
            build(1, 1, size);
    }

    long long query0(const int l, const int r) const {
        return query1(l + 1, r + 1);
    }

    long long query1(const int l, const int r) const {
        return sum(1, 1, size, l, r);
    }

    void update0(const int pos, const long long val) {
        update1(pos + 1, val);
    }

    void update1(const int pos, const long long val) {
        update(pos, val, 1, 1, size);
    }


};

// <<<<<<<<<<<<<

#endif
