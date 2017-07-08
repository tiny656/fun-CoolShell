#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string strInOrd = "TbHVh3ogPWFLuAfGrm1xJ7we0iQYnZ8Kvqk9y5CNBD24UlcpIEMaj6SROXsdzt";
string strPostOrd = "TVHo3hPgbFfAumr7Jxew1YQi0ZnGLKy9kqvNDBC54clU28EIRS6jdsXOaMpWtz";

class Node {
public:
    Node():left(NULL), right(NULL) { }
    Node *left, *right;
    char ch;
};

//通过后序Post和中序In构造前序Pre输出
Node* RecoverFromPostInord(int postLeft, int postRight, int inLeft, int inRight) {
    //调用默认遍历序列是合法的
    assert(postLeft <= postRight && inLeft <= inRight);
    int rootPos;//记录当前根的位置
    //在中序遍历中寻找根的位置
    for (rootPos = inLeft; rootPos <= inRight; ++rootPos) {
        if (strInOrd[rootPos] == strPostOrd[postRight]) {
            break;
        }
    }
    int leftSize = rootPos - inLeft;
    int rightSize = inRight - rootPos;
    Node *root = new Node, *left = NULL, *right = NULL;
    root->ch = strInOrd[rootPos];
    if (leftSize > 0) left = RecoverFromPostInord(postLeft, postLeft + leftSize - 1, inLeft, rootPos - 1);//递归构造左子树
    if (rightSize > 0) right = RecoverFromPostInord(postLeft + leftSize, postRight - 1, rootPos + 1, inRight);//递归构造右子树
    root -> left = left;
    root -> right = right;
    return root;
}


void printPath(Node* node, int len, string path) {
    path += node->ch;
    len += 1;
    if (!(node->left || node->right)) {
        cout << len << " " << path << endl;
        return;
    }
    if (node->left) printPath(node->left, len, path);
    if (node->right) printPath(node->right, len, path);
}

int main() {

    Node* root = RecoverFromPostInord(0, strPostOrd.size() - 1, 0, strInOrd.size() - 1);
    string path = "";
    printPath(root, 0, path);
    // the deepest path
    // 13 zWp8LGn01wxJ7
    return 0;
}