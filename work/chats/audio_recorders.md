I am looking for a program that runs on linux that will record my voice and save it in a mp3 file or wav file for podcasting. What do you suggest? I don't want Audacity.

If you're looking for a voice recording program on Linux **that’s *not* Audacity**, here are some solid alternatives that can record your voice and save in MP3 or WAV format, ideal for podcasting:

---

### 🎙️ **1. `OBS Studio` (Open Broadcaster Software)**
- **Use Case:** Designed for video streaming and recording, but works great for podcasting too.
- **Pros:**
  - Free, open source
  - Highly customizable
  - Great audio quality
  - Supports multiple audio tracks
- **Output:** Records in .mkv by default but you can set it to record just audio (e.g., .mp3 or .wav with plugins)
- **Install:**
  ```bash
  sudo apt install obs-studio
  ```

---

### 🎙️ **2. `Audio Recorder`**
- **Use Case:** Simple GUI-based audio recorder.
- **Pros:**
  - Lightweight and user-friendly
  - Can schedule recordings
  - Supports MP3, WAV, FLAC, and OGG
- **Install:**
  ```bash
  sudo apt install audio-recorder
  ```

---

### 🎙️ **3. `Ardour`**
- **Use Case:** Full digital audio workstation (DAW) for professional podcast production.
- **Pros:**
  - Multitrack recording
  - Great for editing and mixing
  - Supports LADSPA/LV2 plugins
- **Cons:**
  - Heavier learning curve
- **Install:**
  ```bash
  sudo apt install ardour
  ```

---

### 🎙️ **4. `GNOME Sound Recorder`**
- **Use Case:** Extremely simple, for quick recordings.
- **Pros:**
  - Clean interface
  - Just hit record and go
- **Cons:**
  - Limited features
- **Install:**
  ```bash
  sudo apt install gnome-sound-recorder
  ```

---

### 🧪 CLI Option (Bonus): `ffmpeg`
- **If you prefer command line**, `ffmpeg` can do the job:
  ```bash
  ffmpeg -f alsa -i default -acodec libmp3lame output.mp3
  ```
- Swap `libmp3lame` with `pcm_s16le` and `output.wav` if you want WAV.

---

Want a GUI or CLI-based tool? Do you need advanced editing too, or just raw voice capture?
