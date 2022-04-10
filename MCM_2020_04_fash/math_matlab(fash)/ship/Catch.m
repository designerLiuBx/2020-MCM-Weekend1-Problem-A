function catched = Catch(Aship, fishMap, nowYear, deta)
shipX = Aship(1);
shipY = Aship(2);
[lat, lon, ~] = size(fishMap);
S = zeros(lat, lon);
for i =1 :lat
    for j = 1 : lon
        S(i, j) = 111/4 * 111*cos(i+i+1)/2;
    end
end
catched = 5.3*5*1.88*3*fishMap(shipX, shipY, nowYear)/S(i, j)/deta;
end
