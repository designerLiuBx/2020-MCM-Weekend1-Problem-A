function [fzo] = wave(fz)
%UNTITLED �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
for i=22:241
    for j=522:881
        if fz(i,j)==99999
            fz(i,j)=cesuan(fz,i,j,5);
        end
    end
end
fzo=fz;
end

