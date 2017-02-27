# Dynamic Programming

## Ideas
* avoid solving the same problem or subproblem twice
* trade space for runtime

## Demo
Given a sequence of as many as 10,000 integers, what is the maximum decreasing subsequence

### Recursive Descent Solution
* find the recurrence and a terminal condition
* similar to DFS
```C++
check (start, nmatches, smallest) {
    int better, i, best=nmatches;
    for (i = start; i < n; i++) { //terminal condition
        if (sequence[i] < smallest) {
            better = check (i, nmatches+1, sequence[i]); //recurrence
            if (better > best) best = better;
        }
    }
    return best;
}
```

### DP solution
* trade space for the solved subproblems
```C++
for (i = n-1-1; i >= 0; i--) {
    bestsofar[i] = 1;
    for (j = i+1; j < n; j++) {
        if (num[j] < num[i] && bestsofar[j] >= bestsofar[i])  { //use bestsofar[i] to record the length of best sequence from i to end
            bestsofar[i] = bestsofar[j] + 1;
            if (bestsofar[i] > longest) longest = bestsofar[i];
        }
    }
}
```
* trade space for the inner loop
```C++
/*
best[] holds the opitimal subsequence, with each best[i] is the maximum last element of subsequence of length i+1
*/
int sol = -1;
for (i = 0; i < n; i++) {
	best[i] = -1;
	cin>>x;
	for (k = 0; best[k] > x; k++) //find the 
	    ;
	best[k] = x; 
	sol = MAX(sol, k + 1);
}
```
* optimized with line search for k 
```C++
fscanf (in, "%d", &best[0]);
sol = 1;
for (i = 1; i < n; i++) {
    best[i] = -1;
    cin>>x;

    if(x >= best[0]) {
        k = 0;
        best[0] = x;
    }
    else {
        // use binary search instead
        low = 0;
        high = sol-1;
        for(;;) {
            k = (int) (low + high) / 2;
            // go lower in the array
            if(x > best[k] && x > best[k-1]) {
                high = k - 1;
                continue;
            }
            // go higher in the array
            if(x < best[k] && x < best[k+1]) {
                low = k + 1;
                 continue;
            }
            // check if right spot
            if(x > best[k] && x < best[k-1])
                best[k] = x;
            if(x < best[k] && x > best[k+1])
                best[++k] = x;
            break;
        }
    }
	sol = MAX(sol, k + 1);
}
```

## Two Dimensional DP
Given two sequences of integers, what is the longest sequence which is a subsequence of both sequences?
* DP algorithm
```
//the tail of the second sequence is empty
for element = 1 to length1
    length[element, length2+1] = 0

//the tail of the first sequence has one element
matchelem = 0
for element = length2 to 1
    if list1[length1] = list2[element]
        matchelem = 1
        length[length1,element] = nmatchlen 

//loop over the beginning of the tail of the first sequence
for loc = length1-1 to 1
    maxlen = 0
    for element = length2 to 1
        // longest common subsequence doesn't include first element
        if length[loc+1,element] > maxlen
            maxlen = length[loc+1,element]
    //longest common subsequence includes first element
    if list1[loc] = list2[element] && length[loc+1,element+1]+1 > maxlen
        maxlen = length[loc,element+1] + 1
        length[loc,element] = maxlen
```
* output the common subsequence
```
location1 = 1
location2 = 1

while (length[location1,location2] != 0)
    flag = False
    for element = location2 to length2
        if list1[location1] == list2[element] && length[location1+1,element+1]+1 == length[location1,location2]
            output (list1[location1],list2[element])
            location2 = element + 1
            flag = True
            break for
        location1 = location1 + 1
```
