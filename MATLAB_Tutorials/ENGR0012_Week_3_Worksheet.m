%[text] # Week 3 Worksheet (Interactive, Optional to Try and Study)
%%
%[text] ## Review: Access/Modify Individual Elements in Vector and Matrix
%%
%[text] Let's build a large matrix first
A_large = [0.1 0.02 0.3 40 5 600;8 9 11 12 13 16;1 -2 4 -8 5 -9;-67 -90 3 5.89 5.12 611;36 100 31 7 3 6.11;-1.414 3.1415 2.8 90 3.45 6.189] %[output:8b2e9b69]
%%
%Try this first
A_large([1 2], [1 2]) %[output:334a59fd]
%[text] You notice that we just extract the the first two rows and first two columns of the matrix
%%
%Try this next
A_large([1 5 6], [3 4]) %[output:7c4c3c63]
%[text] This time, we extract the the (1st & 5th & 6th rows) and (3rd & 4th columns) of the matrix
%%
% Recall that 2:5 = [2,3,4,5]
% 2:2:6 = [2,4,6]

% Try these:
A_large(2:5, 4) % from 2 to 5th rows, 4th cols %[output:77dadd72]
A_large(1, 2:2:6) % 1st row, and from 2 to 6, extract every other cols, %[output:177c2064]
A_large(2:5, 2:2:6) %[output:5458b5ea]
%%
% One more useful feature of using colon
% Try this:
A_large(2,:) %[output:09ecc8fb]
A_large(:,6) %[output:8aa0f38f]
%[text] When putting just a colon on either row or column field of a matrix indexing, it returns all entries of that dimension
%%
%[text] #### Bulk Modify
%%
% Bulk modify the elements
A_large(:,6) = 8;
A_large %[output:2dda71b5]
%%
% Bulk modify the elements
A_large([4,5],6) = [9; 10]; 
A_large(1,[4,5,6]) = [412, 413, 414];
A_large %[output:3c99c4d5]
%%
%[text] #### Modify Out-of-bound
% Try to access out-of-bounds element
% A19 = A_large(1,9)
% A82 = A_large(8,2)
%%
% Try to modify out-of-bounds element
A_large(1,9) = 3.14;
%%
% Try to modify out-of-bounds element
A_large(8,2) = 3.14;
A_large %[output:34624cce]
%[text]   An attempt to modify an out-of-bound element would just increase the size of matrix and fill the unassigned elements to 0s
%%
A_large(:,:) % no need to access in such a way, but the same as A_large %[output:09784a88]
%%
%[text] ## Concatenating Vectors, Matrices
%[text] Sometimes you need to combine smaller matrices into larger ones.
%[text] Use `vertcat()` to stack vertically (top and bottom) or `horzcat()` to stack horizontally (side by side).
%%
% Create fresh matrices for concatenation examples
A = [1, 2; 3, 4];
B = [5, 6; 7, 8];
%%
% Vertical concatenation: stack matrices on top of each other
C_vertcat = vertcat(A, B) % Shorthand: [A;B] %[output:4ba9bc59]
%[text] Did you get the result:
%[text] 1  2
%[text] 3  4
%[text] 5  6
%[text] 7  8
%%
% You can vertically concatenate multiple matrices as long as they have same cols 
D = [100, 200; 100, 300; 100, 400];
vertcat(C_vertcat, D) %[output:32f259c8]
%%
% The order matters: D on top of C_vertcat
vertcat(D, C_vertcat) %[output:6e60809b]
%%
% Horizontal concatenation: stack matrices side by side
C_horzcat = horzcat(A, B) % Shorthand: [A,B] %[output:3178418b]
%[text] Did you get the result:
%[text] 1  2  5  6
%[text] 3  4  7  8
%%
%[text] **Important dimension requirements:**
%[text] - For `vertcat(A, B)`: A and B must have the **same number of columns**
%[text] - For `horzcat(A, B)`: A and B must have the **same number of rows** \
%%
% Verify that the matrix A (2*2) and matrix D (3*2) cannot be vertically concatenated

% Verify that the matrix A (2*2) and transposed matrix of D (2*3) cannot be horizatally concatenated

