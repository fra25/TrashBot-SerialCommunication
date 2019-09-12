from serial import Serial
import sys

port = "/dev/tty" #la porta

#port = "COM3"

p = input("inserire l'ultima parte della porta (escluso tty): ")

port += p



serial = Serial(port, 9600)
serial.flushInput()

print('- Inserire "destra" per svoltare a destra')
print('- Inserire "sinistra" per svoltare a sinistra')
print('- Inserire "spegni" per spegnere')
print('- Inserire "dritto" per andare dritto')
print('- Inserire "accendi" per accendere')
print('- Inserire un numero tra 90 e 255 per cambiare la velocita')
print('- Inserire "ESC" per uscire\n\n')

while True:
    toWrite = input("Cose da mandare --> ")
    if toWrite == "ESC":
        serial.close()
        sys.exit()
    else:
        serial.write(str.encode(toWrite))
        toRead = serial.readline()
        if toRead:
            print(toRead.decode())
