close all 
clc

% ATTENZIONE: prende dati dal progetto Simulink, quindi stessa directory.
% Inoltre i dati sono quelli che vengono acquisiti dopo la simulazione,
% quindi serve prima simulare il modello almeno una volta.

set(0, 'defaultFigureRenderer', 'painters')	 % per alta risoluzione

%% Plot in 3d valori REALI
% ATTENZIONE: metto abs() per la z perche' e' rivolta verso il basso (vedi sistema di riferimento drone)

positionY_NORMALIZZATO = positionY - 95;
positionX_NORMALIZZATO = positionX - 57;

plot3(positionX_NORMALIZZATO,positionY_NORMALIZZATO,abs(positionZ),'LineWidth',2)
hold on
plot3(positionX_NORMALIZZATO(1,1),positionY_NORMALIZZATO(1,1),abs(positionZ(1,1)),'Marker','*',
'LineStyle','none','MarkerFaceColor',[1 0 0], 'MarkerSize',10,'MarkerEdgeColor',[0, 0.5, 0])
hold on
plot3(positionX_NORMALIZZATO(end,1),positionY_NORMALIZZATO(end,1),abs(positionZ(end,1)),
'Marker','o','LineStyle','none','MarkerFaceColor',[1 0 0],'MarkerSize',10,'MarkerEdgeColor','red')
pbaspect([1 1 1])
grid on
xlabel('$x$ [$m$]','Interpreter','latex')
ylabel('$y$ [$m$]','Interpreter','latex')
zlabel('Altitude [$m$]','Interpreter','latex')
title('Traiettoria','Interpreter','latex')

%% Plot in 2d SOVRAPPOSTO CON PATH dei valori REALI 
figure
plot(yTrack, xTrack, 'color','r', 'LineWidth', 10);
hold on
plot(Ay.C, Ax.C, '.', 'color','r', 'MarkerSize', 80);

hold on
plot3(positionX_NORMALIZZATO,positionY_NORMALIZZATO,abs(positionZ),'LineWidth',2)
grid on
axis equal
pbaspect([1 1 1])
xlabel('$x$ [$m$]','Interpreter','latex')
ylabel('$y$ [$m$]','Interpreter','latex')
zlabel('Altitude [$m$]','Interpreter','latex')
title('Traiettoria','Interpreter','latex')

view(2) % per vedere plot 3d dall'alto (in 2D)  

%% Plot in 2d dei vari casi valore REALE
figure
t = tiledlayout(3,1) % Combine multiple plots
t.Padding = 'compact';
t.TileSpacing = 'compact';

ax1 = nexttile;
plot(ax1,estimatedStates.time(1:end-1),positionX_NORMALIZZATO,'LineWidth',1)
grid on
ylabel('$x$ [$m$]','Interpreter','latex')
title('X position','Interpreter','latex')

ax2 = nexttile;
plot(ax2,estimatedStates.time(1:end-1),positionY_NORMALIZZATO,'LineWidth',1)
grid on
ylabel('$y$ [$m$]','Interpreter','latex')
title('Y position','Interpreter','latex')

ax3 = nexttile;
plot(ax3,estimatedStates.time(1:end-1),abs(positionZ),'LineWidth',1)
grid on
ylabel('$z$ [$m$]','Interpreter','latex')
title('Z position','Interpreter','latex')
xlabel(t,'simulation time [$s$]','Interpreter','latex')

%% Sovrapposizione plot tra valori REALI e valori STIMATI
figure
plot(positionX_NORMALIZZATO,positionY_NORMALIZZATO,'LineWidth',2)

hold on
plot(estimatedStates.signals.values(:,1),estimatedStates.signals.values(:,2),'LineWidth',2)
hold on
plot(estimatedStates.signals.values(1,1),estimatedStates.signals.values(1,2))
hold on
plot(estimatedStates.signals.values(end,1),estimatedStates.signals.values(end,2))
grid on
axis equal
pbaspect([1 1 1])
xlabel('$x$ [$m$]','Interpreter','latex')
ylabel('$y$ [$m$]','Interpreter','latex')
legend('Valori reali $(x,y)$','Valori stimati $(\hat{x},\hat{y})$','Interpreter','latex')
title('Traiettoria reale e stimata','Interpreter','latex')

%% Errore tra valori REALI e valori STIMATI
% le due matrici devono avere la stessa dimensione, quindi bisogna eliminare l'ultima riga per i valori stimati

distance_between_two_points = sqrt((positionX_NORMALIZZATO - estimatedStates.signals.values(1:end-1,1)).^2 + (positionY_NORMALIZZATO - estimatedStates.signals.values(1:end-1,2)).^2);

figure
plot(estimatedStates.time(1:end-1),distance_between_two_points,'LineWidth',1)
grid on
pbaspect([1 1 1])
xlabel('simulation time [$s$]','Interpreter','latex')
ylabel('distanza [$m$]','Interpreter','latex')
title('Distanza tra valori reali e stimati','Interpreter','latex')

