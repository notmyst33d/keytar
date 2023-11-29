/* CUSTOMIZE SHIT HERE FOR YOUR SETUP */

// ADC pin used for polling the strum bar.
const int pin = 34;

// Number of "ticks" to use for smoothing. 1 tick = 1 poll.
const int max_ticks = 32;

// Middle value of the strum bar.
const int middle = 1900;

// Strum bar margins, increase if you see phantom strumming, decrease if s
const int margin = 500;

/* DO NOT TOUCH ANYTHING AFTER THIS LINE IF YOU DONT KNOW WHAT YOU ARE DOING */

// Current strum bar action.
// 0 = Rest
// 1 = Up
// 2 = Down
int action = 0;

// Previous strum bar action.
int previous_action = 0;

// Current smoothing tick.
int tick = 1;

// Smoothing data.
short data[max_ticks];

void setup() {
  Serial.begin(9600); // It might be a good idea to increase the baud rate to get faster speeds.
}

void loop() {
  int value = analogRead(pin);
  if (tick < max_ticks) {
    data[tick - 1] = value;
    tick++;
    return;
  }

  int sum = 0;
  for (int i = 0; i < tick; i++) {
    sum += data[i];
  }

  value = sum / tick;
  tick = 1;

  if (value > middle + margin) {
    previous_action = action;
    action = 1;
  } else if (value < middle - margin) {
    previous_action = action;
    action = 2;
  } else {
    previous_action = action;
    action = 0;
  }

  if (action != previous_action) {
    Serial.write(0);
    Serial.write(action);
  }
}
