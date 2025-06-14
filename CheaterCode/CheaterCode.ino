#define start_button 0
#define sol 1

bool running = false;
const int next_ball_wait_time = 140;
const int down_press_travel_time = 50;


void setup() 
{
 pinMode(start_button, INPUT_PULLUP);
 pinMode(sol, OUTPUT);

 digitalWrite(sol, LOW);

 running = false;
}


void loop() 
{
  startGame();
  
  if (running)
  {
    // adjustable wait intervals for each bucket in milliseconds
    float intervals[] = {1200, 1200, 1340, 1400, 1400, 1340, 1340, 1210, 1270, 1470, 1470, 1200, 1500}; 

    for (int i = 0; i < 13; i++) 
    {
      triggerSolenoid(); // drop 4 balls
      delay(intervals[i]); // Wait for next bucket
    }

    running = false;
  }
}


// drops 4 balls per bucket
void triggerSolenoid() 
{
  digitalWrite(sol, HIGH);
  delay(down_press_travel_time);
  digitalWrite(sol, LOW);
  delay(next_ball_wait_time);

  digitalWrite(sol, HIGH);
  delay(down_press_travel_time);
  digitalWrite(sol, LOW);
  delay(next_ball_wait_time);

  digitalWrite(sol, HIGH);
  delay(down_press_travel_time);
  digitalWrite(sol, LOW);
  delay(next_ball_wait_time);

  digitalWrite(sol, HIGH);
  delay(down_press_travel_time);
  digitalWrite(sol, LOW);
}


void startGame()
{
  bool start_pressed = digitalRead(start_button) == LOW;
  if (start_pressed == HIGH)
  {
    running = true;
  }
}