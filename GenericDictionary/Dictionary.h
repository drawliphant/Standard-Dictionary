//
// Created by drawl_000 on 3/28/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H
#include <iostream>
#include <string>
#include "KeyValue.h"
template <class k,class v>
class Dictionary {
public:
    Dictionary(int s){//set size of array constructor
        entries=new KeyValue<k,v>*[s];
        size=s;
        used=0;
    }
    Dictionary(Dictionary &other){
        size=other.size;
        used=other.used;
        entries=new KeyValue<k,v>*[size];
        for(int i=0; i<used;i++){
            entries[i]=new KeyValue<k,v>(*other.entries[i]);
        }
    }
    ~Dictionary(){//deletes the array
        for(int i=0;i<used;i++){
            delete entries[i];
        }

    }

    void add(k key, v value){//add an entry to the end
        /*if(getByKey(key).getKey()==key){
            throw "Add to dictionary failed: key already exists";
            return;
        }*/

        if(find(key)!=-1)throw "Add to dictionary failed: key already exists";
        grow();//grows used by one. and may double array.
        entries[used-1]=new KeyValue<k,v>(key,value);
    }
    void addSorted(k key, v value){
        int index=biSearch(key,true,0,used);
        if(key==entries[index]->getKey()){
            throw "AddSorted :Error: Key already exists in Dictionary";
        }else{
        //remember grow
        }
    }

    void removeByPosition(int position){//pop(i)

        if(position<used) {

            used--;
            for(int i=position;i<used+1;i++){
                entries[i]=entries[i+1];
            }
            entries[used]=nullptr;
        }else{
            std::cout<<"attempted remove outside of Dictionary size,"<<
                    " attempted index: "<<position<<" Dictionary size:"<<used;
        }
    }
    void removeByKey(k key){//pop(key)
        int index=find(key);
        if(index!=-1){
            removeByPosition(index);
        }
        else throw "Dictionary::remove no key found";

    }

    int getCount(){//return used
        return used;
    }

    KeyValue<k,v> getByKey(k key){//return KeyValue with search
        int index=find(key);
        if(index!=-1)return *entries[index];
        throw "Dictionary::getByKey failed to find Key";
    }
    KeyValue<k,v> operator[](int position){//get KeyValue from position
        //while(used<position){
        //    grow();
        //}
        if(position>=size){
            throw "Dictionary Index out of bounds";
        }
        if(entries[position]!= nullptr){
            return *entries[position];
        }
        throw "Dictionary: operator[] index not set";
    }
private:
    void grow(){//used to double array size if need to
        if(used==size){

            //copy the old array to new one.
            KeyValue<k,v>** holder=new KeyValue<k,v>*[size*2];
            for(int i=0;i<size;i++){
                holder[i]=entries[i];
            }
            entries=holder;
            size*=2;
        }
        used++;
        return;
    }
    int biSearch(k look,bool type,int least,int greatest){
        //type false: its there or not,
        //type true: return position of closest greater than for insertion
        if(least==greatest){
            if(type){
                if(look==entries[least]->getKey()){
                    return least;
                }
                if(entries[least]->getKey()>look){
                    return least;
                }else if(entries[greatest]->getKey()>look) {
                    return greatest;
                }
                return -1;
            }if(entries[least]->getKey()==look) {
                return least;
            }else{
                return -1;
            }
        }
        int cursor=(least+greatest)/2;
        if(look<entries[cursor]->getKey()){
            if(look>entries[cursor-1]->getKey()&&type){
                return cursor;
            }
            return biSearch(look,type,least,cursor-1);
        }else if(look>entries[cursor]->getKey()){
            return biSearch(look,type,cursor+1,greatest);
        }else{
            return cursor;
        }
    }//used for extra cred
    KeyValue<k,v>** entries;//array of pointers to KeyValues
    int used;//returned for getCount 1 count
    int size;//max size 1 count
    int find(k look){
        for(int i=0;i<used;i++){
            if(look==entries[i]->getKey()){
                return i;
            }
        }

        return -1;
    }//linear search
};


#endif //GENERICDICTIONARY_DICTIONARY_H
