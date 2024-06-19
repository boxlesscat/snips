// refer to https://cp-algorithms.com/data_structures/segment_tree.html

#ifndef SEGTREE_MAX
#define SEGTREE_MAX

#include <climits>
#include <vector>

using namespace std;


//! the 'in' vector is expected to be 0-indexed
 // query0() and update0() are also 0-indexed
 // everything else in the implementation is 1 indexed

//! add the most min value during declaration if the type is not int
 // (eg: MaxSegTree<long long, LLONG_MIN> seg(in))
 //                            ^^^^^^^^^


// >>>>>>>>>>>>>

template <typename T = int, T MIN = INT_MIN>
class MaxSegTree {

    const vector<T>& in;
    const int size;
    vector<T> seg;

    void build(const int node, const int il, const int ir) {
        if (il == ir) {
            seg[node] = in[il - 1];
        } else {
            const int im = il + ir >> 1;
            const int lnode = 2 * im + 0;
            const int rnode = 2 * im + 1;
            build(lnode, il, im + 0);
            build(rnode, im + 1, ir);
            seg[node] = max(seg[lnode], seg[rnode]);
        }
    }

    T query(const int node, const int il, const int ir, const int l, const int r) const {
        if (l > r) {
            return MIN;
        }
        if (l == il and ir == r) {
            return seg[node];
        }
        const int im = il + ir >> 1;
        const int lnode = 2 * im + 0;
        const int rnode = 2 * im + 1;
        return max(
            query(lnode, il, im + 0, l, min(r, im + 0)),
            query(rnode, im + 1, ir, max(l, im + 1), r)
        );
    }

    void update(const int pos, const int val, const int node, const int il, const int ir) {
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
            seg[node] = max(seg[lnode], seg[rnode]);
        }
    }


public:

    MaxSegTree(const vector<T>& in):
        in(in), size(in.size()), seg(size << 2) {
            build(1, 1, size);
    }

    T query0(const int l, const int r) const {
        return query1(l + 1, r + 1);
    }

    T query1(const int l, const int r) const {
        return query(1, 1, size, l, r);
    }

    void update0(const int pos, const T val) {
        update1(pos + 1, val);
    }

    void update1(const int pos, const T val) {
        update(pos, val, 1, 1, size);
    }


};

// <<<<<<<<<<<<<


#endif
