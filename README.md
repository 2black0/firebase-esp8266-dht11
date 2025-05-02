# 🔥 Firebase ESP8266 + DHT11

An IoT project using **ESP8266 (NodeMCU)** to:

- Read **temperature and humidity** from **DHT11**
- Send data to **Google Firebase Realtime Database**
- Control **2 LEDs** remotely via Firebase
- Use **SimpleTimer** for periodic DHT11 upload

📺 Tutorial Video: [YouTube - Firebase + ESP8266 + Arduino (Live #1 IoT)](https://www.youtube.com/watch?v=wlUjsAODKqE&t=1911s)

---

## 📦 Project Structure

```

firebase-esp8266-dht11/
├── LICENSE
├── projects
│   └── firebase-esp8266.ino
└── README.md

```

---

## 🛠️ Hardware Requirements

| Component      | Description                        |
|----------------|------------------------------------|
| NodeMCU ESP8266| Main controller board              |
| DHT11 Sensor   | For temperature & humidity reading |
| LED x2         | Controlled via Firebase            |
| Resistors      | (Recommended: 220–330Ω for LEDs)   |

---

## 🔌 Wiring Diagram

| NodeMCU Pin | Connected To        | Description         |
|-------------|---------------------|---------------------|
| D4 (GPIO2)  | DHT11 Data          | Sensor data input   |
| 5V          | DHT11 Vcc           | Sensor power        |
| GND         | DHT11 GND           | Sensor ground       |
| D1 (GPIO5)  | LED1 (via resistor) | LED1 control        |
| D2 (GPIO4)  | LED2 (via resistor) | LED2 control        |

---

## 📡 Firebase Configuration

Replace the placeholders in `firebase-esp8266.ino` with your actual Firebase project info:

```cpp
#define FIREBASE_HOST "your-project-id.firebaseio.com"
#define FIREBASE_AUTH "your-firebase-secret"
#define WIFI_SSID "your-ssid"
#define WIFI_PASSWORD "your-password"
```

### Firebase Realtime Database Keys Used:

| Firebase Key        | Type    | Description          |
| ------------------- | ------- | -------------------- |
| `LED1-Status`       | `int`   | 1 = ON, 0 = OFF      |
| `LED2-Status`       | `int`   | 1 = ON, 0 = OFF      |
| `DHT11-Temperature` | `float` | Sent every 5 seconds |
| `DHT11-Humidity`    | `float` | Sent every 5 seconds |

---

## 📋 Features

* 🌡️ Periodically reads DHT11 sensor (every 5 seconds)
* 📲 Uploads temperature & humidity to Firebase
* 💡 Reads LED states from Firebase and controls GPIOs
* 🔁 Uses `SimpleTimer` for clean interval-based logic
* 🐞 Serial output for debugging and status

---

## ▶️ Example Serial Output

```txt
Connecting......
Connected: 192.168.1.12

Send Humidity and Temperature to Firebase
Humidity(%): 67.0
Temperature (*C): 28.0

LED1 ON
LED2 OFF
```

---

## 🧠 Libraries Used

Make sure you install these libraries via Library Manager:

* `FirebaseArduino` – [GitHub](https://github.com/FirebaseExtended/firebase-arduino)
* `SimpleDHT`
* `SimpleTimer`
* `ESP8266WiFi`

---

## 🧑‍💻 Author

Created by **Ardy Seto Priambodo**
🌐 Website: [robot-terbang.web.id](http://robot-terbang.web.id)
💬 Join Telegram Community: [t.me/robot\_terbang](http://t.me/robot_terbang)

---

## 📜 License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.