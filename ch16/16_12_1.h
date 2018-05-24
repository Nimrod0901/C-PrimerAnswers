/*
 * @Author: Nimrod
 * @Date: 2018-05-11 17:31:37
 */

#ifndef BLOB_H
#define BLOB_H

#include <memory>
#include <vector>

template <class T>
class Blob {
public:
    typedef T value_type;
    typedef class std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();

    // element access
    T& back();
    T& operator[](size_type i);

    const T& back() const;
    const T& operator[](size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    // throw msg if data[i] isn't valid
    void check(size_type i, const std::string& msg) const;
};

// constructors
template <class T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <class T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data(std::make_shared<std::vector<T>>(il)) {}

template <class T>
void Blob<T>::check(size_type i, const std::string& msg) const {
    if (i >= data->size()) throw std::out_of_range(msg);
}

template <class T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <class T>
const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template <class T>
T& Blob<T>::operator[](size_type i) {
    // if i is too big, check function will throw, preventing access to a
    // nonexistent element
    check(i, "subscript out of range");
    return (*data)[i];
}

template <class T>
const T& Blob<T>::operator[](size_type i) const {
    // if i is too big, check function will throw, preventing access to a
    // nonexistent element
    check(i, "subscript out of range");
    return (*data)[i];
}   

template <class T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

#endif  // BLOB_H
