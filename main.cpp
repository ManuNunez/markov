#include <bits/stdc++.h>
using namespace std;

#define ss second
#define ff first
#define pb push_back
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define enl "\n"
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(s) int(s.size())
#define fore(i, n) for (int i = 0; i < n; ++i)
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define arre cout << "YES" << enl;
#define nel cout << "NO" << enl;
#define neg cout << -1 << enl;
#define srt(s) sort(all(s));
#define rsrt(s) sort(rall(s));
#define lower(vec, s) lower_bound(all(vec), s)
#define upper(vec, s) upper_bound(all(vec), s)

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<char> vchar;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MOD = 1000000007;
const double PI = acos(-1.0);
const double TOLERANCE = 1e-10;

void multiplyVectorMatrix(const vector<double>& vec, const vector<vector<double>>& matrix, vector<double>& result, int n) {
    fore(i, n) {
        result[i] = 0;
        fore(j, n) {
            result[i] += vec[j] * matrix[j][i];
        }
    }
}

void normalizeRow(vector<double>& row, int n) {
    double sum = accumulate(all(row), 0.0);
    fore(i, n) {
        row[i] /= sum;
    }
}

void findSteadyState(const vector<vector<double>>& P, vector<double>& pi, int n) {
    vector<double> pi_next(n);
    double sum_diff;

    do {
        multiplyVectorMatrix(pi, P, pi_next, n);

        sum_diff = 0;
        fore(i, n) {
            sum_diff += fabs(pi_next[i] - pi[i]);
            pi[i] = pi_next[i];
        }
    } while (sum_diff > TOLERANCE);
}

int main() {
    fastio;

    int cases;
    cin >> cases;

    while (cases--) {
        int n;
        cin >> n;

        vector<vector<double>> P(n, vector<double>(n));
        fore(i, n) {
            fore(j, n) {
                cin >> P[i][j];
            }
            normalizeRow(P[i], n);
        }

        vector<double> pi(n);
        fore(i, n) {
            cin >> pi[i];
        }

        double sum = accumulate(all(pi), 0.0);
        fore(i, n) {
            pi[i] /= sum;
        }

        findSteadyState(P, pi, n);

        fore(i, n) {
            cout << fixed << setprecision(5) << pi[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << enl;
    }

    return 0;
}
