#include "Graph.hpp"
#include <deque>
#include <exception>

using std::deque;
using std::exception;

struct BadNodeIdException : public exception {
    const char *what() const throw() {
        return "id not found";
    }
};

template<class I, class D>
Node<I, D>::Node(I id, D data) :
id_(id), data_(data) {}

template<class I, class D>
Node<I, D>::Node(I id, const D &data) : 
                id_(id),
                data_(data) {
}

template<class I, class D>
void Node<I, D>::addChildren(const vector<Node<I, D> &> &to_add) {
    if (children_.find(node_id) == children_.end()) {
        throw BadNodeIdException();
    }
    for (auto node : to_add) {
        children_[node.getId()].push_back(node);
    }
}

template<class I, class D>
I Node<I, D>::getId() {
    return id_;
}

template<class I, class D> 
const vector<Node<I, D>> &Node<I, D>::getChildren() {
    return children_;
}

template<class I, class D>
void Graph<I, D>::setRoot(const Node<I, D> &root) {

}

template<class I, class D>
Node<I, D> Graph<I, D>::getNode(I id) {
    if (node_map_.find(id) == node_map_.end()) 
        return nullptr;
    return node_map_[id];
}

template<class I, class D>
unordered_map<I, I> Graph<I, D>::BFS(I input) {
    set<Node<I, D>> seen;
    unordered_map<I, I> ancestors;
    seen.insert(root_.getId());
    deque<I> dq;
    dq.push_front(input);
    while (!dq.empty()) {
        I curr_id = dq.pop_back();
        curr_node = node_map_[curr_id];
        for (Node<I, D> child : curr_node.getChildren()) {
            if (seen.find(child.getId()) != seen.end()) {
                seen.insert(child.getId());
                dq.push_front(child.getId);
                ancestors[child.getId()] = curr_id;
            }
        }
    }
    return ancestors;
}

template<class I, class D>
unordered_map<I, I> Graph<I, D>::DFS(I input) {
    set<Node<I, D>> seen;
    unordered_map<I, I> ancestors;
    seen.insert(root_.getId());
    vector<I> stack;
    stack.push_back(root_.getId());
    while (!stack.empty()) {
        I curr = stack.pop_back();        
        for (I child : curr_node.getChildren()) {
            if (seen.find(child) != seen.end()) {
                seen.insert(child);
                ancestors[child] = curr;
            }
        }
    }
}