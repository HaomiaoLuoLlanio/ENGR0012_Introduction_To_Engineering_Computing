%[text] # Week 3 Worksheet (Interactive, Optional to Try and Study)
%[text] The worksheet is a comprehensive summary of the lecture material, organized into Live Script sections. Concise comments are added where needed to clarify difficult topics. You can request to access the solution or simply ask to address your concerns.
%%
%[text] ## Review: Access/Modify Individual Elements in Vector and Matrix
%%
%[text] Let's build a large matrix first
% TODO: Create a 6x6 matrix named A_large with the following values:
% 0.1, 0.02, 0.3, 40, 5, 600
% 8, 9, 11, 12, 13, 16
% 1, -2, 4, -8, 5, -9
% -67, -90, 3, 5.89, 5.12, 611
% 36, 100, 31, 7, 3, 6.11
% -1.414, 3.1415, 2.8, 90, 3.45, 6.189

%%
% TODO: Access rows 1&2 and columns 1&2 of A_large

%[text] You notice that we just extract the first two rows and first two columns of the matrix
%%
% TODO: Extract rows [1, 5, 6] and columns [3, 4] from A_large

%[text] This time, we extract the (1st & 5th & 6th rows) and (3rd & 4th columns) of the matrix
%%
% Recall that 2:5 = [2,3,4,5] and 2:2:6 = [2,4,6]
% TODO: From 2 to 5th rows, extract the 4th column

%%
% TODO: From the 1st row, extract columns from 2 to 6 with increment of 2 (every other column)

%%
% TODO: From rows 2 to 5, extract columns from 2 to 6 with increment of 2

%%
% One more useful feature of using colon
% TODO: Extract all columns from row 2 using the colon operator

%%
% TODO: Extract all rows from column 6 using the colon operator

%[text] When you use `:` in the row or column position, MATLAB returns all entries along that dimension
%%
%[text] ### Bulk Modification
%%
% TODO: Set all elements in column 6 to the value 8, then display A_large

%%
% TODO: Set rows [4, 5] in column 6 to values [9; 10]

%%
% TODO: Set row 1, columns [4, 5, 6] to values [412, 413, 414]

%%
%[text] ### Modify Out-of-bound
% Try to access out-of-bounds element
% A19 = A_large(1,9)
% A82 = A_large(8,2)
%%
% TODO: Modify the element at position (1, 9) to 3.14 (this is out of bounds!)

%%
% TODO: Modify the element at position (8, 2) to 3.14 (this is also out of bounds!)

%%
% TODO: Display A_large to observe what happened

%[text] An attempt to modify an out-of-bound element will increase the size of the matrix and fill the unassigned elements with 0s
%%
% TODO: Try accessing A_large(:, :) - what do you get? (No need to access in such a way, but the same as A_large)

