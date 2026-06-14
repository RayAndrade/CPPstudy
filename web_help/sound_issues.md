Absolutely 👍 — here’s a **clean, practical troubleshooting report** you can save for your records.
I’ve written it like a **playbook** you can reuse the next time sound breaks, especially on **Linux / PipeWire / Audacity**.

---

# 🎧🎙️ Audio Troubleshooting Report

**Mic Recording & Audio Playback (Linux – PipeWire)**

## Environment (example)

* OS: Linux (Ubuntu / KDE)
* Audio stack: **PipeWire + WirePlumber**
* Applications: YouTube (browser), Audacity
* Hardware: USB microphones (HyperX SoloCast, Maono PD100X)

---

## 1. Symptoms Observed

### Playback issues

* No audio from YouTube or browser
* Volume sliders appear active but no sound

### Recording issues

* Microphone not detected
* Audacity records silence (flat waveform)
* Recording tab in `pavucontrol` empty
* Mic visible in system settings but not usable

---

## 2. First Principles (Always Start Here)

### A. Confirm system playback

* Check system volume (not muted)
* Confirm browser tab is not muted
* Verify **Output Device** is not “Dummy Output”

### B. Confirm system input

* Sound Settings → Input
* Speak and confirm input meter moves
* If no meter → device/profile issue

---

## 3. Use `pavucontrol` (Critical Tool)

Install if missing:

```bash
sudo apt install pavucontrol
```

### Key tabs to inspect:

* **Playback** → Is audio playing?
* **Recording** → Is the app listening to a mic?
* **Configuration** → Are device profiles correct?

---

## 4. Common Root Causes & Fixes

### 🔴 Pro Audio Profile Selected

**Symptom**

* Mic exists but no app can record
* Recording tab empty

**Fix**

* `pavucontrol → Configuration`
* Change device from:
  ❌ Pro Audio
  → ✅ Analog Stereo Input / Duplex

---

### 🔴 Output-Only Profile Selected

**Symptom**

* Mic visible but no input signal

**Fix**

* Select **Analog Stereo Input** or **Analog Stereo Duplex**
* Output-only disables recording completely

---

### 🔴 Multiple USB Mics Plugged In

**Symptom**

* Random mic selection
* One mic suppresses another

**Fix**

* Physically unplug all but **one mic**
* Restart audio services
* Confirm recording works
* Reintroduce other mics one at a time

---

### 🔴 App Listening to “Monitor” Instead of Mic

**Symptom**

* Silence in recordings
* Input source says “Monitor of …”

**Fix**

* Open `pavucontrol → Recording`
* While app is recording:

  * Change input source to the **actual mic**
  * Never select “Monitor of …”

---

## 5. Restart Audio Stack (Safe Reset)

For PipeWire systems:

```bash
systemctl --user restart pipewire
systemctl --user restart pipewire-pulse
systemctl --user restart wireplumber
```

No reboot required.

---

## 6. Audacity-Specific Checklist

### Recommended settings

* Recording Device: **pipewire** or **pulse**
* Channels: **Mono**
* Avoid: “Default” when possible

### If Audacity records silence:

1. Start recording
2. Open `pavucontrol → Recording`
3. Manually bind Audacity to the correct mic

---

## 7. Known Linux Audio Truths (Remember These)

* “Pro Audio” ≠ normal desktop recording
* Monitor sources ≠ microphones
* USB mics can steal focus from each other
* ALSA alone is fragile; PipeWire/Pulse routing is safer
* If Recording tab is empty → profile problem

---

## 8. Quick Recovery Checklist (60-Second Fix)

1. Open `pavucontrol`
2. Configuration → disable Pro Audio
3. Select Analog Stereo Input
4. Recording tab → bind app to mic
5. Test recording

---

## 9. Final Working State (Reference)

* One USB mic active
* Profile: **Analog Stereo Input**
* Audacity bound to mic (not monitor)
* Playback and recording both functional

---

If you want, next time we can:

* Turn this into a **one-page PDF**
* Create a **checklist card**
* Or adapt it into a **blog post / tutorial** for *The Ray Code*

You handled this like a pro — calm, methodical, zero panic. 👏🎙️

