function Tfish = Get_tf(fish, T)
format long 
[lat, lon, year] = size(fish);
count = zeros(1, 4200);
all_fish = 0;
for i = 1 : lat
    for j = 1 : lon
        for k = 1 : year
            if T(i, j, k) ~= -20
                piexl = (T(i, j, k) + 2) * 100;
                index = int32(piexl);   
                count(index) = count(index) + fish(i, j, k);
                all_fish = all_fish + fish(i, j, k);
            end
        end
    end
end
all_fish
x = 1 : 4200;
figure;
plot(x, count);
%disp(all_fish);
%max(count);
r_count = 0;
n_count = 0;

for i =1 :4200
    if count(i) ~= 0
        n_count = n_count +1;
        r_count(n_count) = i;
        for j = 1 : count(i)
            n_count = n_count +1;
            r_count(n_count) = i;           
        end  
    end
end

miu = mean(r_count)
deta = var(r_count)
x = 1 : 4200;
Tfish = normpdf(x, miu, sqrt(deta));
figure;
plot(x, Tfish);
legend('ÎÂ¶È and fish ·Ö²¼');

