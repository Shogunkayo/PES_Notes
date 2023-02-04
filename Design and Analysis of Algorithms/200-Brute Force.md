# Brute Force
---
- Straightforwad approach to solving a problem, usually directly based on the problem statement and definitions of the concepts involved
- Applicable to a very wide variety of problems => more difficult to find a problem where brute force wouldn't work
- For sorting, searching, matrix multiplication and string matching, the brute force approach yields reasonable algorithms of at least some practical value with no limitation on instance size
- Not worth designing a more efficient algorithm if only a few instances of a problem need to be solved, which brute force can solve with acceptable speed
- Useful for solving small-size instances of a problem even if inefficient for the entire set
- Serves as a yardstick with which more efficient alternatives can be judged

> A first  application of the brute-force approach often results in an algorithm that can be improved with a modest amount of effort

## Selection Sort
- Start by scanning the entire given list to find its smallest element
- Exchange it with the first element, putting the smallest element in its final position in the sorted list
- Scan the list starting with second element to find the smallest among the last `n - 1` elements and repeat the same procedure for `n - 2` times
```
for i=0 to n-2 do
	min=i
	
	for j=i+1 to n-1 do
		if A[j] < A[min], min=j  
	
	swap A[i] and A[min]
```
- `C(n) = (n * (n - 1)) / 2`

## Bubble Sort
- Compare adjacent elements of the list and exchange them if they are out of order
- "Bubble up" the largest element to the last position
- The next pass bubbles up the second largest element, and so on  for `n-1 ` passes
```
for i=0 to n-2 do
	for j=0 to n-2-i do
		if A[j+1] < A[j], swap A[j] and A[j+1]
```
- `C(n) = (n * (n - 1)) / 2`

## Sequential Search
- Compare successive elements of a given list with a given search key until either a match is encountered, or the list is exhausted without finding a match
- If the key is appended to the end of the list, we can eliminate the end of list check
```
A[n] = K
i = 0

while A[i] != K do
	i = i+1

if i<n, return i
else return -1 
```
- If the given list is sorted, searching can be stopped as soon as an element greater than or equal to the search key is encountered

## Closest Pair Problem
To find the closest points in a set of `n` points. 
- One important application is cluster analysis in statistics (numerical data -> Euclidean distance, non numerical data -> Hamming distance).
- A bottom-up algorithm begins with each element as a seperate cluster and merges them into successively larger cluster by combining the closest pair of clusters
- Brute force approach is to compute the distance between each pair of distinct points and find a pair with the smallest distance
- To avoid repetition, only consider pair of points `(pi, pj)` where `i < j`
```
d = INT_MAX
for i=1 to n-1 do
	for j=i+1 to n do
		d = min(d, sqrt((xi - xj)^2 + (yi - yj)^2))

return d
```
- The basic operation is computing the square root. Even now, computing square root is not as simple as an operation like addition. Even for most integers, square roots are irrational and only an approximation can be found
- Avoid square roots by considering the `(xi - xj)^2 + (yi - yj)^2)` value itself, as square root function is strictly increasing

## Convex-Hull Problem
*for better undestanding and an alternate algorithm, please see this [video](https://www.youtube.com/watch?v=YNyULRrydVI)*

To find the convex hull for a given set of points in the plane or a higher dimensional space
- Several applications are based on the fact that convex hulls provide convenient approximations of object shapes and data sets given
- Replacing objects by their convex hulls sppeds up collision detection
- Used in computing accessiblity maps produced from satellite images
- Also used for detecting outliers by some statistical techniques

> A set of points (finite or infinite) in the plane is called convex if for any two points p and q in the set, the entire line segment with endpoints at p and q and belongs to the set

![[convexhull1.png]]
![convexhhull1](https://github.com/Shogunkayo/PES_Notes/blob/main/Design%20and%20Analysis%20of%20Algorithms/Images/convexhull1.png)


> The convex hull of a set S of points is the smallest convex set containing S (the convex hull of S must be a subset of any convex set containing S)

![[convexhull2.png]]
![convexhull2](https://github.com/Shogunkayo/PES_Notes/blob/main/Design%20and%20Analysis%20of%20Algorithms/Images/convexhull2.png)

- If `S` is a set of two points, its convex hull is the line segment connecting these points
- If `S` is a set of three points not on the same line, its convex hull is the triangle with the vertices at the three points given. If the three points do lie on the same line, the convex hull is the line segment with its endpoints at the two points that are farthest apart

> **THEOREM** 
> The convex hull of any set S of n > 2 points not all on the same line is a convex polygon with the vertices at some of the points of S (if all the points do lie on the same line, the polygon degenerates to a line segment but still with the endpoints at two points of S)

- The convex hull problem is the problem of constructing the convex hull for a given set `S` of `n` points
- To solve, we need to find the points that will serve as the vertices of the polygon in question. Such points are called extreme points
- Extreme points have several special properties other points of a convex set do not have
- Simple but inefficient algorithm based on the observation about line segments making up the boundary of a convex hull: a line segment connecting two points `pi` and `pj` of a set of `n` points is a part of the convex hull's boundary if and only if all the other points of the set lie on the same side of the straight line through these two points

A line `ax + by = c` divides the plane into two half-planes: for all the points in one of them `ax + by > c`, while for all the points in the other `ax + by < c`. To check whether certain points lie on the same side of the line, we simply check whether the expression `ax + by - c` has the same sign for each of these points. Time efficiency for this algorithm is `O(n^3)` as for each of the `n(n-1)/2` pairs of distinct points, we may need to find the sign of `ax + by -c` for each of the other `n-2` points
