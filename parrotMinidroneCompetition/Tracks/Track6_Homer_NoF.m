%% Track maker 2:
% https://www.geogebra.org/calculator/ahapxxam
% Copy values from geogebra:
TrackName = 'Track6-Homer';

warning('This Track cannot be used to calculate the flight error. Lane is not like a function.', 'No error calculation')
%% Track 1
trans.x.T1 = 0; %B1 x
trans.y.T1 = 0.5; %B1 y
lung.T1 = 1;
angle.T1 = deg2rad(90); %alpha 1

%% Track 2
trans.x.T2 = -0.484; %B2 x
trans.y.T2 = 0.8745; %B2 y
lung.T2 = 1;
angle.T2 = deg2rad(194.5318); %alpha 2

%% Track 3
trans.x.T3 = -0.8978; %B3 x
trans.y.T3 = 1.2441; %B3 y
lung.T3 = 1;
angle.T3 = deg2rad(81.9298); %alpha 3

%% Track 4
trans.x.T4 = -1.3152; %B4 x
trans.y.T4 = 1.6286; %B4 y
lung.T4 = 1;
angle.T4 = deg2rad(192.7753); %alpha 4

%% Circle
trans.x.C = -2.0467; %C x
trans.y.C = 1.4628; %C y

%% Calculated values

xO = init.posNED(2);
yO = init.posNED(1);

% xO = 90; %To use when project is closed
% yO = 50; %To use when project is closed

Ax.T1 = trans.x.T1 - (lung.T1/2) * cos(angle.T1);
Ay.T1 = trans.y.T1 - (lung.T1/2) * sin(angle.T1);
Atx.T1 = Ax.T1 + xO;
Aty.T1 = Ay.T1 + yO;

Bx.T1 = trans.x.T1 + (lung.T1/2) * cos(angle.T1);
By.T1 = trans.y.T1 + (lung.T1/2) * sin(angle.T1);
Btx.T1 = Bx.T1 + xO;
Bty.T1 = By.T1 + yO;

% Adjust Offset
trans.x.T1 = trans.x.T1 + xO;
trans.y.T1 = trans.y.T1 + yO;

% Ax.T2 = trans.x.T2 - (length.T2/2) * cos(angle.T2);
% Ay.T2 = trans.y.T2 - (length.T2/2) * sin(angle.T2);
Bx.T2 = trans.x.T2 + (lung.T2/2) * cos(angle.T2);
By.T2 = trans.y.T2 + (lung.T2/2) * sin(angle.T2);
Btx.T2 = Bx.T2 + xO;
Bty.T2 = By.T2 + yO;
% Adjust Offset
trans.x.T2 = trans.x.T2 + xO;
trans.y.T2 = trans.y.T2 + yO;

% Ax.T3 = trans.x.T3 - (length.T3/2) * cos(angle.T3);
% Ay.T3 = trans.y.T3 - (length.T3/2) * sin(angle.T3);
Bx.T3 = trans.x.T3 + (lung.T3/2) * cos(angle.T3);
By.T3 = trans.y.T3 + (lung.T3/2) * sin(angle.T3);
Btx.T3 = Bx.T3 + xO;
Bty.T3 = By.T3 + yO;
% Adjust Offset
trans.x.T3 = trans.x.T3 + xO;
trans.y.T3 = trans.y.T3 + yO;

% Ax.T4 = trans.x.T4 - (length.T4/2) * cos(angle.T4);
% Ay.T4 = trans.y.T4 - (length.T4/2) * sin(angle.T4);
Bx.T4 = trans.x.T4 + (lung.T4/2) * cos(angle.T4);
By.T4 = trans.y.T4 + (lung.T4/2) * sin(angle.T4);
Btx.T4 = Bx.T4 + xO;
Bty.T4= By.T4 + yO;

% Adjust Offset
trans.x.T4 = trans.x.T4 + xO;
trans.y.T4 = trans.y.T4 + yO;

Ax.C = trans.x.C;
Ay.C = trans.y.C;

% Adjust Offset
trans.x.C = trans.x.C + xO;
trans.y.C = trans.y.C + yO;

%% Plot Track

xTrack = [Ax.T1 Bx.T1 Bx.T2 Bx.T3 Bx.T4];
yTrack = [Ay.T1 By.T1 By.T2 By.T3 By.T4];

figure;
plot(yTrack, xTrack, 'color','r', 'LineWidth', 10);
hold on
plot(Ay.C, Ax.C, '.', 'color','r', 'MarkerSize', 80);
hold off
axis equal
title(TrackName);

% clear xO yO xTrack yTrack