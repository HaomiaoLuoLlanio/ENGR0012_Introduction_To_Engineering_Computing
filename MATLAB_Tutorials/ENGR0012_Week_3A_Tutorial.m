%[text] # Week 3A
%[text] ## Misc: disp, clear, clc, display, path, addpath
% Random messy codes
A = 5.145;
B = [4, 6; 9, 12];
%%
% Display to screen
disp(B) %[output:317baa15]
%%
% Display more information:
disp(['A`s value is: ', num2str(A)]) %[output:12e180c5]
%%
% Clear workspace
clear;
%%
% Clear command window
clc;
%%
%[text] Display all MATLAB search path for scripts. It will be a lot for MATLAB online
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
%[text] Another useful feature when working on ***Command Window***, you may use upper arrow ↑ to quickly retrieve your history commands.
%%
%[text] ## Linspace and Colon methods
% Create a vector 'v' with 101 linearly spaced points between 0 and 1
v = linspace(0, 1, 101) %[output:27c5c9b7]
%[text] The first few elements of `v` would be v = \[0, 0.01, 0.02, 0.03, ..., 0.99, 1\]
%[text] Note the choice of 101, instead of 100.
%[text] Quiz yourself: linspace(0,1,5) would yield \[0, 0.2, 0.4, 0.6, 0.8, 1\] or \[0, 0.25, 0.5, 0.75, 1\]
%%
% Create a vector 'arr' with 6 linearly spaced points between 5 and 30
arr = linspace(5, 30, 6);

% Example: The elements of 'arr' would be:
% arr = [5, 10, 15, 20, 25, 30]
%%
% Create a vector 'b' starting from 1 to 3 with a step size of 0.2
b = 1:0.2:3 %[output:1fa952f1]
%[text] The elements of `b` would be: b = \[1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3\]
%%
%[text] ## Creating Ones and Zeros Matrices
h = ones(3)  % Creates a 3x3 square matrix filled with ones %[output:86bc7a18]
j = zeros(4) % Creates a 4x4 square matrix filled with zeros %[output:87e92fc5]
%%
matOne = ones(2, 3) % Creates a 2x3 matrix filled with ones %[output:09774c4c]
matZero = zeros(5, 2) % Creates a 5x2 matrix filled with zeros %[output:2d7ea438]
%%
i4 = eye(4) % Creates a 4x4 identity matrix %[output:1adb74e4]
%%
%[text] #### Get the dimensions of arrays
%%
% “size” gives length of all matrix dimension
% “length” gives the length of largest array dimension

size(matZero) %[output:6159c0ce]
length(matZero) %[output:4883ff2a]
%%
%[text] ## Access/Modify Individual Elements in Vector/Matrix
%%
% Recall d
disp(i4) %[output:17cbf36a]
%%
element_23 = i4(2, 3) % Access the element in the 2nd row, 3rd column of matrix 'i4' %[output:7357ba93]
element_11 = i4(1,1) % Access the element in the 1st row, 1st column of matrix 'i4' %[output:8b2ce35a]
%%
% Recall h
disp(h) %[output:1a17cbb3]
%%
% Modify individual elements in an array
h(2,3) =10; % Set the element in the 2nd row, 3rd column of matrix 'h' to 10
h(1,1) =5;  % Set the element in the 1st row, 1st column of matrix 'h' to 5 
h %[output:94c7a720]
%%
%[text] ## Perform Matrix Operations
A = [1 2; 3 4] %[output:7d189090]
B = [5 6; 7 8] %[output:6edc6012]
%%
% Matrix +-*/ scalar
A+100, A-99, A*0.01, A/2 %[output:34e01f1f] %[output:65cb7dcf] %[output:92e82156] %[output:28e03f9d]
%%
% Scalar +-* matrix
200+A, -20-A, 0.001*A %[output:52600c80] %[output:8481e514] %[output:47ae2048]
%%
% Element-wise operations + - .* ./ .^
C_ele_add = A + B;  % A_i + B_i
C_ele_sub = A - B;  % A_i - B_i
C_ele_mul = A .* B; % A_i * B_i
C_ele_div = A ./ B; % A_i / B_i
C_ele_pow = A .^ B; % A_i ^ B_i
C_ele_add, C_ele_sub, C_ele_mul, C_ele_div, C_ele_pow %[output:9d8aebbf] %[output:40024c17] %[output:235f003c] %[output:24094f36] %[output:7aa91112]
%%
%[text] In Element-wise operations:
%[text] - order matters
%[text] - A, B matrices have to match size \
%%
% Matrix multiplication
C_mul = A * B; % same as excel mmult
C_mul_diff = B * A; % linear algebra says A*B not always equal to B*A
C_mul, C_mul_diff %[output:94cf8880] %[output:2e272420]
%[text] If A is in dimension `m*n`, B is in dimension `s*t`. n has to be equal to s (`n=s`) so that A\*B is doable
%%
disp(A) %[output:549a3371]
A_transpose = A' % or A_transpose = transpose(A) %[output:3c8ab019]
A_inverse = inv(A) % matrix inverse or A_inverse = A^(-1) %[output:6afeaab7]
%%
B = [2,3;4,5;6,7] %[output:73495e7f]
B_transpose = B' %[output:52b33bea]
%%
% Verify yourself
% A_inverse * A, A * A_inverse
%%
%[text] ## Concatenate arrays
A = [1, 2; 3, 4] %[output:629c29f8]
B = [5, 6; 7, 8] %[output:3a03c045]
C_vertcat = vertcat(A,B) % another way is just C_vertcat = [A;B] %[output:8b2e9b69]
%%
% C_vertcat will be:
%  1  2
%  3  4
%  5  6
%  7  8

