This is note for dynamic programming. Here I will use pack problem as example.
1. zero-one pack (each item has only one copy)
  Basic notation: 
    c[i] : cost of ith item
    w[i] : value of ith item
  let f[i][v] denotes the maximum value of put first i items into a pack of v capacity
  then f[i][v] = max(f[i-1][v], f[i-1][v-c[i]]+w[i])
2. complete pack (each item has infinite copies)
