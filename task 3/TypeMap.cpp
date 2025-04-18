#include "TypeMap.h"

template <typename... Ts>
template <class T, class U>
void TypeMap<Ts...>::AddValue(std::initializer_list<U> list) {
    values_ptrs_[type_list_.get_index<T>] = new T{list};
}

template<typename ... Ts>
template<class T, class... Args>
void TypeMap<Ts...>::AddValue(Args&&... args) {
    values_ptrs_[type_list_.get_index<T>] = new T(args...);
}

template<typename ... Ts>
template <class T>
T& TypeMap<Ts...>::GetValue() {
    auto ptr = values_ptrs_[type_list_.get_index<T>];
    if (ptr == nullptr) {
        throw std::runtime_error("No value found...");
    }
    return *ptr;
}

template<typename ... Ts>
template<class T>
void TypeMap<Ts...>::RemoveValue() {
    if (!Contains<T>()) {
        throw std::runtime_error("No value found...");
    }

    delete values_ptrs_[type_list_.get_index<T>];
}



