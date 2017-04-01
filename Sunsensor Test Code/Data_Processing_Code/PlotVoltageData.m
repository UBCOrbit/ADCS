Volt1 = zeros(60,60);
for i = 1:60
    if(rem(i,2) == 0)
     for j = 1:60
         Volt1(i,j) = Voltage1(60*(i-1) + j);
         if(Volt1(i,j) > 1)
             Volt1(i,j) = 00;
         end
         Volt2(i,j) = Voltage2(60*(i-1) + j);
         if(Volt2(i,j) > 1)
             Volt2(i,j) = 0;
         end
         Volt3(i,j) = Voltage3(60*(i-1) + j);
         if(Volt3(i,j) > 1)
             Volt3(i,j) = 0;
         end
         Volt4(i,j) = Voltage4(60*(i-1) + j);
         if(Volt4(i,j) > 1)
             Volt4(i,j) = 0;
         end
     end
    else 
        for j = 1:60
         Volt1(i,61-j) = Voltage1(60*(i-1) + j);
         if(Volt1(i,61-j) > 1)
             Volt1(i,61-j) = 00;
         end
         Volt2(i,61-j) = Voltage2(60*(i-1) + j);
         if(Volt2(i,61-j) > 1)
             Volt2(i,61-j) = 0;
         end
         Volt3(i,61-j) = Voltage3(60*(i-1) + j);
         if(Volt3(i,61-j) > 1)
             Volt3(i,61-j) = 0;
         end
         Volt4(i,61-j) = Voltage4(60*(i-1) + j);
         if(Volt4(i,61-j) > 1)
             Volt4(i,61-j) = 0;
         end
        end
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