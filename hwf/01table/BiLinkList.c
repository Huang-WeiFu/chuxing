//
// Created by hwf on 2023/8/8.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 生成一个保存26个字母的双向链表
 */
struct BiLNode {
    char ch;
    struct BiLNode *prior;
    struct BiLNode *next;
};

struct BiLNode build(struct BiLNode *biLNode) {
    biLNode = malloc(sizeof(struct BiLNode));
    biLNode->ch = '0';
    biLNode->prior = biLNode;
    biLNode->next = biLNode;
    return *biLNode;
}


// 新增元素于指定位置
void insertLinkListElePtr(struct BiLNode *node, int i, char e) {}

// 删除元素于指定位置
char delLinkListElePtr(struct BiLNode *node, int i) {}

// 修改元素于指定位置
char editLinkListElePtr(struct BiLNode *node, int i, char e) {}

// 查询元素于指定位置
char getLinkListElePtr(struct BiLNode *node, int i, char e) {}

// 生成26字母表
void genAlphabetPtr(struct BiLNode *node) {}

int main() {
    printf("hello world");
}