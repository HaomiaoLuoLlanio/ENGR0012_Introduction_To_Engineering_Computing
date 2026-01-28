%[text] # Week 2 Worksheet (Interactive, Optional to Try and Study)
%[text] The worksheet is a comprehensive summary of the lecture material, organized into Live Script sections. Concise comments are added where needed to clarify difficult topics. You can request to access the solution or simply ask to address your concerns.
%[text] 
%[text] ## Variables in MATLAB
%[text] A variable is a place in computer memory where data is stored and can later be referenced by a particular name that we assign.
%[text] Variables can be defined in both the ***C******ommand Window*** or a ***S******cript Window*** (live script window), depending on the user’s needs. All variables that we create will be reflected in the ***W******orkspace Window***, which helps us keep track of variable definitions and their current values. Variable created in Command Window For example, in the command window, let's create the variable `alpha`
% Try x=4 in Command Window
%%
% Variable created in (Live) Script Window
% For example, in this window (the following block), let's create the variable beta
%%
% Try y=2 in this block and click run section

%%
% Variable can be modified
% Let's modify the variable x to be 4.12

%%
% Variable Echo and Suppress
% Output can be suppressed by adding a semicolon to terminate the line of code. 
% For example, if you define |z = 412| and add a semicolon

%%
%[text] The same if you define z `= 8.7` in the ***C******ommand Window*** and add a semicolon
% Try z=8.7; in Command Window

%%
%[text] Note that these suppressed variables are still defined in the ***W******orkspace*** Scalar Computation Adding the values stored in x and y. Run x `+ y` without a semicolon
% Try adding x and y

%%
%[text] `ans` is the default variable used by MATLAB to temporarily hold the results of a calculation when the final result is not stored in a variable. Note that `ans` has now been defined as a variable since it exists in our workspace. By "temporarily", it means its contents are rarely accessible and can very easily be overwritten.
% Try adding x and z; 
% and on the next line, adding x and z

%%
%[text] Now, where is the sum result of x `+ y?` 
%%
%[text] ## Scalar vs. Vector vs. Matrix
%[text] MATLAB also allows us to store data as a one-dimensional vector or a two-dimensional matrix. These are defined similarly to scalars using the assignment operator `=`.
%[text] Let's define `A` to be a vector of 1, 5, 6, 8.
% Define A in this block

%%
%[text] We see now that variable `A` exists in our workspace. and it shows `1x4,` referring to the dimensions: one row and four columns of data.
%[text] Let's redefine `A` to be a **row vector** of 1.2 -87 3.5 7.8 -12
% Define A in this block but with space instead of comma

%%
%[text] It has been changed to one row and five columns.
%[text] To be consistent, let's not create a row vector using both comma and space to delimit, although there is no error to do so.
%%
%[text] Let's define B to be a **column vector** of 100 200 300
% Define B in this block

%%
%[text] Note that it is separated by semicolon ;
%%
%[text] If we want to create a matrix: C = 1 2 3; 4 5 6, like 2 rows, 3 columns
% Define C in this block

%%
%[text] How to check whether C really has **2 rows and 3 columns**, instead of 3 rows, 2 columns;
% check C's dimension here

%%
%[text] A matrix cannot have mismatched dimension on different rows,  e.g. 1 2 3 4 ; 7 8 9 ; 10 11 12 13
% Attempt to Make C to be 1 2 3 4; 7 8 9; 10 11 12 13

%%
%[text] ## Char and Strings
% You can assign char 'A' to a variable var1, as well as string "abcd" to a
% variable var2

%[text] Check Workspace window for the `var1, var2` values and their Class type
%%
%[text] Note that this is different than assign A to var1, which would just copy variable A's value to var1
%[text] Check Workspace windown for `var1` and its Class type again!
% copy variable A to var1

