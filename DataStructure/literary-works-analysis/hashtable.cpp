#include "hashtable.h"

bool Node::operator!=(const char *str)
{
    if (str == NULL)
        return false;
    string s(str);
    return s != p.first;
}

bool Node::operator!=(const string &str)
{
    return str == p.first;
}

bool Node::operator==(const char *str)
{
    if (str == NULL)
        return false;
    string s(str);
    return s == p.first;
}

bool Node::operator==(const string &str)
{
    return str == p.first;
}

bool Node::operator!=(Node &n)
{
    return p.first == n.p.first;
}

bool Node::operator==(Node &n)
{
    return p.first == n.p.first;
}

char Node::operator[](const int index)
{
    // 返回对应下标的字符
    return p.first[index];
}

int Node::length()
{ // return length of the string
    return p.first.length();
}

int &Node::second()
{
    return p.second;
}

const pair<string, int> *Node::get_pair() const
{
    const pair<string, int>* ptmp = &p;
    return ptmp;
}

Node::~Node()
{
    // 删除 Node 的所有内存
}

HashTable::HashTable()
{
    // 初始化 HashTable
    size = 10000;
    elem = new Node[size];
    Node op;
    for (int i = 0; i < size; i++)
    {
        elem[i] = op;
    }

}

HashTable::~HashTable()
{
    // 删除 HashTable 的所有内存
    if (elem != NULL)
    {
        delete[] elem;
    }
    size = 0;
}

int HashTable::hash(Node &index)
{
    // 将一个 node 转换为一个整数
    int length = index.length();
    int ans = 0;
    int op_times = (length <= 5 ? length : length / 2);
    for (int i = 0; i < length; i++)
        ans += (1 << (tolower(index.get_pair()->first[i]) - 'a') % 10000);
    return ans % 10000;
}

bool HashTable::search(Node &index, int &pos, int &times)
{
    // pos 记录查找的位置，times 记录发送冲突的次数
    // 查找一个 node
    pos = hash(index);
    times = 0;

    while (elem[pos] != index && elem[pos].get_pair()->first == "#")
    {
        pos = (pos + 1) % size;  // 使用循环处理，避免越界
        times++;
        if (times >= size) {     // 如果循环了整个哈希表，说明表已满或未找到
            pos = -1;
            return false;
        }
    }

    return elem[pos] == index;
}

int HashTable::insert(Node &index)
{
    // 插入一个 node
    int pos, times;
    // 目标存在表中  更新词频
    if (search(index, pos, times))
    {
        elem[pos].second()++;
        return 2;
    } 
    
    if (pos >= 0) {
        elem[pos] = index;
        return 1;  // 插入成功
    }

    return 0;  // 插入失败
}

int HashTable::insert(const char *str)
{
    Node n(str);
    return insert(n);  // 重用 insert(Node&) 的逻辑
}

/*
 ==========================================================================
 =================Please Do Not Modify Functions Below=====================
 ========================请不要修改下列函数实现================================
 ==========================================================================
 */

Node::Node()
{
    p = make_pair(string("#"), 1);
}

Node::Node(const char *str)
{
    p = make_pair(string(str), 1);
}

Node::Node(const string &str)
{
    p = make_pair(str, 1);
}

int HashTable::get_size() const
{
    return size;
}

const pair<string, int> *HashTable::get_pair(int index)
{
    if (index < size && index >= 0)
    {
        return (elem[index].get_pair());
    }
    return NULL;
}

const pair<string, int> *HashTable::get_pair(int index) const
{
    if (index < size && index >= 0)
    {
        return (elem[index].get_pair());
    }
    return NULL;
}
