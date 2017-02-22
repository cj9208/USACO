# Minimum Spanning Trees

## The Abstraction
* Definition : 
  * A _spanning tree_ of a graph is any sub-graph which is a connected tree (i.e. there exists a path between any nodes of the original graph which lies entirely in the sub-graph)
  * A _minimal spanning tree_ is a spanning tree which has minimal `cost' (where cost is the sum of the weights of the edges in the tree)
* Problem : 
  * Given: an undirected, connected graph with weighted edges
  * Find a minimal spanning tree

## Prim's algorithm
* Ideal : greedily builds the minimal spanning tree by iteratively adding nodes into a working tree
* Complexity :
  * Time : O(V^2)
* Bad Points
  * Changing any element in a tree requires complete recalculation
  * Break down or too difficult to alter when subjects the tree to any other constraints(no two nodes may be very far away or the average distance must be low)
* Pseudocode : 
  * distance(j) is distance from tree to node j
  * source(j) is which node of so-far connected MST is closest to node j
```
For all nodes i
    distance(i) = infinity        # no connections
    intree(i) = False             # no nodes in tree
    source(i) = nil 

    treesize = 1                    # add node 1 to tree
    treecost = 0                   
    intree(1) = True
    For all neighbors j of node 1   # update distances
        distance(j) = weight(1,j)
        source(j) = 1 

    while (treesize < graphsize)
        find node with minimum distance to tree; call it node i # O(V) need to search all nodes
        assert (distance(i) != infinity, "Graph Is Not Connected") 

    # add edge source(i),i to MST
        treesize += 1
        treecost += distance(i)
        intree(i) = True              # mark node i as in tree 

    # update distance after node i added
        for all neighbors j of node i
            if (distance(j) > weight(i,j))
                distance(j) = weight(i,j)
                source(j) = i
```
