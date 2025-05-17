# 💡 Smart Street Light System

This project is a **Smart Street Light Control System** built using **Arduino** and a **Python GUI**. It allows manual and automatic control of street lights based on time schedules and user input.

---

## 🛠️ Tech Stack

- **Arduino Uno** (or compatible)
- **Python** (Tkinter for GUI, PySerial for communication)
- **LEDs / Relays** (for simulating street lights)
- **LDR Sensor** (optional for real-time light detection)
- **Windows PC** (for running GUI)

---

## 🧠 Features

### Manual Controls
- **Street Lights ON Mode**: Force ON all lights
- **Street Lights OFF Mode**: Force OFF all lights
- **Manual Mode 1 & 2**: Custom user modes

### Automatic & Smart Modes
- **Auto Mode**: Controls lights based on ambient light/time
- **Smart Mood**: Automatically switches between Smart Mode 1 → 2 → Auto Mode after specific intervals

### Time-Based Automation
- At **00:00** (midnight), Smart Mode 1 starts
- After **2 hours**, switches to Smart Mode 2
- After another **2 hours**, returns to Auto Mode

---

## 🖥️ GUI (Python)
Built using **Tkinter**, it provides the following buttons:

- `Street Lights ON Mode`
- `Street Lights OFF Mode`
- `Auto Mode`
- `Manual Mode (1)`
- `Manual Mode (2)`
- `Smart Mood` (Automated cycle)

Status messages are displayed at the top.

---

## 🔌 Communication
- Python GUI communicates with Arduino over **Serial (COM3 by default)**
- Commands sent:
  - `'1'` → ON
  - `'2'` → OFF
  - `'3'` → Auto Mode
  - `'4'` → Smart Mode 1
  - `'5'` → Smart Mode 2

