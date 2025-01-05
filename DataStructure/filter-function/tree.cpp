#include "tree.h"
#include <queue>

Node::Node()
{
    // 初始化变量
    p = nullptr;
    children = new Node *[4];
    for (int i = 0; i < 4; i++)
    {
        children[i] = nullptr;
    }
    width = 0;
    height = 0;
    leaf = false;
    x = 0;
    y = 0;
    mean_r = 0;
    mean_g = 0;
    mean_b = 0;
    before_b = 0;
    before_g = 0;
    before_r = 0;
    cut_times = 0;
}

Node::Node(PNG *corner, int input_width, int input_height, int x, int y)
{
    p = corner;
    children = new Node *[4];
    for (int i = 0; i < 4; i++)
    {
        children[i] = nullptr;
    }
    width = input_width;
    height = input_height;
    leaf = false;
    this->x = x;
    this->y = y;
    mean_r = 0;
    mean_g = 0;
    mean_b = 0;
    before_b = 0;
    before_g = 0;
    before_r = 0;
    cut_times = 0;
}

Node::Node(Node &other)
{
    *p = *(other.p);
    width = other.width;
    height = other.height;
    leaf = other.leaf;
    x = other.x;
    y = other.y;
    mean_r = other.mean_r;
    mean_g = other.mean_g;
    mean_b = other.mean_b;
    before_r = other.before_r;
    before_g = other.before_g;
    before_b = other.before_b;
    cut_times = other.cut_times;
    for (int i = 0; i < 4; i++)
    {
        if (other.children[i] != nullptr)
        {
            children[i] = new Node(*(other.children[i]));
        }
        else
        {
            children[i] = nullptr;
        }
    }
}

Node::Node(Node &&other)
{
    p = other.p;
    other.p = nullptr;

    width = other.width;
    height = other.height;
    leaf = other.leaf;
    x = other.x;
    y = other.y;
    mean_r = other.mean_r;
    mean_g = other.mean_g;
    mean_b = other.mean_b;
    before_r = other.before_r;
    before_g = other.before_g;
    before_b = other.before_b;
    cut_times = other.cut_times;

    for (int i = 0; i < 4; i++)
    {
        children[i] = other.children[i];
        other.children[i] = nullptr;
    }
}

Node &Node::operator=(Node &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < 4; i++)
    {
        children[i] = other.children[i];
    }
    *p = *(other.p);
    width = other.width;
    height = other.height;
    x = other.x;
    y = other.y;
    leaf = other.leaf;
    mean_r = other.mean_r;
    mean_g = other.mean_g;
    mean_b = other.mean_b;
    before_r = other.before_r;
    before_g = other.before_g;
    before_b = other.before_b;
    cut_times = other.cut_times;
    return *this;
}

Node &Node::operator=(Node &&other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < 4; i++)
    {
        children[i] = other.children[i];
        other.children[i] = nullptr;
    }
    p = other.p;
    other.p = nullptr;

    width = other.width;
    height = other.height;
    x = other.x;
    y = other.y;
    leaf = other.leaf;
    mean_r = other.mean_r;
    mean_g = other.mean_g;
    mean_b = other.mean_b;
    before_r = other.before_r;
    before_g = other.before_g;
    before_b = other.before_b;
    cut_times = other.cut_times;
    return *this;
}

void Tree::judge(int threshold)
{
    // 进行四叉树剪枝
    if (root != NULL) {
        child_judge(root, threshold);
        reset(root);
        mean_RGB(root);
    }
}

// 递归剪枝
void Tree::child_judge(Node *node, int threshold)
{
    // 递归终止条件
    if (node->leaf) return;

    // 递归剪枝
    // 方差计算
    int count = 0, var = 0;
    for (int i = 0; i < 4; i++)
    {
        if (node->children[i] != nullptr)
        {
            child_judge(node->children[i], threshold);
            count++;
        }
    }

    // 获取当前节点最大剪枝次数
    node->cut_times = get_max_cut_times(node);
    if (node->cut_times > 2) return;

    // 剪枝
    // 计算方差
    for (int i = 0; i < 4; i++)
    {
        if (node->children[i] != nullptr)
        {
            var += pow(node->children[i]->mean_r - node->mean_r, 2);
            var += pow(node->children[i]->mean_g - node->mean_g, 2);
            var += pow(node->children[i]->mean_b - node->mean_b, 2);
        }
    }
    var /= (30 * count);
    if (var < threshold)
    {
        // 剪枝操作
        prune(node, node->mean_r, node->mean_g, node->mean_b);
    }
}

// 获取当前节点最大剪枝次数
int Tree::get_max_cut_times(Node *node)
{
    if (node->leaf) return node->cut_times;

    int max_cut_times = 0;
    for (int i = 0; i < 4; i++)
    {
        if (node->children[i] != nullptr)
        {
            max_cut_times = std::max(max_cut_times, get_max_cut_times(node->children[i]));
        }
    }

    return max_cut_times;
}

// 剪枝操作
void Tree::prune(Node *node, int r, int g, int b)
{
    if (node != NULL){
        node->mean_r = r;
        node->mean_g = g;
        node->mean_b = b;
        if (node->leaf) {
            node->cut_times++;
            node->get_pxl()->red = r;   // 修改叶子节点的颜色
            node->get_pxl()->green = g;
            node->get_pxl()->blue = b;
        }
        else {
            for (int i = 0; i < 4; i++)
            {
                if (node->children[i] != nullptr)
                {
                    prune(node->children[i], r, g, b);
                    node->cut_times = std::max(node->cut_times, node->children[i]->cut_times);
                }
            }
        }
    }   
}

