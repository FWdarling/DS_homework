#ifndef TREE_H
#define TREE_H
#include "vector.h"

using std::string;

template <typename T>
class TreeNode
{
private:
    T value;
    Vector<TreeNode<T> *> sons;
    TreeNode<T> *fa;

public:
    TreeNode()
    {
        register T tem;
        value = tem;
        fa = nullptr;
    }

    TreeNode(T v, TreeNode<T> *f = nullptr) : value(v), fa(f){};

    ~TreeNode() { fa = nullptr; }

    T &get_value() { return value; }

    const T &get_value() const { return value; }

    void set_value(T val) { value = val; }

    TreeNode<T> *get_fa() const { return fa; }

    void set_fa(TreeNode<T> *f) { fa = f; }

    const Vector<TreeNode<T> *> &get_sons() const { return sons; }

    Vector<TreeNode<T> *> &get_sons() { return sons; }

    bool operator == (const TreeNode<T> &a) const
    {
        return value == a.get_value();
    }
};

template <typename T>
class Tree
{
private:
    TreeNode<T> *root;

public:
    Tree()
    {
        root = nullptr;
    }

    ~Tree()
    {
        delete root;
    }

    void build(T val);

    TreeNode<T> *find(TreeNode<T> *f, T val);

    TreeNode<T> *find(T val);

    void Add(TreeNode<T> *fa, T val);

    void Add(T tar, T val);

    void Delete(TreeNode<T> *tar);

    bool Change(T val, T new_val);

    void clear();
};

template <typename T>
void Tree<T>::build(T val)
{
    root = new TreeNode<T>(val);
}

template <typename T>
TreeNode<T> *Tree<T>::find(TreeNode<T> *fa, T val)
{
    if (fa->get_value() == val)
        return fa;
    else
    {
        Vector<TreeNode<T> *> &v = fa->get_sons();
        for (int32_t i = 0; i < v.get_len(); i++)
        {
            TreeNode<T> *find_res = find(v[i], val);
            if (find_res)
                return find_res;
        }
        return nullptr;
    }
}

template <typename T>
TreeNode<T> *Tree<T>::find(T val)
{
    return find(root, val);
}

template <typename T>
void Tree<T>::Add(TreeNode<T> *fa, T val)
{
    TreeNode<T> *son = new TreeNode<T>(val, fa);
    fa->get_sons().push_back(son);
}

template <typename T>
void Tree<T>::Add(T tar, T val)
{
    TreeNode<T> *fa = find(tar);
    Add(fa, val);
}
/*
template <typename T>
bool Tree<T>::Delete(T val)
{
    TreeNode<T> *find_res = find(val);
    if (!find_res)
    {
        std::cout << "No result found!" << std::endl;
        return false;
    }
    Delete(find_res);
    return true;
}
*/
template <typename T>
void Tree<T>::Delete(TreeNode<T> *tar)
{
    Vector<TreeNode<T> *> &tem = this->root->get_sons();
    if (!tar)
        return;
    TreeNode<T> *fa = tar->get_fa();
    Vector<TreeNode<T> *> &v = tar->get_sons();
    for (int32_t i = 0; i < v.get_len(); i++)
    {
        Delete(v[i]);
    }
    if (fa)
    {
        Vector<TreeNode<T> *> &brothers = fa->get_sons();
        brothers.Delete(brothers.find(tar));
    }
    delete tar;
}

template <typename T>
bool Tree<T>::Change(T val, T new_val)
{
    TreeNode<T> *find_res = find(val);
    if (!find_res)
        return false;
    find_res->set_value(new_val);
    return true;
}

template <typename T>
void Tree<T>::clear()
{
    Delete(root);
}

#endif
