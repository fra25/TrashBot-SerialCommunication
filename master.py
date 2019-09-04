from serial import Serial

port = "/dev/ttyUSB0" # Porta Seriale del Raspberry

ser = Serial(port, 9600) # Inizializzazione Istanza alla porta e a 9600 baudrate

ser.flushInput() # Mi affido a Gabbo per sta funzione che non so che fa

while True:
  toWrite = input("Cose da mandare --> ") # Input scritta da inviare
  ser.write(str.encode(toWrite)) # Invio scritta
