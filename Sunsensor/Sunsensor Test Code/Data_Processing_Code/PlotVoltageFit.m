%reading and defining the data
%filename = 'C:\Users\aless\Documents\UBC Orbit\ADCS-SunSensorData\Sun_Sensor_Data\Data_raw.txt';
filename = 'DataTesting27OCT2018_3.txt';
AnglePlat = int8(csvread(filename,1,0,[1,0,3600,0]));
AngleServo = int8(csvread(filename,1,1,[1,1,3600,1]));
Voltage1 = csvread(filename,1,2,[1,2,3600,2]);
Voltage2 = csvread(filename,1,3,[1,3,3600,3]);
Voltage3 = csvread(filename,1,4,[1,4,3600,4]);
Voltage4 = csvread(filename,1,5,[1,5,3600,5]);

limitV = 100;

for i=1:3600
    if Voltage1(i) > limitV
        Voltage1(i) = 0;
    elseif Voltage2(i) > limitV
        Voltage2(i) = 0;
    elseif Voltage3(i) > limitV
        Voltage3(i) = 0;
    elseif Voltage4(i) > limitV
        Voltage4(i) = 0;
    end
end

%plotting the data 
sf = fit([double(AnglePlat),double(AngleServo)],double(Voltage4),'poly23');
plot(sf,[double(AnglePlat),double(AngleServo)],double(Voltage4));

%sf = fit([double(AnglePlat),double(AngleServo)],double(Voltage2),'poly23');
%plot(sf,[double(AnglePlat),double(AngleServo)],double(Voltage2));

%sf = fit([double(AnglePlat),double(AngleServo)],double(Voltage3),'poly23');
%plot(sf,[double(AnglePlat),double(AngleServo)],double(Voltage3));

%sf = fit([double(AnglePlat),double(AngleServo)],double(Voltage4),'poly23');
%plot(sf,[double(AnglePlat),double(AngleServo)],double(Voltage4));