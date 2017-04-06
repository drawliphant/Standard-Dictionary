//
// Created by drawl_000 on 4/3/2017.
//
#include <iostream>
#include "DictionaryTester.h"
#include "KeyValueTester.h"
int main(){

    KeyValueTester keyTest;
    std::cout<<"~~~Running KeyValue Tests~~~"<<std::endl;
    keyTest.test();
    DictionaryTester dictTest;
    std::cout<<"~~~Running Dictionary Tests~~~"<<std::endl;
    std::cout<<"running constructor tests"<<std::endl;
    dictTest.testConstructors();
    std::cout<<"running unsorted tests"<<std::endl;
    dictTest.testUnsorted();
    std::cout<<"running sorted tests"<<std::endl;
    dictTest.testSorted();

    return 0;
}
