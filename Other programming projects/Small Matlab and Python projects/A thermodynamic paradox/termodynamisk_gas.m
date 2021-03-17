clc
close all
clear all

%% I dette afsnit defineres de st�rrelser, som man eventuelt kunne t�nke sig at justerer p�. (med undtagelse af positionerne til t=0)

dt=0.01;             %tidsstep
T=4;                 %slut-tid
N=100;               %antal partikler
N_x=10;              %antal partikler langs x-aksen
t=0:dt:T;            %tider
K=length(t)-1;       %antal tidsskridt
L=6;                 %boksens l�ngde
x_1=-L/2; x_2=L/2; y_1=-L/2; y_2=L/2;      %boksens gr�nser
R=.1;                %partiklernes radius
enheds_forhold=42;   %forholdet imellem enhederne for markersize og for resten af koden (herunder afstande langs x og y)
wr=0.75;             %Da plottets sk�rm ikke er kvardratisk, s� kan partiklerne ikke v�re spheriske b�de i mark�r-st�rrelser og i data-st�rrelser. Hvis wr er forskellig fra 1, s� bliver partiklerne elliptiske i data-st�rrelse med R_y=R og R_x=wr*R. Dette ser rigtigt ud i animationen, men er fysisk set forkert.
Ev=2;                                       %forventet st�rrelse af starthastigheden
v_x=Ev*randn(N,1);   v_y=Ev*randn(N,1);     %starthastigheder
v_x_bagud=-v_x;           v_y_bagud=-v_y;   %tidsreverede starthastigheder



%% I dette afsnit konstruerer vi partiklernes position til t=0



N_y=N/N_x;            %--------------||------y------ (N og N_x skal v�lges s�ledes at N_y er et heltal)
if ~(floor(N_y)==N_y) %her tester vi om N_y er et heltal. Ellers virker koden nemlig ikke
   disp('N og N_x skal v�lges s�ledes at N_y=N/N_x er et heltal. Ellers virker koden ikke.') 
end
a=L/(N_x+1)/2.4;      %mellemrum imellem nabo-partikler
label_x=(1:N_x)';     %et index, som kan t�lle s�jler med partikler
label_y=(1:N_y)';     %tilsvarende for r�kker
x_0_matrix=(label_x*wr*a+x_1-a/3)*ones(1,N_y);    %matrix med x-koordinater for partiklerne
x_0=reshape(x_0_matrix,[N,1]);                    %her omdannes x-matricen til en vektor
y_0_matrix=((label_y*a+y_1-a/2.5)*ones(1,N_x))';  %tilsvarende for y
y_0=reshape(y_0_matrix,[N,1]);             %tilsvarende for y
x=x_0.*ones(N,length(t));                  %disse fire vektore bliver overskrevet i for-k�kken
y=y_0.*ones(N,length(t));                  
x_bagud=x_0.*ones(N,length(t));            
y_bagud=y_0.*ones(N,length(t));            



%% I dette afsnit definerer vi nogle st�rrelser, som skal overskrives i tidsud- og afviklingen. Desuden s�tter vi aksernes gr�nser.

markoer=plot(x(:,1),y(:,1),'b.','Markersize',enheds_forhold*R*6);   %partiklens mark�r
axis([x_1,x_2,y_1,y_2]);                %aksernes gr�nser

udenfor_x= zeros(N,length(t));          %disse vektore bliver overskrevet i for-k�kken
udenfor_y= zeros(N,length(t));          
paa_vej_vaek_x= zeros(N,length(t));     
paa_vej_vaek_y= zeros(N,length(t));     
r_kvadreret=zeros(N);                   
paa_vej_vaek_sammenstoed=zeros(N);      



%% I dette afsnit gennemf�res tidsud- og afviklingen, b�de mht. beregninger og plots.

