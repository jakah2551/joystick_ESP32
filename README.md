# README - ESP32 Controller Interface 🇬🇧

### 🎮 Description  
This interface allows controlling a robot via an ESP32 creating a Wi-Fi access point. The interface includes:

- A virtual joystick for movement  
- 4 customizable buttons (L1, L2, R1, R2)  
- 2 switches for special functions

### 📡 Communication  
All actions on the web interface send commands to the ESP32 through the `command` variable in `sketch.ino`:

- Default value: `"ON"` (no action)
- **Movement**: Direction is determined by angle θ (theta) calculated from joystick X/Y coordinates
- **Running mode**: Activated by `Switch1`, enables red theme and sets `r = true`:
  - `command` will have **negative** values
- **Walking mode** (default):
  - `command` will have **positive** values
- **Sitting mode**: Activated by `Switch2`, temporarily disables controls

### 🕹️ Button Commands  
Each button sends a specific command:

- `L1` → `command = "L1"`  
- `L2` → `command = "L2"`  
- `R1` → `command = "R1"`  
- `R2` → `command = "R2"`

### 🔌 Connection  
- Connect to Wi-Fi **ESP32_Controller** (password: `12345678`)  
- Open browser at `192.168.4.1`

### 🎨 Interface  
- **Normal theme**: Dark background  
- **Red theme**: Activated by running mode (`Switch1`)  
- **Controls disabled**: Activated by sitting mode (`Switch2`)

---

⚠️ **Note**  
The movement logic should be implemented in the `gestisciAngolo(x, y, r)` function which processes joystick coordinates and running mode to generate appropriate command values.
