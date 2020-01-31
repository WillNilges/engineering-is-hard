#!/usr/bin/env/python
import typing

R1 = float(input("Enter R1: "))
R2 = float(input("Enter R2: "))
R3 = float(input("Enter R3: "))

print (str(R1) +
"                   " + str(R2) + 
'''
x ---VVV---T---VVV--- y
           |
           > ''' + str(R3) + '''
           <
           |
           z
'''
)

numerator = (R1*R2 + R2*R3 + R1*R3)
RA = numerator/R1
RB = numerator/R2
RC = numerator/R3

print ("RA: " + str(RA))
print ("RB: " + str(RB))
print ("RC: " + str(RC))
print (
"         " + str(RC) +
'''
x --------VVV-------- y
   \               /
     >           >   RA (right) ''' + str(RA) + '''
       <       <     RB (left) ''' + str(RB) + '''
         \   /
           z
''')
