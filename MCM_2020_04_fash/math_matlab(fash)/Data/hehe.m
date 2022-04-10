q = 0.15;
for i=1:220
    for j=1:360
        for h=1:16
           if( chuntian(i,j,h)~=-20)
               if (h~=1&&(chuntian(i,j,h)-chuntian(i,j,h-1)<0))
                   b = chuntian(i,j,h)-chuntian(i,j,h-1);
                   chuntian(i,j,h)=chuntian(i,j,h)+ b*1.05;
               end
           end
           if( xiatian(i,j,h)~=-20)
               if (h~=1&&(xiatian(i,j,h)-xiatian(i,j,h-1)<0))
                  b = xiatian(i,j,h)-xiatian(i,j,h-1);
                  xiatian(i,j,h)=xiatian(i,j,h)+ b*1.05;
               end
           end
           if ( qiutian(i,j,h)~=-20)
               if (h~=1&&(qiutian(i,j,h)-qiutian(i,j,h-1)<0))
                  b = qiutian(i,j,h)-qiutian(i,j,h-1);
                  qiutian(i,j,h)=qiutian(i,j,h)+ b*1.05;  
               end
           end
            if( dongtian(i,j,h)~=-20)
                if (h~=1&&(dongtian(i,j,h)-dongtian(i,j,h-1)<0))
                  b = dongtian(i,j,h)-dongtian(i,j,h-1);
                  dongtian(i,j,h)=dongtian(i,j,h)+ b*1.05;                  
                end
            end
        end
    end
end