import processing.serial.*;

Serial comPort;

final int numDataToGather = 3600;
int index = 0;

String[] inputString;
PrintWriter output;

void setup() {
  size(600,600);
  // Display all aailible serial ports
  println(Serial.list());
  println("START");
  // Assign a serial port to red from
  comPort = new Serial(this, Serial.list()[0], 9600);
  comPort.bufferUntil('\n');
  // Initialize output data file
  output = createWriter("DataProof.txt");
  output.println("Voltage1,Voltage2,Voltage3,Voltage4,Calc_angles,Input_angles");
}

void draw() {
  String temp = comPort.readStringUntil('\n');
  if (temp != null) {
    println(temp);
    output.println(temp);
    index++;
  }
  if (index >= numDataToGather) {
    output.close();
    println("DONE");
    while (true) {}
  }
}