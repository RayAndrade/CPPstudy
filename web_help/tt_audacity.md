

```markdown
# Audacity 2-Minute Pre-Recording Check

Use this before recording any video or narration.

---

## 1. Verify Microphone Detected

Run:

```

arecord -l

```

Expected:
Your microphone appears in the device list.

If not → unplug USB and reconnect.

---

## 2. Verify Input Level

Open audio control:

```

pavucontrol

```

Input Devices tab:

- [ ] Correct microphone selected
- [ ] Input meter moves when speaking
- [ ] Device not muted

---

## 3. Verify Audacity Launch

Start Audacity:

```

flatpak run org.audacityteam.Audacity

```

Check:

- [ ] Recording device = microphone
- [ ] Channels = Mono

---

## 4. Quick Recording Test

Press **Record**.

Speak for 3 seconds.

Expected:

- [ ] Waveform appears
- [ ] Input meter moves

If waveform flat → device wrong.

---

## 5. Playback Test

Press **Stop** then **Play**.

Expected:

- [ ] Voice playback through speakers

---

# If Recording Fails

Run system test:

```

arecord test.wav
aplay test.wav

```

If voice plays → Audacity configuration issue.

If voice does NOT play → Linux audio system issue.

---

# When Asking for Help

Report:

- Output of:

```

arecord -l
pactl list sources short

```

- Screenshot of Audacity audio settings
```

---

### Why this helps you

When you come back here, instead of saying **“Audacity doesn't work”**, you'll be able to say:

Example:

> Step 1 OK
> Step 2 input meter not moving
> Step 4 waveform flat

That lets me **diagnose the problem immediately**.

---

Since you record a lot of **design pattern videos for TheRayCode**, I can also show you later how to create a **single command diagnostic script**, something like:

```bash
audio-check
```

that prints **all audio status in one shot**.
Very handy before recording.


```markdown
# Audacity Troubleshooting Checklist (Linux / Ubuntu / DreamQuest OS)

Goal: Verify microphone input, audio system, and Audacity configuration.

---

# 1. Verify Microphone Hardware
- [ ] Microphone is plugged in securely
- [ ] Microphone indicator light is ON (if present)
- [ ] USB cable is not loose
- [ ] Try unplugging the microphone for 10 seconds and reconnecting

---

# 2. Confirm Linux Detects the Microphone

Run:

```

arecord -l

```

Expected:
- The microphone appears in the list of capture devices.

If NOT detected:
- [ ] Try another USB port
- [ ] Reboot the system

---

# 3. Check Audio Devices via PipeWire / PulseAudio

Run:

```

pactl list sources short

```

Expected:
- A device similar to your microphone appears.

Example:
```

alsa_input.usb-XXXX

```

---

# 4. Verify Input Levels

Open the sound control panel:

```

pavucontrol

```

Check:

### Input Devices Tab
- [ ] Microphone appears
- [ ] Input meter moves when you speak
- [ ] Microphone is NOT muted
- [ ] Correct device is selected

---

# 5. Confirm System Default Input

Run:

```

pactl get-default-source

```

Verify the correct microphone is listed.

---

# 6. Verify Audacity Installation Type

Check if Audacity is Flatpak:

```

flatpak list | grep -i audacity

```

If installed as Flatpak, launch with:

```

flatpak run org.audacityteam.Audacity

```

---

# 7. Check Audacity Recording Device

Inside Audacity:

Audio Setup → Recording Device

Verify:

- [ ] Correct microphone selected
- [ ] Host = PipeWire or ALSA
- [ ] Recording Channels = 1 (Mono)

---

# 8. Test Recording

In Audacity:

- [ ] Press Record
- [ ] Speak into microphone
- [ ] Confirm waveform appears

If waveform is flat:
- [ ] Verify input level meter moves
- [ ] Verify correct device selected

---

# 9. Test System Recording Outside Audacity

Run:

```

arecord test.wav

```

Speak for 5 seconds, then press:

```

Ctrl + C

```

Play back:

```

aplay test.wav

```

Expected:
- Your voice plays back.

If not:
- Problem is system audio, not Audacity.

---

# 10. Verify Output Audio

Test speakers:

```

speaker-test -t wav

```

Or test YouTube audio.

---

# 11. Restart Audio Services

Sometimes PipeWire needs restarting:

```

systemctl --user restart pipewire pipewire-pulse

```

Then reopen Audacity.

---

# 12. Final Check

Verify:

- [ ] Microphone detected by Linux
- [ ] Microphone visible in pavucontrol
- [ ] Input levels respond
- [ ] Audacity device correct
- [ ] Recording waveform appears

If all pass → Audacity should record correctly.
```

---

### Tip for your workflow

Since **your YouTube lessons and design-pattern videos depend on Audacity**, this checklist lets you quickly determine:

* 🎤 **Microphone problem**
* 🔊 **Linux audio system problem**
* 🎙 **Audacity configuration problem**