for k=1:K          %her tidsudvikler vi gassen
    x(:,k+1)=v_x*dt+x(:,k);    %n�ste x-position i frav�r af sammenst�d
    y(:,k+1)=v_y*dt+y(:,k);    %tilsvarende for y
    
    udenfor_x(:,k)= ~(x_1+wr*R<x(:,k) &  x(:,k)<x_2-wr*R);  %her har vi det udsagn at partiklen er udenfor langs x-aksen
    paa_vej_vaek_x(:,k)= sign(x(:,k))==sign(v_x);           %dette udsagn siger at partiklen er p� vej v�k fra x=0
    udenfor_y(:,k)= ~(y_1+R<y(:,k) &  y(:,k)<y_2-R);        %tilsvarende for y
    paa_vej_vaek_y(:,k)= sign(y(:,k))==sign(v_y);           %tilsvarende for y
    r_kvadreret=(x(:,k).*ones(N)-(x(:,k).*ones(N))').^2+(y(:,k).*ones(N)-(y(:,k).*ones(N))').^2;     %her beregner vi afstanden mellem hvert partikel-par
    paa_vej_vaek_sammenstoed= (x(:,k).*ones(N)-(x(:,k).*ones(N))').*(v_x.*ones(N)-(v_x.*ones(N))')+(y(:,k).*ones(N)-(y(:,k).*ones(N))').*(v_y.*ones(N)-(v_y.*ones(N))')<0;    %dette udsagn siger at de to kolliderende partikler er p� vej v�k fra hinanden. (Dette er formaliseret ved at lade prikproduktet imellem deres relative positioner og deres relative hastigheder v�re under nul).
    
    
    
    for m=1:N       %kollision med x-aksens v�gge
        if udenfor_x(m,k) && paa_vej_vaek_x(m,k)    %test for sammenst�d med x-aksens v�gge
            v_x(m)=-v_x(m);                         %hastigheds�ndring ved sammenst�d
            x(m,k+1)=v_x(m)*dt+x(m,k);              %n�ste position
            
        end
    end
    
    for m=1:N       %kollision med y-aksens v�gge
        if udenfor_y(m,k) && paa_vej_vaek_y(m,k)    %test for sammenst�d med y-aksens v�gge
            v_y(m)=-v_y(m);                         %hastigheds�ndring ved sammenst�d
            y(m,k+1)=v_y(m)*dt+y(m,k);              %n�ste position
            
        end
    end
    
    for m=1:N       %kollision mellem to partikler
        for n=m+1:N
            if r_kvadreret(m,n)<wr*(2*R)^2 && paa_vej_vaek_sammenstoed(m,n)
                
                relevante_partikler_x=[v_x(m) ; v_x(n)];    %her finder vi de partikler, som indg�r i kollisionen
                relevante_partikler_y=[v_y(m) ; v_y(n)];
                [v_x(m),v_x(n)]=deal(relevante_partikler_x(2),relevante_partikler_x(1));            %her bytter vi om p� de kolliderende partiklers hastighed, hvilket passer med ligningerne for elastiske sammenst�d, imellem lige tunge bolde
                [v_y(m),v_y(n)]=deal(relevante_partikler_y(2),relevante_partikler_y(1));
                x(:,k+1)=v_x*dt+x(:,k);    %n�ste x-position i givet sammenst�d
                y(:,k+1)=v_y*dt+y(:,k);    %tilsvarende for y
            end
        end
    end
    
end


