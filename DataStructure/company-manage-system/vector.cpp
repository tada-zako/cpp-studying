#include "vector.h"
#include "worker.h"
#include <string>
#include <iostream>
#include <cstdlib>
/*��ʾ������� data ��һ��ָ��ָ���ָ�롣
 �ڲ���ָ��ǰ����˼��
 ����㲻֪���Ļ���malloc �Ĺ��ܺ� new ���ƣ�
 ����ʹ�� malloc ��Ϊ�˷���ռ䲻��ʱ������չ��
 ���õ��ģ���չ������Ϊ��д�á�
 ����ǰһλʵϰ��
 */
 /*
  TODO ʵ�� insert �������������ڲ����µ� worker��
  ����������˵��� expand()������ 1
  �������ִ�в��룬���� 0
  */
int vector::insert(Worker* new_worker) {
    if (length >= size) {
        expand();   // ����
        data[length] = new_worker;
        length++;
        return 1;
    }

    data[length] = new_worker;
    length++;
    return 0;
}

//TODO get �����Ĺ��ܲ�����������������д���Ƿ����룬���Ǿ����������ڴ����
Worker* vector::get(int index) {
    if (index < 0 || index >= length) {
        return nullptr; // ���ؿ�ָ��
    }
    return data[index];
}

//TODO
Worker* vector::remove(int index) {
    if (index < 0 || index >= length) {
        return nullptr; // ���ؿ�ָ��
    }
    Worker* removed_worder = data[index];   // ���Ƴ���Ա��
    for (int i = index; i < length - 1; i++) {
        data[i] = data[i + 1];  // ǰ��Ԫ��
    }
    length--;
    return removed_worder;
}

/*�������ݲ������޸ġ�*/

vector::~vector() {
    for (int i = 0; i < length; i++) {
        delete* (data + i);
    }
    free(data);
}

vector::vector(int input_size) {
    size = input_size;
    length = 0;
    data = (Worker**)calloc(sizeof(Worker*), input_size);
}

void vector::expand() {
    size = size * 2;
    data = (Worker**)realloc(data, sizeof(Worker*) * size);
    return;
}

void vector::print() {
    std::cout << "Current vector:\n";
    for (int i = 0; i < length; i++) {
        std::cout << "[" << i << "] ";
        (*(data + i))->print();
    }
    std::cout << "Current vector Ends\n";
}
