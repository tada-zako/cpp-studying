#include "dict.h"

int Dict::insert(const char *str) {
    // 将单词插入字典 并更新 size
    Node n(str);
    if (h.insert(n)) {
        size++;
        return 0;
    }

    return 1;
}

/*
 ==========================================================================
 =================Please Do Not Modify Functions Below=====================
 ========================请不要修改下列函数实现================================
 ==========================================================================
 */

Dict::Dict() {
    size = 0;
}

void Dict::print() const {
    for (int i = 0; i < h.get_size(); i++) {
        if (h.get_pair(i)->first.compare("#")) {
            std::cout << "[" << h.get_pair(i)->first << "]:[" << h.get_pair(i)->second << "]\n";
        }
    }
    std::cout << "\nTotal: " << size << " words.\n";
}
