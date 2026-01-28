%[text] # Week 3B
%[text] ## Revisit disp
%%
A = 5.145;

% You shouldn't mix the vector with two types string and numerical
disp(['A`s value is: ', A]) %[output:4484dbfb]
% Also try yourself
disp(["A`s value is: ", num2str(A)])    % Note the double quotes %[output:49ce25c4]
disp(['A`s value is: ', num2str(A, 3)])  %[output:205c5deb]
%%
%[text] Another useful feature when working on ***Command Window***, you may use upper arrow ↑ to quickly retrive your history commands.
%%
%[text] ## Revisit: Linspace and Colon methods
%%
% Create a vector 'c' starting from 1 to 12 with a step size of 1
c = 1:12 % same as C=1:1:12, when step=1, it can be omitted %[output:4a7b4d47]
%%
% Step can be negative too
d = 15:-4:7 %[output:148ddb42]
%%
% Ending point is not always included
e = 15:-4:0 %[output:9c6c3700]
%%
%[text] ## IMPORTANT: Access/Modify Individual Elements in Vector/Matrix
%%
%[text] Let's build a large matrix first
A_large = [0.1 0.02 0.3 40 5 600;8 9 11 12 13 16;1 -2 4 -8 5 -9;-67 -90 3 5.89 5.12 611;36 100 31 7 3 6.11;-1.414 3.1415 2.8 90 3.45 6.189] %[output:2e65d177]
%%
%Try this first
A_large([1 2], [1 2]) %[output:165c515e]
%[text] You notice that we just extract the the first two rows and first two columns of the matrix
%%
%Try this next
A_large([1 5 6], [3 4]) %[output:1898df77]
%[text] This time, we extract the the (1st & 5th & 6th rows) and (3rd & 4th columns) of the matrix
%%
% Recall that 2:5 = [2,3,4,5]
% 2:2:6 = [2,4,6]

% Try these:
A_large(2:5, 4) % from 2 to 5th rows, 4th cols %[output:14a33632]
A_large(1, 2:2:6) % 1st row, and from 2 to 6, extract every other cols, %[output:2e190029]
A_large(2:5, 2:2:6) %[output:10576579]
%%
% One more useful feature of using colon
% Try this:
A_large(2,:) %[output:9e4075cf]
A_large(:,6) %[output:3a363e7d]
%%
%[text] When putting just a colon on either row or column field of a matrix, it returns all entries of that dimension
%%
%[text] #### Bulk Modify
%%
% Bulk modify the elements
A_large(:,6) = 8;
A_large %[output:521d1889]
%%
% Bulk modify the elements

A_large([4,5],6) = [9; 10];

A_large(1,[4,5,6]) = [412, 413, 414];
A_large %[output:41cebd6d]
%%
%[text] #### Modify Out-of-bound
% Try to access out-of-bounds element
%x = A_large(1,9)
%y = A_large(8,2)
%%
% Try to modify out-of-bounds element
A_large(1,9) = 3.14;
A_large %[output:5acfb986]
%%
% Try to modify out-of-bounds element
A_large(8,2) = 3.14;
A_large %[output:1cd6bce3]
%%
%[text] An attempt to modify an out-of-bound element would just increase the size of matrix and fill the unassigned elements to 0s
%%
A_large(:,:) % no need to access in such a way, same as A_large %[output:0b223163]
A_large(:) % obtain a column vector of all entries %[output:3c39a42c]
A_large(:)' % obtain a row vector of all entries, we will learn ' transpose very soon %[output:1a55b5d4]
%%
%[text] ## Concatenate vectors of strings
%%
%str_vec = ['I', 'enjoy', 'MATLAB'];
str_vec = ['I ', 'enjoy ', 'MATLAB '];
horzcat(str_vec) %[output:4701bad5]
%%
%[text] ## num2str
%[text] Convert a number to a string
num = 12;
num2str(num) %[output:08512a3c]
%%
disp(['The number as a string is: ', num2str(num)]); % str can be viewed as an array/vector of char %[output:00284233]
%%
str_vec2 = ['from ', 'ENGR', num2str(num)];
horzcat(str_vec, str_vec2) %[output:95affbd7]
%%
%[text] ## Rounding Commands
num = 3.1415926;
round(num) %[output:7a0b5448]
ceil(num) %[output:2eecce3f]
floor(num) %[output:6a50cded]
fix(num) %[output:4f48af4e]
fix(-1.49999) %[output:5be3deef]
matrix_r = [0.5001, -0.4999; 1.501, 1.999] %[output:742c80bf]
fix(matrix_r) %[output:4b4f7ebb]
%%
%[text] ## Generate Random Numbers
%%
% Generate a random number between 0 and 1
rand %[output:580a5f76]
%%
% Generate a row vector of 5 random numbers between 0 and 1
rand_num = rand(1, 5) %[output:086bce91]
% Example output: [0.8147 0.9058 0.1270 0.9134 0.6324]
rand(3,2) %[output:937e9d0a]
%%
% Generate a random integer between 1 and 100
randi(100) %[output:536ed5e1]
%%
% Generate a row vector of 5 random integers between 1 and 100
randi_num = randi(100, [1,5]) %[output:4038d901]
%%
randi(100, 3) %[output:460780a1]
%%
% Generate a row vector of 8 random integers between -10 and 15
randi([-10,15], [1,8]) %[output:56baeae6]
%%
%[text] ## Statistics Functions
%%
% Let's first generate a row vector of 52 random integers from 60 to 100
% assume it is the final grade of our ENGR12 course
grades = randi([60,100], [1, 53]) %[output:0f3220cc]
%%
avg_grd = mean(grades);
median_grd = median(grades);
mode_grd = mode(grades);
stdev_grd = std(grades);
var_grd = var(grades);

