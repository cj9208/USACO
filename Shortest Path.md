# Shortest Path

## Dijkstra Algorithm
* Objection : Find the shortest paths from source vertex to any other vertices
* Complexity :
    * Time : O(V^2)
    * Space : requires the adjacency matrix form of the graph
* Ideas : greedy + BFS
* Bad point
    * Only work for graphs with non-negative weights
* Pseudocode :
    * distance(j) is distance from source vertex to vertex j
    * parent(j) is the vertex that precedes vertex j in any shortest path
```
For all nodes i
distance(i) = infinity         	# not reachable yet
    visited(i) = False
    parent(i) = nil	# no path to vertex yet 

distance(source) = 0	# source -> source is start of all paths
parent(source) = nil
while (nodesvisited < graphsize)
    find unvisited vertex with min distance to source; call it vertex i
    assert (distance(i) != infinity, "Graph is not connected") 

    visited(i) = True	# mark vertex i as visited 

    # update distances of neighbors of i
    For all neighbors j of vertex i
        if distance(i) + weight(i,j) < distance(j) then
        distance(j) = distance(i) + weight(i,j)
        parent(j) = i
```

## Floyd-Warshall Algorithm
* Objection : Find the shortest paths between all pairs of vertices
* Complexity :
    * Time : O(V^3)
    * Space : requires the adjacency matrix form of the graph  
* Pseudocode : 
    * dist(i,j) is "best" distance so far from vertex i to vertex j 
    * The magic point is that it only need one iteration
```
For i = 1 to n do
    For j = 1 to n do
        dist(i,j) = weight(i,j) 

For k = 1 to n do	# k is the `intermediate' vertex
    For i = 1 to n do
        For j = 1 to n do
            if (dist(i,k) + dist(k,j) < dist(i,j)) then	# shorter path
                dist(i,j) = dist(i,k) + dist(k,j)
```

## [Shortest Path Faster Algorithm (SPFA)](https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm)
* Objection : Find the shortest paths from source vertex to any other vertices
* Complexity :
    * Time : O(V^2)
    * Space : requires the adjacency matrix form of the graph
* Ideas : greedy + BFS
* Good points
    * Suit well for graphs with negative weights
    * Believed to work well on random sparse graphs
* Bad points:
    * The performance is strongly determined by the order in which candidate vertices are used to relax other vertices
* Pseudocode :
    * Q is a first-in, first-out queue of candidate vertices
    * w(u, v) is the edge weight of (u, v).
```
procedure Shortest-Path-Faster-Algorithm(G, s)
      for each vertex v ≠ s in V(G)
          d(v) := ∞
      d(s) := 0
      offer s into Q
      while Q is not empty
          u := poll Q
          for each edge (u, v) in E(G)
              if d(u) + w(u, v) < d(v) then
                  d(v) := d(u) + w(u, v)
                  if v is not in Q then
                      offer v into Q                
```
* Optimization (To be understand in practice)
    * Small Label First (SLF)
    ```
    procedure Small-Label-First(G, Q)
     if d(back(Q)) < d(front(Q)) then
         u := pop back of Q
         push u into front of Q
    ```
    * Large Label Last (LLL) 
    ```
    procedure Large-Label-Last(G, Q)
     x := average of d(v) for all v in Q
     while d(front(Q)) > x
         u := pop front of Q
         push u to back of Q
    ```
