Task 1: Define an affine transformation
An affine transformation takes a single point in space and applies a linear transformation
matrix and translation, mapping to the point to a new location in space. The parameters of a
2D affine transform are the four elements of the transformation matrix m00, m01, m10 and m11
and the two translation terms dx and dy. Write a C++ class to represent the parameters of an affine transformation, including
suitable constructors and accessors.

Task 2: Implement a transformation function
When an affine transformation is applied to a point (x,y), the transformed point (x’,y’) is
defined by the following equations:

x’ = m00x + m01y + dx
y’ = m10x + m11y + dy

In matrix form this can be expressed as:

x’ = Mx + δ

Write a C++ function to apply an affine transformation to a point.

Task 3: Inverse transformations
The inverse of an affine transform reverses the effect of the transformation, for example
(x’,y’) would be transformed back to (x,y). The parameters of the inverse transformation,
m00’, m01’, m10’, m11’, dx’ and dy’, are given by the following equations:

m00’ = m11 / (m00m11 - m01m10)
m01’ = - m01 / (m00m11 - m01m10)
m10’ = - m10 / (m00m11 - m01m10)
m11’ = m00 / (m00m11 - m01m10)
dx’ = - dx * m00’ - dy * m01’
dy’ = - dx * m10’ - dy * m11’

Write a C++ function to compute the inverse of an affine transformation.

Task 4: Combine transformations
Two affine transformations can be composed into a single affine transformation. In matrix
form, the combined parameters M’ and δ’ can be written in terms of the two transforms
(M1,δ1) and (M2,δ2) as:

M’ = M1M2
δ’ = δ1 + M1δ2

Write a function or operator that combines two affine transformations.