%%
%[text] ## Create, Run, Save m-files (Scripts)
%[text] An m-file is a script or function saved with a .m extension. It allows you to save your code and run it as a script. 
%[text] To create an m-file, follow these steps:
%[text] 1. Open MATLAB and go to the Home tab. 
%[text] 2. Click on "New Script" to open the editor.
%[text] 3. Write your MATLAB code in the editor. 
%[text] 4. Save the file with a .m extension, for example, `abc123.m`.
%[text] 5. To run the script, you can either click the "Run" button in the editor or type the name of the script (without the .m extension) in the Command Window and press Enter. \
%%
% Let's create a simple script that calculates the sum of two numbers and displays
% the result. Save the following code in a file named `abc123.m`:

% r = 5;
% area = pi*r*r
%[text] To run the script, type `abc123` in the Command Window and press Enter.
%%
%[text] To save an m-file, use the "Save" button in the editor or press Ctrl+S.
%[text] You can find m-files in the Current Folder window or by using the `dir` command in the Command Window.
%%
%[text] ## Incorporate Comments in Code
%[text] Comments are added using the % symbol. Everything after % on the same line is ignored by MATLAB.
%[text] For example:
% This is a comment
% a = 5; % This is an inline comment
%%
%[text] ## MATLAB Variable Naming Conventions
%[text] Variable names in MATLAB must follow these rules: 
%[text] - Start with a letter. 
%[text] - Can contain letters, numbers, and underscores. 
%[text] - Cannot contain spaces or special characters. 
%[text] - Are case-sensitive (e.g., `Var` and `var` are different variables). \
% Examples of valid variable names:
% validVar1 = 10;  % Uncomment to try
% valid_var2 = 20; % Uncomment to try
% validVar3 = 30;  % Uncomment to try
%%
% Examples of invalid variable names:
% 1invalidVar = 40; % Starts with a number
% invalid-var = 50; % Contains a hyphen
% invalid var = 60; % Contains a space
%%
% MATLAB keywords cannot be used as variable names. For example:
% if = 70; % 'if' is a keyword
%%
%[text] It is good practice to use meaningful variable names that describe the data or purpose of the variable, instead of random names like x, y, z, etc.
%%
%[text] ## Basic Mathematical Operations
%[text] Examples of sqrt, abs, exp, log, log10, sum, prod, min, max, sort, rem, mod, sin, cos, tan
% sqrt: square root of a scalar, e.g., 16

%%
% sqrt_matrix will be a matrix with the square roots of 
% the original matrix elements [4, 9; 16, 25]

%%
% abs: absolute value of a number, e.g., -5

%%
% exp: exponential of a number, e.g., e to 1
% this is a way to get access to natural number e

%%
% exp(vector) will return the exponential of each element in the vector

%%
% log: natural logarithm of a number
% log(vector) will return the natural logarithm of each element in the vector

%%
% log10: base-10 logarithm of a number, verify that base-10 log of 100 is 2

%%
% sum: sum of elements in a vector 1 2 3 4

%%
% sum: sum of elements in a column vector 100 200 300

%%
% sum of elements in a matrix C = 1, 2, 3; 4, 5, 6
% find how to get [5, 7, 9], i.e., sum of all columns into a row vec

%%
% what if we want to sum the elements in each row? [6; 15]


% what if we want to sum the elements all together?


%%
% prod: product of elements in a vector 1 2 3 4

%%
% min: minimum value in a vector 1 2 3 4

%%
% You can also return not only the minimum value but also the index of the minimum value

%%
% max: maximum value in a vector 10 2 3 4

%%
% sort: sort elements in a vector 10 2 3 4

%%
% sort: sort elements in a vector 10 2 3 4 from large to small

%%
% rem: remainder after division, e.g., the remainder of 10/3 is 1
% the limit of rem is that it only works for integers

%%
% mod: modulus after division, the modulus of 10/3 is 1
% the limit of mod is that it only works for integers

%%
% sin: sine of an angle in radians

%%
% cos: cosine of an angle in radians

%%
% tan: tangent of an angle in radians

%[text] The above functions are just a few examples of the mathematical operations
%%
%[text] ## disp, clear, clc, display, path, addpath
% Random messy codes

