/*
 * @Author: Nimrod
 * @Date: 2018-05-25 19:35:54
 */
#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

template <class T>
class BlobPtr;

template <class T>
class Blob {
    friend class BlobPtr<T>;

public:
    typedef std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T& t) { data->push_back(t); }
    void pop_back();
    T& front();
    T& back();
    BlobPtr<T> begin();
    BlobPtr end();

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const T& msg) const;
};

template <class T>
class BlobPtr {
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
    T& deref() const;
    BlobPtr& incr();
    bool operator!=(const BlobPtr& p) { return p.curr != curr; }

private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const T&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <class T>
Blob::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <class T>
Blob::Blob(std::initializer_list<T> il)
    : data(std::make_shared<std::vector<T>>(il)) {}

template <class T>
void Blob::check(size_type i, const T& msg) const {
    if (i >= data->size()) throw std::out_of_range(msg);
}

template <class T>
T& Blob::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template <class T>
T& Blob::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <class T>
void Blob::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <class T>
BlobPtr Blob::begin() {
    return BlobPtr(*this);
}

template <class T>
BlobPtr Blob::end() {
    auto ret = BlobPtr(*this, data->size());
    return ret;
}

template <class T>
std::shared_ptr<std::vector<T>> BlobPtr::check(std::size_t i,
                                               const T& msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

template <class T>
T& BlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <class T>
BlobPtr& BlobPtr::incr() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

#endif  // BLOBPTR_H