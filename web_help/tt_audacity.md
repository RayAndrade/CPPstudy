Good idea. A **checklist is perfect for troubleshooting**, especially since you like to work **step-by-step**.
Below is a **clean Markdown checklist** you can paste directly into your file:

```bash
touch tt_audacity.md
```

---

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

---

If you'd like, I can also give you a **much shorter “2-minute diagnostic version”** you can run **before every recording session** for your **TheRayCode videos**.

