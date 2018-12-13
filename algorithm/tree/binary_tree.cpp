#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node 
{
    char data;
    Node *left,*right;
};

class BiTree
{
public:
    Node *root;  //根节点
    BiTree();
    Node* create();
    void pre_order_rec(Node *node);   //前序遍历递归版
    void pre_order_non_rec();         //前序遍历非递归版
    void in_order_rec(Node *node);    //中序
    void in_order_non_rec();          //
    void post_order_rec(Node *node);  //后序
    void post_order_non_rec();        //
    void level_order();               //层次遍历
    int count_node(Node *node);       //求节点数
    int count_leaf(Node *node);       //求叶子数
};

int main()
{
    cout << "前序遍历递归与非递归\n";
    BiTree myTree;
    //1.  
    cout << "前序遍历递归与非递归\n";
    myTree.pre_order_rec(myTree.root); cout << endl;
    myTree.pre_order_non_rec(); cout << endl << endl;
    //2.  
    cout << "中序遍历递归与非递归\n";
    myTree.in_order_rec(myTree.root); cout << endl;
    myTree.in_order_non_rec(); cout << endl << endl;
    //3.  
    cout << "后序遍历递归与非递归\n";
    myTree.post_order_rec(myTree.root); cout << endl;
    myTree.post_order_non_rec(); cout << endl << endl;;

    //4.  
    cout << "层次遍历\n";
    myTree.level_order(); cout << endl << endl;;

    //5.  
    cout << "该二叉树的节点有";
    cout << myTree.count_node(myTree.root);
    cout << "个\n\n";

    //6.  
    cout << "该二叉树的叶子有";
    cout << myTree.count_leaf(myTree.root);
    cout << "个\n\n";

    return 0;
}

BiTree::BiTree()
{
    root = create();
}

Node * BiTree::create()
{
    Node *p = nullptr;
    char ch;
    cin >> ch;
    if (ch == '.')  //结束输入
        p = nullptr;
    else
    {
        p = new Node;
        p->data = ch;
        p->left = create();
        p->right = create();
    }
    return p;
}

void BiTree::pre_order_rec(Node * node)
{
    if (node == nullptr)
        return;
    else
    {
        cout << node->data << " ";   //先输出当前节点   
        pre_order_rec(node->left);   //然后输出左孩子
        pre_order_rec(node->right);  //最后输出右孩子
    }
}

void BiTree::pre_order_non_rec()
{
    stack<Node*> S;
    Node *p = root;
    while (p || !S.empty())
    {
        while (p)
        {                            
            cout << p->data << " ";  //先输出当前节点  
            S.push(p);
            p = p->left;  //然后输出左孩子
        }  //while结束意味着左孩子已经全部输出
        if (!S.empty())
        {
            p = S.top()->right;  //最后输出右孩子
            S.pop();
        }
    }
}

void BiTree::in_order_rec(Node * node)
{
    if (node == nullptr)
        return;
    else
    {
        in_order_rec(node->left);   //先输出左孩子
        cout << node->data << " ";  //然后输出当前节点
        in_order_rec(node->right);  //最后输出右孩子
    }
}

void BiTree::in_order_non_rec()
{
    stack<Node*> S;
    Node *p = root;
    while (p || !S.empty())
    {
        while (p)
        {
            S.push(p);   
            p = p->left;  
        }  //while结束意味着左孩子为空
        if (!S.empty())
        {
            cout << S.top()->data << " ";  //左孩子全部输出，接着输出当前节点
            p = S.top()->right;  //左孩子全部输出，当前节点也输出后，最后输出右孩子
            S.pop();
        }
    }
}

void BiTree::post_order_rec(Node * node)
{
    if (node == nullptr)
        return;
    else
    {
        post_order_rec(node->left);   //先输出左孩子
        post_order_rec(node->right);  //然后输出右孩子
        cout << node->data << " ";    //最后输出当前节点
    }
}

void BiTree::post_order_non_rec()
{
    if (root == nullptr)
        return;

    Node *pre = nullptr;
    Node *cur = root;
    stack<Node*> S;
    S.push(cur);
    while (!S.empty())
    {
        cur = S.top();
        //第一个输出的必是无左右孩子的叶子节点，由(!cur->left && !cur->right)
        //来判断，只要第一个节点输出，以后的pre就不会是空。此处的判断语句加入
        if ((!cur->left && !cur->right) ||                     
            (pre && (pre == cur->left || pre == cur->right)))  
        {                                                      //一个pre，只是用来确保输出正确的第一个节点。
            cout << cur->data << " ";  //左右孩子都全部输出，再输出当前节点
            pre = cur;
            S.pop();
        }
        else
        {
            if (cur->right)
                S.push(cur->right);  //先进右孩子，再进左孩子，取出来的才是左孩子
            if (cur->left)
                S.push(cur->left);
        }
    }
}

void BiTree::level_order()
{
    if (root == nullptr)
        return;

    Node *p = root;
    queue<Node*> Q;  //队列
    Q.push(p);
    while (!Q.empty())
    {
        p = Q.front();
        cout << p->data << " ";
        Q.pop();
        if (p->left)
            Q.push(p->left);  //注意顺序，先进左孩子
        if (p->right)
            Q.push(p->right);
    }
}

int BiTree::count_node(Node *node)
{
    if (node == nullptr)
        return 0;
    return count_node(node->left) + count_node(node->right) + 1;
}

int BiTree::count_leaf(Node *node)
{
    if (node == nullptr)
        return 0;
    if (!node->left && !node->right)
        return 1;
    return count_leaf(node->left) + count_leaf(node->right);
}
