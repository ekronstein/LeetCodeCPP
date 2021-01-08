#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::cout;
using std::endl;
using std::set;

typedef vector<vector<int>> DIVec;  // Double Int Vector
typedef vector<int> IVec;

class AllPathsSourceTarget {
public:
    DIVec allPathsSourceTarget(DIVec &graph) {
        DIVec res;
        aux(graph, 0, res);
        return res;
    }

private:
    void aux(DIVec &graph, int root, DIVec &res) {
        if (root == graph.size() - 1) {
            res.resize(res.size() + 1);
            res[res.size() - 1].push_back(root);
        }

        for (auto child : graph[root]) {
            aux(graph, child, res);
            res[res.size() - 1].push_back(root);
        }
    }
};

void reversePaths(DIVec &input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size() / 2; j++) {
            int tmp = input[i][j];
            input[i][j] = input[i][input[i].size() - j - 1];
            input[i][input[i].size() - j - 1] = tmp;
        }
    }
}

int main() {
    DIVec graph = {{1, 2}, {3}, {3}, {}};
    AllPathsSourceTarget sol;
    DIVec res = sol.allPathsSourceTarget(graph);
    reversePaths(res);
    cout << "[";
    for (int path = 0; path < res.size(); path++) {
        cout << "[";
        for (int j = 0; j < res[path].size(); j++) {
            if (j == res[path].size() - 1)
                cout << res[path][j] << "]";
            else
                cout << res[path][j] << ", ";
        }
        if (path == res.size() - 1)
            cout << "]" << endl;
        else
            cout << ", ";
    }

}