for k=1:K          %her tidsafvikler vi gassen
    x_bagud(:,k+1)=v_x_bagud*dt+x_bagud(:,k);    %n�ste x-position i frav�r af sammenst�d
    y_bagud(:,k+1)=v_y_bagud*dt+y_bagud(:,k);    %tilsvarende for y
    
    udenfor_x(:,k)= ~(x_1+wr*R<x_bagud(:,k) &  x_bagud(:,k)<x_2-wr*R);  %her har vi det udsagn at partiklen er udenfor langs x-aksen
    paa_vej_vaek_x(:,k)= sign(x_bagud(:,k))==sign(v_x_bagud);           %dette udsagn siger at partiklen er p� vej v�k fra x=0
    udenfor_y(:,k)= ~(y_1+R<y_bagud(:,k) &  y_bagud(:,k)<y_2-R);        %tilsvarende for y
    paa_vej_vaek_y(:,k)= sign(y_bagud(:,k))==sign(v_y_bagud);           %tilsvarende for y
    r_kvadreret=(x_bagud(:,k).*ones(N)-(x_bagud(:,k).*ones(N))').^2+(y_bagud(:,k).*ones(N)-(y_bagud(:,k).*ones(N))').^2;     %her beregner vi afstanden mellem hvert partikel-par
    paa_vej_vaek_sammenstoed= (x_bagud(:,k).*ones(N)-(x_bagud(:,k).*ones(N))').*(v_x_bagud.*ones(N)-(v_x_bagud.*ones(N))')+(y_bagud(:,k).*ones(N)-(y_bagud(:,k).*ones(N))').*(v_y_bagud.*ones(N)-(v_y_bagud.*ones(N))')<0;    %dette udsagn siger at de to kolliderende partikler er p� vej v�k fra hinanden. Dette er formaliseret ved at lade prikproduktet imellem deres relative positioner og deres relative hastigheder v�re under nul.
    
    
    
    for m=1:N       %kollision med x-aksens v�gge
        if udenfor_x(m,k) && paa_vej_vaek_x(m,k)    %test for sammenst�d med x-aksens v�gge
            v_x_bagud(m)=-v_x_bagud(m);                         %hastigheds�ndring ved sammenst�d
            x_bagud(m,k+1)=v_x_bagud(m)*dt+x_bagud(m,k);              %n�ste position
            
        end
    end
    
    for m=1:N       %kollision med y-aksens v�gge
        if udenfor_y(m,k) && paa_vej_vaek_y(m,k)    %test for sammenst�d med y-aksens v�gge
            v_y_bagud(m)=-v_y_bagud(m);                         %hastigheds�ndring ved sammenst�d
            y_bagud(m,k+1)=v_y_bagud(m)*dt+y_bagud(m,k);              %n�ste position
            
        end
    end
    
    for m=1:N       %kollision mellem to partikler
        for n=m+1:N
            if r_kvadreret(m,n)<wr*(2*R)^2 && paa_vej_vaek_sammenstoed(m,n)
                
                relevante_partikler_x=[v_x_bagud(m) ; v_x_bagud(n)];    %her finder vi de partikler, som indg�r i kollisionen
                relevante_partikler_y=[v_y_bagud(m) ; v_y_bagud(n)];
                [v_x_bagud(m),v_x_bagud(n)]=deal(relevante_partikler_x(2),relevante_partikler_x(1));            %her bytter vi om p� de kolliderende partiklers hastighed, hvilket passer med ligningerne for elastiske sammenst�d, imellem lige tunge bolde
                [v_y_bagud(m),v_y_bagud(n)]=deal(relevante_partikler_y(2),relevante_partikler_y(1));
                x_bagud(:,k+1)=v_x_bagud*dt+x_bagud(:,k);    %n�ste x-position i givet sammenst�d
                y_bagud(:,k+1)=v_y_bagud*dt+y_bagud(:,k);    %tilsvarende for y
            end
        end
    end
    
end




for k=1:K  %her afspiller vi animationen for tidsafviklingen
    
    set(markoer,'Xdata',x_bagud(:,K+1-k),'Ydata',y_bagud(:,K+1-k))      %den k'ne position plottes
    pause(dt)
    
end 


for k=1:K  %her afspiller vi animationen for tidsudviklingen
    
    set(markoer,'Xdata',x(:,k),'Ydata',y(:,k))      %den k'ne position plottes
    pause(dt)
    
end 


%% I dette afsnit er der nogle extra plots, som man kan tilf�je, hvis det bliver relevant.

% figure       %her viser vi den tidligste tilstand
% hold on
% title('past state')
% plot(x_bagud(:,K),y_bagud(:,K),'b.','Markersize',enheds_forhold*R*6);
% axis([x_1,x_2,y_1,y_2]);
% 
% figure       %her viser vi den initielle tilstand
% hold on
% title('initial state')
% plot(x(:,1),y(:,1),'b.','Markersize',enheds_forhold*R*6);
% axis([x_1,x_2,y_1,y_2]);
% 
% figure       %her viser vi den fremtidige tilstand
% hold on
% title('future state')
% plot(x(:,K),y(:,K),'b.','Markersize',enheds_forhold*R*6);
% axis([x_1,x_2,y_1,y_2]);


% figure         %her plotter vi positionens udvikling over tid, for x og y koordinaterne
% hold on
% plot(t,x,'k')
% plot(t,y,'r')
% plot(t,3*ones(1,length(t)),'k--')
% plot(t,-3*ones(1,length(t)),'k--')







