function [fzo] = cesuan(fz,x,y,i)
%UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明
a=fz(x-i:x,y);
b=fz(x:x+i,y);
c=fz(x,y-i:y);
d=fz(x,y:y+i);
  fzo=fz(3,3);
if (sum(a==99999)~=i+1)&&(sum(b==99999)~=i+1)&&(sum(c==99999)~=i+1)&&(sum(d==99999)~=i+1)
    h=fz(x-i:x+i,y-i:y+i);
    l=sum(h(:)==99999);
    h(h==99999)=0;
    sum(h(:));
    
    fzo=sum(h(:))/((2*i+1)^2-l);
end

end

