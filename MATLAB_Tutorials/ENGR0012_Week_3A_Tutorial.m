%[text] # Week 3A: MATLAB Basics - Workspace, Arrays, and Operations
%[text]
%[text] ## Section 1: Useful Workspace Commands
%[text] These commands help you organize and manage your MATLAB environment:
%[text] - disp(): Display values in the command window
%[text] - clear: Remove variables from memory
%[text] - clc: Clear the command window
%[text] - addpath(): Add folders to MATLAB's search path

% Sample variables to work with
A = 5.145;
B = [4, 6; 9, 12];
%%
% Using disp() to display values
disp(B) %[output:317baa15]
%%
% You can combine text and numbers using square brackets []
% This requires converting numbers to strings using num2str()
disp(['A`s value is: ', num2str(A)]) %[output:12e180c5]
%%
% Clear workspace
clear;
%%
% Clear command window
clc;
%%
%[text] Display all MATLAB search paths for scripts. It will be a lot for MATLAB Online
%path
%%
% Add a path
% e.g. you want to run a script stored at this folder
addpath("/MATLAB Drive/somefolder/"); %[output:54e36aeb]
%%
%[text] By default, MATLAB Drive root folder is already in the path
%[text] Adding a path is usually done with the GUI by either copying file to the working folder
%[text] Or right click the desired file and choose "add to path" on MATLAB desktop
%%
%[text] Another useful feature when working in the ***Command Window***, you may use the upper arrow ↑ to quickly retrieve your command history.

%[text] ## Section 2: Creating Vectors - Linspace and Colon Methods  
%[text] Linspace and colon operators are useful for creating vectors with evenly-spaced values.
%[text] This is common when you need to create x-axes for plots or generate test data.

% Create a vector 'v' with 101 linearly spaced points between 0 and 1
v = linspace(0, 1, 101) %[output:27c5c9b7]
%[text] The first few elements of `v` would be v = \[0, 0.01, 0.02, 0.03, ..., 0.99, 1\]
%[text] Note the choice of 101, instead of 100.
%[text] Quiz yourself: linspace(0,1,5) would yield \[0, 0.2, 0.4, 0.6, 0.8, 1\] or \[0, 0.25, 0.5, 0.75, 1\]
%%
% Create a vector 'arr' with 6 linearly spaced points between 5 and 30
arr = linspace(5, 30, 6);
%[text] The elements of 'arr' would be: arr = \[5, 10, 15, 20, 25, 30\]

%%
% Alternatively, use the colon operator start:step:end to create vectors
% This is often easier when you know the step size rather than the number of points
b = 1:0.2:3 %[output:1fa952f1]
%[text] Syntax: start:step:end creates a vector from start to end with given step size
%[text] The elements of `b` would be: b = \[1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3\]
%%
%[text] ## Section 3: Creating Special Matrices
%[text] Often you need to initialize matrices with specific values.
%[text] MATLAB provides convenient functions like ones(), zeros(), and eye().

% Create square matrices (same number of rows and columns)
h = ones(3)  % Creates a 3x3 square matrix filled with ones %[output:86bc7a18]
j = zeros(4) % Creates a 4x4 square matrix filled with zeros %[output:87e92fc5]
%%
% You can also specify rows and columns separately
matOne = ones(2, 3) % Creates a 2x3 matrix filled with ones (2 rows, 3 columns) %[output:09774c4c]
matZero = zeros(5, 2) % Creates a 5x2 matrix filled with zeros (5 rows, 2 columns) %[output:2d7ea438]
%%
% The identity matrix (ones on diagonal, zeros elsewhere) is useful for matrix operations
i4 = eye(4) % Creates a 4x4 identity matrix %[output:1adb74e4]
%%
%[text] ## Section 4: Checking Array Dimensions
%[text] When working with arrays, you often need to know their size.
%[text] Use size() for 2D info or length() for the longest dimension.

% size() returns the number of rows and columns
% length() returns the size of the largest dimension

size(matZero) %[output:6159c0ce]
length(matZero) %[output:4883ff2a]
%%
%[text] ## Section 5: Accessing and Modifying Array Elements
%[text] You often need to read or change specific values in an array.
%[text] Use matrix indexing (row, column) to access individual elements.

