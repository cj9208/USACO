#[Dynamic Programming](http://love-oriented.com/pack/)

## zero-one pack (each item has only one copy)

* Basic notation: 
    * N : number of items, V : capacity of pack
    * c[i] : cost of ith item
    * w[i] : value of ith item
    
* Transition function:·
    ···
    let f[i][v] denotes the maximum value of put first i items into a pack of v capacity
    
    then f[i][v] = max(f[i-1][v], f[i-1][v-c[i]]+w[i])
    ···
      
* Optimization:

    * The space can be reduced to O(V)
    ````
    for i=1...N
      for v= V...0   
        f[v] = max(f[v], f[v-c[i]]+w[i])  

    ```
    * Constant Optimization : only need to calculate f[V-sum(c[i])]...f[V], useful when V is large
    
## complete pack (each item has infinite copies)

* Reduce to zero-one pack problem
    * The number of copies of item i is less than V/c[i]
    * regard item i with infinite copies as V/c[i] items with same cost and value as item i
    
* Optimization
    * Binary thoughts : can use item of cost and value c[i]*2^k, w[i]*2^k, thus reduce the cost from O(V/c[i]) to O(log V/C[i])
    * O(VN) solution
    ```
    for i=1...N  
      for v= 0...V  //here is the difference, by doing so, we allow duplicates 
        f[v] = max(f[v], f[v-c[i]]+w[i]) 
    ```

       
## Multi pack (item i has n[i] copies)
* Optimization
    * Binary thoughts : can use item of cost and value c[i]*2^k, w[i]*2^k, and c[i]*(n[i]-2^k+1),w[i]*(n[i]-2^k+1)
    * O(VN) solution : use monotone priority queue (to be updated)
    
## Combination of above three
```
for i=1...N
    do update according to the type of item
```
    
## Two dimensional costs pack problem (item i has two costs, a[i], b[i])

* Solution
    * Just add one dimension to the state
* In practice
    * regard restriction of at most m items as another costs with each item has cost 1 
    
## Grouped Pack (items are divided into several groups than can select at most one  item from one group)
Solution:
```
    Regard as selecting groups with one group has multi choices 
    for all groups
      for v = V..0
        for all items in current group
          f[v] = max(f[v], f[v-c[i]]+w[i])
```
## Pack problem with dependency
* Description
    * There exists some relations between items. That is if you choose i, then you must choose j
  
* Solution
    * Use extended item 
    * Regard items with dependency as an extended item, then can use solution from group pack problem
    
* Optimization
    * Do a pack optimization to each extended item to find the best combination for each cost
  

## Extended item
* Description
    * The extended item is a function of cost and value. This is given the item cost i, it will have value h(i)

## In practice

* Output optimal strategy : Record the strategy during every step 
* Output alphabetically optimal strategy : Be careful of strategy selection
* output kth strategy : the state is k-array
* Output number of strategies
    * simple modification :  f[v] = sum(f[v], f[v-c[i]]) 
* Can also be solved by search
  
