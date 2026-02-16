%[text] # Week 4 Worksheet (Interactive, Optional to Try and Study)
%[text] The worksheet is a comprehensive summary of the lecture material, organized into Live Script sections. Concise comments are added where needed to clarify difficult topics. You can request to access the solution or simply ask to address your concerns.
%%
%[text] ## File Input/Output and Data Management
%%
%[text] ### Different Loading Practices (Not Recommended)
%[text] While the following methods work, they are not recommended due to unclear variable naming.
R = randi(15, 3, 4);
save("datafile.txt", "R", "-ascii")

% Some working but not recommended loading practice:
% Default variable name after loading
load("datafile.txt");  % It creates a variable named 'datafile'
load datafile.txt;     % It creates a variable named 'datafile'
%%
%[text] ### Error Checking When Loading Files
%[text] Best practice is to use error checking with `exist()` to ensure the file exists before loading.
filename = input('Please enter file name: ', 's');
while exist(filename, 'file') == 0
    filename = input('Please enter file name: ', 's');
end
% Alternatively, hard-code: filename = 'datafile.txt'
matrix = load(filename);
%%
%[text] ## Loops: Challenging Practices
%[text] Apply loops to solve more complex problems. We'll practice finding specific values and computations.
%%
%[text] #### Example 1: Find the Average of Values Greater than a Threshold
%[text] Find the average of all vector entries whose value is greater than 25.
vec2 = randi([-50, 50], 1, 20);
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

avg_of_25_more = currentSum / currentCount;
%%
%[text] #### Example 2: Find the Largest Perfect Square in a Range
%[text] Find the largest perfect square number in the range \[2000, 2050\].
%[text] A number is a perfect square if sqrt(var) equals floor(sqrt(var)).
%[text] Algorithm:
%[text] 1. Initialize currentlargest = 0
%[text] 2. For var = 2000, 2001, ..., 2050
%[text] 3. Check if var is a perfect square
%[text] 4. Update currentlargest if true
%[text] 5. End loop and display currentlargest \
currentlargest = 0;
for var = 2000:2050
    if sqrt(var) == floor(sqrt(var))
        currentlargest = var;
    end
end
disp(currentlargest) %[output:187d43c3]
%%
%[text] ## Create and Call Functions
%[text] Functions are useful tools to perform common tasks without recreating code. They encapsulate logic and make code reusable.
%[text] There are four types of functions based on inputs and outputs.
%%
%[text] ### Function Types Summary Table
%[text] Overview of all function types and their usage patterns:
%[text:table]{"columnWidths":[-1,-1,-1,220,169,-1]}
%[text] | Type | Inputs | Outputs | Function Signature (First Line) | Function Call In Main | Function Body Example |
%[text] | --- | --- | --- | --- | --- | --- |
%[text] | 1 | No | No | `function function_name()` | `function_name()` | <p>`function greet()`</p><p> `disp('Hi');`</p><p>`end`</p> |
%[text] | 2 | No | Yes | `function [out1, out2] = function_name()` | `[var1, var2] = function_name()` | <p>`function [x, y] = getData()`</p><p> `x=5;`</p><p> `y=10;`</p><p>`end`</p> |
%[text] | 3 | Yes | No | `function function_name(in1, in2)` | `function_name(val1, val2)` | <p>`function show(base, height)`</p><p> `disp(base*height);`</p><p>`end`</p> |
%[text] | 4 | Yes | Yes | `function [out1, out2] = function_name(in1, in2)` | `[var1, var2] = function_name(val1, val2)` | <p>`function [c,a]=calcTriangle(a,b)`</p><p> `c=sqrt(a^2+b^2);`</p><p> `a=0.5*a*b;`</p><p>`end`</p> |
%[text:table]
%%
%[text] ### Detailed Examples For Each Function Type:
%%
%[text] #### Type 1: No Inputs and No Outputs
%[text] The simplest function type. Call the function and it performs an action.
% TODO: Call display_welcome() to run the example.

