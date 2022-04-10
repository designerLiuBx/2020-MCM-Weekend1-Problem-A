function [X0, C, D] = data_test (X0) 
X0 = X0 + 2;
[lat, lon, year]=size(X0);
D = zeros(lat, lon);
C = zeros(lat, lon);
bad_data = 0;
changed_data = 0;
nochanged_data = 0;
beta = zeros(lat, lon, year-1);
for i = 1 : lat
    for j = 1 : lon
        for k = 2 : year
            e = X0(i, j, k);
            e_1 = X0(i, j, k-1);
            %dx(i, j, k-1) = e - e_1;
            beta(i, j, k-1) = e_1/e;
        end
    end
end
%Inspection and adjustment++++++++++++++++++++++++++++++%

delte = [exp(-2/(year+1)) exp(2/(year+1))];
for i = 1 : lat
    for j = 1 : lon
        for k = 1 : year
            if X0(i, j, k) == -18
                D(i, j) =-1;
                %disp(1);
                %if max(X0(i, j, :))>0
                [~, x] = find(X0(i, j, :) > 0);
                 if x> year/2
                    X0 = pinghua(X0, i, j, k);
                    D(i, j) = 0;
                end
            
            else
                if max(beta(i, j, :)) - min(beta(i, j, :))>delte(2) - delte(1)
                    bad_data = bad_data +1;
                    %D(i, j) = -1;
                elseif max(beta(i, j, :))< delte(2) && min(beta(i, j, :))<delte(1)
                     changed_data = changed_data + 1;
                     %D(i, j) = -1;
                elseif max(beta(i, j, :))< delte(2) && min(beta(i, j, :))<delte(1)
                     changed_data = changed_data+ 1;
                     %D(i, j) = -1;                     
                else
                    %D(i, j) = 0;
                    nochanged_data = nochanged_data + 1;
                end
            end
        end
    end
end

for i = 1 : lat
    for j = 1 : lon
        if D(i, j) == -1 
            for k = 1 : year
                X0(i, j, k) = -20;
            end
        end
    end
end


bad_data
changed_data           
nochanged_data