avg_grd, median_grd, mode_grd, stdev_grd, var_grd %[output:05bbc632] %[output:9d459e09] %[output:84487f9a] %[output:72aec687] %[output:0f905337]
%%
% note that stdev ^ 2 = var
test1 = (stdev_grd^2 == var_grd) %[output:4295f5e1]
test2 = abs(stdev_grd^2-var_grd)<0.0000001 %[output:7b1f91d1]
%test1, test2 % will study true and false later!
%%
%[text] ## Revisit: Load, input in MATLAB
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
data = load('data.txt') %[output:53e0e3d1]
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
disp(['The element you inquired at Row ', num2str(x), ' Column ', num2str(y), ' of file ', file, ' is: ', num2str(result(x,y))]) %[output:9914bde9]
%%
%[text] ## If-elseif-else-end statement
%[text] <u>if (Condition 1)</u>
%[text]  <u>do thing 1</u>
%[text] elseif (Condition 2)
%[text]     do thing 2
%[text] elseif (do thing 3)
%[text]     do thing 3
%[text] ......
%[text] else
%[text]     do thing n
%[text] <u>end</u>
%[text] Underlined parts have to be there, others can be omitted as pair
%%
% Temperature Control Example
temperature = 75; % Example temperature value

if temperature < 60 %[output:group:5de78ba7]
    disp('The temperature is cold.')
elseif (temperature >=60 && temperature <=90)
    disp('The temperature is moderate.') %[output:1ca08746]
else
    disp('The temperature is hot.')
end %[output:group:5de78ba7]
%%
% Another example with user input
temp = input("please input a temp: ") %[output:8d6d06df]
if temp < 60 %[output:group:4be33015]
    disp('The temperature is cold.')
elseif (temp >=60 && temp<=90)
    disp('The temperature is moderate.')
else
    disp('The temperature is hot.') %[output:1448c77f]
end %[output:group:4be33015]

