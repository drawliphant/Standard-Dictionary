//
// Created by drawl_000 on 4/4/2017.
//

#include "DictionaryTester.h"
#include "../Dictionary.h"
DictionaryTester::DictionaryTester(){

}
bool DictionaryTester::testConstructors(){
    //test int constructor
    Dictionary<int,int> test(10);

    test.add(10,20);
    test.add(20,30);
    test.add(30,40);
    if(test.getCount()!=3){
        std::cout<<"int contructor failed to set count. Should be 3. Actual"<<test.getCount();
    }
    Dictionary<int,int> test2(test);
    if(test2.getCount()!=test.getCount()){

        std::cout<<"copy constructor failed to set count. Should be 3. Actual"<<test2.getCount();
        for(int i=0;i<3;i++){
            if(test2[i].getKey()!=(i+1)*10){
                std::cout<<"copyConstuctor["<<i<<"].get key failed. Should be "<<(i+1)*10<<std::endl;
            }
        }
    }

    return true;
}
bool DictionaryTester::testUnsorted(){
    Dictionary<int,int> uns(10);
    for(int i=0;i<30;i++){//run add test and resize
        uns.add(i,rand());
    }
    for(int i=0;i<30;i++){
        if(uns.getCount()!=30){
            std::cout<<"got wrong count for uns. Expected 30. Actual "<<uns.getCount()<<std::endl;
        }
        if(uns[i].getKey()!=i){
            std::cout<<"uns["<<i<<"] did not get right key. Should have "<<i<<" Actual "<<uns[i].getKey()<<std::endl;
        }
    }

    //run getByKey test;
    if(uns.getByKey(0).getKey()!=0){
        std::cout<<"getKey did not work returned "<<uns.getByKey(0).getKey()<<" instead"<<std::endl;
    }
    if(uns.getByKey(uns.getCount()-1).getKey()!=29){
        std::cout<<"getKey did not work returned "<<uns.getByKey(uns.getCount()-1).getKey()<<" instead"<<std::endl;
    }

    uns.removeByPosition(10);//run remove by position test
    if(uns.getCount()!=29){
        std::cout<<"removeByPosition failed to decriment"<<std::endl;
    }
    for(int i=0;i<10;i++){
        if(uns[i].getKey()!=i){
            std::cout<<"remove moved too low value at "<<i<<std::endl;
        }
    }
    for(int i=10;i<uns.getCount()-1;i++){
        if(uns[i].getKey()!=i+1){
            std::cout<<"remove failed to move "<<i<<std::endl;
        }
    }
    uns.removeByKey(12);//remove by key test
    for(int i=0;i<10;i++){
        if(uns[i].getKey()!=i){
            std::cout<<"removeByKey moved too low value at "<<i<<std::endl;
        }
    }
    for(int i=11;i<uns.getCount()-1;i++){
        if(uns[i].getKey()!=i+2){
            std::cout<<"removeByKey failed to move "<<i<<std::endl;
        }
    }


    //i decided not to specifically test [] because it is tested thoroughly throughout
    return true;
}
bool DictionaryTester::testSorted(){
    //will run these tests for extra credit
    return true;
}

