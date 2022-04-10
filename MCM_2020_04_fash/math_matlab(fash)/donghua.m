x=-49.875:0.25:39.875;
y=84.875:-0.25:30.125;
[xx,yy]=meshgrid(x,y);
contourf(xx,yy,Dyuan(:,:,14));
theaxes=axis;
fmat=moviein(100);
for i=1:100
    hhh=idivide(int32(i),int32(2),'ceil');
    contourf(xx,yy,Dyuan(:,:,hhh));
    axis(theaxes);
    fmat(:,i)=getframe;
end
movie(fmat,10);