% First, let's display the identity matrix we created earlier
disp(i4) %[output:17cbf36a]
%%
% Access elements using (row, column) indexing
element_23 = i4(2, 3) % Get the element at row 2, column 3 %[output:7357ba93]
element_11 = i4(1, 1) % Get the element at row 1, column 1 %[output:8b2ce35a]
%%
% Recall the ones matrix 'h' from Section 3
disp(h) %[output:1a17cbb3]
%%
% To modify a value, assign a new value to its location
h(2, 3) = 10; % Change element at row 2, column 3 to 10
h(1, 1) = 5;  % Change element at row 1, column 1 to 5 
h %[output:94c7a720]
%%
%[text] ## Section 6: Matrix Operations
%[text] MATLAB excels at mathematical operations on matrices.
%[text] You can operate between matrices and scalars, or between two matrices.
%[text] Be careful: * and / perform linear algebra operations, while .* and ./ are element-wise.

% Define two 2x2 matrices for examples
A = [1, 2; 3, 4] %[output:7d189090]
B = [5, 6; 7, 8] %[output:6edc6012]
%%
% Add, subtract, multiply, and divide each matrix element by a scalar
% These operations apply to all elements uniformly
A+100, A-99, A*0.01, A/2 %[output:34e01f1f] %[output:65cb7dcf] %[output:92e82156] %[output:28e03f9d]
%%
% Order doesn't matter for + and * with scalars (scalar can be on either side)
200+A, -20-A, 0.001*A %[output:52600c80] %[output:8481e514] %[output:47ae2048]
%%
% Element-wise operations: apply operation to corresponding elements
% Use . before the operator for element-wise: .* ./ .^ 
C_ele_add = A + B;  % Add corresponding elements
C_ele_sub = A - B;  % Subtract corresponding elements
C_ele_mul = A .* B; % Multiply corresponding elements (note the dot: .*)
C_ele_div = A ./ B; % Divide corresponding elements (note the dot: ./)
C_ele_pow = A .^ B; % Raise corresponding elements to each other's power (note the dot: .^)
C_ele_add, C_ele_sub, C_ele_mul, C_ele_div, C_ele_pow %[output:9d8aebbf] %[output:40024c17] %[output:235f003c] %[output:24094f36] %[output:7aa91112]
%%
%[text] **Important notes about element-wise operations:**
%[text] - The order of operations matters (A .* B ≠ B .* A in general)
%[text] - Both matrices must have the same dimensions
%[text] - Compare this to matrix multiplication (A * B), which has different dimension requirements
%%
% Matrix multiplication (linear algebra operation, NOT element-wise)
C_mul = A * B; % Standard matrix multiplication
C_mul_diff = B * A; % Note: Matrix multiplication is NOT commutative (A*B ≠ B*A)
C_mul, C_mul_diff %[output:94cf8880] %[output:2e272420]
%[text] **Matrix multiplication rule:** If A has dimensions m×n and B has dimensions s×t,
%[text] then A*B is only possible if n = s (inner dimensions must match).
%%
disp(A) %[output:549a3371]
%%
% Transpose: flip rows and columns
A_transpose = A' % or A_transpose = transpose(A) - both work %[output:3c8ab019]
%%
% Matrix inverse: only works for square non-singular matrices
A_inverse = inv(A) % or A_inverse = A^(-1) - both work %[output:6afeaab7]
%%
% Transpose also works on non-square matrices
B = [2, 3; 4, 5; 6, 7] %[output:73495e7f]
B_transpose = B' % A 3×2 matrix becomes 2×3 %[output:52b33bea]
%%
% Try verifying: Does A_inverse * A give the identity matrix I?
% Try: A_inverse * A, A * A_inverse
%%
%[text] ## Section 7: Concatenating Arrays
%[text] Sometimes you need to combine smaller matrices into larger ones.
%[text] Use vertcat() to stack vertically or horzcat() to stack horizontally.

% Create fresh matrices for concatenation examples
A = [1, 2; 3, 4] %[output:629c29f8]
B = [5, 6; 7, 8] %[output:3a03c045]
%%
% Vertical concatenation: stack matrices on top of each other
C_vertcat = vertcat(A, B) % Shorthand: [A;B] %[output:8b2e9b69]
% Result: A is stacked on top of B
%  1  2
%  3  4
%  5  6
%  7  8

% You can concatenate multiple matrices
D = [100, 200; 100, 300; 100, 400];
vertcat(C_vertcat, D) %[output:334a59fd]
%%
% The order matters: D on top of C_vertcat
vertcat(D, C_vertcat) %[output:7c4c3c63]
%%
% Reset matrices for horizontal concatenation
A = [1, 2; 3, 4];
B = [5, 6; 7, 8];

