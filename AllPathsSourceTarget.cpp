#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

vector<vector<int>> aux(vector<vector<int>> &grpah, int node, unordered_map<int, vector<int>> &mem, vector<vector<int>> &res) {
    if (mem.find(node) != mem.end()) {

    }
}

class AllPathsSourceTarget {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        unordered_map<int, vector<int>> mem;
        vector<vector<int>> res;
        return aux(graph, 0, mem, res);
    }
};