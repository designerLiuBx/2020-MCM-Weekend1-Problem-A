%clear;
clc;

load('G:\workspace\ws_matlab\Data\Fish\datareal.mat') ;%read Fish_data
[spring, summer, autumn, winter] = readData();
%hehe
%Spring = chuntian;
%summer = xiatian;
%autumn = qiutian;
%winter  = dongtian;
[spring_Fore    ,~ ,~]  = T_Forecasting(spring      ,50);
[summer_Fore ,~ ,~]  = T_Forecasting(summer   ,50);
[autumn_Fore  ,~ ,~] = T_Forecasting(autumn    ,50);
[winter_Fore    ,~ ,~] = T_Forecasting(winter      ,50);

all_fish0 = cat (3,chun0,xia0,qiu0,dong0);
all_fish1 = cat (3,chun1,xia1,qiu1,dong1);
all_T      = cat (3,spring, summer, autumn, winter);
all_TFore      = cat (3,spring_Fore, summer_Fore, autumn_Fore, winter_Fore);

TFish0 = Get_tf(all_fish0, all_T);
TFish1 = Get_tf(all_fish1, all_T);

