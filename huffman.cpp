#include "huffman.h"

TreeNode& HuffmanArchiver::get_min() {
    TreeNode leaf;
    if(symbols_.empty()) {
        leaf=leafs_.front();
        leafs_.pop_front();
        return leaf;
    }
    if(leafs_.empty()) {
        leaf=d.front();
        symbols_.pop_front();
        return leaf;
    }
    if(leafs.front() < symbols_.front()){
        leaf=leafs_.front();
        leafs_.pop_front();
        return leaf;
    }else{
        leaf=b.front();
        symbols_.pop_front();
        return leaf;
    }
}

void HuffmanArchiver::archivate(string &filename) {
    get_symbols(filename);
    while(!b.empty()||d.size()>1){
        TreeNode* t;
        bor* p=new bor;
        bor* top=new bor;
        *t=getmin();
        *p=getmin();
        top->freq=t->freq+p->freq;
        top->c="$";
        top->left=t;
        top->right=p;
        d.push_back(*top);
    }
    return &d.front();
}
void HuffTree::get_codes(TreeNode* leaf,string prefix) {
    if(m.find(leaf->c)!=m.end()){
        codes_[leaf->symbol_]=prefix;
        return;
    }
    get_codes(leaf->left_, prefix + '0');
    get_codes(leaf->right_, prefix + '1');
}