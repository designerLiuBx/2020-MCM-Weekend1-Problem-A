function [Spring, summer, autumn, winter] = readData()
load('G:\workspace\ws_matlab\Data\Temp\WD.mat');
Spring = chuntian;
summer = xiatian;
autumn = qiutian;
winter  = dongtian;
%[Spring, summer, autumn, winter] = Read_TData();

