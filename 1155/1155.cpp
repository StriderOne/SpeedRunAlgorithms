#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>
#include <vector>

using namespace std;

struct point {
    int x, y, z;

    string out() {
        return to_string(x) + " " + to_string(y) + " " + to_string(z);
    }
};

point operator-(point a, point b) {
    return {a.x-b.x,a.y-b.y,a.z-b.z};
}

point operator+(point a, point b) {
    return {a.x+b.x,a.y+b.y,a.z+b.z};
}

double operator*(point a, point b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

bool operator<(point a, point b) {
    return (a.x < b.x) | (a.y < b.y) | (a.z < b.z);
}

bool operator==(point a, point b) {
    return (a.x == b.x) & (a.y == b.y) & (a.z == b.z);
}

bool operator!=(point a, point b) {
    return (a.x != b.x) | (a.y != b.y) | (a.z != b.z);
}

double dist(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

map<int, char> vertex_idx = {
    {0, 'A'},
    {1, 'B'},
    {2, 'C'},
    {3, 'D'},
    {4, 'E'},
    {5, 'F'},
    {6, 'G'},
    {7, 'H'}
};

map<char, point> vertex_coord = {
    {'A', {0, 0, 0}},
    {'B', {1, 0, 0}},
    {'C', {1, 1, 0}},
    {'D', {0, 1, 0}},
    {'E', {0, 0, 1}},
    {'F', {1, 0, 1}},
    {'G', {1, 1, 1}},
    {'H', {0, 1, 1}}
};

vector<int> g[10];

string findValue(map<char, point>* map, point val) {
    for (auto i = map->begin(); i != map->end(); i++) {
        if ((i->second) == val) {
            string res(1, i->first);
            return res;
        }
    }
    
}

string moveOneDuonDiag(point start, point finish) {
    // How find another 2 points in the suqre?
    point vec;

    // point point1, point2;
    vector <point> points;
    for (auto i = vertex_coord.begin(); i != vertex_coord.end(); i++) {
        point it = i->second;
        if ((it - start) * (it - finish) == 0 && it != start && it != finish) {
            points.push_back(it);
        }
    }
    // cout << point1.out() << " " << point2.out() << endl;
    string pl = "+";
    string min = "-";
    string res = findValue(&vertex_coord, start) + findValue(&vertex_coord, points[0]) + pl + '\n';
    res = res + findValue(&vertex_coord, points[0]) + findValue(&vertex_coord, finish) + pl + '\n';
    res = res + findValue(&vertex_coord, finish) + findValue(&vertex_coord, points[1]) + pl + '\n';
    res = res + findValue(&vertex_coord, points[1]) + findValue(&vertex_coord, start) + min + '\n';
    res = res + findValue(&vertex_coord, start) + findValue(&vertex_coord, points[0]) + min + '\n';
    res = res + findValue(&vertex_coord, points[0]) + findValue(&vertex_coord, finish) + min + '\n';

    return res;
}

int main() {
    long long n, a[10];
    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < 8; i++) {
        cin >> a[i];
    }
    
    sum1 = a[0] + a[2] + a[5] + a[7];
    sum2 = a[1] + a[3] + a[4] + a[6];

    if (sum1 != sum2) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int k = 0; k < 8; k++) {
        point cur = vertex_coord.at(vertex_idx.at(k));
        int c = 0;
        for (auto i = vertex_coord.begin(); i != vertex_coord.end(); i++) {
            // cout << dist(cur, i->second) << " ";
            if (dist(cur, i->second) == 1.0) {
                int min_ = min(a[k], a[c]);
                for (int j = 0; j < min_; j++) {
                    a[k]--;
                    a[c]--;
                    cout << findValue(&vertex_coord, cur) << findValue(&vertex_coord, i->second) << "-" << endl;
                }
            }
            c++;
        }
        // cout << endl;
    }

    sum1 = a[0] + a[2] + a[5] + a[7];
    sum2 = a[1] + a[3] + a[4] + a[6];

    for (int i = 0; i < a[2]; i++) {
        cout << moveOneDuonDiag(vertex_coord.at(vertex_idx.at(2)), vertex_coord.at(vertex_idx.at(0)));
    }
    for (int i = 0; i < a[5]; i++) {
        cout << moveOneDuonDiag(vertex_coord.at(vertex_idx.at(5)), vertex_coord.at(vertex_idx.at(0)));
    }
    for (int i = 0; i < a[7]; i++) {
        cout << moveOneDuonDiag(vertex_coord.at(vertex_idx.at(7)), vertex_coord.at(vertex_idx.at(0)));
    }

    for (int i = 0; i < a[3]; i++) {
        cout << moveOneDuonDiag(vertex_coord.at(vertex_idx.at(3)), vertex_coord.at(vertex_idx.at(1)));
    }
    for (int i = 0; i < a[4]; i++) {
        cout << moveOneDuonDiag(vertex_coord.at(vertex_idx.at(4)), vertex_coord.at(vertex_idx.at(1)));
    }
    for (int i = 0; i < a[6]; i++) {
        cout << moveOneDuonDiag(vertex_coord.at(vertex_idx.at(6)), vertex_coord.at(vertex_idx.at(1)));
    }
    

    for (int i = 0; i < sum1; i++) {
        cout << "AB-" << endl;
    }
    // point G = vertex_coord.at('G');
    // point D =  vertex_coord.at('D');

    // cout << (G-D).out();

    return 0;
}
