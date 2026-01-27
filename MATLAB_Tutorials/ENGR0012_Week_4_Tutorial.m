%[text] # Week 4
%[text] ## Load Text Files, Save to Variable
mydata = load('datafile.txt') %[output:1eca87ba]
%[text] if datafile.txt is 4 5 6 7, mydata will be a 1x4 vector
%%
% default variable name after loading
load('datafile.txt');  % it creates a variable named 'datafile'
%%
%[text] ## User input string and input numbers
%[text] Prompt user for a string input and number input
userString = input('Enter a string: ', 's'); % check workspace

% Prompt user for a numeric input
userNumber = input('Enter a number: '); % check workspace
%%
%[text] ## Relation Operators (\>, \<, \>=, \<=, ==, ~=)
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
if a > b %[output:group:183b72d3]
    disp('a is greater than b');
else
    disp('a is not greater than b'); %[output:5440943c]
end %[output:group:183b72d3]
if f2 %[output:group:722d0910]
    disp('a is less than b'); %[output:8f7956c3]
else
    disp('a is not less than b');
end %[output:group:722d0910]
%%
%[text] ## Logic Operators (&&, ||, ~)
%[text] - Both statement 1 AND statement 2 are true:  s1 && s2 
%[text] - At least one of statement 1 OR statement 2 is true:    s1 || s2
%[text] - NOT statement 1 is true:   ~s1 \
%%
valid1 = (userString == "hello" || userString == "hi");
%%
% TODO1: valid2 denotes that userNumber is between 50 and 100 (inclusive)

% Answer:

valid2 = (userNumber <=100 && userNumber >= 50);
%%
valid3 = ~(a>b);
%%
%[text] ## If-end statement, If-else-end, If-elseif-else-end
temperature = 75;

if temperature < 60 %[output:group:1bf636ac]
    disp('The temperature is cold.')
elseif (temperature < 90 && temperature >= 60)
    disp('The temperature is moderate.') %[output:1299c52b]
else
    disp('The temperature is hot.')
end %[output:group:1bf636ac]
%%
%[text] ## Switch Case
%[text] switch var 
%[text]         case value1 
%[text]                 statement1 
%[text]         case value2 
%[text]                 statement2 
%[text]         otherwise
%[text]                 statement3
day = input('Enter a number (1-7) to represent the day of the week: ');
switch day %[output:group:80bdd028]
    case 1
        disp('Monday')
    case 2
        disp('Tuesday')
    case 3
        disp('Wednesday')
    case 4
        disp('Thursday') 
    case 5
        disp('Friday') %[output:3409dd9c]
    case {6, 7}
        disp('Weekends')
    otherwise
        disp('Invalid input. Please enter a number between 1 and 7.')
end %[output:group:80bdd028]
%%
%[text] ## While-loop
%[text] Example: buffet-eat strategy
full_stomach = 10; % 10 plates
eaten = 0;
while (eaten < full_stomach)

    plates = input('How many more plates do you want to eat? ');
    eaten = eaten + plates;

end
disp('You are finally full!'); %[output:0b6687a6]
%%
%[text] `while (condition)`
%[text]  `Statement block that could change the condition` 
%[text] `end`
%[text] 
%[text] Each time executing the statement block, check the condition again
%[text] If the condition is still true, execute the statement block again
%[text] otherwise, exit the while-loop
%%
%[text] Example: use while-loop to go through vector element
vec = randi([-5, 5], 1, 10); % random integer vector

i = 1;
while (i<= length(vec)) %[output:group:7cb014fa]
    disp(vec(i)); %[output:06c1fedd]
    i = i + 1;
end %[output:group:7cb014fa]
%%
%[text] ## For-loop
%[text] Example: use for-loop to go through vector element
% TODO2: every 3rd element of vec 1 4 7 10

% Answer:

for i = 1:3:length(vec) %[output:group:7dc016d5]
 disp(vec(i)) %[output:50e00284]
end %[output:group:7dc016d5]
%%
%[text] `for var = start:increment:end` <u>or</u> `for var = start:end` <u>or</u> `for var = [x1 x2 x3 ...]`
%[text]  `statement block related to var or not`
%[text] `end`
%%
for x = [0, pi/4, pi/2, 3*pi/4, pi] %[output:group:3176bcae]
    disp(sin(x)); %[output:6f0729d9]
