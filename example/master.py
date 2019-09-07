from serial import Serial

port = "/dev/ttyUSB0" # Porta Seriale del Raspberry che va cambiata in base a dove la colleghi

ser = Serial(port, 9600) # Inizializzazione Istanza alla porta e a 9600 baudrate

ser.flushInput() # Mi affido a Gabbo per sta funzione che non so che fa
				 # Gabbo sta qua e ti assicura che sta funzione sicuro fa qualcosa di utile 

print("manna 1 o 2 per i lampeggi")
while True:
  toWrite = input("Cose da mandare --> ") # Input scritta da inviare
  ser.write(str.encode(toWrite)) # Invio scritta
