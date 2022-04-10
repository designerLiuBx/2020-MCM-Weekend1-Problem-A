function [U, X0, C, D] = Gray_Forecast(X0)
[X0, C, D] = data_test(X0);

alpha = 0.5;
[lat, lon, year]=size(X0);
Z = zeros(lat, lon, year-1);
U = zeros(lat, lon, 2);
X1 = X0;
for i =1 : lat
    for j = 1 : lon
       for k = 2 : year
           X1(i, j, k) = X1(i, j, k) + X1(i, j, k-1);
       end
    end
end
for i = 1 : lat
    for j = 1 : lon
        for k = 2 : year
            Z(i,  j , k) = alpha*X1(i, j, k) + (1-alpha)*X1(i, j, k-1);
        end
    end
end
for i = 1: lat
    for j = 1 : lon
        Y = squeeze(X0(i, j, 2:end));
        Z1 = -squeeze(Z(i, j, 2:end)); 
        C1 = ones(year-1, 1);
        B = [Z1 C1];
        u = inv(B'*B)*B'*Y;
        U(i, j, 1) = u(1, 1);
        U(i, j, 2) = u(2,1);
    end
end
