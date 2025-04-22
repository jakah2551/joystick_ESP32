# README - ESP32 Controller Interface 🇮🇹

### 🎮 Descrizione  
Questa interfaccia permette di controllare un robot tramite un ESP32 che crea una rete Wi-Fi access point. L'interfaccia include:

- Un joystick virtuale per il movimento  
- 4 pulsanti personalizzabili (L1, L2, R1, R2)  
- 2 switch per funzioni speciali

### 📡 Comunicazione  
Tutte le azioni sull'interfaccia web inviano comandi all'ESP32 tramite la variabile `command` nel file `sketch.ino`:

- Valore default: `"ON"` (nessuna azione)
- **Movimento**: La direzione è determinata dall'angolo θ (teta) calcolato dalle coordinate X/Y del joystick
- **Modalità corsa**: Attivabile con `Switch1`, attiva il tema rosso e imposta `r = true`:
  - `command` avrà valori **negativi**
- **Modalità camminata** (default):
  - `command` avrà valori **positivi**
- **Modalità seduto**: Attivabile con `Switch2`, disabilita temporaneamente i controlli

### 🕹️ Comandi Pulsanti  
Ogni pulsante invia un comando specifico:

- `L1` → `command = "L1"`  
- `L2` → `command = "L2"`  
- `R1` → `command = "R1"`  
- `R2` → `command = "R2"`

### 🔌 Connessione  
- Connettiti alla rete Wi-Fi **ESP32_Controller** (password: `12345678`)  
- Apri il browser all'indirizzo `192.168.4.1`

### 🎨 Interfaccia  
- **Tema normale**: sfondo scuro  
- **Tema rosso**: attivato dalla modalità corsa (`Switch1`)  
- **Disabilitazione controlli**: attivata dalla modalità seduto (`Switch2`)

---
