#include <iostream>
#include <string>
#include "Dictionary.h"
int main() {
    //lets make a Dictionary that relates my cattle numbers to their name
    Dictionary<int,std::string> heardName(1);
    heardName.add(1,"Lucy");//Lucy was just born, she is my first cow.
    heardName.add(2,"Bess");//Bess was just purchased too.
    heardName.removeByKey(1);//poor Lucy died in youth.
    //notice that bess just got moved to place 0;
    std::cout<<heardName[0].getKey()<<" ";
    std::cout<<heardName[0].getValue()<<std::endl;//print Bess.
    heardName.add(7,"Luck");//had to tag him with 7 because hes lucky but it still works
    heardName.removeByPosition(0);//bess was sold for a tidy profit.
    //suddenly there was a new group to buy.
    heardName.add(3,"Jackie");
    heardName.add(4,"Oreo");
    heardName.add(5,"Jimmy John");
    std::cout<<"Wow we've got "<<heardName.getCount()<<" cows. We're doing well"<<std::endl;
    //You decide to give your herd to your friend.
    Dictionary<int,std::string> friendsHeard(heardName);//copy constructor
    std::cout<<"Now your friend has "<< friendsHeard.getCount()<<" cows."<<std::endl;
    std::cout<<"But we still have "<<heardName.getCount()<<" cows."<<std::endl;
    std::cout<<"Remember to delete your heard"<<std::endl;
    for(int i=heardName.getCount()-1;i>0;i--){
        heardName.removeByPosition(i);
    }
    std::cout<<"Now we have "<<heardName.getCount()<<" cows,"<<std::endl;
    std::cout<<"and your friend has "<<friendsHeard.getCount()<<" cows."<<std::endl;



    return 0;
}