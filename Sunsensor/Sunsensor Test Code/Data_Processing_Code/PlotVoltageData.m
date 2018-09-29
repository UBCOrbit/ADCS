filename = 'SunSensor Data_raw.txt';
AnglePlat = int8(csvread(filename,1,0,[1,0,3600,0]));
AngleServo = int8(csvread(filename,1,1,[1,1,3600,1]));
Voltage1 = csvread(filename,1,2,[1,2,3600,2]);
Voltage2 = csvread(filename,1,3,[1,3,3600,3]);
Voltage3 = csvread(filename,1,4,[1,4,3600,4]);
Voltage4 = csvread(filename,1,5,[1,5,3600,5]);

Volt1 = zeros(60,60);
Volt2 = zeros(60,60);
Volt3 = zeros(60,60);
Volt4 = zeros(60,60);
for i = 1:3600
     Volt1(AnglePlat(i)+31,AngleServo(i)+31) = Voltage1(i);
     Volt2(AnglePlat(i)+31,AngleServo(i)+31) = Voltage2(i);
     Volt3(AnglePlat(i)+31,AngleServo(i)+31) = Voltage3(i);
     Volt4(AnglePlat(i)+31,AngleServo(i)+31) = Voltage4(i);
     if Voltage1(i) > 100
        Volt1(AnglePlat(i)+31,AngleServo(i)+31) = 0;
     elseif Voltage2(i) > 100
        Volt2(AnglePlat(i)+31,AngleServo(i)+31) = 0;
     elseif Voltage3(i) > 100
        Volt3(AnglePlat(i)+31,AngleServo(i)+31) = 0;
     elseif Voltage4(i) > 100
        Volt4(AnglePlat(i)+31,AngleServo(i)+31) = 0;
     end
end

%platform = linspace(-29,30,60);
%servo = linspace(-29,30,60);

%surf(platform, servo, Volt1);
%axis([-30 30 -30 30 0 40]);
subplot(2,2,1);
%colormap('hot');
imagesc(Volt1);
colorbar;
subplot(2,2,2);
%colormap('hot');
imagesc(Volt2);
colorbar;
subplot(2,2,3);
%colormap('hot');
imagesc(Volt3);
colorbar;
subplot(2,2,4);
%colormap('hot');
imagesc(Volt4);
colorbar;