#include "worker.h"
#include <string>
#include <iostream>

using namespace std;

/*TODO ʵ��һ�����캯����
 Worker �������Ѿ��������ڶ�(Heap)��*/
Worker::Worker(std::string& input_name) {
    this->id = num_worder;
    num_worker++;
    this->name = input_name;
}

/*TODO ʵ��һ�� get ������
 ���ظ� worker �� id*/
int Worker::get_id() {
    return this->id;
}

/*TODO ʵ��һ�� get ������
 ���ظ� worker �� Name*/
std::string& Worker::get_name() {
    return this->name;
}


/*Ԥ�����������ݲ����޸ġ�*/
int Worker::num_worker = 0;                  //���棺�㲻���ԸĶ���һ�У�

Worker::Worker() {                            //���棺�㲻���ԸĶ����������
    this->id = num_worker;
    num_worker++;
    this->name = std::string("default_string");

}

Worker::~Worker() {                           //���棺�㲻���ԸĶ����������
}

int Worker::print() {
    std::cout << "Worker [" << this->id << "] with name [" << (this->name) << "]\n";
    return 0;
}
