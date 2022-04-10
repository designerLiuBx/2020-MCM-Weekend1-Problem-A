function [spring, summer, autumn, winter] = Read_TData()
dong=zeros(220,360,3);
chun=zeros(220,360,3);
xia=zeros(220,360,3);
qiu=zeros(220,360,3);
winter=zeros(220,360,16);
spring=zeros(220,360,16);
summer=zeros(220,360,16);
autumn=zeros(220,360,16);
aaa='G:\workspace\ws_matlab\Data\Temp\MYD28M_';
bbb='-01_rgb_1440x720.SS.CSV';
ccc='-';

nian=2002;
yue=12;
i=1;
for j=1:5
    for h=1:12
        if yue>=10        
        lujing=[aaa,num2str(nian),ccc,num2str(yue),bbb];
        else
        lujing=[aaa,num2str(nian),ccc,'0',num2str(yue),bbb];
        end
        [num0,label0]=xlsread(lujing);
        num0=wave(num0);
        num0= medfilt2(num0);
      if yue==12||yue==1||yue==2
           if i==3
            dong(:,:,i)=num0(22:241,522:881); 
            i=1;
            winter(:,:,j)=roundn((dong(:,:,1)+dong(:,:,2)+dong(:,:,3))/3,-2);
            
            winter(winter>100)=-20;
        else
            
            dong(:,:,i)=num0(22:241,522:881); 
            
            i=i+1;
           end                           
        elseif 3<=yue&&yue<=5
          if i==3
            chun(:,:,i)=num0(22:241,522:881);
            i=1;
            spring(:,:,j)=roundn((chun(:,:,1)+chun(:,:,2)+chun(:,:,3))/3,-2);
            spring(spring>100)=-20;
          else            
            chun(:,:,i)=num0(22:241,522:881); 
            i=i+1;
           end      
        elseif  6<=yue&&yue<=8
          if i==3
             xia(:,:,i)=num0(22:241,522:881); 
            i=1;
            summer(:,:,j)=roundn((xia(:,:,1)+xia(:,:,2)+xia(:,:,3))/3,-2);
            summer(summer>100)=-20;
          else            
            xia(:,:,i)=num0(22:241,522:881); 
             i=i+1;
           end    
        elseif 9<=yue&&yue<=11
         if i==3
            qiu(:,:,j)=num0(22:241,522:881); 
            i=1;
            autumn(:,:,j)=roundn((qiu(:,:,1)+qiu(:,:,2)+qiu(:,:,3))/3,-2);
            autumn(autumn>100)=-20;
        else
          
            qiu(:,:,i)=num0(22:241,522:881);
            i=i+1;
         end     
       end
       yue
        if yue==12
            yue=1;
            nian=nian+1;
        else
            yue=yue+1;
        end
    end
    
end
%contourf(xx,yy,winter(:,:,1));