%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"inline","rightPanelPercent":37.1}
%---
%[output:4484dbfb]
%   data: {"dataType":"text","outputData":{"text":"A`s value is: □\n","truncated":false}}
%---
%[output:49ce25c4]
%   data: {"dataType":"text","outputData":{"text":"    \"A`s value is: \"    \"5.145\"\n\n","truncated":false}}
%---
%[output:205c5deb]
%   data: {"dataType":"text","outputData":{"text":"A`s value is: 5.14\n","truncated":false}}
%---
%[output:4a7b4d47]
%   data: {"dataType":"matrix","outputData":{"columns":12,"name":"c","rows":1,"type":"double","value":[["1","2","3","4","5","6","7","8","9","10","11","12"]]}}
%---
%[output:148ddb42]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"d","rows":1,"type":"double","value":[["15","11","7"]]}}
%---
%[output:9c6c3700]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"e","rows":1,"type":"double","value":[["15","11","7","3"]]}}
%---
%[output:2e65d177]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"A_large","rows":6,"type":"double","value":[["0.1000","0.0200","0.3000","40.0000","5.0000","600.0000"],["8.0000","9.0000","11.0000","12.0000","13.0000","16.0000"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","-9.0000"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","611.0000"],["36.0000","100.0000","31.0000","7.0000","3.0000","6.1100"],["-1.4140","3.1415","2.8000","90.0000","3.4500","6.1890"]]}}
%---
%[output:165c515e]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["0.1000","0.0200"],["8.0000","9.0000"]]}}
%---
%[output:1898df77]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":3,"type":"double","value":[["0.3000","40.0000"],["31.0000","7.0000"],["2.8000","90.0000"]]}}
%---
%[output:14a33632]
%   data: {"dataType":"matrix","outputData":{"columns":1,"name":"ans","rows":4,"type":"double","value":[["12.0000"],["-8.0000"],["5.8900"],["7.0000"]]}}
%---
%[output:2e190029]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"ans","rows":1,"type":"double","value":[["0.0200","40.0000","600.0000"]]}}
%---
%[output:10576579]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"ans","rows":4,"type":"double","value":[["9.0000","12.0000","16.0000"],["-2.0000","-8.0000","-9.0000"],["-90.0000","5.8900","611.0000"],["100.0000","7.0000","6.1100"]]}}
%---
%[output:9e4075cf]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"ans","rows":1,"type":"double","value":[["8","9","11","12","13","16"]]}}
%---
%[output:3a363e7d]
%   data: {"dataType":"matrix","outputData":{"columns":1,"name":"ans","rows":6,"type":"double","value":[["600.0000"],["16.0000"],["-9.0000"],["611.0000"],["6.1100"],["6.1890"]]}}
%---
%[output:521d1889]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"A_large","rows":6,"type":"double","value":[["0.1000","0.0200","0.3000","40.0000","5.0000","8.0000"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","8.0000"],["36.0000","100.0000","31.0000","7.0000","3.0000","8.0000"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000"]]}}
%---
%[output:41cebd6d]
%   data: {"dataType":"matrix","outputData":{"columns":6,"name":"A_large","rows":6,"type":"double","value":[["0.1000","0.0200","0.3000","412.0000","413.0000","414.0000"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","9.0000"],["36.0000","100.0000","31.0000","7.0000","3.0000","10.0000"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000"]]}}
%---
%[output:5acfb986]
%   data: {"dataType":"matrix","outputData":{"columns":9,"name":"A_large","rows":6,"type":"double","value":[["0.1000","0.0200","0.3000","412.0000","413.0000","414.0000","0","0","3.1400"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000","0","0","0"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000","0","0","0"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","9.0000","0","0","0"],["36.0000","100.0000","31.0000","7.0000","3.0000","10.0000","0","0","0"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000","0","0","0"]]}}
%---
%[output:1cd6bce3]
%   data: {"dataType":"matrix","outputData":{"columns":9,"name":"A_large","rows":8,"type":"double","value":[["0.1000","0.0200","0.3000","412.0000","413.0000","414.0000","0","0","3.1400"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000","0","0","0"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000","0","0","0"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","9.0000","0","0","0"],["36.0000","100.0000","31.0000","7.0000","3.0000","10.0000","0","0","0"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000","0","0","0"],["0","0","0","0","0","0","0","0","0"],["0","3.1400","0","0","0","0","0","0","0"]]}}
%---
%[output:0b223163]
%   data: {"dataType":"matrix","outputData":{"columns":9,"name":"ans","rows":8,"type":"double","value":[["0.1000","0.0200","0.3000","412.0000","413.0000","414.0000","0","0","3.1400"],["8.0000","9.0000","11.0000","12.0000","13.0000","8.0000","0","0","0"],["1.0000","-2.0000","4.0000","-8.0000","5.0000","8.0000","0","0","0"],["-67.0000","-90.0000","3.0000","5.8900","5.1200","9.0000","0","0","0"],["36.0000","100.0000","31.0000","7.0000","3.0000","10.0000","0","0","0"],["-1.4140","3.1415","2.8000","90.0000","3.4500","8.0000","0","0","0"],["0","0","0","0","0","0","0","0","0"],["0","3.1400","0","0","0","0","0","0","0"]]}}
%---
%[output:3c39a42c]
%   data: {"dataType":"matrix","outputData":{"columns":1,"name":"ans","rows":72,"type":"double","value":[["0.1000"],["8.0000"],["1.0000"],["-67.0000"],["36.0000"],["-1.4140"],["0"],["0"],["0.0200"],["9.0000"]]}}
%---
%[output:1a55b5d4]
%   data: {"dataType":"matrix","outputData":{"columns":72,"name":"ans","rows":1,"type":"double","value":[["0.1000","8.0000","1.0000","-67.0000","36.0000","-1.4140","0","0","0.0200","9.0000","-2.0000","-90.0000","100.0000","3.1415","0","3.1400","0.3000","11.0000","4.0000","3.0000","31.0000","2.8000","0","0","412.0000","12.0000","-8.0000","5.8900","7.0000","90.0000"]]}}
%---
%[output:4701bad5]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"'I enjoy MATLAB '"}}
%---
%[output:08512a3c]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"'12'"}}
%---
%[output:00284233]
%   data: {"dataType":"text","outputData":{"text":"The number as a string is: 12\n","truncated":false}}
%---
%[output:95affbd7]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"'I enjoy MATLAB from ENGR12'"}}
%---
%[output:7a0b5448]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"3"}}
%---
%[output:2eecce3f]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"4"}}
%---
%[output:6a50cded]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"3"}}
%---
%[output:4f48af4e]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"3"}}
%---
%[output:5be3deef]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"-1"}}
%---
%[output:742c80bf]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"matrix_r","rows":2,"type":"double","value":[["0.5001","-0.4999"],["1.5010","1.9990"]]}}
%---
%[output:4b4f7ebb]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":2,"type":"double","value":[["0","0"],["1","1"]]}}
%---
%[output:580a5f76]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"0.9797"}}
%---
%[output:086bce91]
%   data: {"dataType":"matrix","outputData":{"columns":5,"name":"rand_num","rows":1,"type":"double","value":[["0.4389","0.1111","0.2581","0.4087","0.5949"]]}}
%---
%[output:937e9d0a]
%   data: {"dataType":"matrix","outputData":{"columns":2,"name":"ans","rows":3,"type":"double","value":[["0.2622","0.2217"],["0.6028","0.1174"],["0.7112","0.2967"]]}}
%---
%[output:536ed5e1]
%   data: {"dataType":"textualVariable","outputData":{"name":"ans","value":"32"}}
%---
%[output:4038d901]
%   data: {"dataType":"matrix","outputData":{"columns":5,"name":"randi_num","rows":1,"type":"double","value":[["43","51","9","27","81"]]}}
%---
%[output:460780a1]
%   data: {"dataType":"matrix","outputData":{"columns":3,"name":"ans","rows":3,"type":"double","value":[["3","49","46"],["93","58","97"],["74","24","55"]]}}
%---
%[output:56baeae6]
%   data: {"dataType":"matrix","outputData":{"columns":8,"name":"ans","rows":1,"type":"double","value":[["3","-4","2","6","7","0","-1","15"]]}}
%---
%[output:0f3220cc]
%   data: {"dataType":"matrix","outputData":{"columns":53,"name":"grades","rows":1,"type":"double","value":[["61","96","97","92","64","70","73","87","65","89","64","86","80","91","89","97","96","73","88","68","61","90","80","79","97","85","85","95","93","83"]]}}
%---
%[output:05bbc632]
%   data: {"dataType":"textualVariable","outputData":{"name":"avg_grd","value":"80.8491"}}
%---
%[output:9d459e09]
%   data: {"dataType":"textualVariable","outputData":{"name":"median_grd","value":"83"}}
%---
%[output:84487f9a]
%   data: {"dataType":"textualVariable","outputData":{"name":"mode_grd","value":"61"}}
%---
%[output:72aec687]
%   data: {"dataType":"textualVariable","outputData":{"name":"stdev_grd","value":"12.5811"}}
%---
%[output:0f905337]
%   data: {"dataType":"textualVariable","outputData":{"name":"var_grd","value":"158.2845"}}
%---
%[output:4295f5e1]
%   data: {"dataType":"textualVariable","outputData":{"header":"logical","name":"test1","value":"   1\n"}}
%---
%[output:7b1f91d1]
%   data: {"dataType":"textualVariable","outputData":{"header":"logical","name":"test2","value":"   1\n"}}
%---
%[output:53e0e3d1]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"data","rows":4,"type":"double","value":[["1","2","3","4"],["5","6","7","8"],["9","10","11","12"],["13","14","15","16"]]}}
%---
%[output:9914bde9]
%   data: {"dataType":"text","outputData":{"text":"The element you inquired at Row 3 Column 4 of file data.txt is: 12\n","truncated":false}}
%---
%[output:1ca08746]
%   data: {"dataType":"text","outputData":{"text":"The temperature is moderate.\n","truncated":false}}
%---
%[output:8d6d06df]
%   data: {"dataType":"textualVariable","outputData":{"name":"temp","value":"400"}}
%---
%[output:1448c77f]
%   data: {"dataType":"text","outputData":{"text":"The temperature is hot.\n","truncated":false}}
%---
