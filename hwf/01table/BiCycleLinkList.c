//
// Created by hwf on 2023/8/8.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 生成一个保存26个字母的双向循环链表
 */
struct BiCLNode {
    char ch;
    struct BiCLNode *prior;
    struct BiCLNode *next;
};

struct BiCLNode build(struct BiCLNode *head) {
    head = malloc(sizeof(struct BiCLNode));
    head->ch = '0';
    head->prior = head;
    head->next = head;
    return *head;
}

// 新增元素于指定位置
void insertLinkListElePtr(struct BiCLNode *node, int i, char e) {}

// 删除元素于指定位置
char delLinkListElePtr(struct BiCLNode *node, int i) {}

// 修改元素于指定位置
char editLinkListElePtr(struct BiCLNode *node, int i, char e) {}

// 查询元素于指定位置
char getLinkListElePtr(struct BiCLNode *node, int i, char e) {}

// 生成26字母表
void genAlphabetPtr(struct BiCLNode *node) {}

int main() {
    printf("hello world");
}