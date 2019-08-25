//
// Created by xiaomi on 8/25/19.
//
#include "union_find.h"
#include "iostream"
void test_union_find(){
    algorithms_princeton::UnionFind union_find(10);
    union_find.Union(0, 1);
    union_find.Union(1, 2);
    union_find.Union(2, 3);
    union_find.Union(4, 3);
    union_find.Union(5, 4);
    union_find.Union(6, 7);
    union_find.Union(8, 9);

    std::cout << union_find.Connected(0, 6) << std::endl;
    std::cout << union_find.Connected(0, 8) << std::endl;

    union_find.Union(3, 6);
    std::cout << union_find.Connected(0, 6) << std::endl;
    std::cout << union_find.Connected(0, 8) << std::endl;

    union_find.Union(7, 9);
    std::cout << union_find.Connected(0, 6) << std::endl;
    std::cout << union_find.Connected(0, 8) << std::endl;

}


int main(int argc,char** argv){

    test_union_find();

    return 0;
}
