# Divide and Conquer
---
1. Divide instance of problem into two or more smaller instances => Divide
2. Solve smaller instances recursively => Conquer
3. Obtain solution to original instance by combining these solutions => Combine

> A divide-and-conquer algorithm breaks down a large problem into smaller subproblems which themselves may be broken down into even smaller subproblems, and so on. The recursion bottoms out when it reaches a base case and the subproblem is small enough to solve directly without further recursing

- Even though binary search does not solve the other half of the subproblem, it can be considered as divide and conquer

## Master Theorem
- Provides bounds for recurrences of the form `T(n) = aT(n/b) + f(n)`

![[master.png]]

> Write an algorithm to find the sum of array elements using divide and conquer
> 

```
foo(A[0...n-1], n)
	if n=1, return A[0]
	else foo(A[0...n/2], n/2) + fun(A[(n/2)+1...n-1], n/2)

T(n) = 2T(n/2) + 1
```

- Decrease and conquer method
```
foo(A[0...n-1])
	if n=0, return 0
	return foo(A[0...n-2]) + A[n-1]

T(n) = T(n-1) + 1
```

> Apply brute force, decrease and conquer, divide and conquer to find a^n

- Brute force
```
foo(a, n)
	prod = 1
	for i=1 to n
		prod = prod*a
	return prod
```

- Decrease and conquer
```
foo(a, n)
	if n=1, return a
	return a * foo(a, n-1)

T(n) = T(n-1) + 1
```

- Divide and conquer
```
foo(a, n)
	if n=1, return a
	if n is odd, return a * foo(a, (n-1)/2) * foo(a, (n-1)/2)
	return foo(a, n/2) * foo(a, n/2)

T(n) = 2T(n/2) + 1
```

## Merge Sort

> For a given array, find the method to sort the elements which takes nlog(n) in the worst case with or without an extra space

```
Mergesort(A[0...n-1])
	if n>1
		copy A[0...(n/2)-1] to B[0...(n/2)-1]
		copy A[(n/2)...n-1] to C[0...(n/2)-1]
		Mergesort(B[0...(n/2)-1])
		Mergesort(C[0...(n/2)-1])
		Merge(B,C,A)

Merge(B[0...p-1], C[0...q-1], A[0...p+q-1])
	i=0, j=0, k=0
	while i<p and j<q do
		if B[i] <= C[j]
			A[k] = B[i], i=i+1
		else
			A[k] = C[j], j=j+1
		k = k +1

	if i=p, copy C[j...q-1] to A[k...p+q-1]
	else copy B[i...p-1] to A[k...p+1-1]
```

- The function of merging two arrays plays a major role in time efficiency
- The merging of two sorted arrays can be done as follows. Two pointers (array indices) are initialized to point to the first elements of the arrays being merged. The elements pointed to are compared, and the smaller of them is added to a new array being constructed; after that, the index of the smaller element is incremented to point to its immediate successor in the array it was copied from. This operation is repeated until one of the two given arrays is exhausted, and then the remaining elements of the other array are copied to the end of the new array