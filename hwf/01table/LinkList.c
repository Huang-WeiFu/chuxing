//
// Created by hwf on 2023/8/8.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 26

/**
 * 生成一个保存26个字母的链表
 */
struct LNode {
    char ch;
    struct LNode *next;
};

// 初始化一个链表的头结点
struct LNode build() {
    //    head = (LNode *) malloc(sizeof(struct LNode)); //c++
    //    C++语法与C的区别
    struct LNode *head = malloc(sizeof(struct LNode));//c
    if (head == NULL) {
        exit(-1);
    }
    head->next = NULL;
    head->ch = '0';
    return *head;
}

// 新增元素于指定位置
void insertLinkListElePtr(struct LNode *node, int i, char e) {
    // 临时指针指向头结点
    struct LNode *p = node;
    int count = 1;
    /**
     * 临时节点不为空并且计数器的数值小于要插入位置的数值
     * 循环继续跳到下一节点
     */
    while (p && count < i) {
        p = p->next;
        ++count;
    }
    /**
     * i的位置小于1或者是i大于表长了
     */
    if (!p || count > i) {
        exit(-1);
    }
    /**
     * 符合新增节点的条件
     * 从内存中分配一个节点的空间
     * 将值赋予该节点，该节点指向原节点的下一节点
     * 原节点再指向该节点，形成通路
     */
    struct LNode *newNode = malloc(sizeof(struct LNode));
    newNode->ch = e;
    newNode->next = p->next;
    p->next = newNode;
}

// 删除元素于指定位置
char delLinkListElePtr(struct LNode *node, int i) {
    // 临时指针指向头结点
    struct LNode *p = node;
    int count = 1;
    // 寻找第i个节点，并让p指向其前驱
    while (p->next && count < i) {
        p = p->next;
        ++count;
    }
    // 释放位置不合理，返回个空值
    if (!(p->next) || count > i) {
        exit(-1);
    }
    /**
     * 建立一个临时指针指向要删除的节点
     * 让p节点指向要删除节点的下一节点
     * p节点的值取出用于返回
     * 释放临时节点的空间
     */
    struct LNode *temp = p->next;
    p->next = temp->next;
    char e = p->ch;
    free(temp);
    return e;
}

// 修改元素于指定位置
char editLinkListElePtr(struct LNode *node, int i, char e) {}

// 查询元素于指定位置
char getLinkListElePtr(struct LNode *node, int index) {
    // 临时指针指向头结点指针的下一元素，即该链表的第一个真正元素
    struct LNode *p = node->next;
    // 计数器，从1开始
    int count = 1;

    /**
     * 从第一个元素开始遍历，有两种情况发生
     * 第一种情况是j遍历到了i的位置  --> 该情况是找到了元素
     * 第二种情况是p指针遍历到了空   --> 该情况是该节点为最后节点
     */
    while (p->next && count < index) {
        p = p->next;
        ++count;
    }

//    todo:p指针遍历到空之后，再往后输出的都是最后一个节点值
    // 第i个元素不存在，一般是0，0为头结点，不访问
    // if (!p->next ||count > index) { // 尾节点无法访问
    if (count > index) { // 此条件在26个字母表情况下，26往后的元素都返回a
        exit(-1);
    }

    // 取第i个元素并返回
    char e;
    e = p->ch;
    return e;
}

// 头插法生成26字母表
struct LNode genAlphabetPtr() {
    struct LNode head = build();
    for (int i = 0; i < MAX_LENGTH; ++i) {
        struct LNode *p = malloc(sizeof(struct LNode));
        p->ch = 'a' + i;
        p->next = head.next;
        head.next = p;
    }
    return head;
}

int main() {
    struct LNode p = genAlphabetPtr();
//    for (int i = 1; i <= MAX_LENGTH; i++) {
//        char e = getLinkListElePtr(&p, i);
//        printf("%d:%c\n", i, e);
//    }
    while (p.next) {
        p = *p.next;
        printf("%c", p.ch);
    }
}