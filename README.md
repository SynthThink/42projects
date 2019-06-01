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

### Piscine php
Intensive 2 weeks work to learn the essentials of php, html/css, mysql and introduction to javascript.

* Day00 : HTML/CSS
* Day01 : Basics of PHP
* Day02 : PHP + Regex
* Day03 : PHP POST, GET, SESSION + use of local server
* Day04 : PHP POST, GET, SESSION (basic login/auth, prototype for a chat)
* Rush00 : Two days to make a crude e-commerce website with PHP and MYSQL database. Main features: Differents products that can be filtered and dynamically added/modified. Accounts management, possibility to order and keep track of preceding orders. Admin panel with user/product management etc.
* Day05 : Mysql
* Day06 : Introduction to object-oriented programming with PHP
* Day07 : Object-oriented programming with PHP
* Day09 : Introduction to js, jquery and AJAX. 

### ft_ls
The goal of the project is to make an implementation of the POSIX command ls with several options such as recursive -R in order to familiarize oneself with the filesystem.

#### Installation
To install simply type: `make`<br/>

#### Usage
`ft_ls [-1Raglrtu] [file ...]`


### ft_printf
Implementation of the printf function which is widely available in many programming languages. This implementation aims to be close to the MacOs implementation in C.

Supported conversions: 
* integers : `DiouxX` floats: `fF` 
* strings: `sS` char: `cC` 
* addresses: `p`

Options availables:
* `-+0 #`
* minimum-length `[0-9]*`
* precision `.[0-9)*`
* size of conversions `hh, h, l, ll, z, j, L`

