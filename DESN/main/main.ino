#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h> //for making bluetooth work. Make sure to install "dabble" library in arduino IDE

void right_turn(void);
void gamepad_input(void);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000); // make sure Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      
  pinMode(8,OUTPUT); // For testing with LED

}

void loop() {
  // put your main code here, to run repeatedly:
  right_turn();
  gamepad_input();

}

void right_turn(void)
{
  //turn the wheel right
}


void Gamepad_Input(void) //detects input from gamepad app
{
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.
  if (GamePad.isUpPressed())
  {
    Serial.print("KeyPressed: UP");
    Serial.println();
    
    //put drive forward here
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("KeyPressed: DOWN ");
    Serial.println();
    //put drive backwards here
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("KeyPressed: LEFT ");
    Serial.println();
    //put turn left here
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("KeyPressed: RIGHT ");
    Serial.println();
    //put turn right here
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("KeyPressed: SQUARE");
    Serial.println();
    //lift bucket up here
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("KeyPressed: CIRCLE");
    Serial.println();
    //lower trapdoor down here
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("KeyPressed: CROSS");
    Serial.println();
    //move bucket down here
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("KeyPressed: TRIANGLE");
    Serial.println();
    //lift trapdoor up here
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("KeyPressed: START");
    Serial.println();
    //horn
    digitalWrite(8,HIGH); //turns LED on
  } else {
    digitalWrite(8,LOW); //turns LED off when button is not pressed
  }
  
  if (GamePad.isSelectPressed())
  {
    Serial.print("KeyPressed: SELECT");
    Serial.println();
  }
}




