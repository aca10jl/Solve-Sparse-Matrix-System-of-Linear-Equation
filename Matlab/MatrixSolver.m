% record starting time
tic

% set working directory to the current folder
currentFolder = pwd;

% load matrix A
load A.txt

% load vector b
load b.txt

% convert matrix A from zero-based index to one-based index
A = [(A(:,1:2)+1),A(:,(3))];

% convert density matrix A to a sparse matrix
A = spconvert(A);

% set iteration stop criteria
tol = 1e-3;
maxit = 1000;

% execute lsqr algorithm to solve the linear equation problem
x = lsqr(A,b,tol,maxit);

% % validate results
% out = ((norm(A*x-b))^2)/2;
% out < 1e-3

% write results into a file
save('out.txt', 'x', '-ascii')

% display the elapsed time
toc