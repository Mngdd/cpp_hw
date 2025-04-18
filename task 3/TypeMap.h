#ifndef TYPEMAP_H
#define TYPEMAP_H

#include <any>
#include <array>
#include <initializer_list>
#include <ranges>
#include <iostream>

#include "../task 2/TypeList.hpp"


// TODO: think about universal ref + rvalue......
template <typename... Ts>
class TypeMap {
public:
    TypeMap() {
        for (size_t i = 0; i < values_ptrs_.size(); i++) {
            values_ptrs_[i] = nullptr;
        }
    }

    ~TypeMap() {
        std::cout << "releasing memory..." << std::endl;
        for (size_t i = 0; i < values_ptrs_.size(); i++) {
            if ((type_list_[i])(values_ptrs_[i]) != nullptr)
                delete values_ptrs_[i];
        }
    }

    template <class T, class U>
    void AddValue(std::initializer_list<U> list);

    template <class T, class... Args>
    void AddValue(Args&&... args);

    template <class T>
    T& GetValue();

    template <class T>
    bool Contains() { return type_list_.contains<T>; }

    template <class T>
    void RemoveValue();
private:
    TypeList<Ts...> type_list_{};
    std::array<std::any, TypeList<Ts...>::size> values_ptrs_{};
};



#endif //TYPEMAP_H
