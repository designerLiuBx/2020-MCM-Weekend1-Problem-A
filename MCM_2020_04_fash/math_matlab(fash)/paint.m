%X_00 = Fish_0(:, :, 3)*10000000- 2195800;
%M = spring(:, :, 1);
%[lat , lon, year ] = size(M)
%X_00 = M(:, :, 1);


%mesh(x, y, X_00);
%[y, x]=size();
x=-49.875:0.25:39.875;
y=84.875:-0.25:30.125;
[xx,yy]=meshgrid(x,y); 
contourf(x,y,winter(:,:,5));






