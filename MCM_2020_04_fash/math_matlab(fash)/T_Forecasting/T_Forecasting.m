function [X_0, deta, D] =T_Forecasting( X0, set_years)
format long 
[U, X0, C, D] = Gray_Forecast(X0);
[lat, lon, year] = size(X0);
A = zeros(lat, lon);
B = zeros(lat, lon);
X_1= zeros(lat, lon, set_years);
X_1(:, :, 1) = X0(:, :, 1);
X_0= zeros(lat, lon, set_years);
X_0(:, :, 1) = X0(:, :, 1);

for i = 1:lat
    for j= 1:lon
        if D(i, j) ==-1
        else                   
            A(i, j) = U(i, j, 1);
            B(i, j) = U(i, j, 2);
        end
    end
end
for i = 1:lat
    for j = 1:lon
        if D(i, j) ==-1
        else           
            for k  = 1:set_years-1
                X_1(i, j, k+1) = (X0(i, j, 1) - B(i, j)/A(i, j)) * exp(-A(i, j)*k) + B(i, j)/A(i, j);
                X_0(i, j, k+1) = X_1(i, j, k+1) - X_1(i, j, k);
                        %printf('X_0 %d %d %d\n',i, j, k+1);
            end
        end
    end
end
for i = 1 : lat 
    for j = 1 : lon
        for k = 2 : set_years-1
            if X_0(i, j, k+1) <= X_0(i, j, k) && D(i, j) ~= -1
                %X_0(i, j, k) - X_0 (i, j, k+1);
                %X_0(i, j, k+1) = (X_0(i, j, k) - X_0 (i, j, k+1))*(1)*+ X_0 (i, j, k+1);
            end
        end
    end
end

        
size(X_0)
num =0;
for i = 1:lat
    for  j = 1 : lon
        for k = 1 : set_years
            if (X_0(i,j,k) - X0(i, j,1))>5 || (X_0(i,j,k) - X0(i, j,1))<-5 
                D(i, j) = -1;
                num = num+1;
                break
            end
        end
    end
end
for i = 1 :lat
    for j =1 : lon
        for k = 1 :set_years
            if X_0(i, j, k) >40 || X_0(i, j, k)<-5
                X_0(i, j, k) = -20;
            end
            if D(i, j) == -1
                X_0(i, j, k) = -20;
            end
            if X_0(i, j, k) == -20
                [~, x] = find(X_0(i, j, :) > 0);
                 if x> year/2
                    X_0 = pinghua(X_0, i, j, k);
                 end
            end
        end
    end
end
for i = 1 : lat
    for j = 1 : lon
        if D(i, j) ==-1
        else           
            for k = 1 : year
                deta(i, j, k) = (X0(i, j, k) - X_0(i, j, k))/X0(i, j, k);
            end
        end
    end
end
X_0 = X_0 - 2;