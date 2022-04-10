function [yuan] = huayuan(a,b)
%UNTITLED4 此处显示有关此函数的摘要
%   此处显示详细说明
yuan=zeros(220,360);
x=-49.875:0.25:39.875;
y=84.875:-0.25:30.125;
[xx,yy]=meshgrid(x,y);
for i=1:220
    for j=1:360
        if (xx(i,j)-xx(a,b))^2+(yy(i,j)-yy(a,b))^2<=81
            yuan(i,j)=10;
        end
    end
end
end

