#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <set>
#include <iterator>

using std::unordered_map;
using std::vector;
using std::set;
using std::iterator;


template<class I, class D = int>
class Node {
public:
    Node() {}
    Node(I id, D data);
    Node(I id, const D &data);
    Node(const Node<I, D> &to_copy);
    I getId();
    vector<Node<I, D> *> getChildren();
    void addChildren(const vector<Node<I, D>> &to_add);
    const vector<Node<I, D>> &getChildren();


private:
    I id_;
    D data_;
    vector<Node<I, D>> children_;
};


template<class I, class D>
class Graph {
/*
* class for representing a graph data structure. 
* class I - type of the 
*/
public:
    /*
    * constructor for Graph. 
    * root - the graph root node. It is assumed it has it's connectios
    * and it's connections has their own connections and their conn...
    * you get the point
    */
    Graph() {};
    void setRoot(const Node<I, D> &root);
    uint_t size();
    unordered_map<I, I> DFS(I input);  // implement function ptr input for search in data
    unordered_map<I, I> BFS(I input);  // implement function ptr input for search in data
    Node<I, D> getNode(I id);

private:
    I root_id_;
    unordered_map<I, Node<I, D>> node_map_;
};

#endif  // GRAPH_H