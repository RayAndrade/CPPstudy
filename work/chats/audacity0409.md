# Audacity USB Microphone Issue on Ubuntu (PD100X Not Recording)

## 🐞 Reported Problem

Audacity 3.4.2 running on Ubuntu (with PipeWire + PulseAudio) failed to record audio from a Maono PD100X USB microphone. The mic was detected by the system, but no sound was captured in Audacity. The following symptoms were observed:

- Audacity showed `Actual Rate: 44100` instead of 48000
- The input meter in Audacity remained flat
- The mic appeared in `arecord -l` and `pavucontrol` > Input Devices
- `arecord` and `gnome-sound-recorder` also produced silent recordings
- `pavucontrol` > Recording tab showed no activity during Audacity sessions

## 🔍 Discovered Problem

1. **Audacity was not using PulseAudio**, and was attempting to record directly from ALSA (`hw:1,0`), bypassing system routing.
2. The mic was functioning correctly but **not properly routed to Audacity**.
3. The Audacity config had to be reset and the recording interface changed to `pulse`.

## 🧠 How It Was Discovered

- System test with `arecord` showed the mic was silent, suggesting a routing issue.
- `pavucontrol` showed live activity in the **Input Devices tab**, proving the mic was working.
- No Audacity presence in `pavucontrol > Recording` confirmed it was not using PulseAudio.
- Switching the recording device to `pulse` triggered the correct connection.

## ✅ Resolution Steps

1. **Reset Audacity configuration:**

   ```bash
   mv ~/.config/audacity ~/.config/audacity-backup



Absolutely, Ray — here’s a clean and complete `README.md` in Markdown format summarizing your journey, the problem, and how it was resolved and tested:

---

```markdown
# Audacity USB Microphone Issue on Ubuntu (PD100X Not Recording)

## 🐞 Reported Problem

Audacity 3.4.2 running on Ubuntu (with PipeWire + PulseAudio) failed to record audio from a Maono PD100X USB microphone. The mic was detected by the system, but no sound was captured in Audacity. The following symptoms were observed:

- Audacity showed `Actual Rate: 44100` instead of 48000
- The input meter in Audacity remained flat
- The mic appeared in `arecord -l` and `pavucontrol` > Input Devices
- `arecord` and `gnome-sound-recorder` also produced silent recordings
- `pavucontrol` > Recording tab showed no activity during Audacity sessions

## 🔍 Discovered Problem

1. **Audacity was not using PulseAudio**, and was attempting to record directly from ALSA (`hw:1,0`), bypassing system routing.
2. The mic was functioning correctly but **not properly routed to Audacity**.
3. The Audacity config had to be reset and the recording interface changed to `pulse`.

## 🧠 How It Was Discovered

- System test with `arecord` showed the mic was silent, suggesting a routing issue.
- `pavucontrol` showed live activity in the **Input Devices tab**, proving the mic was working.
- No Audacity presence in `pavucontrol > Recording` confirmed it was not using PulseAudio.
- Switching the recording device to `pulse` triggered the correct connection.

## ✅ Resolution Steps

1. **Reset Audacity configuration:**

   ```bash
   mv ~/.config/audacity ~/.config/audacity-backup
   ```

2. **Restart the PipeWire audio system:**

   ```bash
   systemctl --user restart pipewire pipewire-pulse
   ```

3. **Reopen Audacity** and set the following from the top toolbar:

   - **Host** = `ALSA`
   - **Recording Device** = `pulse`
   - **Playback Device** = `pulse` or `default`
   - **Channels** = `1 (Mono)`
   - **Project Rate** = `48000` (manually set in `audacity.cfg` if needed)

4. **Open `pavucontrol` and switch the recording source:**

   - Go to the **Recording** tab
   - Start recording in Audacity
   - Select **PD100X Podcast Microphone (Mono)** from the source dropdown

## 🧪 Testing and Confirmation

- Mic level was confirmed to move in `pavucontrol > Input Devices`
- Audacity's input meter responded when speaking into the mic
- Audio was recorded and played back successfully in Audacity
- Issue confirmed resolved

## 📝 Notes

- Using `pulse` instead of `hw:` allows Audacity to record via the PulseAudio/ PipeWire interface.
- Hardware mute on the PD100X may be enabled by default; the mic's button toggles mute/unmute.
```

---

Let me know if you want this saved as a `.md` file or tweaked for sharing or documentation. 👌
