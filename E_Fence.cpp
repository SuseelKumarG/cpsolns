#include "testlib.h"
#include <set>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10000000, "t");
    inf.readEoln();

    for (int test = 1; test <= t; ++test) {
        setTestCase(test);

        int n = inf.readInt(1, 500, format("n[%d]", test).c_str());
        inf.readEoln();

        if (ouf.seekEof()) {
            quitf(_fail, "Unexpected EOF in output before test case %d", test);
        }

        string token = ouf.readToken(format("a[%d][0]", test).c_str());

        if (token == "-1") {
            ouf.readEoln();
            continue;
        }

        // Try parsing first number
        int firstVal;
        try {
            firstVal = stoi(token);
        } catch (...) {
            quitf(_fail, "Non-integer token found in test case %d: '%s'", test, token.c_str());
        }

        ensuref(1 <= firstVal && firstVal <= 1000,
                "First value out of bounds in test case %d: %d", test, firstVal);

        vector<int> a = {firstVal};

        for (int i = 1; i < n; ++i) {
            if (ouf.seekEof()) {
                quitf(_fail, "Unexpected EOF while reading a[%d][%d]", test, i);
            }
            int x = ouf.readInt(1, 1000, format("a[%d][%d]", test, i).c_str());
            a.push_back(x);
        }

        ouf.readEoln();

        if ((int)a.size() != n) {
            quitf(_fail, "Expected %d elements, got %d in test case %d", n, (int)a.size(), test);
        }

        set<int> xorvals;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                xorvals.insert(a[i] ^ a[j]);

        if ((int)xorvals.size() != n) {
            quitf(_fail, "XOR set size is %d, expected %d in test case %d", (int)xorvals.size(), n, test);
        }

        for (int k = 1; k <= n; ++k) {
            if (!xorvals.count(k)) {
                quitf(_fail, "Missing XOR value %d in test case %d", k, test);
            }
        }
    }

    ouf.readEof();  // Final EOF check
}