% TODO: Define function display_welcome() with no inputs or outputs.
% TODO: Inside, display two welcome lines using disp.
%%
%[text] #### Type 2: No Inputs but Has Outputs
%[text] Create and return data without requiring input parameters.
% TODO: Call generate_values() and capture three outputs.
% TODO: Optionally display the returned values with disp.

% TODO: Define function [x, y, z] = generate_values() that sets x=5, y=10, z=15.
%%
%[text] #### Type 3: Has Inputs but No Outputs
%[text] Process data and display results without returning values.
% TODO: Call display_triangle with 4 and 6 to show the area.

% TODO: Define function display_triangle(base, height).
% TODO: Compute area = 0.5 * base * height and display "Triangle Area: <value>".
%%
%[text] #### Type 4: Has Both Inputs and Outputs
%[text] The most versatile function type. Process input data and return computed results.
% TODO: Call calculate_triangle with 3 and 4 and capture hypotenuse and area.

% TODO: Define function [c, area] = calculate_triangle(a, b).
% TODO: Compute c = sqrt(a^2 + b^2) and area = 0.5 * a * b.
%%
%[text] #### Practice: Calling Functions and Observing Variable Names
%[text] Important: Variables in functions are LOCAL to that function. Only output variables appear in the main workspace.
%[text] Example: Calling Type 4 function with different variable names
% TODO: Set side1 and side2 values.
% TODO: Call calculate_triangle(side1, side2) and store outputs in h and t.
%[text] What variables are added to workspace after this line?
%[text] - Answer: Only h and t (the output variables).
%[text] - The function parameters a, b and local variables c, area are NOT in the workspace \
%%
%[text] ## Spotlight: Variable Names in Main Script vs. Function
%[text] One major advantage of functions is that variable names in the function do NOT need to match variable names in the main script. Variables are passed by POSITION, not by NAME.
%%
%[text] #### KEY CONCEPT: Position-Based Parameter Passing
%[text] Variables are matched by POSITION, not by NAME. When you call a function:
%[text] 1. Input values are passed in order to function parameters
%[text] 2. Function processes the data with its own variable names
%[text] 3. Output values are returned in order to your specified variables
%[text] 4. ONLY the output variables appear in the workspace \
%%
%[text] ### Example 1: Simple Variable Name Change
%[text] In this example, we have different variable names in the main vs. the function.
% TODO: Set side3 and side4 values.
% TODO: Call calculate_triangle(side3, side4) and store outputs in hypotenuse and s.

% Note: FUNCTION DEFINITION is same as above (Type 4 function)
%%
%[text] WHAT HAPPENS:
%[text] - `side3` (value 3) is passed to parameter 'a' (position 1)
%[text] - `side4` (value 4) is passed to parameter 'b' (position 2)
%[text] - Function calculates `c` and `area` using local variables
%[text] - `c` value is returned to `hypotenuse` (position 1)
%[text] - `area` value is returned to `s` (position 2) \
%[text] WORKSPACE CONTAINS:
%[text] - `side3, side4, hypotenuse, s` \
%[text] WORKSPACE DOES NOT CONTAIN:
%[text] - `a, b, c, area` (these are local to the function) \
%%
%[text] ### Example 2: More Complex Variable Name Changes
%[text] All variables change names between main and function
% MAIN SCRIPT:
% TODO: Set x, y, z values with 5/10/3
% TODO: Call math_operation(x, y, z) and store outputs in result1, result2, result3.

