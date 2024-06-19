// refer to https://cp-algorithms.com/string/z-function.html

#ifndef Z_FUNCTION
#define Z_FUNCTION

#include <string>
#include <vector>

using namespace std;


//! z[i] is the length of longest match between prefix of str and the substring str[i:]
//! z[0] is 0 and not size


// >>>>>>>>>>>>>

vector<int> zf(const string& str) {
    const int size = str.size();
    vector<int> z(size);
    int l = 0;
    int r = 0;
    for (int i = 1; i < size; ++i) {
        if (i < r)
            z[i] = min(z[i - l], r - i);
        while (i + z[i] < size and str[z[i]] == str[i + z[i]])
            ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// <<<<<<<<<<<<<


#endif