// 重置树
void Tree::reset(Node *node)
{
    if (node != nullptr) {
        if (node->leaf) {
            node->cut_times = 0;
            node->mean_r = node->before_r;
            node->mean_g = node->before_g;
            node->mean_b = node->before_b;
        }
        else {
            for (int i = 0; i < 4; i++)
            {
                if (node->children[i] != nullptr)
                {
                    reset(node->children[i]);
                }
            }
        }
    }
}

void Tree::load_png(PNG *png)
{
    // 读取 PNG 对象并创建四叉树
    root->p = png;
    root->width = png->get_width();
    root->height = png->get_height();
    root->x = 0;
    root->y = 0;
    root->leaf = false;
    root->cut_times = 0;
    
    // 判断是否是单像素
    if (root->width == 1 && root->height == 1)
    {
        root->leaf = true;
        root->mean_r = png->get_pxl(0, 0)->red;
        root->mean_g = png->get_pxl(0, 0)->green;
        root->mean_b = png->get_pxl(0, 0)->blue;
        root->before_r = root->mean_r;
        root->before_g = root->mean_g;
        root->before_b = root->mean_b;
        return;
    }

    // 广度优先创建四叉树
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        // 如果是叶子节点
        if (current->leaf) {
            continue;
        }

        // 划分图片区块
        int width[4], height[4];    // 四个子区块的宽度和高度
        int x[4], y[4]; // 左上角坐标

        width[0] = width[2] = current->width / 2;
        height[0] = height[2] = current->height / 2;

        width[1] = width[3] = current->width - width[0];
        height[1] = height[3] = current->height - height[0];

        x[0] = x[2] = current->x;
        y[0] = y[1] = current->y;

        x[1] = x[3] = current->x + width[0];
        y[2] = y[3] = current->y + height[0];

        // 创建四个子区块
        for (int i = 0; i < 4; i++)
        {
            // 如果子区域无效  跳过
            if (width[i] == 0 || height[i] == 0)
            {
                current->children[i] = nullptr;
                continue;
            }

            // 创建子区块
            current->children[i] = new Node(current->p, width[i], height[i], x[i], y[i]);
            
            // 判断是否是叶子节点
            if (width[i] == 1 && height[i] == 1)
            {
                current->children[i]->leaf = true;
                current->children[i]->mean_r = current->p->get_pxl(x[i], y[i])->red;
                current->children[i]->mean_g = current->p->get_pxl(x[i], y[i])->green;
                current->children[i]->mean_b = current->p->get_pxl(x[i], y[i])->blue;
                current->children[i]->before_r = current->children[i]->mean_r;
                current->children[i]->before_g = current->children[i]->mean_g;
                current->children[i]->before_b = current->children[i]->mean_b;
            }
            else
            {
                current->children[i]->leaf = false;
                q.push(current->children[i]);
            }
        }
    }
    
    // 计算每个节点的平均值
    mean_RGB(root);
}

void Tree::mean_RGB(Node *node)
{
    if (node->leaf) return;

    int r = 0, g = 0, b = 0, count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (node->children[i] != nullptr)
        {
            mean_RGB(node->children[i]);
            r += node->children[i]->mean_r;
            g += node->children[i]->mean_g;
            b += node->children[i]->mean_b;
            count++;
        }
    }

    node->mean_r = r / count;
    node->mean_g = g / count;
    node->mean_b = b / count;
}



/*
 ================================================
 ====DO NOT MODIFY ANY OF THE FUNCTIONS BELOW====
 ==============请不要修改以下任何函数================
 ================================================
 */

Node::~Node()
{
    for (int i = 0; i < 4; i++)
    {
        if (children[i] != NULL)
        {
            delete children[i];
        }
    }
    delete[] children;
}

void Node::print()
{
    if (children[0] != NULL)
    {
        children[0]->print();
    }
    if (children[1] != NULL)
    {
        children[1]->print();
    }
    if (children[2] != NULL)
    {
        children[2]->print();
    }
    if (children[3] != NULL)
    {
        children[3]->print();
    }
    printf("Red: %u, Green: %u, Blue: %u, Width: %d, Height: %d\n", mean_r, mean_g, mean_b, width, height);
    // printf("Red: %u, Green: %u, Blue: %u, Width: %d, Height: %d,", p->red, p->green, p->blue, width, height);
    std::cout << "Leaf: " << leaf << std::endl;
    return;
}

pxl *Node::get_pxl()
{
    return p->get_pxl(x, y);
}

Tree::Tree()
{
    root = new Node();
}

Tree::~Tree()
{
    delete root;
}

Tree::Tree(Tree &other)
{
    if (other.root != NULL)
    {
        root = new Node(*other.root);
    }
}

Tree &Tree::operator=(Tree &other)
{
    if (other.root != NULL && &other != this)
    {
        root = new Node(*(other.root));
    }
    return *this;
}

pxl *Tree::get_pxl()
{
    return root->get_pxl();
}

void Tree::print()
{
    root->print();
}
