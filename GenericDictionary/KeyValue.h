//
// Created by drawl_000 on 3/28/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H


template <class k,class v>
class KeyValue{
public:
    KeyValue(){}
    KeyValue(k kay,v val){
        key=kay;
        value=val;
    }

    KeyValue(KeyValue &other){
        key=other.getKey();
        value=other.getValue();
    }
    bool operator==(const KeyValue other);
    k getKey(){
        return key;
    }
    v getValue(){
        return value;
    }
private:
    k key;
    v value;
};




#endif //GENERICDICTIONARY_KEYVALUE_H
