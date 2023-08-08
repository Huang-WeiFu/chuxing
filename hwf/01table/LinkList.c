//
// Created by hwf on 2023/8/8.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 生成一个保存26个字母的链表
 */
struct LNode {
    char ch;
    struct LNode *next;
};

// 初始化一个链表
struct LNode build(struct LNode *head) {
//    head = (LNode *) malloc(sizeof(struct LNode)); //c++
//    C++语法与C的区别
    head = malloc(sizeof(struct LNode));//c
    head->next = head;
    head->ch = '0';
    return *head;
}

// 新增元素于指定位置
void insertLinkListElePtr(struct LNode *node, int i, char e) {}

// 删除元素于指定位置
char delLinkListElePtr(struct LNode *node, int i) {}

// 修改元素于指定位置
char editLinkListElePtr(struct LNode *node, int i, char e) {}

// 查询元素于指定位置
char getLinkListElePtr(struct LNode *node, int i, char e) {}

// 生成26字母表
void genAlphabetPtr(struct LNode *node) {}

int main() {
    printf("hello world");
}