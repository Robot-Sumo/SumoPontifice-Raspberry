#include <wiringSerial.h>
#include <iostream>


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


   
void setYaw(int Yaw);

void setRoll(int Roll);
 
int main(int argc, char** argv)
{
    // allocate memory for file content
    long size = 100;
    char* buffer = new char[size];
    // Datos de motores calibrados


    fd = serialOpen ("/dev/ttyAMA0", 9600);
    
    usleep (50000);
    cout << "Starting Serial with "<< fd<< endl;

    if (fd != -1) 
    {
       
        int  bytes_written  =  0 ;   
        char read_buffer[32];
        serialFlush (fd);                                                
       
        usleep (500000);             // sleep enough to transmit the 7 plus
        char buf [100];
        
        for (int roll = roll_min; roll<roll_90; roll = roll +2 )
        {
            setRoll(roll);
            usleep (100000);
        }
        /*
        int n = read(fd,&read_buffer,32);  // read up to 100 characters if ready to read
        cout << bytes_written<<endl;
        cout << n<<endl;
        for (int i; i< n ; i++) cout << read_buffer[i]<<endl;
        */
        serialClose(fd);
    }
    
                                     // receive 25:  approx 100 uS per char transmit
  

   
    
    
    
    


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
