#include "heap.h"
#define LEFT true
#define RIGHT false

#define LIST_SIZE 2000

Heap::~Heap()
{
    // 小根堆析构
    delete[] arr;
}

Heap::Heap(Heap &other)
{
    // 实现深拷贝
    num = other.num;
    arr = new Player_info[LIST_SIZE];
    for (int i = 0; i < num; i++)
    {
        arr[i] = other.arr[i];
    }
}

Heap &Heap::operator=(Heap &other)
{
    num = other.num;
    delete[] arr;
    arr = new Player_info[LIST_SIZE];
    for (int i = 0; i < num; i++)
    {
        arr[i] = other.arr[i];
    }
    return *this;
}

void Heap::heapify_up()
{
    // 向上堆化
    int index = num - 1;
    while (index > 0)
    {
        int father = get_father(index);
        if (arr[index] < arr[father])
        {
            // 交换
            Player_info temp = arr[index];
            arr[index] = arr[father];
            arr[father] = temp;
            index = father;
        }
        else
        {
            break;
        }
    }
}

void Heap::heapify_down()
{
    // 向下堆化
    int index = 0;
    while (index < num)
    {
        int left = get_child(LEFT, index);
        int right = get_child(RIGHT, index);
        if (left >= num)
        {
            break;
        }

        // 找到左右孩子中较小的那个
        int min_index = left;
        if (right < num && arr[right] < arr[left])
        {
            min_index = right;
        }

        // 如果较小的孩子比当前节点小，则交换
        if (arr[min_index] < arr[index])
        {
            Player_info temp = arr[index];
            arr[index] = arr[min_index];
            arr[min_index] = temp;
            index = min_index;
        }
        else
        {
            break;
        }
    }
}

int Heap::get_child(bool direction, int index)
{
    // 获取左右孩子对应的下标
    if (direction == LEFT)
    {
        if (2 * index + 1 < num)
        {
            return 2 * index + 1;
        }
    }
    else
    {
        if (index * 2 + 2 < num)
        {
            return index * 2 + 2;
        }
    }
    return num;
}

int Heap::get_father(int index)
{
    // 获取父节点对应的下标
    return (index - 1) / 2;
}

int Heap::insert(Player_info &p)
{
    // 插入元素  顶插入方式  替换堆顶元素  然后向下堆化
    if (num == 0)
    {
        arr[0] = p;
        num++;
        return 0;
    }

    if (num < LIST_SIZE)
    {
        arr[num] = p;
        num++;
        heapify_up();
        return 0;
    }

    if (p > arr[0])
    {
        arr[0] = p;
        heapify_down();
        return 0;
    }

    return -1;
}

Player_info *Heap::sort()
{
    // 返回降序排序的数组
    if (num == 0)
    {
        return nullptr;
    }

    // 将小根堆降序排序
    while (true)
    {
        if (num == 1)
        {
            break;
        }
        Player_info temp = arr[0];
        arr[0] = arr[num - 1];
        arr[num - 1] = temp;
        num--;
        heapify_down();
    }

    Player_info *sorted = new Player_info[LIST_SIZE];
    for (int i = 0; i < num; i++)
    {
        sorted[i] = arr[i];
    }

    return sorted;
}

/*
 =========================================================
 ================ WARNING ===== 警告 ======================
 ===Please Do Not Modify Any of the Following Functions===
 ===================请不要修改以下函数=======================
 =========================================================
 */

int Heap::get_num() const
{
    return num;
}

Heap::Heap()
{
    num = 0;
    arr = new Player_info[LIST_SIZE];
}

void Heap::print()
{
    for (int i = 0; i < num; i++)
    {
        arr[i].print();
    }
    printf("\nSize of the heap is %d\n", num);
}

Player_info::Player_info()
{
    username = std::string("#");
    uid = 0;
    score = 0;
}

Player_info::~Player_info()
{
}

Player_info::Player_info(Player_info &other)
{
    username = std::string((other.username));
    score = other.score;
    uid = other.uid;
}

Player_info::Player_info(std::string in_name, long in_uid, int in_score)
{
    username = std::string(in_name);
    score = in_score;
    uid = in_uid;
}

Player_info &Player_info::operator=(Player_info &other)
{
    username = std::string((other.username));
    score = other.score;
    uid = other.uid;
    return *this;
}

int Player_info::get_score() const
{
    return score;
}

const std::string &Player_info::get_name() const
{
    return username;
}

bool Player_info::operator==(Player_info &other) const
{
    if (score == other.score)
    {
        return true;
    }
    return false;
}

bool Player_info::operator!=(Player_info &other) const
{
    if (score == other.score)
    {
        return false;
    }
    return true;
}

bool Player_info::operator<(Player_info &other) const
{
    if (score < other.score)
    {
        return true;
    }
    return false;
}

bool Player_info::operator<=(Player_info &other) const
{
    if (score <= other.score)
    {
        return true;
    }
    return false;
}

bool Player_info::operator>(Player_info &other) const
{
    if (score > other.score)
    {
        return true;
    }
    return false;
}

bool Player_info::operator>=(Player_info &other) const
{
    if (score >= other.score)
    {
        return true;
    }
    return false;
}

void Player_info::print()
{
    printf("[%ld]%s - %d\n", uid, username.c_str(), score);
    return;
}
