
[H,theta,rho] = hough(BWff) %Hough Transform;
peaks = houghpeaks(H,1) %peak values;
DegAngle = max(theta(peaks(:,2))); %found angle value;

DegAngle
