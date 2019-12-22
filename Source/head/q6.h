#include"../../Lab/tree.h"

void build(Tree<string>& tree, string ancestor){
    tree.build(ancestor);
}

bool search(Tree<string>& tree, string target){
    TreeNode<string> *search_result =  tree.find(target);
    if(!search_result){
         cout << "Error: Incorrect entering member name" << endl;
         cout << endl;
         return false;
    }else {
        Vector<TreeNode<string>* > &sons = search_result->get_sons();
        cout << "Member " << target << " has " << sons.get_len() << " child(ren):" << endl;
        for(int32_t i = 0 ;i < sons.get_len(); i++){
            TreeNode<string>* son = sons[i];
            cout << son->get_value() << " ";
        }
        if(!sons.get_len()) cout << "empty" << endl;
        else cout << endl;
        cout << endl;
        return true;
    }
}

void insert(Tree<string>&tree, string target, string new_name){
    TreeNode<string> *search_result =  tree.find(target);
    if(!search_result){
         cout << "Error: Incorrect entering member name" << endl;
         cout << endl;
         return;
    }else {
        tree.Add(target, new_name);
        cout << "Added successfully!" << endl;
        cout << endl;
    }
}

void add(Tree<string> &tree, string target, Vector<string>& sons){
    TreeNode<string> *search_result =  tree.find(target);
    if(!search_result){
         cout << "Error: Incorrect entering member name" << endl;
         cout << endl;
         return;
    }else {
        if(search_result->get_sons().get_len() > 0) {
            cout << "Selected members already have a family!" << endl;
            cout << endl;
            return;
        }
        for(int32_t i = 0; i < sons.get_size(); i++){
            tree.Add(search_result, sons[i]);
        }
        cout << "Establish successfully!" << endl;
        cout << endl;
    }
}

bool modify(Tree<string>&tree, string target, string new_name){
    TreeNode<string> *search_result =  tree.find(target);
    if(!search_result){
         cout << "Error: Incorrect entering member name" << endl;
         cout << endl;
         return false;
    }else {
        if(tree.Change(target, new_name)){
            cout << "Modify successfully!" << endl;
            cout << endl;
            return true;
        }
        cout << endl;
        return false;
    }
}

void fdelete(Tree<string>&tree, string target){
    TreeNode<string> *search_result =  tree.find(target);
    if(!search_result){
         cout << "Error: Incorrect entering member name" << endl;
         cout << endl;
         return;
    }else {
        tree.Delete(search_result);
        cout << "Dissolve successfully!" << endl;
        cout << endl;
    }
}



