clear all 
close all
clc

%input

H=25;
W=40;
T=116;
pause_time=0.001;

world=zeros(H,W,T);  %tom verden

%nu begynder vi at lave objekter

glider_down_right=[0 0 1
                   1 0 1
                   0 1 1];
glider_down_left=fliplr(glider_down_right);
glider_up_left=flipud(glider_down_left);
glider_up_right=fliplr(glider_up_left);

block=[1 1
       1 1];
big_left_part_of_gun=[0 0 1 0 0 0
                      0 1 0 1 0 0
                      1 0 0 0 1 1
                      1 0 0 0 1 1
                      1 0 0 0 1 1
                      0 1 0 1 0 0
                      0 0 1 0 0 0];

big_right_part_of_gun=[0 0 0 0 1
                       0 1 1 1 1
                       1 1 1 1 0
                       1 0 0 1 0
                       1 1 1 1 0
                       0 1 1 1 1
                       0 0 0 0 1];

gun=zeros(9,36);    %nuller til at bygge en gospel glider gun
gun(6:7,1:2)=block;
gun(3:9,12:17)=big_left_part_of_gun;
gun(1:7,22:26)=big_right_part_of_gun;
gun(2:3,31)=1;
gun(4:5,35:36)=block;

%start tilstanden bygges

world(2+(1:9),2+(1:36))=gun;

%world(:,:,1)=randi([0 1],H,W);


%tidsudvikling

for t=1:(T-1)

world_up=[zeros(1,W); world(:,:,t)];
world_up=world_up(1:H,:);              %her laver vi en matrix med øvre nabo celler

world_up_right=[zeros(1,W+1); [world(:,:,t) zeros(H,1)]];
world_up_right=world_up_right(1:H,2:end);              %her laver vi en matrix med øvre-højre nabo celler

world_right=[world(:,:,t) zeros(H,1)];
world_right=world_right(:,2:end);              %her laver vi en matrix med højre nabo celler

world_down_right=[[world(:,:,t) zeros(H,1)] ; zeros(1,W+1)];
world_down_right=world_down_right(2:end,2:end);              %her laver vi en matrix med nedre-højre nabo celler

world_down=[world(:,:,t) ; zeros(1,W)];
world_down=world_down(2:end,:);              %her laver vi en matrix med nedre nabo celler

world_down_left=[[zeros(H,1) world(:,:,t)] ; zeros(1,W+1)];
world_down_left=world_down_left(2:end,1:W);              %her laver vi en matrix med nedre-venstrer nabo celler

world_left=[zeros(H,1) world(:,:,t)];
world_left=world_left(:,1:W);              %her laver vi en matrix med venstrer nabo celler

world_up_left=[zeros(1,W+1) ; [zeros(H,1) world(:,:,t)]];
world_up_left=world_up_left(1:H,1:W);              %her laver vi en matrix med øvre-venstrer nabo celler

count=world_up+world_up_right+world_right+world_down_right++world_down+world_down_left+world_left+world_up_left;   %her tæller antallet af naboceller
world(:,:,t+1)=count==3 | count==2 & world(:,:,t)==1;   %her beregner vi tilstanden til tiden t+1. Vi benytter reglen at en levende celle med 2-3 naboer forbliver levende og en død celle med 3 naboer bliver født, mens resultatet i alle andre tilfælde er en død celle.

end

%animation

figure
hold on
title('time 1')
axis([0 W+1 0 H+1])
grey=[0.94 0.94 0.94]; %alternativ baggrundsfarve
set(gca,'Color','k')   %her sætter vi baggrundsfarven

for t=1:T

title(['time ' num2str(t)])
[x,y]=find(fliplr(world(:,:,t)'));  %x og y koordinater for rektanglerne

for k=1:length(x)
   fill([x(k)-0.5 x(k)-0.5 x(k)+0.5 x(k)+0.5],[y(k)-0.5 y(k)+0.5 y(k)+0.5 y(k)-0.5],'g')  %her tegner vi de grønne rektangler
end

pause(pause_time)

if t<T
    fill([0 0 W+1 W+1],[0 H+1 H+1 0],'k')
end

end









