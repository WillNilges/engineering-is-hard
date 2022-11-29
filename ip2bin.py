#!/usr/bin/env python

import sys

def binary(num, length=8):
    return format(num, '#0{}b'.format(length + 2))

def ip2bin(ip_str):
    ip_bin = ""
    for byte in ip_str.split('.'):
       ip_bin += f"{binary(int(byte))} " 
    print(ip_bin.replace("0b", ""))

ip2bin(sys.argv[1])