function [fzo] = wave(fz)
%UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
for i=22:241
    for j=522:881
        if fz(i,j)==99999
            fz(i,j)=cesuan(fz,i,j,5);
        end
    end
end
fzo=fz;
end