%%
%[text] ## Concatenating Vectors, Matrices
%[text] Sometimes you need to combine smaller matrices into larger ones.
%[text] Use `vertcat()` to stack vertically (top and bottom) or `horzcat()` to stack horizontally (side by side).
%%
% TODO: Create a 2x2 matrix A with values [1 2 // 3 4]

%%
% TODO: Create a 2x2 matrix B with values [5 6 // 7 8]

%%
% TODO: Vertically concatenate A and B using vertcat() and store in C_vertcat
% (Hint: shorthand is [A;B])

%[text] Did you get the result:
%[text] 1  2
%[text] 3  4
%[text] 5  6
%[text] 7  8
%%
% TODO: Create a 3x2 matrix D with values [100, 200; 100, 300; 100, 400]

%%
% TODO: Vertically concatenate C_vertcat and D using vertcat()

%%
% TODO: Now try vertically concatenating D on top of C_vertcat (order matters!)

%%
% TODO: Horizontally concatenate A and B using horzcat() and store in C_horzcat
% (Hint: shorthand is [A,B])

%[text] Did you get the result:
%[text] 1  2  5  6
%[text] 3  4  7  8
%%
%[text] **Important dimension requirements:**
%[text] - For `vertcat(A, B)`: A and B must have the **same number of columns**
%[text] - For `horzcat(A, B)`: A and B must have the **same number of rows** \
%%
%[text] Quick checks:
%[text] - Try `vertcat(A, D)`
%[text] - Try `horzcat(A, D')`
%[text] - What error did you obtain? \
%%
%[text] ## Converting Numbers to Strings (num2str) and Display
%[text] When you want to display numbers along with text, you need to convert them.
%[text] `num2str()` converts a number into a string format.
%[text] Try course\_num = 12 and converted = num2str(course\_num) to verify the two variables' types
% TODO: Define a variable course_num and assign it the value 12

%%
% TODO: Convert course_num to a string using num2str() and store it in a variable named converted

%%
% TODO: Display 'I ', 'enjoy ', and 'MATLAB ' together using horizontal concatenation [ , , ]

%%
% TODO: Use horzcat() to display 'I ', 'enjoy ', and 'MATLAB ' together

%%
% TODO: Use num2str() to combine 'From ', 'ENGR', and course_num to obtain 'From ENGR12'

%%
% TODO: Find a way to combine strings to obtain 'I enjoy MATLAB from ENGR12'

%%
%[text] ## Unexpected Display (Should Avoid)
%%
% TODO: Create a variable A with value 5.145

%%
% TODO: Try displaying ['The value of A is: ', A] - what happens?

%%
% TODO: Try displaying ["The value of A is: ", num2str(A)] - what's different?

%%
% Should not try to assign something to disp; below are two warning cases
% (won't trigger an error)
% disp = ['The value of A is 5.145']
% disp = ('The value of A is 5.145')
%%
%[text] ## Rounding Numbers
%[text] Different rounding functions give different results.
%[text] Use `round()` for the nearest integer, `ceil()` for always rounding up, `floor()` for always rounding down.
%[text] num = 3.1415926;
% TODO: Round num to the nearest integer using round()

%%
% TODO: Round num up using ceil()

%%
% TODO: Round num down using floor()

%%
% TODO: Round num towards zero using fix() (i.e., removing all decimal places)

%%
% TODO: Create matrix_r = [0.5001, -0.4999; 1.501, 1.999]
% TODO: Try round(), ceil(), floor(), and fix() on matrix_r to see how they work element-wise

%%
%[text] ## Random Numbers
%%
% TODO: Generate a single random number between 0 and 1 using rand, store in variable r

%%
% TODO: Generate a row vector of 5 random numbers between 0 and 1, store in rand_vec

%%
% TODO: Generate a 3x2 matrix with random numbers between 0 and 1, store in rand_mat

%%
% TODO: Generate a random integer between 1 and 100, store in randi_num

%%
% TODO: Generate a row vector (1x5) of random integers between 1 and 100, store in randi_num_vec

%%
% TODO: Generate a square matrix (3x3) of random integers between 1 and 100, store in randi_num_mat

%%
% TODO: Generate a row vector (1x8) of random integers between -10 and 15, store in randi_range_mat

%%
%[text] **Pattern Recognition**
%[text] - `somefunc(p, n)` or `somefunc(n)` creates an n × n matrix (p usually controls type or values, not the size)
%[text] - `somefunc(p, n1, n2)` or `somefunc(n1, n2)` creates an n1 × n2 matrix, e.g., ones/zeros/rand/randi \
%%
%[text] ## Statistics Functions
%%
% TODO: Generate a row vector of 55 random integers from 60 to 100, store in variable grades
% Assume it is the final grade of some ENGR12 course

%%
% TODO: Find the average of grades using mean() and store in avg_grd
% TODO: Find the median of grades using median() and store in median_grd
% TODO: Find the mode of grades using mode() and store in mode_grd
% TODO: Find the standard deviation of grades using std() and store in stdev_grd
% TODO: Find the variance of grades using var() and store in var_grd

%%
% TODO: Find the range of grades using range() and store in range_grd
% TODO: Find the 25th percentile using prctile(grades, 25) and store in percentile_25
% TODO: Find the 75th percentile using prctile(grades, 75) and store in percentile_75

%%
%[text] ## Saving and Loading Data
%[text] MATLAB can save variables for later use, storing them in `.mat` files by default.
%[text] For greater compatibility or plain-text viewing, data can also be saved to `.csv` or `.txt` files using `save('file_name.ext','var_name','-ascii’)`
% TODO: Create a column vector sample_vec with 5 random integers from 60 to 100

%%
% TODO: Create a 4x4 matrix sample_mat with random values using rand(4)

%%
% TODO: Save sample_vec to 'sample.txt' in ASCII format
% TODO: Save sample_mat to 'sample.csv' in ASCII format

%%
% TODO: Clear the current workspace using clear

%%
% TODO: Load content from 'sample.txt' into variable loaded1 using load()
% TODO: Load content from 'sample.csv' into variable loaded2 using load()

%%
%[text] ## Input and Exist Functions
%%
%[text] User inputs a number
% TODO: Prompt user to input x between 1~4 and store in variable x
% TODO: Prompt user to input y between 1~4 and store in variable y

%%
%[text] User inputs a string
% TODO: Prompt user to input a file name and store it in fname (use 's' option for string)

%%
%[text] Suppose you have created a sample.csv and put some data inside.
%[text] Suppose you also have created a sample.txt and put inside
%%
% Let's try to load the content from fname into a vector
% You can use res = load(fname), but not load("fname")

% You can use res = load("sample.txt"), but not load(sample.txt)

%%
% TODO: Create a variable fname2 with the value "sample.txt"
% TODO: Use exist() to check if fname2 is a file and display the result

%%
%[text] **Literal and Variable Differences**
%[text] A **literal** is a value written **directly** in the code.
%[text] `5, 3.14, 'hello', [1 2 3]`
%[text] - It does **not** have a name.
%[text] - You cannot change it, e.g. you cannot assign 5 = 4 or 'hello' = 'hi' \
%[text] A **variable** is a **named container** that stores a value.
%[text] `x, approxi_pi, name, row3`
%[text] - The name refers to the data (would cause error if no value stored there)
%[text] - The value **can change**. e.g. you can assign such as hello = 'hi', A5 = 4 \
%%
% TODO: Load the content of "sample.csv" into variable result

%%
% TODO: Display a message showing: 'The element you inquired at Row [x] Column [y] of file [fname] is: [value]'
% Use result(x, y) to get the element value

%%
%[text] You can use the exist() function to check if something already exists, e.g., a variable or a file
%[text] In this course, we only care whether a file exists.
% TODO: Check if "abc123.m" exists as a file using exist() and display the result (what value do you get?)

%%
%[text] ## Loop Prerequisite: Relational Operators
%[text] - == is equivalence
%[text] - ~= is non-equivalence
%[text] - In almost all programming languages, one single equal-sign means "Assignment": assign RHS to LHS
%[text] - Double equal-signs means "Check Equivalence" \
% Create a variable a with value 5
% Create a variable b with value 10

% TODO: Create f1 to store the result of (a > b) - should be false
% TODO: Create f2 to store the result of (a < b) - should be true
% TODO: Create f3 to store the result of (a == b) - should be false
% TODO: Create f4 to store the result of (a ~= b) - should be true
% TODO: Create f5 to store the result of (a >= b) - should be false
% TODO: Create f6 to store the result of (a <= b) - should be true

%%
%[text] ## Logical Operators (&&, ||, ~)
%[text] - Both statement 1 AND statement 2 are true:  s1 && s2
%[text] - At least one of statement 1 OR statement 2 is true:  s1 || s2
%[text] - NOT statement 1 is true:  ~s1 \
%%
% TODO: Create f7 using f2 && f4 (both f2 and f4 are true, so f7 should be true)

%%
% TODO: Create f8 using f2 || f3 (at least one is true, so f8 should be true)

%%
% TODO: Create f9 using ~f2 (NOT f2, so f9 should be false since f2 is true)

%[text] Only expressions of logical class can be placed after if or while. These are referred as conditional statements, e.g., f1, f2, f3, … f7, f8, f9 
%%
%[text] ## If-end statement, If-else-end statement
%%
% TODO: Write an if-end statement to check if a == 9, and display 'a is equal to 9' if true

%%
% TODO: Write an if-else-end statement to check if a > b
%       If true, display 'a is greater than b'
%       Otherwise, display 'a is not greater than b'

%%
% TODO: Write an if-else-end statement using f2 as the condition (same as putting a<b)
%       If true, display 'a is less than b'
%       Otherwise, display 'a is not less than b'

%%
%[text] ## If-elseif-else-end statement
%[text] <u>if (Condition 1)</u>
%[text]  do thing 1
%[text] elseif (Condition 2)  % When you are here, it must mean Condition 1 is false
%[text]     do thing 2
%[text] elseif (Condition 3) % When you are here, it must mean Condition 1 and Condition 2 are both false
%[text]     do thing 3
%[text] ......
%[text] else
%[text]     do thing n
%[text] <u>end</u>
%%
% Temperature Control Example
% TODO: Create a variable temperature with value 75

% TODO: Write an if-elseif-else-end statement:
%       If temperature < 60, display 'The temperature is cold.'
%       Else if temperature <= 90, display 'The temperature is moderate.'
%       Otherwise, display 'The temperature is hot.'

%%
% Another example with user input
% TODO: Prompt user to input a temperature and store in temp
% TODO: Write an if-elseif-else-end statement:
%       If temp < 60, display 'The temperature is cold.'
%       Else if temp >= 60 && temp <= 90, display 'The temperature is moderate.'
%       Otherwise, display 'The temperature is hot.'

%%
%[text] ## Switch Case
%[text] <u>switch</u> (var)
%[text]         case value1 
%[text]                 statement1 
%[text]         case value2 
%[text]                 statement2 
%[text]         case {value3, value4}
%[text]                 statement x
%[text]         otherwise
%[text]                 other\_statement
%[text] <u>end</u>
% TODO: Prompt user to enter a number (1-7) to represent the day of the week and store in day

% TODO: Write a switch-case-end statement:
%       case 1: display 'Monday'
%       case 2: display 'Tuesday'
%       case 3: display 'Wednesday'
%       case 4: display 'Thursday'
%       case 5: display 'Friday'
%       case {6, 7}: display 'Weekends'
%       otherwise: display 'Invalid input. Please enter a number between 1 and 7.'

%%
%[text] ## While-loop
%[text] You don't know how many iterations in advance (it depends on termination conditions!)
%[text] 
%[text] `while (condition)`
%[text]          Statement block that must change the condition 
%[text] `end`
%[text] **Infinite-loop safety:**
%[text] - If your `while` condition never becomes false, the loop will run forever.
%[text] - To stop a stuck loop while running:
%[text] -  - Windows: `Ctrl + C`
%[text] -  - Mac: `Command + .` \
%[text] **Enter the while-loop by checking the condition:**
%[text] - if false, skip the entire loop
%[text] - if true, execute the statement block, then check the condition again.
%[text] - If the condition is still true, execute the statement block again. Otherwise, exit the while-loop \
% Example: eat buffet
% TODO: Create a variable full_stomach with value 25 (representing 25 plates)
% TODO: Write a while loop that continues while (eaten < full_stomach):
%       - Prompt the user to input how many plates they want to eat, store in plates
%       - Add plates to eaten

% TODO: After the loop, display 'You are finally full and ate [eaten] plates!'

%%
%[text] #### Example 1: Go through vector elements via index i and access
% TODO: Create a vector vec with 9 random integers from -5 to 5

% TODO: Create a variable i with initial value 1
% TODO: Write a while loop that continues while i <= length(vec):
%       - Display vec(i)
%       - Increment i by 1

%%
%[text] #### Example 2: Go through vector elements and update
% TODO: Create a vector xnew from 1 to 10
% TODO: Create a vector fxnew of zeros with the same length as xnew

% TODO: Create a variable j with initial value 1
% TODO: Write a while loop that continues while j < length(fxnew) + 1:
%       - Set fxnew(j) to j*j
%       - Increment j by 1

%[text] Trace the above while-loop:
%[text] - xnew = \[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10\], fxnew = \[0, 0, 0, 0, 0, 0, 0, 0, 0, 0\] \
%[text] - At j=1, 1\<11 is true:
%[text] - Enter loop for the first time, fxnew(1) = 1\*1 = 1
%[text] - \[1, 0, 0, 0, 0, 0, 0, 0, 0, 0\]
%[text] - j is incremented to 2 \
%[text] - At j=2, 2\<11 is still true
%[text] - Enter loop for the second time, fxnew(2) = 2\*2 = 4
%[text] - \[1, 4, 0, 0, 0, 0, 0, 0, 0, 0\]
%[text] - j is incremented to 3 \
%[text] - ...
%[text] - fxnew(10) = 10\*10 = 100
%[text] - \[1, 4, 9, 16, 25, 36, 49, 64, 81, 100\]
%[text] - j is incremented to 11 \
%[text] - At j=11, 11\<11 is false
%[text] - Exit loop \
%%
%[text] #### Example 3: Error-checking until user gives a valid number
% TODO: Prompt user to enter a year between 2000 and 2050, store in inputYear

% TODO: Write a while loop that continues while (inputYear < 2000 OR inputYear > 2050):
%       - Keep prompting for a valid year

%%
%[text] #### Example 4: Input inside loop to record preference of running again
% TODO: Create a variable run_choice with initial value 'y'

% TODO: Write a while loop that continues while run_choice is not equal to 'n':
%       - Display 'You finished some tasks here!'
%       - Prompt user to input 'y' or 'n' to run again (use 's' option), store in run_choice

%%
%[text] ## More Error-checking Patterns
%[text] A common strategy is to write the loop condition as a **failure condition** (invalid cases). The loop keeps repeating while the input is invalid.
%%
%[text] Example 1 (range check): Desired $&dollar&;1 \\le x \\le &dollar&;4$
%[text] Failure condition (undesired): $&dollar&;(x \< 1) || (x \> 4)&dollar&;$
% TODO: Prompt user to enter a number from 1 to 4, store in x_range

% TODO: Write a while loop that continues while (x_range < 1) OR (x_range > 4):
%       - Keep prompting for a valid number

%%
%[text] Example 2 (specific values): only accept 'y' or 'n'
%[text] \[Failure condition (invalid): usr\_str ~= ‘y’ && usr\_str ~= ‘n’\]
% TODO: Prompt user to enter only 'y' or 'n' (use 's' option), store in usr_str
% TODO: Write a while loop that continues while (usr_str is not 'y' AND usr_str is not 'n'):
%       - Keep prompting for valid input

%%
%[text] Example 3 (filename validation): only accept an existing filename
%[text] \[Failure condition (invalid): file doesn’t exist\]
%[text] Tip: `exist(filename, 'file')` returns 0 when the file doesn't exists.
% TODO: Prompt user to enter a filename that exists (use 's' option), store in filename

% TODO: Write a while loop that continues while exist(filename, 'file') == 0:
%       - Keep prompting for a valid filename

%%
%[text] ## For-loop
%[text] 
%[text] You know how many iterations in advance
%[text] `for var = start:increment:end` 
%[text]          statement block
%[text] `end`
%[text] or
%[text] `for var = start:end`
%[text]          statement block
%[text] `end`
%[text] or
%[text] `for var = [x1 x2 x3 ...]`
%[text]          statement block
%[text] `end`
%%
%[text] #### Example 1: Use for-loop to go through vector elements
% TODO: Write a for loop where x takes values [0, pi/4, pi/2, 3*pi/4, pi]:
%       - Display sin(x) for each value

%%
%[text] #### Example 2: Use for-loop to update vector elements
%%
% TODO: Create a vector vec_initial of ones with the same length as xnew

% TODO: Write a for loop where i goes from 1 to length(vec_initial) with increment of 2:
%       - Set vec_initial(i) to 0.01 * i

%%
%[text] Trace the above for-loop:
%[text] - Initially vec\_initial is all ones \[1 1 1 1 1 1 1 1 1 1\]
%[text] - i takes values in order of 1, 3, 5, 7, 9 \
%[text] - when i = 1, vec\_initial(1) = 0.01 \* 1 = 0.01
%[text] - \[0.01 1 1 1 1 1 1 1 1 1\] \
%[text] - The loop continues and get into the 2nd iteration
%[text] - now i = 3, vec\_initial(3) = 0.01 \* 3 = 0.03
%[text] - \[0.01 1 0.03 1 1 1 1 1 1 1\] \
%[text] - ... \
%[text] - The last iteration when i = 9, vec\_initial(9) = 0.01 \* 9 = 0.09
%[text] - \[0.01 1 0.03 1 0.05 1 0.07 1 0.09 1\] \
%%
%[text] #### Example 3: Summation ($\\sum$) and Product ($\\prod$)
%[text] Summation form:
%[text] $S = \\sum\_{i=1}^{n} a\_i$
%[text] $$$$Product form:
%[text] $P = \\prod\_{i=1}^{n} b\_i$$$
% TODO: Create a vector a with values [2, 4, 6, 8]

% TODO: Initialize S to 0
% TODO: Write a for loop where i goes from 1 to length(a):
%       - Add a(i) to S

% TODO: Verify your result using builtin sum

%%
% TODO: Create a vector b with values [1, 3, 5, 7]

% TODO: Initialize P to 1
% TODO: Write a for loop where i goes from 1 to length(b):
%       - Multiply P by b(i)

% TODO: Verify your result using builtin product

%%
%[text] #### Example 4: compute $&dollar&;\\sum\_{i=1}^{n} \\frac{1}{i}&dollar&;$ using a for-loop
% TODO: Set n to 5000
% TODO: Display S_rep as above equation

% TODO: Display log(n+0.5)+0.5772 to compare

%%
%[text] #### Example 5: Use for-loop to manually find the extreme in a vector
% TODO: Create vec_unsorted with 20 random integers from -50 to 50

% TODO: Initialize largest to vec_unsorted(1)
% TODO: Write a for loop where i goes from 2 to length(vec_unsorted):
%       - If vec_unsorted(i) is greater than largest, update largest to vec_unsorted(i)

% TODO: Display largest

%%
%[text] ## Loops: When to Use (and When Not to Use)
%[text] Loops let you repeat the same block of code multiple times.
%[text:table]
%[text] | Use loops when... | Don't use loops when... |
%[text] | --- | --- |
%[text] | You need error checking (keep asking until input is valid). | You only need to run something once. |
%[text] | You are doing a summation/product (e.g., $\\sum$ or $\\prod$). | You're implementing branching logic (use `if-else` / `switch`). |
%[text] | You need to update/manipulate elements in an array/matrix repeatedly. | A MATLAB built-in function already solves it cleanly. |
%[text] | You would otherwise copy/paste the same lines many times. |  |
%[text:table]
%%
%[text] ## For-loop vs While-loop
%[text:table]
%[text] | For-loop | While-loop |
%[text] | --- | --- |
%[text] | Use when you know how many iterations (or the range) in advance. | Use when you don't know how many iterations in advance. |
%[text] | Great for iterating through ranges, arrays, and matrices. | Great for user input + error checking. |
%[text] | Condition is usually a range like `1:10` or `1:2:n`. | Condition is usually a logical test like `(x < 1) || (x > 5)`. |
%[text] | Error checking is possible, but often less natural than `while`. | Natural choice for error checking (repeat until valid). |
%[text:table]
%%
%[text] ## Challenging Practices
%%
%[text] (1) Try to use a for-loop to find the average of all vector entries whose value is \>25
% Use vector created above

%%
%[text] (2) Try to find the largest square number in the range \[2000, 2050\]
%[text] 
%[text] Hints: initialize result = 0
%[text] Start from x=2000, if 2000 is a square number, update result = 2000
%[text] Increase x by 1, if 2001 is a square number, update result = 2001
%[text] ...
%[text] Increase until x=2050, if 2050 is a square number, update result = 2050
%[text] A number is a square number if it is the result of some integer squared (in other words, its sqrt result is a whole number)
%[text] A whole number is a number whose rounding value is the same as itself.
% 

%%
%[text] ## Trace Problem
%[text] 
%[text] a = 1;
%[text] b = 7;
%[text] num = 0;
%[text] initial = 199
%[text] while a \<= b
%[text]     if mod(initial, 2) == 1
%[text]         initial = (initial - 1) / 2;
%[text]     else
%[text]         initial = initial / 2;
%[text]     end
%[text]     num = num + 1;
%[text]     disp(\['Division times: ', num2str(num)\]);
%[text]     a = a + 1;
%[text]     b = b - 1;
%[text] end
%[text] last = initial
%[text] disp('Done');
%[text] 
%[text] **Answer:** 
%[text:table]{"ignoreHeader":true}
%[text] |  |
%[text] | --- |
%[text] |  |
%[text] |  |
%[text] |  |
%[text] |  |
%[text] |  |
%[text] |  |
%[text:table]
%[text] 
%[text] **Scratch work** to track all variables' value <u>*(!!! this is not solution, just your thoughts!!!)*</u>
%[text:table]{"ignoreHeader":true}
%[text] | Change of a: | 1 |  |  |  |  |
%[text] | --- | --- | --- | --- | --- | --- |
%[text] | Change of b: | 7 |  |  |  |  |
%[text] | Change of num: | 0 |  |  |  |  |
%[text] | Change of initial: | 199 |  |  |  |  |
%[text:table]
%[text] 

%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"inline","rightPanelPercent":37.1}
%---
