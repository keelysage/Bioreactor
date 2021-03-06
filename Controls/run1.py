import PySimpleGUI as sg

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
    print('You entered ', values[0])

window.close()