%%
%[text] ## Converting Number to String (num2str) and Display 
%[text] When you want to display numbers along with text, you need to convert them. 
%[text] `num2str()` converts a number into a string format.
%[text] Try course\_num = 12 and converted = num2str(course\_num) to verify the two variables' type
% Define a number
course_num = 12 %[output:0b4b8ba6]
% Convert to string
converted = num2str(course_num) %[output:3cf501a7]
%%
% Char-type of array (inside single quote, not double quotes) can be concatenated horizontally [?,?,?]
% Try to display 'I ' and 'enjoy ' and 'MATLAB ' inside [ , , ] together
% ['I ', 'enjoy ', 'MATLAB ']

%%
% Try horzcat() to display 'I ' and 'enjoy ' and 'MATLAB '

%%
% Use num2str() to combine numbers with text
% Mixing text and numbers: try 'From ', 'ENGR' and course_num to obtain 'From ENGR12' or 'From ENGR11';

%%
% Concatenating strings works the same way as concatenating matrices
% Find a way to obtain string 'I enjoy MATLAB from ENGR12'


%%
%[text] ## Unexpected Display (Should Avoid)
%%
A = 5.145;

% You shouldn't mix the row vector with two types string and numerical
disp(['The value of A is: ', A]) %[output:254f1a04]
disp(["The value of A is: ", num2str(A)]) %[output:1e793c0c]

