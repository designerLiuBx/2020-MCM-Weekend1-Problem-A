function Fish_0 = fish_Forecasting(X_0,TFish, D)
%RM 
[lat, lon, year] = size(X_0);
Fish_0 = zeros(lat, lon, year);
X_1 = zeros(lat, lon, year);
for i  = 1 : lat
    for j = 1 : lon
        if D(i, j) ~= -1 
            for k = 1: year
                if X_0(i, j, k)~= -20
                    X_1(i, j, k) = int32((X_0(i, j, k) + 0)*100);
                end
            end
        end
    end
end

for i = 1 : lat
    for j = 1 : lon
        for k = 1 : year
            if D(i, j) ~= 0
                Fish_0(i, j, k) = TFish(X_1(i, j, k)+1);
            else
                Fish_0(i, j, k) = nan;
            end
        end
    end
end

%figure,contourf(xx,yy,dst(:,:,1));

