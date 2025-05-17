import serial
import tkinter as tk
from tkinter import ttk
import datetime

arduino_port = 'COM3'
baud_rate = 9600
ser = serial.Serial(arduino_port, baud_rate)

def send_command(command):
    ser.write(command.encode())

def turn_on_leds():
    send_command('1')
    status_label.config(text=" Street Lights turned ON")

def turn_off_leds():
    send_command('2')
    status_label.config(text=" Street Lights turned OFF")

def enter_auto_mode():
    send_command('3')
    status_label.config(text="Auto Mode enabled")

def enter_smart_mode1():
    send_command('4')
    status_label.config(text="Smart Mode(1) enabled")

def enter_smart_mode2():
    send_command('5')
    status_label.config(text="Smart Mode(2) enabled")

def activate_smart_mode1():
    enter_smart_mode1()
    root.after(7200000, activate_smart_mode2)  # Switch to Smart Mode (2) after 2 hours (7200000 milliseconds)

def activate_smart_mode2():
    enter_smart_mode2()
    root.after(7200000, enter_auto_mode)  # Switch to Auto Mode after 2 hours (7200000 milliseconds)

def check_time_and_activate():
    current_time = datetime.datetime.now().time()
    if current_time.hour == 00 and current_time.minute == 00:
        activate_smart_mode1()
    else:
        enter_auto_mode()
        root.after(60000, check_time_and_activate)  # Check the time every minute (60000 milliseconds)

# Create the main window
root = tk.Tk()
root.title("Smart Street Light Control")
root.geometry("800x400")  # Increased window size

# Create a frame to add a border around the label
label_frame = ttk.Frame(root, relief=tk.SUNKEN, borderwidth=2)
label_frame.grid(row=0, column=0, columnspan=2, padx=10, pady=20)

# Create a label inside the frame with a larger font size
status_label = ttk.Label(label_frame, text="", font=("Times New Roman", 30))  # Increased font size
status_label.pack()


button_width = 30
button_height = 2


style = ttk.Style()
style.configure("Large.TButton", font=("Times New Roman", 14), padding=(20, 10))

on_button = ttk.Button(root, text="Street Lights ON Mode", command=turn_on_leds, width=button_width,
                       style="Large.TButton")
off_button = ttk.Button(root, text="Street Lights OFF Mode", command=turn_off_leds, width=button_width,
                        style="Large.TButton")
auto_button = ttk.Button(root, text="Auto Mode", command=enter_auto_mode, width=button_width, style="Large.TButton")
smart_button1 = ttk.Button(root, text="Manual Mode (1)", command=enter_smart_mode1, width=button_width,
                           style="Large.TButton")
smart_button2 = ttk.Button(root, text="Manual Mode (2)", command=enter_smart_mode2, width=button_width,
                           style="Large.TButton")


activate_smart_mode_button = ttk.Button(root, text="Smart Mood",
                                        command=check_time_and_activate, width=button_width, style="Large.TButton")

on_button.grid(row=1, column=0, padx=10, pady=10, sticky="w")
off_button.grid(row=2, column=0, padx=10, pady=10, sticky="w")
auto_button.grid(row=3, column=0, padx=10, pady=10, sticky="w")
smart_button1.grid(row=1, column=1, padx=10, pady=10, sticky="w")
smart_button2.grid(row=2, column=1, padx=10, pady=10, sticky="w")
activate_smart_mode_button.grid(row=3, column=1, padx=10, pady=10, sticky="w")


root.mainloop()
