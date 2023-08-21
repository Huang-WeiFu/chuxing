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
char getLinkListElePtr(struct LNode *node, int i, char e) {
    // 临时指针指向头结点
    struct LNode *p = node;
    // 计数器
    int count = 1;

    /**
     * 从第一个元素开始遍历，有两种情况发生
     * 第一种情况是j遍历到了i的位置  --> 该情况是找到了元素
     * 第二种情况是p指针遍历到了空   --> 该情况是索引下标超出了范围
     */
    while (p->next && count < i) {
        p = p->next;
        ++count;
    }

    // 第i个元素不存在
    if (!p->next || count > i) {
        return 0;
    }

    // 取第i个元素并返回
    e = p->ch;
    return e;
}

// 生成26字母表
void genAlphabetPtr(struct LNode *node) {}

int main() {
    printf("hello world");
}