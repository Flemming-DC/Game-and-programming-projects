clc
close all
clear all


gamma=1;    %måler syrken af elektrisk kraft
delta=-0.1;  %måler styrken af magnetisk kraft

t=0:0.1:130;   %tid
x_0=1;  y_0=0;  z_0=1;              %position med cartesiske koordinater
v_x0=0;  v_y0=1;  v_z0=0;           %hastighed med cartesiske koordinater
h_0=[x_0 y_0 z_0 v_x0 v_y0 v_z0]';  %h_0=[position_0  hastighed_0]'



r=@(h) sqrt(h(1)^2+h(2)^2+h(3)^2);
theta=@(h) acos(h(3)/r(h)); 
phi=@(h)  atan(h(2)/h(1));
theta_hat_x= @(h) h(3)/r(h)*cos(phi(h));
theta_hat_y= @(h) h(3)/r(h)*sin(phi(h));
theta_hat_z= @(h) -sin(phi(h));

B_x=@(h) delta/r(h)^3*(2*h(3)*h(1)/r(h)^2+sin(theta(h))*theta_hat_x(h));
B_y=@(h) delta/r(h)^3*(2*h(3)*h(2)/r(h)^2+sin(theta(h))*theta_hat_y(h));
B_z=@(h) delta/r(h)^3*(2*h(3)*h(3)/r(h)^2+sin(theta(h))*theta_hat_z(h));

dhdt=@(t,h) [h(4) 
             h(5) 
             h(6)   
             -gamma*h(1)/r(h)^3 + h(5)*B_z(h)-h(6)*B_y(h)    
             -gamma*h(2)/r(h)^3 + h(6)*B_x(h)-h(4)*B_z(h)   
             -gamma*h(3)/r(h)^3 + h(4)*B_y(h)-h(5)*B_x(h)];  %dhdt=[hastighed  acceleration]'

error_settings=odeset('reltol',10^-5,'abstol',10^-6);

[t,h]=ode45(dhdt,t,h_0,error_settings);

x=h(:,1);  y=h(:,2);  z=h(:,3);
v_x=h(:,4);  v_y=h(:,5);  v_z=h(:,6);
a_x=diff(v_x);  a_y=diff(v_y);  a_z=diff(v_z);  


figure
hold on
plot3(0,0,0,'b.','markersize',20)                   %kuglen er vist med en blå prik
plot3(x(end),y(end),z(end),'k.','markersize',10)    %slut-positionen er vist med en sort prik
plot3(x,y,z,'k')                                    %kredsløb
view(3)








