# Fixing Audacity Playback Issue on Ubuntu

## Summary

This document outlines the troubleshooting process and resolution for an issue where **Audacity could record audio**, but **playback within Audacity was silent**, despite system audio working normally.

---

## Problem Description

- Audacity could record audio successfully.
- System audio (e.g., MP3/WAV files, YouTube) worked correctly.
- Exported audio from Audacity played fine using external players.
- However, **playback within Audacity did not produce any sound**.

---

## Initial System Check

- Verified `.asoundrc` was configured correctly.
- Confirmed `aplay` worked.
- Verified system sound output was functional.

---

## Troubleshooting Steps

1. **Checked Audacity Audio Setup**:
   - Opened Audacity.
   - Navigated to `Audio Setup > Host` and tried different host options: `ALSA`, `PulseAudio`, etc.
   - Changed `Playback Device` from a specific output (e.g., `hw:0,0`) to `Default`.

2. **Confirmed Audacity Volume Levels**:
   - Ensured playback volume slider was up.
   - Checked track gain settings.

3. **Launched Audacity via Terminal**:
   - Ran `audacity` from terminal to monitor error output.
   - No major errors reported; indicated that the application was functioning.

---

## Root Cause

Audacity was set to use a **specific playback device** that was not actively routed to system output. This prevented internal playback from being heard, even though the system and exported audio worked fine.

---

## Solution

- In Audacity:
  - Set `Host` to a compatible driver (`ALSA` or `PulseAudio`).
  - Set `Playback Device` to `Default` instead of a specific device.
- This allowed Audacity to use the same audio routing as the rest of the system.

---

## Result

Audacity playback now works correctly. Audio is heard internally during playback without needing to export.

---

## Notes

- Always check `Audio Setup` in Audacity when playback or recording issues occur.
- Using `Default` as the playback device is often the safest choice unless you need advanced routing.

---

*End of document.*


