function [yuan] = huayuan(a,b)
%UNTITLED4 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
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