% Should not try to assign something to disp, below are two warning cases
% (won't trigger error)
% disp = ['The value of A is 5.145']
% disp = ('The value of A is 5.145')
%%
%[text] ## Rounding Numbers
%[text] Different rounding functions give different results.
%[text] Use `round()` for nearest integer, `ceil()` for always rounding up, `floor()` for always rounding down.
%[text] num = 3.1415926;
% Round to nearest integer

%%
% Round up

%%
% Round down

%%
% Round towards zero (i.e., removing all decimal places)

%%
% All these functions work on matrices element-wise
% Try on matrix_r = [0.5001, -0.4999; 1.501, 1.999]
% with different rounding functions
% 
%%
%[text] ## Random Numbers
%%
% Generate a random number between 0 and 1
r = rand %[output:35709e50]

%%
% Generate a row vector of 5 random numbers between 0 and 1
rand_vec = rand(1, 5) %[output:179ab1f8]

%%
% Generate a matrix of 3*2 with random numbers between 0 and 1
rand_mat = rand(3,2) %[output:5f9d57e1]

%%
% Generate a random integer between 1 and 100
randi_num = randi(100) %[output:245a04e0]

%%
% Generate a row vector (1*5 size) of random integers between 1 and 100
randi_num_vec = randi(100, 1, 5) %[output:4ff951c2]
%%
% Generate a square matrix (3*3) of random integers between 1 and 100
randi_num_mat = randi(100, 3) %[output:65feb2e4]
%%
% Generate a row vector (1*8 size) of random integers between -10 and 15
randi_range_mat = randi([-10,15], 1, 8) %[output:1afd45a9]
%%
%[text] ## Statistics Functions
%%
% Let's first generate a row vector of 55 random integers from 60 to 100
% assume it is the final grade of some ENGR12 course
grades = randi([60,100], 1, 55) %[output:5a51928b]
%%
% Find the average, median, mode, variance, standard deviation of the
% grades
avg_grd = mean(grades);
median_grd = median(grades);
mode_grd = mode(grades);
stdev_grd = std(grades);
var_grd = var(grades);
%%
% Find the range, and the 25% or 75% percentile grade

%%
%[text] ## Saving and Loading Data
%[text] MATLAB can save your variables to files (.mat files) for later use.
%[text] But saving into .csv or .txt files are more flexible for other use scenarios
% Create some sample data
sample_vec = randi([60, 100], 5, 1);
sample_mat = rand(4);
%%
% Save specific variables to a text file
save('sample.txt', 'sample_vec', '-ascii');
save('sample.csv', 'sample_mat', '-ascii');
%%
% Loading data from a saved file
% First clear current workspace
clear

% Use load() function to load content to a variable
loaded1 = load('sample.txt');
loaded2 = load('sample.csv');
%%
%[text] ## Input Function, Exist Function
%%
%[text] User inputs a number
x = input("please input x between 1~4: ");
y = input("please input y between 1~4: ");
%%
%[text] User inputs a string
fname = input("please input file name to import: ", 's');
%%
%[text] Supposing above you have created a sample.csv and put some data inside
%[text] Supposing you also have created a sample.txt and put inside
%%
% Let us try to load the content from fname to a vec
% You can use res = load(fname), but not load("fname")

% You can use res = load("sample.txt"), but not load(sample.txt)

%%
%[text] **Literal and Variable Differences**
%[text] A **literal** is a value written **directly** in the code.
%[text] `5, 3.14, 'hello', [1` `2` `3``]`
%[text] - It does **not** have a name.
%[text] - You cannot change it, e.g. you assign 5 = 4 or 'hello' = 'hi' \
%[text] A **variable** is a **named container** that stores a value.
%[text] `x, approxi_pi, name, row3`
%[text] - The name refers to the data (would cause error if no value stored there)
%[text] - The value **can change**. e.g. you can assign such as hello = 'hi', A5 = 4 \
%%
% Now let result stores the loaded content of sample.csv
result = load("sample.csv");
%%
% Can you finish this small interface:
disp(['The element you inquired at Row ', num2str(x), ' Column ', num2str(y), ' of file ', fname, ' is: ', num2str(result(x,y))]) %[output:649a632c]
%%
%[text] You can use exist() function to check if something already exists, e.g., a variable or a file
%[text] In this course, we only care whether a file exists,
% Try to display to see what value the exist() function returns if the inquired item doesn't exist
% e.g. abc123.m is not a file now in current path
% 
%%
%[text] ## Loop Prerequisite: Relation Operators
%[text] - == is equivalence
%[text] - ~= is non-equivalence
%[text] - In almost all programming languages, one single equal-sign means "Assignment", assign RHS to LHS
%[text] - double equal-signs means "Check Equivalence" \
a = 5;
b = 10;

% Examples of logical Class: check workspace!
f1 = (a > b); % false
f2 = (a < b); % true
f3 = (a == b); % false
f4 = (a ~= b); % true
f5 = (a >= b); % false
f6 = (a <= b); % true
%%
%[text] ## Logic Operators (&&, ||, ~)
%[text] - Both statement 1 AND statement 2 are true:  s1 && s2
%[text] - At least one of statement 1 OR statement 2 is true:    s1 || s2
%[text] - NOT statement 1 is true:   ~s1 \
%%
% Examples of logical Class: check workspace!
f7 = f2 && f4; % f7 is true since both f2 and f4 are true
f8 = f2 && f3; % f8 is true since one of (f2 or f3) is true
f9 = ~f2; %f9 is false since f2 is true
%%
%[text] ## If-end statement, If-else-end statement
%%
if a == 9
    disp("a is equal to 9")
end
%%
if a > b %[output:group:14f880fb]
    disp('a is greater than b');
else
    disp('a is not greater than b'); %[output:038ce7bf]
end %[output:group:14f880fb]
%%
if f2 % same as putting a<b here %[output:group:379af058]
    disp('a is less than b'); %[output:69a9236d]
else
    disp('a is not less than b');
end %[output:group:379af058]
%%
%[text] ## If-elseif-else-end statement
%[text] <u>if (Condition 1)</u>
%[text]  do thing 1
%[text] elseif (Condition 2)  % when you are here, it must mean Condition 1 is false
%[text]     do thing 2
%[text] elseif (Condition 3) % when you are here, it must mean Condition 2 and Condition 3 are both false
%[text]     do thing 3
%[text] ......
%[text] else
%[text]     do thing n
%[text] <u>end</u>
%%
% Temperature Control Example
temperature = 75;

if temperature < 60 %[output:group:690cfaf1]
    disp('The temperature is cold.')
elseif (temperature >=60 && temperature <=90) % this can be simplied to temp <=90 only
    disp('The temperature is moderate.') %[output:26da71f8]
else
    disp('The temperature is hot.')
end %[output:group:690cfaf1]
%%
% Another example with user input
temp = input("please input a temp: ");
if temp < 60 %[output:group:64d14999]
    disp('The temperature is cold.')
elseif (temp >=60 && temp<=90)
    disp('The temperature is moderate.') %[output:8f8708bb]
else
    disp('The temperature is hot.')
end %[output:group:64d14999]
%%
%[text] ## Switch Case
%[text] switch (var )
%[text]         case value1 
%[text]                 statement1 
%[text]         case value2 
%[text]                 statement2 
%[text]         case {value3, value4}
%[text]                 statement x
%[text]         otherwise
%[text]                 other\_statement
day = input('Enter a number (1-7) to represent the day of the week: ');
switch day %[output:group:6bb529b2]
    case 1
        disp('Monday')
    case 2
        disp('Tuesday')
    case 3
        disp('Wednesday')
    case 4
        disp('Thursday') 
    case 5
        disp('Friday')
    case {6, 7}
        disp('Weekends') %[output:5bb3ddb2]
    otherwise
        disp('Invalid input. Please enter a number between 1 and 7.')
end %[output:group:6bb529b2]
%%
%[text] ## While-loop
%[text] You don't know how many iterations in advance (it is up to termination conditions!)
%[text] 
%[text] `while (condition)`
%[text]          Statement block that must change the condition 
%[text] `end`
% Example: eat buffet
full_stomach = 25; % 25 plates
eaten = 0;
while (eaten < full_stomach)

    plates = input('How many more plates do you want to eat? ');
    eaten = eaten + plates;

end
disp(['You are finally full and ate ', num2str(eaten),' plates!']); %[output:1f28de7f]
%%
%[text] Enter the while-loop by checking the condition:
%[text] - if false, skip the entire loop
%[text] - if true, executing the statement block, check the condition again. If the condition is still true, execute the statement block again. Otherwise, exit the while-loop \
%%
%[text] #### Example Use: go through vector element via index i
vec = randi([-5, 5], 1, 9);

i = 1;                % start by assigning initial index i = 1
while i<= length(vec) % won't stop until i is greater than length() %[output:group:744428fc]
    disp(vec(i));     % do something to each entry %[output:36945b74]
    i = i + 1;        % increase i by 1 so it can go to next index and finally exit by exceeding over length 
end %[output:group:744428fc]
%%
%[text] #### Example Use: go through vector element and update
xnew = 1:10;
fxnew = zeros(1, length(xnew));

j = 1;
while j< length(fxnew)+1
    fxnew(j) = j*j;
    j = j + 1;
end
%[text] Trace the above while-loop:
%[text] - xnew = \[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10\], fxnew = \[0, 0, 0, 0, 0, 0, 0, 0, 0, 0\] \
%[text] - At j=1, 2\<11 is true: 
%[text] - Enter loop for the first time, fxnew(1) = 1\*1 = 1
%[text] - \[1, 0, 0, 0, 0, 0, 0, 0, 0, 0\]
%[text] - j is incremented to 2 \
%[text] - At j=2, 3\<11 is still true
%[text] - Enter loop for the second time, fxnew(2) = 2\*2 = 4
%[text] - \[1, 4, 0, 0, 0, 0, 0, 0, 0, 0\]
%[text] - j is incremented to 3 \
%[text] - ... 
%[text] - fxnew(10) = 10\*10 = 100
%[text] - \[1, 4, 9, 16, 25, 36, 49, 64, 81, 100\]
%[text] - j is incremented to 11 \
%[text] - At j=11, 12\<11 is false
%[text] - Exit loop \
%%
%[text] #### Error-checking: Keep asking until user gives a valid number
inputYear = input('Enter a year between 2000 and 2050: ');
while (inputYear < 2000 || inputYear > 2050)
    inputYear = input('Enter a year between 2000 and 2050: ');
end
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
%[text] #### Example: use for-loop to go through vector element
for x = [0, pi/4, pi/2, 3*pi/4, pi] %[output:group:955790b4]
    disp(sin(x)); %[output:816daa28]
end %[output:group:955790b4]
%%
%[text] #### Example: use for-loop to update vector element
%%
vec_initial = ones(1, length(xnew));

% e.g., update every 2nd element from first element
for i = 1:2:length(vec_initial)
   vec_initial(i) = 0.01 * i;
end
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
%[text] #### Example: use for-loop to mannually find the extreme in vector
% Try: for-loop to find largest number
vec_unsorted = randi([-50, 50], 1, 20);
largest = vec_unsorted(1);
for i = 2:length(vec_unsorted)
    if (vec_unsorted(i)>largest)
        largest = vec_unsorted(i);
    end
end
disp(largest); %[output:2bc1e25f]
%%
%[text] ## Challenging Practices
%%
%[text] Try to use for-loop to find average of all vector entries whose value is \>25
currentSum = 0;
currentCount = 0;
loopIndex = 1;

while (loopIndex <= length(vec_unsorted))
    if (vec_unsorted(loopIndex) > 25)
        currentSum = currentSum + vec_unsorted(loopIndex);
        currentCount = currentCount + 1;
    end
    loopIndex = loopIndex + 1;
end

avg_of_25_more = currentSum/currentCount %[output:7e25f751]
%%
%[text] Try to find the largest square number in this range \[2000, 2050\]
%[text] Hints: initialize result = 0
%[text] starts from x=2000, if 2000 is square number, update result = 2000
%[text] increase x by 1, if 2001 is square number, update result = 2001
%[text] ...
%[text] Increase until x=2050, if 2050 is a square number, update result = 2050
%[text] A number is a square number if it is the result of some integer squared (in other words, its sqrt result is a whole number)
%[text] A whole number is a number whose round-ing value is the same as itself.
currentlargest = 0;
for var = 2000:2050
    if sqrt(var) == floor(sqrt(var))
        currentlargest = var;
    end
end
disp(currentlargest) %[output:17d824e3]
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
%[text] | initial=199 |
%[text] | --- |
%[text] | Division times: 1 |
%[text] | Division times: 2 |
%[text] | Division times: 3 |
%[text] | Division times: 4 |
%[text] | last=12 |
%[text] | Done |
%[text:table]
%[text] 
%[text] **Scratch work** to track all variables' value <u>*(!!! this is not solution, just your thoughts!!!)*</u>
%[text:table]{"ignoreHeader":true}
%[text] | Change of a: | 1 | 2 | 3 | 4 | 5 |
%[text] | --- | --- | --- | --- | --- | --- |
%[text] | Change of b: | 7 | 6 | 5 | 4 | 3 |
%[text] | Change of num: | 0 | 1 | 2 | 3 | 4 |
%[text] | Change of initial: | 199 | 99 | 49 | 24 | 12 |
%[text:table]
%[text] 
%[text] **Verify via running Matlab**
a = 1;
b = 7;
num = 0;
initial = 199 %[output:group:529adeaf] %[output:40d3c4e9]
while a <= b
    if mod(initial, 2) == 1
        initial = (initial - 1) / 2;
    else
        initial = initial / 2;
    end
    num = num + 1;
    disp(['Division times: ', num2str(num)]); %[output:3f19902e]
    a = a + 1;
    b = b - 1;
end %[output:group:529adeaf] %[output:88961640] %[output:7593a029]

%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"inline","rightPanelPercent":37.1}
%---
%[output:8b2e9b69]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"A_large","rows":6,"type":"double","value":[["0.1000","0.0200","0.3000","40.0000","5.0000","600.0000"],["8.0000","9.0000","11.0000","12.0000","13.0000","16.0000"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","-9.0000"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","611.0000"],["36.0000","100.0000","31.0000","7.0000","3.0000","6.1100"],["-1.4140","3.1415","2.8000","90.0000","3.4500","6.1890"]]}}
%---
%[output:334a59fd]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["0.1000","0.0200"],["8.0000","9.0000"]]}}
%---
%[output:7c4c3c63]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":3,"type":"double","value":[["0.3000","40.0000"],["31.0000","7.0000"],["2.8000","90.0000"]]}}
%---
%[output:77dadd72]
%   data: {"dataType":"matrix","outputData":{"columns":1,"name":"ans","rows":4,"type":"double","value":[["12.0000"],["-8.0000"],["5.8900"],["7.0000"]]}}
%---
%[output:177c2064]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"ans","rows":1,"type":"double","value":[["0.0200","40.0000","600.0000"]]}}
%---
%[output:5458b5ea]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"ans","rows":4,"type":"double","value":[["9.0000","12.0000","16.0000"],["-2.0000","-8.0000","-9.0000"],["-90.0000","5.8900","611.0000"],["100.0000","7.0000","6.1100"]]}}
%---
%[output:09ecc8fb]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"ans","rows":1,"type":"double","value":[["8","9","11","12","13","16"]]}}
%---
%[output:8aa0f38f]
%   data: {"dataType":"matrix","outputData":{"columns":1,"name":"ans","rows":6,"type":"double","value":[["600.0000"],["16.0000"],["-9.0000"],["611.0000"],["6.1100"],["6.1890"]]}}
%---
%[output:2dda71b5]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"A_large","rows":6,"type":"double","value":[["0.1000","0.0200","0.3000","40.0000","5.0000","8.0000"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","8.0000"],["36.0000","100.0000","31.0000","7.0000","3.0000","8.0000"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000"]]}}
%---
%[output:3c99c4d5]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"A_large","rows":6,"type":"double","value":[["0.1000","0.0200","0.3000","412.0000","413.0000","414.0000"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","9.0000"],["36.0000","100.0000","31.0000","7.0000","3.0000","10.0000"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000"]]}}
%---
%[output:34624cce]
%   data: {"dataType":"matrix","outputData":{"columns":9,"name":"A_large","rows":8,"type":"double","value":[["0.1000","0.0200","0.3000","412.0000","413.0000","414.0000","0","0","3.1400"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000","0","0","0"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000","0","0","0"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","9.0000","0","0","0"],["36.0000","100.0000","31.0000","7.0000","3.0000","10.0000","0","0","0"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000","0","0","0"],["0","0","0","0","0","0","0","0","0"],["0","3.1400","0","0","0","0","0","0","0"]]}}
%---
%[output:09784a88]
%   data: {"dataType":"matrix","outputData":{"columns":9,"name":"ans","rows":8,"type":"double","value":[["0.1000","0.0200","0.3000","412.0000","413.0000","414.0000","0","0","3.1400"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000","0","0","0"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000","0","0","0"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","9.0000","0","0","0"],["36.0000","100.0000","31.0000","7.0000","3.0000","10.0000","0","0","0"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000","0","0","0"],["0","0","0","0","0","0","0","0","0"],["0","3.1400","0","0","0","0","0","0","0"]]}}
%---
%[output:4ba9bc59]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_vertcat","rows":4,"type":"double","value":[["1","2"],["3","4"],["5","6"],["7","8"]]}}
%---
%[output:32f259c8]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":7,"type":"double","value":[["1","2"],["3","4"],["5","6"],["7","8"],["100","200"],["100","300"],["100","400"]]}}
%---
%[output:6e60809b]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":7,"type":"double","value":[["100","200"],["100","300"],["100","400"],["1","2"],["3","4"],["5","6"],["7","8"]]}}
%---
%[output:3178418b]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"C_horzcat","rows":2,"type":"double","value":[["1","2","5","6"],["3","4","7","8"]]}}
%---
%[output:0b4b8ba6]
%   data: {"dataType":"textualVariable","outputData":{"name":"course_num","value":"12"}}
%---
%[output:3cf501a7]
%   data: {"dataType":"textualVariable","outputData":{"name":"converted","value":"'12'"}}
%---
%[output:254f1a04]
%   data: {"dataType":"text","outputData":{"text":"The value of A is: \u0005\n","truncated":false}}
%---
%[output:1e793c0c]
%   data: {"dataType":"text","outputData":{"text":"    \"The value of A is: \"    \"5.145\"\n\n","truncated":false}}
%---
%[output:35709e50]
%   data: {"dataType":"textualVariable","outputData":{"name":"r","value":"0.1781"}}
%---
%[output:179ab1f8]
%   data: {"dataType":"matrix","outputData":{"columns":5,"name":"rand_vec","rows":1,"type":"double","value":[["0.3596","0.0567","0.5219","0.3358","0.1757"]]}}
%---
%[output:5f9d57e1]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"rand_mat","rows":3,"type":"double","value":[["0.2089","0.4685"],["0.9052","0.9121"],["0.6754","0.1040"]]}}
%---
%[output:245a04e0]
%   data: {"dataType":"textualVariable","outputData":{"name":"randi_num","value":"75"}}
%---
%[output:4ff951c2]
%   data: {"dataType":"matrix","outputData":{"columns":5,"name":"randi_num_vec","rows":1,"type":"double","value":[["74","57","19","60","30"]]}}
%---
%[output:65feb2e4]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"randi_num_mat","rows":3,"type":"double","value":[["14","8","45"],["22","25","2"],["90","6","90"]]}}
%---
%[output:1afd45a9]
%   data: {"dataType":"matrix","outputData":{"columns":8,"name":"randi_range_mat","rows":1,"type":"double","value":[["-5","-8","-3","1","-8","15","-2","-3"]]}}
%---
%[output:5a51928b]
%   data: {"dataType":"matrix","outputData":{"columns":55,"name":"grades","rows":1,"type":"double","value":[["62","72","61","80","91","85","63","63","91","97","81","64","93","73","72","90","60","61","87","84","81","89","88","92","71","88","82","76","62","91"]]}}
%---
%[output:649a632c]
%   data: {"dataType":"text","outputData":{"text":"The element you inquired at Row 2 Column 3 of file sample.csv is: 0.77193\n","truncated":false}}
%---
%[output:038ce7bf]
%   data: {"dataType":"text","outputData":{"text":"a is not greater than b\n","truncated":false}}
%---
%[output:69a9236d]
%   data: {"dataType":"text","outputData":{"text":"a is less than b\n","truncated":false}}
%---
%[output:26da71f8]
%   data: {"dataType":"text","outputData":{"text":"The temperature is moderate.\n","truncated":false}}
%---
%[output:8f8708bb]
%   data: {"dataType":"text","outputData":{"text":"The temperature is moderate.\n","truncated":false}}
%---
%[output:5bb3ddb2]
%   data: {"dataType":"text","outputData":{"text":"Weekends\n","truncated":false}}
%---
%[output:1f28de7f]
%   data: {"dataType":"text","outputData":{"text":"You are finally full and ate 28 plates!\n","truncated":false}}
%---
%[output:36945b74]
%   data: {"dataType":"text","outputData":{"text":"    -3\n\n    -3\n\n     4\n\n     2\n\n     1\n\n    -3\n\n    -3\n\n    -5\n\n     5\n\n","truncated":false}}
%---
%[output:816daa28]
%   data: {"dataType":"text","outputData":{"text":"     0\n\n    0.7071\n\n     1\n\n    0.7071\n\n   1.2246e-16\n\n","truncated":false}}
%---
%[output:2bc1e25f]
%   data: {"dataType":"text","outputData":{"text":"    28\n\n","truncated":false}}
%---
%[output:7e25f751]
%   data: {"dataType":"textualVariable","outputData":{"name":"avg_of_25_more","value":"28"}}
%---
%[output:17d824e3]
%   data: {"dataType":"text","outputData":{"text":"        2025\n\n","truncated":false}}
%---
%[output:40d3c4e9]
%   data: {"dataType":"textualVariable","outputData":{"name":"initial","value":"199"}}
%---
%[output:3f19902e]
%   data: {"dataType":"text","outputData":{"text":"Division times: 1\nDivision times: 2\nDivision times: 3\nDivision times: 4\n","truncated":false}}
%---
%[output:88961640]
%   data: {"dataType":"textualVariable","outputData":{"name":"last","value":"12"}}
%---
%[output:7593a029]
%   data: {"dataType":"text","outputData":{"text":"Done\n","truncated":false}}
%---