% Horizontal concatenation: stack matrices side by side
C_horzcat = horzcat(A, B) % Shorthand: [A,B] %[output:77dadd72]
% Result: B is placed to the right of A
%  1  2  5  6
%  3  4  7  8

%%
% Another example with different dimensions
E = [0.1, 0.2, 0.3; 0.4, 0.5, 0.6] %[output:9dcd5449]
horzcat(C_horzcat, E) %[output:1af33150]

%[text] **Important dimension requirements:**
%[text] - For vertcat: A and B must have the **same number of columns**
%[text] - For horzcat: A and B must have the **same number of rows**
%%
%[text] ## Section 8: Converting Numbers to Strings (num2str)
%[text] When you want to display numbers along with text, you need to convert them.
%[text] num2str() converts a number or matrix into a string format.

num = 12;
num2str(num) % Convert the number 12 to the string '12' %[output:84e69544]
%%
% Use num2str() to combine numbers with text
% Strings can be concatenated using square brackets []
disp(['The number as a string is: ', num2str(num)]); %[output:439c55c2]
%%
% Concatenating strings works the same way as concatenating matrices
str_vec = ['I ', 'enjoy ', 'MATLAB '];
horzcat(str_vec) %[output:6c7a3fc5]
%%
% Mixing text and numbers
str_vec2 = ['from ', 'ENGR', num2str(num)];
horzcat(str_vec, str_vec2) %[output:235bc8ac]
%%
% You can also convert entire matrices to strings
matrix = [1.1, 2.2; 3.3, 4.4] %[output:4128c09c]
matrix_str = num2str(matrix) % Formats each row with fixed-width spacing %[output:95f23a34]
%%
matrix_b = [1, 100, 2.04; 7, 8, -9] %[output:5491725b]
matrix_b_str = num2str(matrix_b) % Useful for saving matrices as text %[output:905afc66]
%%
%[text] ## Section 9: Rounding Numbers
%[text] Different rounding functions give different results.
%[text] Use round() for nearest integer, ceil() for always up, floor() for always down.

num = 3.1415926;
round(num) % Round to nearest integer %[output:65c0ddfb]
%%
ceil(num)  % Round up (ceiling) %[output:6b062886]
floor(num) % Round down (floor) %[output:339979de]
%%
% fix() truncates toward zero (useful for removing decimal part)
fix(num) %[output:20368a9b]
fix(-1.49999) % With negative numbers, fix() rounds toward zero, not toward -infinity %[output:88e6fb3d]
%%
% All these functions work on matrices element-wise
matrix_r = [0.5001, -0.4999; 1.501, 1.999] %[output:10aa97b7]
fix(matrix_r) % Apply fix to each element %[output:3aed21ee]
%%
%[text] ## Section 10: Saving and Loading Data
%[text] MATLAB can save your variables to files (.mat files) for later use.
%[text] This is useful for storing results and sharing data.

% Create some sample data
sample_data = rand(5, 5);
sample_text = 'Hello, MATLAB!';

%%
% Save specific variables to a MAT file
save('sample.mat', 'sample_data', 'sample_text'); % Save only these variables
%%
% Save ALL variables in the workspace
save('all.mat');
%%
% Loading data from a saved file
clear; % Clear the workspace to show that load() will restore the variables
load('sample.mat'); % Load the variables back (you can also double-click the .mat file in the file browser)
%%
%[text] You can also load numerical data from plain text files (.txt files)
%[text] **Example:** Suppose you have a file data.txt containing:
%[text]   1, 2, 3, 4
%[text]   5, 6, 7, 8
%[text]   9, 10, 11, 12
%[text]   13, 14, 15, 16
%[text]
%[text] You can load it like this:
data = load('data.txt') %[output:7c583c53]
%%
%[text] ## Section 11: Interactive Input from the User
%[text] The input() function allows users to enter values while the script is running.

% Get numerical input from the user
x = input("Please input x between 1~4: ");
y = input("Please input y between 1~4: ");
%%
% Get string input from the user (the 's' flag means "string input")
file = input("Please input file name to import: ", 's');
result = load(file);
%%
% Display results using concatenation of strings and numbers
disp(['The element you inquired at Row ', num2str(x), ' Column ', num2str(y), ' of file ', file, ' is: ', num2str(result(x, y))]) %[output:8f82d77e]

