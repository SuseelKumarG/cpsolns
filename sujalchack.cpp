#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
mt19937 rng(0); // Fixed seed for deterministic output

// Returns a random number in the inclusive range [low, high]
ll getRandomNumber(ll low, ll high) {
    uniform_int_distribution<ll> dist(low, high);
    return dist(rng);
}

// Checks if n is a power of 2
bool isPowerOfTwo(ll n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Generates test cases in the range [2, 1e9]
void generateTestCases(int num_cases) {
    cout << num_cases << "\n"; // First line: number of test cases
    for (int i = 0; i < num_cases; i++) {
        ll n;
        int type = getRandomNumber(1, 6);
        switch (type) {
            case 1: {
                // Exactly a power of 2; exponent in [1,29] so that 2^exp is in [2, 1e9]
                int exp = getRandomNumber(1, 29);
                n = 1LL << exp;
                break;
            }
            case 2: {
                // Just below a power of 2; use exponent in [2,29] to keep n >= 2
                int exp = getRandomNumber(2, 29);
                n = (1LL << exp) - 1;
                break;
            }
            case 3: {
                // Just above a power of 2; exponent in [1,29]
                int exp = getRandomNumber(1, 29);
                n = (1LL << exp) + 1;
                break;
            }
            case 4: {
                // Very small numbers in [2,20]
                n = getRandomNumber(2, 20);
                break;
            }
            case 5: {
                // Large random composite number in [100, 1e9] that is not a power of 2
                do {
                    n = getRandomNumber(100, 1000000000);
                } while (isPowerOfTwo(n) || isPowerOfTwo(n + 1));
                break;
            }
            case 6: {
                // A general random number in the full range [2, 1e9]
                n = getRandomNumber(2, 1000000000);
                break;
            }
        }
        cout << n << "\n";
    }
}

int main() {
    int t = 15; // Fixed number of test cases (you can adjust this as needed)
    generateTestCases(t);
    return 0;
}
