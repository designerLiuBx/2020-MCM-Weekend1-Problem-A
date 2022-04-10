function [A2, p] = Location_refresh (A, speed, alpha, t, year, MAP)
% name  : Location refresh 
% autor £ºliuBaixu
% Entrance parameters   : A          1 x 2  
%                                        speed  1 x 1   km/h
%                                        alpha   1 x 1   ¡ã

%A = [110, 180];
%speed = 22.2;
%alpha = 90/180*pi;
%t = 1;

V = speed;
Vx = V*sin(alpha);
Vy = V*cos(alpha);
LAT = 84.875:-0.25:30.125;
LON =-49.875:0.25:39.875;
[Mlat, Mlon, ~] = size(MAP);
for i = 1 : Mlat
    for j = 1 : Mlon
        if MAP(i, j, year) == -20
            MAP(i, j, year) = 1;
        else
            MAP(i, j, year) = 0;
        end
    end
end
LAT = 84.875:-0.25:30.125;
LON =-49.875:0.25:39.875;
lat = A(1);     lon = A(2);
lat0 = lat;    lon0 = lon;

lat1 = ( Vy*t / 111 ) + lat0;
lon1 = ( Vx*t*2 / ( cos((lat0+lat1)/2)*111)) + lon0;
LAT = 84.875:-0.25:30.125;
LON =-49.875:0.25:39.875;
if lat1 < 30.125 || lat1 > 84.875 || lon1 <-49.875 || lon1 > 39.875
    p = 1;
else
    lat = find( LAT<=lat1+0.125 & LAT>=lat1-0.125 );
    lon = find( LON<=lon1+0.125 & LON>=lon1-0.125);
%    A1 = [lat(1), lon(1)];
end

lat2 = LAT( lat(1));
lon2 = LAT( lon(1));
A2 = [lat2, lon2];

if MAP(lat(1), lon(1)) == 1 || p==1
    A2 = nan;
    p = 1;
else
    p = 0;
end






