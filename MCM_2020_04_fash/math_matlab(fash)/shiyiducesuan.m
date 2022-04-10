shiyingdu=fishFore_S0;
% mei_ye_he=sum(sum(shiyingdu,1),2);
% for i=1:50
%     shiyingdu(:,:,i)=shiyingdu(:,:,i)/mei_ye_he(i);
% end
% shiyingdu=shiyingdu/100;
yuan=zeros(220,360);
x=-49.875:0.25:39.875;
y=84.875:-0.25:30.125;
[xx,yy]=meshgrid(x,y);
for i=1:220
    for j=1:360
        if (xx(i,j)-(-1.375))^2+(yy(i,j)-53.875)^2<=81
            yuan(i,j)=10;
        end
    end
end
Dyuan=zeros(220,360,50);
Dyuanxin_x=zeros(1,50);
Dyuanxin_y=zeros(1,50);
Dyuan(:,:,1)=yuan;
Dyuanxin_x(1)=yuanxin_x;
Dyuanxin_y(1)=yuanxin_y;
for h=1:50
all_shiyindu=0;
yuansuhe=0;
for i=1:220
    for j=1:360
        if Dyuan(i,j,h)==10
            if shiyingdu(i,j,h)~=0
            all_shiyindu=shiyingdu(i,j,h)+all_shiyindu;
            yuansuhe=yuansuhe+1;
            end
        end
    end
end
ave_shiyingdu=all_shiyindu/yuansuhe;
min_zhi=100;
k=0;
for i=1:220
    for j=1:360
        if Dyuan(i,j,h)==10
            if (abs(shiyingdu(i,j,h)-ave_shiyingdu)<min_zhi)
                min_zhi=abs(shiyingdu(i,j,h)-ave_shiyingdu);
                min_y=j;
                min_x=i;   
              
            end
        end
    end
end
if h<=49
Dyuan(:,:,h+1)=huayuan(min_x,min_y);
end
end