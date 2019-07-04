#include <iostream>
#define SIZE 1000
#define PRINT_TREE(tree) for (int i = 1; i <= tot; ++ i) {PRINT_NODE(tree[i]);}
#define PRINT_NODE(node) cout << node.l << " " << node.r << " " << node.val << endl;

using namespace std;

struct BST {
    int l, r;
    int val;
} a[SIZE];
int tot, root, INF = 1<<30;

int New(int val) {
    a[++tot].val = val;
    return tot;
}

void Build() {
    New(-INF), New(INF);
    root = 1, a[1].r = 2;
}

int Get(int p, int val) {
    if (p == 0) return 0;
    if (val == a[p].val) return p;
    return val < a[p].val ? Get(a[p].l, val) : Get(a[p].r, val);
}

void Insert(int &p, int val) {
    if (p == 0) {
        p = New(val);
        return;
    }
    if (val == a[p].val) return;
    if (val < a[p].val) Insert(a[p].l, val);
    else Insert(a[p].r, val);
}

int GetNext(int val) {
    int ans = 2;
    int p = root;
    while (p) {
        if (val == a[p].val) {
            if (a[p].r > 0) {
                p = a[p].r;
                while (a[p].l > 0) p = a[p].l;
                ans = p;
            }
            break;
        }
        if (a[p].val > val && a[p].val < a[ans].val) ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return ans;
}

void Remove(int &p, int val) { // 从子树 p 中删除值为 val 的节点
if (p == 0) return;
if (val == a[p].val) { // 已经检索到值为 val 的节点
if (a[p].l == 0) { // 没有左子树
p = a[p].r; // 右子树代替 p 的位置，注意 p 是引用
}
else if (a[p].r == 0) { // 没有右子树
p = a[p].l; // 左子树代替 p 的位置，注意 p 是引用
}
else { // 既有左子树又有右子树
// 求后继节点
int next = a[p].r;
while (a[next].l > 0) next = a[next].l;
// next 一定没有左子树，直接删除
Remove(a[p].r, a[next].val);
// 令节点 next 代替节点 p 的位置
a[next].l = a[p].l, a[next].r = a[p].r;
p = next; // 注意 p 是引用
}
return;
}
if (val < a[p].val) {
Remove(a[p].l, val);
} else {
Remove(a[p].r, val);
}
}

int main() {
    Build();
    Insert(root, 100);
    Insert(root, 10);
    Insert(root, -100);
    Insert(root, -10);
    // int test = 2;
    // Insert(test, 1000);
    Remove(root, 10);
    PRINT_TREE(a);
    cout << root;
}