/*
 @file /include/vector.h
 */
#ifndef vector_H
#define vector_H
#include "worker.h"

class vector {
    //This is a class of vector. As you can see it is actually a vector of workers.
    /*���� vector �࣬��Ҳ���Ѿ������ˣ�����ʵ��һ�� Worker �����Ա�*/
private:
    int size;  // vector ������
    int length;  // vector �е�Ԫ�ظ���
    Worker** data;
    /*
     ��ʾ������� data ��һ��ָ��ָ���ָ�롣
     �ڲ���ָ��ǰ����˼��
     */
public:
    vector(int input_size);
    ~vector();                          //TODO
    int insert(Worker* new_worker);   //TODO
    Worker* remove(int index);        //TODO
    void expand();
    Worker* get(int index);           //TODO
    void print();
};

#endif
