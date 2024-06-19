// refer to https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

#ifndef ERATOSTHENES_SIEVE
#define ERATOSTHENES_SIEVE

#include <vector>
#include <cmath>

using namespace std;


//! N is safe upto 10⁶


// >>>>>>>>>>>>>

vector<bool> is_prime;
vector<long long> primes;

void sieve(const long long N) {
    is_prime.assign(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long p = 2; p <= N; p++)
        if (is_prime[p]) {
            for (long long j = p * p; j <= N; j += p)
                is_prime[j] = false;
            primes.push_back(p);
        }
}

// <<<<<<<<<<<<<


#endif 