function X0 = pinghua(X0, i, j, k)
a = 10;
if i >= 11 && i <= 21 && j >=11 && j <=339
%    M = [X0(i-1, j-1, k) X0(i, j-1, k) X0(i+1, j-1, k) X0(i-1, j, k) X0(i+1, j, k) X0(i-1, j+1, k) X0(i, j+1,k) X0(i+1,j+1,k) ];
    M = [X0(i-a, j-a, k) X0(a, j-a, k) X0(i+a, j-a, k) X0(i-a, j, k) X0(i+a, j, k) X0(i-a, j+a, k) X0(i, j+a,k) X0(i+a,j+a,k) ];
    M = find(M > 0);
    X0(i, j, k) = median(M);
end
