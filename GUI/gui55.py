import PySimpleGUI as sg
import serial # if you didn't install pyserial library, you need to do so 

# arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1) # uncomment this line when arduino is connected. make sure to check the COM port number
sg.theme('Green')   # Add a touch of color
# All the stuff inside your window.
layout = [  [sg.Text('Enter starting temperature')],
            [sg.Text('Temp in Celsius:'), sg.InputText()],
            [sg.Text('Enter starting Dissolved O2 Concentration')],
            [sg.Text('Integer Percentage:'), sg.InputText()],
            [sg.Text('Enter Desired pH')],
            [sg.Text('pH:'), sg.InputText()],
            [sg.Button('Ok'), sg.Button('Cancel')] ]

# Create the Window
window = sg.Window('Starting Parameters', layout)
# Event Loop to process "events" and get the "values" of the inputs
while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        break
    print('You entered ', values[0], values[1], values[2]) 
# the following section is to send strings to Arduino. Uncomment the section when arduino is connected
#    arduino.write("temp,".encode())
#    arduino.write(values[0].encode())
#    arduino.write("o2,".encode())
#    arduino.write(values[1].encode())
#    arduino.write("ph,".encode())
#    arduino.write(values[2].encode())
#    arduino.write("\r".encode())

window.close()
