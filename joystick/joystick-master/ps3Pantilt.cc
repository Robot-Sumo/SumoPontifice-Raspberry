// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Copyright Drew Noakes 2013-2016

#include "joystick.hh"
#include <unistd.h>
#include <iostream>
#include <wiringSerial.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

 //dmesg | grep tty
int fd;
uint8_t yaw_180 =228;
uint8_t yaw_0 = 36;

uint8_t roll_90 = 245;
uint8_t roll_0 = 131;
uint8_t roll_min = 100;  // minimo angulo sin que el motor choque con la base


#define Cross 0
#define Circle 1
#define Triangle 2
#define Rectangle 3
#define L1 4
#define R1 5
#define L2 6
#define R2 7
#define Select 8
#define Start 9
#define PS 10
#define L3_button 11
#define R3_button 12
#define Up 13
#define Down 14
#define Left 15
#define Right 16
#define L3_x_axis 0
#define L3_y_axis 1
#define R3_x_axis 3
#define R3_y_axis 4
#define R2_x_axis 5
#define L2_x_axis 2


using namespace std;

void decodeButton(JoystickEvent event);
void setYaw(int Yaw);

void setRoll(int Roll);

int main(int argc, char** argv)
{
  // Create an instance of Joystick
  Joystick joystick("/dev/input/js0");
  fd = serialOpen ("/dev/ttyAMA0", 9600);
  cout << "Starting Serial with "<< fd<< endl;

  // Ensure that it was found and that we can use it
  if (!joystick.isFound())
  {
    printf("open failed.\n");
    exit(1);
  }
  if (fd != -1) 
  {
    while (true)
    {
        // Restrict rate
        usleep(1000);

        // Attempt to sample an event from the joystick
        JoystickEvent event;
        if (joystick.sample(&event))
        {
            decodeButton(event);
        }
    }
  }
  
}

void decodeButton(JoystickEvent event)
{
   if (event.isButton())
      {
        string buttonLabel;
        switch (event.number)
        {
            case Cross:
                buttonLabel = "Cross";
                break;
            case Circle:
                buttonLabel = "Circle";
                break;
            case Triangle:
                buttonLabel = "Triangle";
                break;
            case Rectangle:
                buttonLabel = "Rectangle";
                break;
            case L1:
                buttonLabel = "L1";
                break;
            case R1:
                buttonLabel = "R1";
                break;
            case L2:
                buttonLabel = "L2";
                break;
            case R2:
                buttonLabel = "R2";
                break;
            case Select:
                buttonLabel = "Select";
                break;
            case Start:
                buttonLabel = "Start";
                break;
            case PS:
                buttonLabel = "PS";
                break;
            case L3_button:
                buttonLabel = "L3 button";
                break;
            case R3_button:
                buttonLabel = "R3 button";
                break;
            case Up:
                buttonLabel = "Up Arrow";
                break;
            case Down:
                buttonLabel = "Down Arrow";
                break;
            case Left:
                buttonLabel = "Left Arrow";
                break;
            case Right:
                buttonLabel = "Right Arrow";
                break;
        
          default:
            break;
        }

          if (buttonLabel!="")
            cout << buttonLabel << " is "  << (event.value == 0 ? "up" : "down") << endl;

      }
      else if (event.isAxis())
      {
        string axisLabel;
        switch (event.number)
        {
            case R3_x_axis:
                axisLabel = "R3 x Axis";
                break;
            case L3_x_axis:
                axisLabel = "L3 x Axis";
                break;
            case R3_y_axis:
                axisLabel = "R3 y Axis";
                break;
            case L3_y_axis:
                axisLabel = "L3 y Axis";
                break;
            case R2_x_axis:
                axisLabel = "R2 x Axis";
                break;
            case L2_x_axis:
                axisLabel = "L2 x Axis";
                break;
            default:
            break;

        }
        if (axisLabel !="")
            cout << axisLabel << " is at position "  << event.value  << endl;
      }
}


void setYaw(int Yaw)
{
    char write_buffer[] = {255, 1, yaw_0 }; 
    if (Yaw>yaw_180)
    {
        write_buffer[2] = yaw_180;
        write(fd ,write_buffer,sizeof(write_buffer));
    }
    else if (Yaw<yaw_0)
    {
        write_buffer[2] = yaw_0;
        write(fd ,write_buffer,sizeof(write_buffer));
    }
    else
    {
        write_buffer[2] = Yaw;
        write(fd ,write_buffer,sizeof(write_buffer));
    }
    
    
}


void setRoll(int Roll)
{
    char write_buffer[] = {255, 2, roll_min }; 
    if (Roll>roll_90)
    {
        write_buffer[2] = roll_90;
        write(fd ,write_buffer,sizeof(write_buffer));
    }
    else if (Roll<roll_min)
    {
        write_buffer[2] = roll_min;
        write(fd ,write_buffer,sizeof(write_buffer));
    }
    else
    {
        write_buffer[2] = Roll;
        write(fd ,write_buffer,sizeof(write_buffer));
    }
    
    
}