end %[output:group:3176bcae]
%%
% TODO3: use for-loop to display the sqrt of all integers from 2020 to 2030

% Answer:

for i = 2020:2030 %[output:group:614b9cc9]
    disp(sqrt(i)) %[output:92af1ef9]
end %[output:group:614b9cc9]
%%
% Try: for-loop to find largest number
vec2 = randi([-50, 50], 1, 9);
largest = vec2(1);
for i = 1:length(vec2)

    % TODO4: change the if statement to finish this work based on your understanding

    % Answer:

    if (vec2(i)>largest)

        largest = vec2(i);
    end
end
disp(largest); %[output:1f5d9e02]
%%
%[text] ## Loops Practice
%[text] Try: while-loop to find avg of (numbers \> 25)
currentSum = 0;
currentCount = 0;
loopIndex = 1;

while (loopIndex <= length(vec2))
    if (vec2(loopIndex) > 25)
        currentSum = currentSum + vec2(loopIndex);
        currentCount = currentCount + 1;
    end
    loopIndex = loopIndex + 1;
end

avg_of_25_more = currentSum/currentCount %[output:85e8c975]
%%
%[text] Try: error-check of a user input until user gives a valid number between 2000 to 2050
inputYear = input('Enter a year between 2000 and 2050: ');
while (inputYear < 2000 || inputYear > 2050)
    inputYear = input('Enter a year between 2000 and 2050: ');
end
%%
%[text] Try: find the largest square number in this range (2000, 2050)
% TODO 5: use the following pseudocode
% 1. currentlargest = 0;
% 2. for var = 2000, 2001, ..., 2050
% 3. how to determine var is a square number : its sqrt is equal to the floor of its sqrt
% 4. currentlargest = var;
% 5. end and display currentlargest

% Answer:

currentlargest = 0;
for var = 2000:2050
    if sqrt(var) == floor(sqrt(var))
        currentlargest = var;
    end
end
disp(currentlargest) %[output:12862552]
%%
%[text] ## Solve a Trace Problem
%[text] 
%[text] **TODO 6: finish this trace problem**
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
initial = 199
while a <= b
    if mod(initial, 2) == 1
        initial = (initial - 1) / 2;
    else
        initial = initial / 2;
    end
    num = num + 1;
    disp(['Division times: ', num2str(num)]);
    a = a + 1;
    b = b - 1;
end
last = initial
disp('Done'); %[output:6f5279af] %[output:4fcb9ad2] %[output:4c4b1916] %[output:43d361d7]
%%
%[text] ## Create and Call functions
%----------------------You can save it as func1.m----------------------
function func1()
    disp('This is a function without input or output, it just displays a message');
end
%----------------------You can save it as func1.m----------------------
%%
%----------------------You can save it as func2.m----------------------
function func2(a)
    disp('This is a function with one input but no output, it displays the input');
    disp(a);
end
%----------------------You can save it as func2.m----------------------
%%
%----------------------You can save it as func3.m----------------------
% This function has outputs but no inputs
function [a, b] = func3()
    a = 1;
    b = 2;
end
%----------------------You can save it as func3.m----------------------
%%
%----------------------You can save it as func4.m----------------------
% This function has two outputs and two inputs
function [c,area] = fun4(a, b)
    c = sqrt(a^2 + b^2);
    area = 0.5*a * b;
end
%----------------------You can save it as func4.m----------------------
%%
%----------------------You can save it as func5.m----------------------
% This function has one output and one input
function y = func5(x)
    y = x^6 + 2*x^5 - 3*x^4 + 4*x^3 - 5*x^2 + 6*x - 7;
end
%----------------------You can save it as func5.m----------------------
%%
func1(); %[output:455a118a]
func2(15); %[output:95793ff4]
[res_a, res_b] = func3();
%%
clear
clc
%%
% TODO7: what vars are added to workspace after this line? a? b? c? area? res_c? res_area?
[res_c, res_area] = fun4(3, 4);

% Answer:

% it will be res_c, res_area, others are not in the workspace
%%
y1 = func5(1); % evaluate func5 at x=1

