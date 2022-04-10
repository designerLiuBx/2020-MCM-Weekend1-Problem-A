function fishFore = get_fishFore(TFish, T)
[lat, lon, year]  = size(T);
fishFore = zeros(lat, lon, year);
for i = 1 : lat
    for j = 1 : lon
        for k = 1 : year
            if T(i, j, k) ~= -20 &&T(i, j, k) ~= -2
                piexl = (abs(T(i, j, k) + 2)) * 100;
                index = int32(piexl);
                fishFore(i, j, k) = TFish(index+1);
            end
        end
    end
end
[y, x, ~] = size(fishFore);
x = 1 : x;
y = 1 : y;
[x, y] = meshgrid(x, y);
figure;
mesh(x, y, fishFore(:, :, 1));
figure;
mesh(x, y, fishFore(:, :, 50));

            