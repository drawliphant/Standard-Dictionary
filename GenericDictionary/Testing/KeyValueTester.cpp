//
// Created by drawl_000 on 4/3/2017.
//
#include <string>
#include <iostream>
#include "KeyValueTester.h"
#include "../KeyValue.h"
KeyValueTester::KeyValueTester(){

}
void KeyValueTester::test(){
    std::cout<<"running KeyValue tests"<<std::endl;
    KeyValue<std::string,int> test("cats",5);
    KeyValue<float,int> test2(1,7);
    KeyValue<float,int> copy(test2);
    if(test.getKey()!="cats"){
        std::cout<<"test.getKey failed. Should return cats, actual "<<test.getKey()<<std::endl;
    }
    if(test.getValue()!=5){
        std::cout<<"test.getValue failed. Should return 5, actual "<<test.getValue()<<std::endl;
    }
    if(test2.getKey()!=1){
        std::cout<<"test2.getKey failed. Should return 1, actual "<<test2.getKey()<<std::endl;
    }
    if(test2.getValue()!=7){
        std::cout<<"test2.getValue failed. Should return 7, actual "<<test2.getValue()<<std::endl;
    }
    if(copy.getKey()!=test2.getKey()){
        std::cout<<"copy.getKey() had wrong key. actual "<<copy.getKey();
    }
    if(copy.getValue()!=test2.getValue()){
        std::cout<<"copy.getValue() had wrong key. actual "<<copy.getValue();
    }


}