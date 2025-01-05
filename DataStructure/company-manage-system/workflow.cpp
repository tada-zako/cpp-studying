#include "workflow.h"
#include "worker.h"
#include "vector.h"
#include <iostream>
#include <utility>

Job::~Job() {
    delete worker;
    worker = NULL;
}

Workflow::Workflow() {
    head = NULL;
    tail = NULL;
    size = 0;
}

Workflow::~Workflow() {
    Job* current = head;
    while (current != NULL){
        Job* next = current->next;
        delete current;
        current = next;
    }
}

int Workflow::insert(Job* j) {
    if (j == NULL) {
        return 1;
    }

    j->prev = NULL;
    j->next = NULL;

    if (head == NULL) {
        head = j;
        tail = j;
    }
    else {
        tail->next = j;
        j->prev = tail;
        tail = j;
    }
    size++;
    return 0;
}

int Workflow::swap(int original_index, int target_index) {
    if (original_index < 0 || original_index >= size || target_index < 0 || target_index >= size) {
        return 1; // ���ش���
    }

    if (original_index == target_index) {
        return 0;
    }
        
    Job* original = head;
    Job* target = head;

    // ������Ҫ������ Job
    for (int i = 0; i < original_index; i++) {
        original = original->next;
    }
    for (int i = 0; i < target_index; i++) {
        target = target->next;
    }

    // ��������ڵ������ڵ�
    if (original->next == target) {
        if (original->prev) original->prev->next = target;
        if (target->next) target->next->prev = original;

        target->prev = original->prev;
        original->next = target->next;
        target->next = original;
        original->prev = target;
    }
    else if (target->next == original) {
        if (target->prev) target->prev->next = original;
        if (original->next) original->next->prev = target;

        original->prev = target->prev;
        target->next = original->next;
        original->next = target;
        target->prev = original;
    }
    else {
        // ��������ڵ㲻�����ڵ�
        if (original->prev) original->prev->next = target;
        if (original->next) original->next->prev = target;

        if (target->prev) target->prev->next = original;
        if (target->next) target->next->prev = original;

        std::swap(original->prev, target->prev);
        std::swap(original->next, target->next);
    }

    // ����ͷβָ��
    if (original == head) head = target;
    else if (target == head) head = original;

    if (original == tail) tail = target;
    else if (target == tail) tail = original;


    return 0;
}

Job* Workflow::pop() {
    if (head == NULL) {
        return NULL;
    }

    Job* popped_job = head;
    head = head->next;

    if (head) {
        head->prev = NULL;
    }
    else {
        tail = NULL;
    }
    size--;
    return popped_job;
}

int Workflow::process(vector* l, int index) {
    if (l == nullptr || index < 0 || index >= size) {
        return 1;
    }

    // ��ȡ�����б��еĹ���
    Worker* selected_worker = l->get(0);

    if (selected_worker == NULL) {
        return 1;
    }

    // �Ƴ�ѡ�еĹ���
    l->remove(0);

    // ��ȡ��Ӧ�Ĺ���
    Job* current_job = head;
    for (int i = 0; i < index; i++) {
        current_job = current_job->next;
    }

    // ����Ƿ��й����ڹ���
    if (current_job->worker != NULL) {
        delete current_job->worker;
    }

    current_job->worker = selected_worker;

    return 0;
}

/*Ԥ�����������ݲ����޸ġ�*/
int Job::num_job = 0;   //Do not remove or modify this line.
//���棺�㲻���ԸĶ���һ�У�
Job::Job() {               //���棺�㲻���ԸĶ����������
    id = num_job;
    num_job++;
    next = NULL;
    prev = NULL;
    worker = NULL;
}
int Workflow::print() {     //���棺�㲻���ԸĶ����������
    Job* curr = head;
    int i = 0;
    if (curr == NULL) {
        std::cout << "Empty Flow\n";
        return 0;
    }
    while (curr != NULL) {
        std::cout << "[" << i << "]";
        curr->print();
        i++;
        curr = curr->next;
    }
    return 0;
}
int Job::print() {
    std::cout << "job [" << this->id << "]\n";
    return 0;
}
