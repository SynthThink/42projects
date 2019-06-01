## Repository for various projects made at 42 Paris as part of the cursus

### Push_swap

The goal of the project is to create two programs. One program (push_swap) will take as an input an unordered list of numbers and will output a serie of operations to sort them.
The sorting will happen through using two stacks, one that will initialy contain the unordered list and the other which is empty. 
<br/>The main operations are rotating the pile (first become last or inverse) and pushing the top element to the second stack (or inverse).

Due to these constraints it is not possible to directly take well-known sorting algorithms.
This project uses an algorithm that is alike 'selection sort', it pushes to the second stack the elements that are close 
to the minimum or maximum and once the stack B is full it finishes the sort while pushing to the stack A.

<img src ="http://g.recordit.co/Nk7tF2PpJJ.gif" width =500 height =420/>

#### Installation
***Only works on MacOS with provided library***<br/>
To install simply type: `make`<br/>
OpenGL has to be installed as it is required by the MLX library.<br/>

#### Usage
An example of usage using ruby:<br/>
`ARG=`ruby -e "puts (-150..149).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG`
