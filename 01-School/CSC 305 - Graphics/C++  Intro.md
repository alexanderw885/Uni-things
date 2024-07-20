## Basics
compiled language, industry standard for graphics

it's a pain to compile many files together, so make systems make this easier. For this class, we use CMAKE

it can be used as an extension of C, or as it's own object-oriented languages

#### Compared to java
unlike java, you can define functions outside of a class. Main **must** be outside of a class
Has something called templates, similar to generics in java
C++ has multiple inheritance
in C++, you can define C types. In Java, all user defined types are classes

Java has no pointers, C++ has explicit pointers and references (don't need pointers much in this class)

### References
this can be used to ensure you don't pass copies of variables into functions

```int&p;``` does not work
```c++
int a;
int& x = a;

// In a function call
int example(int &x, int &y){
	return x + y;
}

int main(){
	int a = 10;
	int b = 12;
	std::cout << example(a,b) << std::endl;
}
```
now x acts like a variable, ```p=15;``` changes the value of a
this means you can pass primitive types into functions instead of copies

References are safe, use them instead of pointers

### Classes
put declarations of classes in header, actual code in classes
```C++
// Filename: point.h
class point{
	float x; float y;
	void print();
	void set(float x0, float y0);
	point(float x0, float y0);
};
//----------------------------------
// Filename: point.c
#include "point.h"
...
```

### Dynamic and static binding
if you want to do polymorphism, declare the function virtual
```
virtual void methis(int a){}
```

### Objects
created like variables, but destroyed when p goes out of scope
```C++
Point p; //good, no parenthesis if no args
Point p(2.5, 3.3); //good, don't say new
```

using operated new, don't get deleted when out of scope. You have to manually delete these, try not to do this
```C++
Point*p = new Point;
```
this can cause memory leaks!

### Inheritance
```C++
class child : public parent
{
	public:
		float z;
		point3d(floatx, float y, float z) : point(x,y)
		{z = z0}
};
```

### Operator Overloading
lets you call a new function using standard operators

### Types of lists
vectors are like python lists
lists are double linked lists
arrays must define length at compile time

### Lambda function
create function that's treated like a variable
```c++
program.Example = [](int i, int j)
{
// function
}; // note the semicolon
```
![[Pasted image 20240711104100.png]]

## Eigen
how to use Eigen/Dense
#### Vectors
vector addition with +, -
scalar multiplication with \*, /

```Eigen::vector2d``` means 2 dimensional vector of *doubles*
```Eigen::vector2i``` means 2 dimensional vector of *integers*
and so on

to get length of vector a: ```a.norm()```
```a.normalize()``` sets length of a to 1
```a.normalized()``` returns a vector of length 1 in the direction of a

$a^T$ = ```a.transpose()```
```a.dot(b) == a.transpose()*b``` for dot product
in class, $a*b$ will be shown as $<a, b>$

given 3 dimensional vectors,
```v.cross(x)``` for cross products

#### Matrices
matrix addition with +, -
scalar multiplication with \*, /
matrix multiplication is ```A*B```

transposition
```c++
B = A.transpose();
A.transposeInPlace();
```
note: $(AB)^T=B^TA^T$

as long as A is small-ish, under 10x10:
```A.inverse()```
$(AB)^{-1}=B^{-1}A^{-1}$

Diagonal
```D = A.asDiagonal```

**If you want to solve a linear system $Ax=y$, use a direct solver**
```c++
Matrix3f A;
Vector3f b;
Vector3f x; 

x = A.colPivHouseholderQr().solve(b);
```
or, you could use:
```c++
Matrix3f A;
Vector3f b;
Vector3f x;

Matrix3f C = A.inverse();
x = B*b
```
but this is slower

#### Intersecting lines in code
points P1, P2 for line 1
points L1, L2 for line 2       