D = [100, 200; 100, 300; 100, 400];
vertcat(C_vertcat, D) %[output:334a59fd]
%%
vertcat(D, C_vertcat) %[output:7c4c3c63]
%%
A = [1, 2; 3, 4];
B = [5, 6; 7, 8];

C_horzcat = horzcat(A, B) % another way is just C_horzcat = [A,B] %[output:77dadd72]
% C_horzcat will be:
%  1  2  5  6
%  3  4  7  8

E = [0.1, 0.2, 0.3; 0.4, 0.5, 0.6] %[output:9dcd5449]
horzcat(C_horzcat, E) %[output:1af33150]
%[text] Make sure that A and B have compatible dimensions for these operations:
%[text] - For vertcat, A and B must have the same number of columns.
%[text] - For horzcat, A and B must have the same number of rows \
%%
%[text] ## num2str
%[text] Convert a number to a string
num = 12;
num2str(num) %[output:84e69544]
%%
disp(['The number as a string is: ', num2str(num)]); % str can be viewed as an array/vector of char %[output:439c55c2]
%%
%str_vec = ['I', 'enjoy', 'MATLAB'];
str_vec = ['I ', 'enjoy ', 'MATLAB '];
horzcat(str_vec) %[output:6c7a3fc5]
%%
str_vec2 = ['from ', 'ENGR', num2str(num)];
horzcat(str_vec, str_vec2) %[output:235bc8ac]
%%
% Convert a matrix to a string
matrix = [1.1, 2.2; 3.3, 4.4] %[output:4128c09c]
matrix_str = num2str(matrix) %fix-width on each row %[output:95f23a34]
matrix_b = [1, 100, 2.04; 7, 8, -9] %[output:5491725b]
matrix_b_str= num2str(matrix_b) %fix-width on each row %[output:905afc66]
%%
%[text] ## Rounding Commands
num = 3.1415926;
round(num) %[output:65c0ddfb]
ceil(num) %[output:6b062886]
floor(num) %[output:339979de]
fix(num) %[output:20368a9b]
fix(-1.49999) %[output:88e6fb3d]
matrix_r = [0.5001, -0.4999; 1.501, 1.999] %[output:10aa97b7]
fix(matrix_r) %[output:3aed21ee]
%%
%[text] ## Save and Load in MATLAB
% Create some sample data
sample_data = rand(5, 5);
sample_text = 'Hello, MATLAB!';

% Save the data to a MAT file
save('sample.mat', 'sample_data', 'sample_text');
save('all.mat');
%%
% Load the data from the MAT file

clear; % to verify the functionality of load below
load('sample.mat'); % you can also double-click to load
%%
%[text] Supposing you have created a <u>data.txt</u> and put inside
%[text] 1, 2, 3, 4
%[text] 5, 6, 7, 8
%[text] 9, 10, 11, 12
%[text] 13, 14, 15, 16
%[text] Supposing you have created a <u>data2.txt</u> and put inside
%[text] \-1, -2, -3, -4
%[text] \-5, -6, -7, -8
%[text] \-9, -10, -11, -12
%[text] \-13, -14, -15, -16
data = load('data.txt') %[output:7c583c53]
%%
%[text]  Load from user input
x = input("please input x between 1~4: ");
y = input("please input y between 1~4: ");
%%
%[text] Load from user input as string
file = input("please input file name to import: ", 's');
result = load(file);
%%
% A small interface:
disp(['The element you inquired at Row ', num2str(x), ' Column ', num2str(y), ' of file ', file, ' is: ', num2str(result(x,y))]) %[output:8f82d77e]

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
