#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = a[i][j] + b[i][j];
    return res;
}

vector<vector<int>> subtract(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = a[i][j] - b[i][j];
    return res;
}

vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    if (n == 1) {
        return {{a[0][0] * b[0][0]}};   
    }
    int k = n / 2;
    vector<vector<int>> a11(k, vector<int>(k)), a12(k, vector<int>(k)), a21(k, vector<int>(k)), a22(k, vector<int>(k));
    vector<vector<int>> b11(k, vector<int>(k)), b12(k, vector<int>(k)), b21(k, vector<int>(k)), b22(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }
    }
    auto p1 = strassen(a11, subtract(b12, b22));
    auto p2 = strassen(add(a11, a12), b22);
    auto p3 = strassen(add(a21, a22), b11);
    auto p4 = strassen(a22, subtract(b21, b11));
    auto p5 = strassen(add(a11, a22), add(b11, b22));
    auto p6 = strassen(subtract(a12, a22), add(b21, b22));
    auto p7 = strassen(subtract(a11, a21), add(b11, b12));
    auto c11 = add(subtract(add(p5, p4), p2), p6);
    auto c12 = add(p1, p2);
    auto c21 = add(p3, p4);
    auto c22 = subtract(subtract(add(p5, p1), p3), p7);
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            c[i][j] = c11[i][j];
            c[i][j + k] = c12[i][j];
            c[i + k][j] = c21[i][j];
            c[i + k][j + k] = c22[i][j];
        }
    }
    return c;
}

int main() {
    vector<vector<int>> a = {{1, 2}, {3, 4}};
    vector<vector<int>> b = {{5, 6}, {7, 8}};
    auto c = strassen(a, b);
    for (auto &i : c) {
        for (int &j : i) {  
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}