%%
% A = 5.145, B = [4, 6; 9, 12], use disp() to screen instead of ;

%%
% Clear workspace

%%
% Clear command window

%%
%[text] Display all MATLAB search path for scripts. It will be a lot for MATLAB online
%[text] Comment below to test which script folder you can run now
% path
%%
%[text] Add a path, e.g. you want to run a script stored at this folder
%[text] Put the path name and comment below to add path
%%
% addpath("/MATLAB Drive/somefolder/");

%%
%[text] By default, MATLAB Drive root folder is already in the path
%[text] Adding a path is usually done with the GUI by either copying file to the working folder
%[text] Or right click the desired file and choose "add to path" on MATLAB desktop
%%
%[text] Another useful feature when working on ***Command Window***, you may use upper arrow ↑ to quickly retrieve your history commands.
%%
%[text] ## Linspace and Colon methods
% Create a vector 'v' with 101 linearly spaced points between 0 and 1

%[text] The first few elements of `v` would be v = \[0, 0.01, 0.02, 0.03, ..., 0.99, 1\]
%[text] Note the choice of 101, instead of 100.
%[text] Quiz yourself: linspace(0,1,5) would yield \[0, 0.2, 0.4, 0.6, 0.8, 1\] or \[0, 0.25, 0.5, 0.75, 1\]
%%
% Create a vector 'arr' with 6 linearly spaced points between 5 and 30
% The elements of 'arr' would be: arr = [5, 10, 15, 20, 25, 30]

%%
% Use : create a vector 'b' starting from 1 to 3 with a step size of 0.2

%[text] The elements of `b` would be: b = \[1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3\]
%%
% Show that : notation would stop at the last valid value

%%
%[text] ## Creating Ones and Zeros Matrices
% Creates a 3x3 square matrix filled with ones

%%
% Creates a 4x4 square matrix filled with zeros

%%
% Creates a 5x2 matrix filled with ones

%%
% Creates a 2x3 matrix filled with zeros

%%
% Creates a 4x4 identity matrix, use help to find what eye() does!

%%
%[text] #### Get the dimensions of arrays
%%
% “size” gives length of all matrix dimension
% “length” gives the length of largest array dimension
% try on the 5x2 matrix ones above

%%
%[text] ## Access/Modify Individual Elements in Vector/Matrix
%%
% Access the element in the 2nd row, 3rd column of matrix 5x2 matrix ones

%%
% Access the element in the 1st row, 1st column of matrix 5x2 matrix ones


%%
% Modify individual elements in an array
% Set the element in the 2nd row, 3rd column of matrix '5x2 matrix ones' to 10

%%
% Show the new matrix

%%
% Set the element in the 6th row, 1st column of matrix '5x2 matrix ones' to 5 

%%
% Show the new matrix

%%
%[text] ## Perform Matrix Operations
%[text] Given A = \[1 2; 3 4\], B = \[5 6; 7 8\]
%%
% Try Matrix (first) +-*/ scalar
% A+100, A-99, A*0.01, A/2

%%
% Try Scalar (first) +-* matrix
% 200+A, -20-A, 0.001*A

%%
% Element-wise operations + - .* ./ .^
% C_ele_add
% C_ele_sub
% C_ele_mul
% C_ele_div
% C_ele_power
%%
%[text] In Element-wise operations:
%[text] - A, B matrices have to match size \
%%
% Matrix multiplication, same as excel mmult
% C_mul

%%
% Show that A*B is not always equal to B*A

%[text] If A is in dimension `m*n`, B is in dimension `s*t`. Inner dimension n has to be equal to s (`n=s`) so that A\*B is feasible, and the result dimension is `m*t`
%%
% Find two methods of doing matrix transpose

%%
% Find two methods of doing matrix inverse

%%
% Verify that A_inverse * A, A * A_inverse is identity matrix

%%
% Verify A is invertible since the determinant ≠ 0


%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"inline","rightPanelPercent":26.4}
%---