%% Velocita X
figure
plot(estimatedStates.time(1:end-1),velocitaX,'LineWidth',1)
hold on
plot(estimatedStates.time,estimatedStates.signals.values(:,7),'LineWidth',1)
grid on
xlabel('simulation time [$s$]','Interpreter','latex')
ylabel('velocit\`a X [$\frac{m}{s}$]','Interpreter','latex')
legend('Valori reali $v_{x}$','Valori stimati $\hat{v}_{x}$','Interpreter','latex')
title('Velocit\`a X','Interpreter','latex')

%% Velocita Y
figure
plot(estimatedStates.time(1:end-1),velocitaY,'LineWidth',1)
hold on
plot(estimatedStates.time,estimatedStates.signals.values(:,8),'LineWidth',1)
grid on
xlabel('simulation time [$s$]','Interpreter','latex')
ylabel('velocit\`a Y [$\frac{m}{s}$]','Interpreter','latex')
legend('Valori reali $v_{y}$','Valori stimati $\hat{v}_{y}$','Interpreter','latex')
title('Velocit\`a Y','Interpreter','latex')

%% Angolo Yaw
% Attenzione: tutti i valori di angoli trovati sono rispetto al sistema di
% riferimento inerziale, non rispetto al drone
Yaw_deg = rad2deg(Yaw);   % trasformo rad to deg
YawHAT_deg = rad2deg(estimatedStates.signals.values(:,4));

figure
plot(estimatedStates.time(1:end-1),Yaw_deg,'LineWidth',1)
hold on
plot(estimatedStates.time,YawHAT_deg,'LineWidth',1)
grid on
xlabel('simulation time [$s$]','Interpreter','latex')
ylabel('$\psi$ [$^{\circ}$]','Interpreter','latex')
legend('Valori reali $\psi$','Valori stimati $\hat{\psi}$','Interpreter','latex')
title('Yaw reale e stimato','Interpreter','latex')

%% Motori
figure
t = tiledlayout(2,2) % Combine multiple plots
t.Padding = 'compact';
t.TileSpacing = 'compact';

ax3 = nexttile;
plot(ax3,estimatedStates.time(1:end),Motor1,'r','LineWidth',1)
grid on
title('Motor3','Interpreter','latex')
xticks(0:10:70);
xlim([0 70])

ax1 = nexttile;
plot(ax1,estimatedStates.time(1:end),Motor2,'Color',[0, 0.5, 0],'LineWidth',1)
grid on
title('Motor1','Interpreter','latex')
xticks(0:10:70);
xlim([0 70])

ax2 = nexttile;
plot(ax2,estimatedStates.time(1:end),Motor4,'Color',[0, 0.5, 0],'LineWidth',1)
grid on
title('Motor2','Interpreter','latex')
xticks(0:10:70);
xlim([0 70])

ax4 = nexttile;
plot(ax4,estimatedStates.time(1:end),Motor3,'r','LineWidth',1)
grid on
title('Motor4','Interpreter','latex')
xticks(0:10:70);
xlim([0 70])
xlabel(t,'simulation time [$s$]','Interpreter','latex')
ylabel(t,'velocit\`a angolare [$RPM$]','Interpreter','latex')

%% Velocita reali
figure
t = tiledlayout(3,1) % Combine multiple plots
t.Padding = 'compact';
t.TileSpacing = 'compact';

ax1 = nexttile;
plot(ax1,estimatedStates.time(1:end-1),velocitaX,'LineWidth',1)
grid on
ylabel('velocit\`a X [$\frac{m}{s}$]','Interpreter','latex')
title('Velocit\`a X','Interpreter','latex')

ax2 = nexttile;
plot(ax2,estimatedStates.time(1:end-1),velocitaY,'LineWidth',1)
grid on
ylabel('velocit\`a Y [$\frac{m}{s}$]','Interpreter','latex')
title('Velocit\`a Y','Interpreter','latex')

ax3 = nexttile;
plot(ax3,estimatedStates.time(1:end-1),velocitaZ,'LineWidth',1)
grid on
ylabel('velocit\`a Z [$\frac{m}{s}$]','Interpreter','latex')
title('Velocit\`a Z','Interpreter','latex')
xlabel(t,'simulation time [$s$]','Interpreter','latex')

%% Yaw reale e reference
figure
plot(estimatedStates.time(1:end-1),Yaw,'LineWidth',1)
hold on
plot(estimatedStates.time(1:end-1),YawReference,'LineWidth',1)
grid on
xlabel('simulation time [$s$]','Interpreter','latex')
ylabel('$\psi$ [$^{\circ}$]','Interpreter','latex')
legend('$\psi$ reale','$\psi$ riferimento','Interpreter','latex')
title('Segnale di Yaw rispetto a riferimento','Interpreter','latex')