% You can also try creating .m files and calling functions within the m.file
%%
%[text] ## Solving Ax=b on text-stored matrix:
matrix_data = load('data.txt'); % you may incorporate this into an error checking loop
A_fix = matrix_data(1:3, 1:3); % extract data
b_fix = matrix_data(1:3, 4);

% what if A is 7x8 not 3x4? We can flexible
[rows, cols] = size(matrix_data);
A = matrix_data(:, 1:rows); % A matrix
b = matrix_data(:, rows+1); % b vector
%%
% x = A\b; another way to denote solution

if det(A) == 0 %[output:group:804dc312]
    disp('Matrix is singular, linear system has no unique solution');
else
    x = A^(-1)*b;
    disp(x); %[output:75a3e1f9]
end %[output:group:804dc312]
%%
filename='CountryA.txt';
while exist(filename)==0
    filename=input('Please enter file name: ','s');
end
matrix = load(filename);

%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"inline","rightPanelPercent":40}
%---
%[output:1eca87ba]
%   data: {"dataType":"matrix","outputData":{"columns":4,"name":"mydata","rows":1,"type":"double","value":[["4","5","6","7"]]}}
%---
%[output:5440943c]
%   data: {"dataType":"text","outputData":{"text":"a is not greater than b\n","truncated":false}}
%---
%[output:8f7956c3]
%   data: {"dataType":"text","outputData":{"text":"a is less than b\n","truncated":false}}
%---
%[output:1299c52b]
%   data: {"dataType":"text","outputData":{"text":"The temperature is moderate.\n","truncated":false}}
%---
%[output:3409dd9c]
%   data: {"dataType":"text","outputData":{"text":"Friday\n","truncated":false}}
%---
%[output:0b6687a6]
%   data: {"dataType":"text","outputData":{"text":"You are finally full!\n","truncated":false}}
%---
%[output:06c1fedd]
%   data: {"dataType":"text","outputData":{"text":"    -4\n\n     2\n\n    -5\n\n    -2\n\n    -5\n\n    -4\n\n     4\n\n     2\n\n    -2\n\n     5\n\n","truncated":false}}
%---
%[output:50e00284]
%   data: {"dataType":"text","outputData":{"text":"    -4\n\n    -2\n\n     4\n\n     5\n\n","truncated":false}}
%---
%[output:6f0729d9]
%   data: {"dataType":"text","outputData":{"text":"     0\n\n    0.7071\n\n     1\n\n    0.7071\n\n   1.2246e-16\n\n","truncated":false}}
%---
%[output:92af1ef9]
%   data: {"dataType":"text","outputData":{"text":"   44.9444\n\n   44.9555\n\n   44.9667\n\n   44.9778\n\n   44.9889\n\n    45\n\n   45.0111\n\n   45.0222\n\n   45.0333\n\n   45.0444\n\n   45.0555\n\n","truncated":false}}
%---
%[output:1f5d9e02]
%   data: {"dataType":"text","outputData":{"text":"    46\n\n","truncated":false}}
%---
%[output:85e8c975]
%   data: {"dataType":"textualVariable","outputData":{"name":"avg_of_25_more","value":"36"}}
%---
%[output:12862552]
%   data: {"dataType":"text","outputData":{"text":"        2025\n\n","truncated":false}}
%---
%[output:6f5279af]
%   data: {"dataType":"textualVariable","outputData":{"name":"initial","value":"199"}}
%---
%[output:4fcb9ad2]
%   data: {"dataType":"text","outputData":{"text":"Division times: 1\nDivision times: 2\nDivision times: 3\nDivision times: 4\n","truncated":false}}
%---
%[output:4c4b1916]
%   data: {"dataType":"textualVariable","outputData":{"name":"last","value":"12"}}
%---
%[output:43d361d7]
%   data: {"dataType":"text","outputData":{"text":"Done\n","truncated":false}}
%---
%[output:455a118a]
%   data: {"dataType":"text","outputData":{"text":"This is a function without input or output, it just displays a message\n","truncated":false}}
%---
%[output:95793ff4]
%   data: {"dataType":"text","outputData":{"text":"This is a function with one input but no output, it displays the input\n    15\n\n","truncated":false}}
%---
%[output:75a3e1f9]
%   data: {"dataType":"text","outputData":{"text":"   -0.3333\n    0.0417\n    1.4167\n\n","truncated":false}}
%---