% FUNCTION DEFINITION:
% TODO: Define function [out_a, out_b, out_c] = math_operation(in1, in2, in3).
% TODO: Compute out_a = in1 + in2, out_b = in1 * in2, out_c = in3^2
%%
%[text] #### POSITION-BY-POSITION MAPPING:
%[text] INPUT SIDE (when calling function):
%[text] - Position 1: x (value 5) → receives as in1
%[text] - Position 2: y (value 10) → receives as in2
%[text] - Position 3: z (value 3) → receives as in3 \
%[text] OUTPUT SIDE (returning from function):
%[text] - Position 1: out\_a (value 15) → returns to result1
%[text] - Position 2: out\_b (value 50) → returns to result2
%[text] - Position 3: out\_c (value 9) → returns to result3 \
%[text] WORKSPACE AFTER CALL:
%[text] - Contains: `x=5, y=10, z=3, result1=15, result2=50, result3=9`
%[text] - DOES NOT contain: `in1, in2, in3, out_a, out_b, out_c` \
%%
%[text] ### Example 3: Variable Passing and Returning By Position
% MAIN SCRIPT:
% TODO: Set a and b values with 10/20
% TODO: Call my_function(b, a) and store the returned value in b.

% FUNCTION:
% TODO: Define function n = my_function(m, n).
% TODO: Display m and n, then set n = m + n and return it.
%%
%[text] #### POSITION-BY-POSITION MAPPING:
%[text] INPUT SIDE (when calling function):
%[text] - Position 1: b (value 20) → receives as m
%[text] - Position 2: a (value 10) → receives as n \
%[text] OUTPUT SIDE (returning from function):
%[text] - Position 1: n (value 30) → returns to b \
%[text] WORKSPACE AFTER CALL:
%[text] - Contains: a=10, b=30 (b changed from 20 to 30)
%[text] - DOES NOT contain: n, m \
%%
%[text] ## Solving Systems of Linear Equations
%[text] Learn to solve systems of equations using matrix algebra and MATLAB functions.
%%
%[text] ### Basic Concept
%[text] Express a system of equations in matrix form: Ax = b
%[text] - A = coefficient matrix
%[text] - x = unknowns (what we're solving for)
%[text] - b = constants (right-hand side) \
%%
%[text] #### Example System:
%[text] x + 2y + z = 3
%[text] 4x - y + 3z = 7
%[text] 3x + 5y - 3z = 8
%[text] Matrix form:
%[text] A = \[1  2  1\]      b = \[3\]
%[text]     \[4 -1  3\]          \[7\]
%[text]     \[3  5 -3\]          \[8\]
%%
%[text] ### Simple Approach (for Specific Data File)
%[text] When you have a hardcoded data file path and know its structure:
% Load data from 'datafile.txt' into matrix_data.
% TODO: Extract A_hardcoded as the first 3 columns and first 3 rows.
% TODO: Extract b_hardcoded as the last column of the first 3 rows.
%%
%[text] ### Flexible Approach (Handles Different Data Files and Sizes)
%[text] More robust solution that works with any properly formatted data file.
% Step 1: Ask user to enter filename and check if it exists


% Step 2: Load the data and determine dimensions automatically


% Step 3: Extract matrix A and vector b


%%
%[text] ### Solving Ax = b with Error Checking
%[text] Before solving, we must verify two important conditions:
%[text] 1. Matrix A must be square (number of rows = number of columns)
%[text] 2. Determinant of A must not equal zero (det(A) ≠ 0) for a unique solution \
% Check if A is square
% TODO: If not, display an error about A not being square.

% TODO: Otherwise, check if det(A) == 0 and display a singular error if so.

% TODO: If A is square and non-singular, compute x
%%
%[text] ## Linear-Algebra Related Functions
%[text] Essential functions for solving systems of equations and matrix operations.
%[text] Choose the right function based on your needs:
%%
%[text] ### Linear Algebra Functions Reference Table
%[text] Overview of essential functions and their usage patterns:
%[text:table]
%[text] | Useful Function | Keyword | What Does It Do? | Example |
%[text] | --- | --- | --- | --- |
%[text] | Transpose | `transpose(A)` or `A'` | Converts rows to columns and vice versa | `B = A'` creates transposed matrix B |
%[text] | Determinant | `det(A)` | Returns scalar value; det(A)=0 means singular matrix | <p>`d = det(A);`</p><p>`if d==0`</p><p> `disp('singular')`</p><p>`end`</p> |
%[text] | Inverse | `inv(A)` or `A^(-1)` | Returns inverse of square matrix A | <p>`A_inv = inv(A)` or </p><p>`A_inv = A^(-1)`</p> |
%[text] | Solve Ax=b | `x = A\b` or `x = inv(A)*b` | Solves system of equations | `x = A\b` is more efficient than `inv(A)*b` |
%[text] | Matrix Size | `size(A)` | Returns \[rows, cols\] dimensions | `[m, n] = size(A)` extracts dimensions |
%[text:table]
%%
%[text] ## Solving Trace Problems
%[text] Practice with detailed trace execution and variable tracking.
%[text] ### Trace Example 3b: Loop Division Problem
%[text] #### **Answer:**
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
%[text] #### **Scratch Work:**
%[text] Track all variables' values throughout the loop execution.
%[text] (This is for your understanding, showing how variables change each iteration)
%[text:table]{"ignoreHeader":true}
%[text] | Change of a: | 1 | 2 | 3 | 4 | 5 |
%[text] | --- | --- | --- | --- | --- | --- |
%[text] | Change of b: | 7 | 6 | 5 | 4 | 3 |
%[text] | Change of num: | 0 | 1 | 2 | 3 | 4 |
%[text] | Change of initial: | 199 | 99 | 49 | 24 | 12 |
%[text:table]
%%
%[text] ### Running All Trace Examples
%[text] Execute all practice traces to verify your understanding:
% Call main function to run all traces
run_all_traces() %[output:1b7e1e78] %[output:59a145d0] %[output:5a59717e] %[output:161ebc96] %[output:0cc7e694] %[output:0f93bc63] %[output:8738d257] %[output:66e9fc0e] %[output:80c722d5] %[output:806d826c] %[output:0273da4a] %[output:3d50c9d2] %[output:9e0130ae] %[output:32f6339b] %[output:16065f20] %[output:1e62e70d] %[output:9f4c1f30]
function run_all_traces() %MARKED
disp('____________________________')
disp('Running trace_1a:')
disp(repmat(char([32, 773]), 1, 28))
trace_1a()

disp('____________________________')
disp('Running trace_1b:')
disp(repmat(char([32, 773]), 1, 28))
trace_1b()

disp('____________________________')
disp('Running trace_1c:')
disp(repmat(char([32, 773]), 1, 28))
trace_1c()

disp('____________________________')
disp('Running trace_2a:')
disp(repmat(char([32, 773]), 1, 28))
trace_2a()

disp('____________________________')
disp('Running trace_2b:')
disp(repmat(char([32, 773]), 1, 28))
trace_2b()

disp('____________________________')
disp('Running trace_3a:')
disp(repmat(char([32, 773]), 1, 28))
trace_3a()

disp('____________________________')
disp('Running trace_3b:')
disp(repmat(char([32, 773]), 1, 28))
trace_3b()
end


function trace_1a()

x = [-2, 3, 0, 5, 4, 2, 1, -11];
new = 11;
for i = 1:3:length(x)
    new = new + x(i);
end
disp(new)

end

function trace_1b()

j = 25;
for i = 20:-5:1
    j = j + i
end
display(j)

end

function trace_1c()

c = 5;
b = 15;
while c < 15
    b = b - c;
    c = c + 2;
end
disp(b)

end

function trace_2a()

disp('Start Here');
oldvariable = 10;
k = 1;
while k <= 10
    if (k < 3)
        newvariable = k + 2
    elseif (k <= 7 & k > 4)
        oldvariable = k * 2;
        disp(oldvariable)
    elseif (k == 10 | k == 12)
        oldvariable = k;
        disp('oldvariable')
    else
        newvariable = oldvariable - 1;
        disp(newvariable)
    end
    k = k + 1;
end
disp('End Now')

end

function trace_2b()

disp('Start Here');
A = [1 2 3 4 5 6 7 8 9 10];
oldvariable = 10;
total = 5;
j = 0;
for i = 1:2:oldvariable
    total = total + i;
    disp(['total = ', num2str(total)])
    j = j + 1;
    disp(['j = ', num2str(j)])
end
disp(['i = ', num2str(i)])
disp('End Now');

end

function trace_3a()

disp('Traces!')
x = [1 3 0 2 3 2 4 1]
s = 2
count = 0;
%Loop
while s <= 5
    for i = 8:-4:4
        count = count + x(i);
    end
    s = s + 2;
end
disp(['The result is ', num2str(count)])
disp(['The mean is ', num2str(mean(x))])

end

function trace_3b()

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
disp('Done');

end

%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"inline","rightPanelPercent":40}
%---
%[output:187d43c3]
%   data: {"dataType":"text","outputData":{"text":"        2025\n\n","truncated":false}}
%---
%[output:1b7e1e78]
%   data: {"dataType":"text","outputData":{"text":"____________________________\nRunning trace_1a:\n ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅\n    15\n\n____________________________\nRunning trace_1b:\n ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅\n","truncated":false}}
%---
%[output:59a145d0]
%   data: {"dataType":"textualVariable","outputData":{"name":"j","value":"45"}}
%---
%[output:5a59717e]
%   data: {"dataType":"textualVariable","outputData":{"name":"j","value":"60"}}
%---
%[output:161ebc96]
%   data: {"dataType":"textualVariable","outputData":{"name":"j","value":"70"}}
%---
%[output:0cc7e694]
%   data: {"dataType":"textualVariable","outputData":{"name":"j","value":"75"}}
%---
%[output:0f93bc63]
%   data: {"dataType":"textualVariable","outputData":{"name":"j","value":"75"}}
%---
%[output:8738d257]
%   data: {"dataType":"text","outputData":{"text":"____________________________\nRunning trace_1c:\n ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅\n   -30\n\n____________________________\nRunning trace_2a:\n ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅\nStart Here\n","truncated":false}}
%---
%[output:66e9fc0e]
%   data: {"dataType":"textualVariable","outputData":{"name":"newvariable","value":"3"}}
%---
%[output:80c722d5]
%   data: {"dataType":"textualVariable","outputData":{"name":"newvariable","value":"4"}}
%---
%[output:806d826c]
%   data: {"dataType":"text","outputData":{"text":"     9\n\n     9\n\n    10\n\n    12\n\n    14\n\n    13\n\n    13\n\noldvariable\nEnd Now\n____________________________\nRunning trace_2b:\n ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅\nStart Here\ntotal = 6\nj = 1\ntotal = 9\nj = 2\ntotal = 14\nj = 3\ntotal = 21\nj = 4\ntotal = 30\nj = 5\ni = 9\nEnd Now\n____________________________\nRunning trace_3a:\n ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅\nTraces!\n","truncated":false}}
%---
%[output:0273da4a]
%   data: {"dataType":"matrix","outputData":{"columns":8,"name":"x","rows":1,"type":"double","value":[["1","3","0","2","3","2","4","1"]]}}
%---
%[output:3d50c9d2]
%   data: {"dataType":"textualVariable","outputData":{"name":"s","value":"2"}}
%---
%[output:9e0130ae]
%   data: {"dataType":"text","outputData":{"text":"The result is 6\nThe mean is 2\n____________________________\nRunning trace_3b:\n ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅ ̅\n","truncated":false}}
%---
%[output:32f6339b]
%   data: {"dataType":"textualVariable","outputData":{"name":"initial","value":"199"}}
%---
%[output:16065f20]
%   data: {"dataType":"text","outputData":{"text":"Division times: 1\nDivision times: 2\nDivision times: 3\nDivision times: 4\n","truncated":false}}
%---
%[output:1e62e70d]
%   data: {"dataType":"textualVariable","outputData":{"name":"last","value":"12"}}
%---
%[output:9f4c1f30]
%   data: {"dataType":"text","outputData":{"text":"Done\n","truncated":false}}
%---
