# C++ Standard Template Library
## [Containers](http://www.cplusplus.com/reference/stl/)
(how they are implemented, good/bad/properties)
(to be finished)
* Sequence Containers
    * vector (array)
    * list (linked list)
    * deque
        * random access
        * efficient insertion and deletion of elements at the beginning of the sequence
    
* Associated Containers 
    * map, multimap
        * the elements are always sorted by its key
        * slower than unordered_map containers to access individual elements by their key
        * allow the direct iteration on subsets based on their order
        * typically implemented as binary search trees.
    * set, multiset
        * The value of the elements cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container
        * the elements are always sorted
        * each value in a _set_ must be unique
        * slower than unordered_set containers to access individual elements by their key  
        * allow the direct iteration on subsets based on their order
        * typically implemented as binary search trees

* Unordered Associated Containers
    * the elements are not sorted 
    * allows for fast retrieval of individual elements

* Container Adapters
    * stack (LIFO) (use deque to implement)
    * queue (FIFO) (use list to implement)
    * priority_queue (use vector to implement)
        * specifically designed such that its first element is always the greatest of the elements it contains
        * similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved 
        * support random access iterators

## [algorithm](http://www.cplusplus.com/reference/algorithm/)
* test / match / find / 
* modify
* sort
* merge 
* heap
* min/max

## Other Libraries
* [biset](http://www.cplusplus.com/reference/bitset/bitset/) 
    * access : test(i), count() (regard as function, "()", not "[]") 
    * operation : set / reset / flip
    * to_string / to_ulong / to_ullong
    * eg : chapter 3.1 contact, change 0/1 sequence to binary 
* [functional](http://www.cplusplus.com/reference/functional/)
    * hash
* [string](http://www.cplusplus.com/reference/string/)
   * convert from/to strings
   * substr
