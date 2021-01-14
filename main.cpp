#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T, typename U>
class Dictionary{
private:
    std::vector<T> keys;
    std::vector<U> values;
public:
    Dictionary();
    Dictionary(std::initializer_list<std::pair<T,U>>);
    bool has(T) const;
    void add(T,U);
    T* begin();
    T* end();
    U operator[](T);
};

template <typename T, typename U>
T* Dictionary<T,U>::begin(){
    return &(keys[0]);
}

template <typename T, typename U>
T* Dictionary<T,U>::end(){
    return &(keys[keys.size()-1])+1;
}

template <typename T, typename U>
Dictionary<T,U>::Dictionary (std::initializer_list<std::pair<T,U>> store){
    for (std::pair<T,U> object : store){
        keys.push_back(object.first);
        values.push_back(object.second);
    }
}

template <typename T, typename U>
bool Dictionary<T,U>::has(T targetKey) const{
    for (T currentKey : keys){
        if (currentKey == targetKey){
            return true;
        }
    }
    return false;
}

template <typename T, typename U>
void Dictionary<T,U>::add (T key, U value){
    keys.push_back(key);
    values.push_back(value);
}

template <typename T, typename U>
U Dictionary<T,U>::operator[] (T key){
    unsigned int pos = std::find(keys.begin(), keys.end(), key) - keys.begin();
    return values[pos];
}





int main() {


    return 0;
}