%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"inline","rightPanelPercent":37.1}
%---
%[output:317baa15]
%   data: {"dataType":"text","outputData":{"text":"     4     6\n     9    12\n\n","truncated":false}}
%---
%[output:12e180c5]
%   data: {"dataType":"text","outputData":{"text":"A`s value is: 5.145\n","truncated":false}}
%---
%[output:54e36aeb]
%   data: {"dataType":"warning","outputData":{"text":"Warning: Name is nonexistent or not a directory: \/MATLAB Drive\/somefolder"}}
%---
%[output:27c5c9b7]
%   data: {"dataType":"matrix","outputData":{"columns":101,"name":"v","rows":1,"type":"double","value":[["0","0.0100","0.0200","0.0300","0.0400","0.0500","0.0600","0.0700","0.0800","0.0900","0.1000","0.1100","0.1200","0.1300","0.1400","0.1500","0.1600","0.1700","0.1800","0.1900","0.2000","0.2100","0.2200","0.2300","0.2400","0.2500","0.2600","0.2700","0.2800","0.2900"]]}}
%---
%[output:1fa952f1]
%   data: {"dataType":"matrix","outputData":{"columns":11,"name":"b","rows":1,"type":"double","value":[["1.0000","1.2000","1.4000","1.6000","1.8000","2.0000","2.2000","2.4000","2.6000","2.8000","3.0000"]]}}
%---
%[output:86bc7a18]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"h","rows":3,"type":"double","value":[["1","1","1"],["1","1","1"],["1","1","1"]]}}
%---
%[output:87e92fc5]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"j","rows":4,"type":"double","value":[["0","0","0","0"],["0","0","0","0"],["0","0","0","0"],["0","0","0","0"]]}}
%---
%[output:09774c4c]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"matOne","rows":2,"type":"double","value":[["1","1","1"],["1","1","1"]]}}
%---
%[output:2d7ea438]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"matZero","rows":5,"type":"double","value":[["0","0"],["0","0"],["0","0"],["0","0"],["0","0"]]}}
%---
%[output:1adb74e4]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"i4","rows":4,"type":"double","value":[["1","0","0","0"],["0","1","0","0"],["0","0","1","0"],["0","0","0","1"]]}}
%---
%[output:6159c0ce]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":1,"type":"double","value":[["5","2"]]}}
%---
%[output:4883ff2a]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"5"}}
%---
%[output:17cbf36a]
%   data: {"dataType":"text","outputData":{"text":"     1     0     0     0\n     0     1     0     0\n     0     0     1     0\n     0     0     0     1\n\n","truncated":false}}
%---
%[output:7357ba93]
%   data: {"dataType":"textualVariable","outputData":{"name":"element_23","value":"0"}}
%---
%[output:8b2ce35a]
%   data: {"dataType":"textualVariable","outputData":{"name":"element_11","value":"1"}}
%---
%[output:1a17cbb3]
%   data: {"dataType":"text","outputData":{"text":"     1     1     1\n     1     1     1\n     1     1     1\n\n","truncated":false}}
%---
%[output:94c7a720]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"h","rows":3,"type":"double","value":[["5","1","1"],["1","1","10"],["1","1","1"]]}}
%---
%[output:7d189090]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"A","rows":2,"type":"double","value":[["1","2"],["3","4"]]}}
%---
%[output:6edc6012]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"B","rows":2,"type":"double","value":[["5","6"],["7","8"]]}}
%---
%[output:34e01f1f]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["101","102"],["103","104"]]}}
%---
%[output:65cb7dcf]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["-98","-97"],["-96","-95"]]}}
%---
%[output:92e82156]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["0.0100","0.0200"],["0.0300","0.0400"]]}}
%---
%[output:28e03f9d]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["0.5000","1.0000"],["1.5000","2.0000"]]}}
%---
%[output:52600c80]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["201","202"],["203","204"]]}}
%---
%[output:8481e514]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["-21","-22"],["-23","-24"]]}}
%---
%[output:47ae2048]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["0.0010","0.0020"],["0.0030","0.0040"]]}}
%---
%[output:9d8aebbf]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_ele_add","rows":2,"type":"double","value":[["6","8"],["10","12"]]}}
%---
%[output:40024c17]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_ele_sub","rows":2,"type":"double","value":[["-4","-4"],["-4","-4"]]}}
%---
%[output:235f003c]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_ele_mul","rows":2,"type":"double","value":[["5","12"],["21","32"]]}}
%---
%[output:24094f36]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_ele_div","rows":2,"type":"double","value":[["0.2000","0.3333"],["0.4286","0.5000"]]}}
%---
%[output:7aa91112]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_ele_pow","rows":2,"type":"double","value":[["1","64"],["2187","65536"]]}}
%---
%[output:94cf8880]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_mul","rows":2,"type":"double","value":[["19","22"],["43","50"]]}}
%---
%[output:2e272420]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_mul_diff","rows":2,"type":"double","value":[["23","34"],["31","46"]]}}
%---
%[output:549a3371]
%   data: {"dataType":"text","outputData":{"text":"     1     2\n     3     4\n\n","truncated":false}}
%---
%[output:3c8ab019]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"A_transpose","rows":2,"type":"double","value":[["1","3"],["2","4"]]}}
%---
%[output:6afeaab7]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"A_inverse","rows":2,"type":"double","value":[["-2.0000","1.0000"],["1.5000","-0.5000"]]}}
%---
%[output:73495e7f]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"B","rows":3,"type":"double","value":[["2","3"],["4","5"],["6","7"]]}}
%---
%[output:52b33bea]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"B_transpose","rows":2,"type":"double","value":[["2","4","6"],["3","5","7"]]}}
%---
%[output:629c29f8]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"A","rows":2,"type":"double","value":[["1","2"],["3","4"]]}}
%---
%[output:3a03c045]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"B","rows":2,"type":"double","value":[["5","6"],["7","8"]]}}
%---
%[output:8b2e9b69]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"C_vertcat","rows":4,"type":"double","value":[["1","2"],["3","4"],["5","6"],["7","8"]]}}
%---
%[output:334a59fd]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":7,"type":"double","value":[["1","2"],["3","4"],["5","6"],["7","8"],["100","200"],["100","300"],["100","400"]]}}
%---
%[output:7c4c3c63]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":7,"type":"double","value":[["100","200"],["100","300"],["100","400"],["1","2"],["3","4"],["5","6"],["7","8"]]}}
%---
%[output:77dadd72]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"C_horzcat","rows":2,"type":"double","value":[["1","2","5","6"],["3","4","7","8"]]}}
%---
%[output:9dcd5449]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"E","rows":2,"type":"double","value":[["0.1000","0.2000","0.3000"],["0.4000","0.5000","0.6000"]]}}
%---
%[output:1af33150]
%   data: {"dataType":"matrix","outputData":{"columns":7,"name":"ans","rows":2,"type":"double","value":[["1.0000","2.0000","5.0000","6.0000","0.1000","0.2000","0.3000"],["3.0000","4.0000","7.0000","8.0000","0.4000","0.5000","0.6000"]]}}
%---
%[output:84e69544]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"'12'"}}
%---
%[output:439c55c2]
%   data: {"dataType":"text","outputData":{"text":"The number as a string is: 12\n","truncated":false}}
%---
%[output:6c7a3fc5]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"'I enjoy MATLAB '"}}
%---
%[output:235bc8ac]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"'I enjoy MATLAB from ENGR12'"}}
%---
%[output:4128c09c]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"matrix","rows":2,"type":"double","value":[["1.1000","2.2000"],["3.3000","4.4000"]]}}
%---
%[output:95f23a34]
%   data: {"dataType":"textualVariable","outputData":{"header":"2x15 char array","name":"matrix_str","value":"    '1.1         2.2'\n    '3.3         4.4'\n"}}
%---
%[output:5491725b]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"matrix_b","rows":2,"type":"double","value":[["1.0000","100.0000","2.0400"],["7.0000","8.0000","-9.0000"]]}}
%---
%[output:905afc66]
%   data: {"dataType":"textualVariable","outputData":{"header":"2x29 char array","name":"matrix_b_str","value":"    '1           100          2.04'\n    '7             8            -9'\n"}}
%---
%[output:65c0ddfb]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"3"}}
%---
%[output:6b062886]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"4"}}
%---
%[output:339979de]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"3"}}
%---
%[output:20368a9b]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"3"}}
%---
%[output:88e6fb3d]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"-1"}}
%---
%[output:10aa97b7]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"matrix_r","rows":2,"type":"double","value":[["0.5001","-0.4999"],["1.5010","1.9990"]]}}
%---
%[output:3aed21ee]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["0","0"],["1","1"]]}}
%---
%[output:7c583c53]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"data","rows":4,"type":"double","value":[["1","2","3","4"],["5","6","7","8"],["9","10","11","12"],["13","14","15","16"]]}}
%---
%[output:8f82d77e]
%   data: {"dataType":"text","outputData":{"text":"The element you inquired at Row 2 Column 3 of file data2.txt is: -7\n","truncated":false}}
%---
