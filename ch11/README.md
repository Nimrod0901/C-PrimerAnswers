#11.01
```map``` is an associate container, ```vector``` is a sequence container.

#11.02

#11.08
https://stackoverflow.com/questions/8686725/what-is-the-difference-between-stdset-and-stdvector
>A set is ordered. It is guaranteed to remain in a specific ordering, according to a functor that you provide. No matter what elements you add or remove (unless you add a duplicate, which is not allowed in a set), it will always be ordered.

>A vector has exactly and only the ordering you explicitly give it. Items in a vector are where you put them. If you put them in out of order, then they're out of order; you now need to sort the container to put them back in order.

>Admittedly, set has relatively limited use. With proper discipline, one could insert items into a vector and keep it ordered. However, if you are constantly inserting and removing items from the container, vector will run into many issues. It will be doing a lot of copying/moving of elements and so forth, since it is effectively just an array.

>The time it takes to insert an item into a vector is proportional to the number of items already in the  vector. The time it takes to insert an item into a set is proportional to the log₂ of the number of items. If the number of items is large, that's a huge difference. log₂(100,000) is ~16; that's a major speed improvement. The same goes for removal.

>However, if you do all of your insertions at once, at initialization time, then there's no problem. You can insert everything into the vector, sort it (paying that price once), and then use standard algorithms for sorted vectors to find elements and iterate over the sorted list. And while iteration over the elements of a set isn't exactly slow, iterating over a vector is faster.

>So there are cases where a sorted vector beats a set. That being said, you really shouldn't bother with the expense of this kind of optimization unless you know that it is necessary. So use a set unless you have experience with the kind of system you're writing (and thus know that you need that performance) or have profiling data in hand that tells you that you need a vector and not a set.

#11.09
``std::map<std::string, std::list<unsigned int>> m```
#11.10
#11.11
#11.15
```cpp
mapped_type : int  
key_type : int  
value_type : vector<int>
```
#11.16
```cpp
std::map<int, std::string> map;
map[1] = "Nimrod";
```
#11.17
#11.18
``std::map(std::string, size_t)::const_iterator;
#11.21
```
For input word
    if word is existed:
        word_count[word]++
    else:
        word_count[word] = 0
        word_count[word] ++
```
#11.22
```cpp
std::pair<std::string, std::vector<int>>    // argument
std::pair<std::map<std::string, std::vector<int>>::iterator, bool> // return
```
#11.23
