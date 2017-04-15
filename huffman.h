#include <iostream>
#include <string>
#include <deque>
#include <map>

class HuffTree{
private:
    TreeNode root_;
    map<char,string> code
    s_;
public:
    void add_node();
    void get_codes(string prefix);
};

class TreeNode{
private:
    TreeNode* left_,right_;
    int freq_;
    char symbol_;
public:
    bool operator<(const TreeNode& a,const TreeNode& b);
    TreeNode(TreeNode& left,TreeNode& right,int freq,char symbol):left_(&left),right_(right),freq_(freq),symbol_(symbol){}
};


class HuffmanArchiver{
public:
    void get_symbols(string& filename);
    void archivate(string& filename);
    void dearchivate(string& filename);
private:
    deque<TreeNode> leafs_;
    deque<TreeNode> symbols_;
    TreeNode get_min();
};