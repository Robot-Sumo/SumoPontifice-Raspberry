#!/usr/bin/env python

import socket
import time
import base64
import sys
import json
import time
import smbus
import math

class MPU6050:

    def __init__(self):
        self.power_mgmt_1 = 0x6b
        self.power_mgmt_2 = 0x6c
        self.address = 0x68       # via i2cdetect
        self.bus = smbus.SMBus(1) # bus = smbus.SMBus(0) fuer Revision 1
        # Aktivieren, um das Modul ansprechen zu koennen
        self.bus.write_byte_data(self.address, self.power_mgmt_1, 0)
        self.gyro_scale = (250.0/32768.0)*math.pi/180.0
        self.acc_scale = 9.81/16384.0
        print("I2C initialized")

    def read_byte(self, reg):
        return self.bus.read_byte_data(self.address, reg)
 
    def read_word(self, reg):
        self.h = self.bus.read_byte_data(self.address, reg)
        self.l = self.bus.read_byte_data(self.address, reg+1)
        self.value = (self.h << 8) + self.l
        return self.value

    def read_word_2c(self, reg):
        self.val = self.read_word(reg)
        if (self.val >= 0x8000):
            return -((65535 - self.val) + 1)
        else:
            return self.val

    def get(self):
        self.gyro_x = self.read_word_2c(0x43)*self.gyro_scale
        self.gyro_y = self.read_word_2c(0x45)*self.gyro_scale
        self.gyro_z = self.read_word_2c(0x47)*self.gyro_scale
        self.acc_x = self.read_word_2c(0x3b)*self.acc_scale
        self.acc_y = self.read_word_2c(0x3d)*self.acc_scale
        self.acc_z = self.read_word_2c(0x3f)*self.acc_scale

        self.list_measurements = list((self.gyro_x, self.gyro_y, self.gyro_z, 
            self.acc_x, self.acc_y, self.acc_z))


        return self.list_measurements


def main():

    TCP_IP = '192.168.1.114'
    TCP_PORT = 5005
    BUFFER_SIZE = 2**20


    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((TCP_IP, TCP_PORT))

    time_start = time.time()
    time_stamp = time.time()
    sum = 0
    i = 0

    period = 0.02
    dif = 0.0
    i = 0

    imu = MPU6050()
    
    while time_stamp-time_start<100:
        time_stamp = time.time()
        imu_sample = imu.get()
        if i >0:
            dif =time_stamp-last_time_stamp
            print(dif*1000)
            sum = dif+sum
        
        #imu_sample = imu.get()
        t = json.dumps(imu_sample)
	
        s.sendall(t+"\n")
        i = i+1
        last_time_stamp = time_stamp
 
        time_current= time.time()

        while time_current-time_stamp <= period:
            time_current= time.time()

    #data = s.recv(BUFFER_SIZE)
    print(sum/i*1000)
    print(i)
    s.close()

#print "received data:", data

if __name__ == "__main__": main()
