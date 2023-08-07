//
// Created by hwf on 2023/8/7.
//

#include <stdio.h>
#include <stdlib.h>
/**
 * 生成一个保存26个字母的顺序表
 */
#define MAX_TABLE_LENGTH 26

typedef struct SeqTables {
//  字符节点
    char *ch;
//  表长度
    int length;
//  表当前大小
    int size;
} SeqTablesAlias; // 结构体别名全局变量



// 初始化一个顺序表
struct SeqTables build() {
    struct SeqTables tables;
    tables.ch = (char *) malloc(sizeof(struct SeqTables) * MAX_TABLE_LENGTH);
    if (!tables.ch) {
        exit(-1);
    }
    tables.size = 0;
    tables.length = MAX_TABLE_LENGTH;
    return tables;
}


// ===================================recommend===================================

// 新增指定位置元素
void insertPtr(struct SeqTables *tables, int i, char e) {
    if (i > tables->length) {
        exit(-1);
    }
    for (int j = tables->size; j > i; j--) {
        tables->ch[j] = tables->ch[j - 1];
    }
    tables->ch[i] = e;
    tables->size = tables->size + 1;
}

// 删除指定位置元素
char delSeqTableElePtr(struct SeqTables *tables, int i) {
    if (i > tables->size) {
        exit(-1);
    }
    char result = tables->ch[i];
    for (int j = i; j < tables->size; j++) {
        tables->ch[j] = tables->ch[j + 1];
    }
    tables->size = tables->size - 1;
    return result;
}

// 修改某位置元素
char editSeqTableElePtr(struct SeqTables *tables, int i, char e) {
    if (i > tables->size) {
        exit(-1);
    }
    char result = tables->ch[i];
    tables->ch[i] = e;
    return result;
}

// 查询指定位置元素
char getSeqTableElePtr(struct SeqTables *tables, int i) {
    if (i > tables->size) {
        exit(-1);
    }
    return tables->ch[i];
}

// 获取26字母表
void genAlphabetPtr(struct SeqTables *tables) {
    for (int i = 0; i < tables->length; i++) {
        insertPtr(tables, i, ('a' + i));
    }
}
// ===================================recommend===================================

void insert(struct SeqTables tables, int i, char e) {
    if (i > tables.length) {
        exit(-1);
    }
    for (int j = tables.size; j > i; j--) {
        tables.ch[j] = tables.ch[j - 1];
    }
    tables.ch[i] = e;
}


char getSeqTableEle(struct SeqTables tables, int i) {
    if (i > tables.size) {
        exit(-1);
    }
    return tables.ch[i];
}

void getAlphabet(struct SeqTables tables) {
    for (int i = 0; i < tables.length; i++) {
//        insertPtr(&tables, i, ('a' + i));
        insert(tables, i, ('a' + i));
    }
}


// ===================================可能有错未确定的函数===================================
// 初始化一个顺序表
// TODO:返回堆栈的地址会发生异常，返回的地址是释放过的地址，不会是想要的类型变量的首地址，对改地址进行操作会有可能操作到其他函数/功能使用的地址空间致使发生异常
//SeqTablesAlias *init() {
struct SeqTables *init() {
//    struct SeqTables tables;
//  两条语句的区别
    SeqTablesAlias tablesAlias;
    tablesAlias.ch = (char *) malloc(sizeof(tablesAlias) * MAX_TABLE_LENGTH);
    if (!tablesAlias.ch) {
        exit(-1);
    }
    tablesAlias.size = 0;
    tablesAlias.length = MAX_TABLE_LENGTH;
//    这里返回能找到内存地址，但是估计系统没管理这片内存，已经被free()，会被malloc()函数重新分配
    return &tablesAlias;
}


struct SeqTables *buildPtr() {
    struct SeqTables tables;
    tables.ch = (char *) malloc(sizeof(struct SeqTables) * MAX_TABLE_LENGTH);
    if (!tables.ch) {
        exit(-1);
    }
    tables.size = 0;
    tables.length = MAX_TABLE_LENGTH;
    return &tables;
}
// ===================================可能有错未确定的函数===================================


int main() {
//    非指针
    struct SeqTables table1 = build();
    getAlphabet(table1);
    printf("非指针方法获取字母表：%s\n", table1.ch);

//    指针
    struct SeqTables table2 = build();

    genAlphabetPtr(&table2);

    printf("指针方法获取字母表：%s ,%d\n", table2.ch,table2.size);
    printf("指针方法获取指定位置元素%c\n", getSeqTableElePtr(&table2, 3));

    printf("指针方法修改指定位置元素%c\n", editSeqTableElePtr(&table2, 3,'a'));
    printf("指针方法修改指定位置元素字母表剩余内容%s,%d\n", table2.ch, table2.size);

    printf("指针方法删除指定位置元素%c\n", delSeqTableElePtr(&table2, 4));
    printf("指针方法删除后字母表剩余内容%s,%d\n", table2.ch, table2.size);

}