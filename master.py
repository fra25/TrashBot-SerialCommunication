from serial import Serial

port = "/dev/tty" #la porta


p = input("inserire l'ultima parte della porta (escluso tty): ")

port += p

serial = Serial(port, 9600)
serial.flushInput()

print('inserire "destra" per svoltare a destra')
print('inserire "sinistra" per svoltare a sinistra')
print('inserire "spegni" per spegnere')
print('inserire "accendi" per accendere')
print('inserire un numero tra 190 e 255 per cambiare la velocità')
print('inserire "GIERI" per uscire\n\n')
while True:
    toWrite = input("Cose da mandare -->")
    if toWrite == "GIERI":
        exit()
    else:
        serial.write(str.encode(toWrite))
