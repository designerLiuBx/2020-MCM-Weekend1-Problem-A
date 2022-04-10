function fishMap = Get_FishNum(MAP, T, allFish)
format long
[lat, lon, year] = size(T);
fishMap = zeros(lat, lon, year);
m = 0;
deta = zeros(year);
for k = 1 : year
    for i = 1 : lat
        for j = 1  : lon
            if MAP(i, j, k) == 10
                m = T(i, j, k)+m;
            end
        end 
    end
    deta(k) = 1/m;
end

for k = 1 :year
    for i = 1 :lat
        for j = 1:lon
            fishMap(i, j, k) = abs(deta(k) * T(i, j, k) * allFish);
        end
    end
end
