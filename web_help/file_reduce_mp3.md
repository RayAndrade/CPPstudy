Here is the same content rewritten **cleanly and ready to drop directly into a `README.md`** file.

---

# Media Optimization Guide (Audio & Video)

This guide explains **how to convert and compress audio and video files** for websites (especially **WordPress / LearnDash**) to reduce hosting usage while keeping good quality.

---

## 🎧 AUDIO CONVERSION (Voice Lessons)

### ❌ Avoid

* **WAV** — uncompressed and very large

### ✅ Recommended Formats

* **MP3** — best compatibility, “just works”
* **M4A (AAC)** — often smaller than MP3 at the same quality

---

## 🎯 Recommended Audio Settings (Speech)

| Setting     | Value      |
| ----------- | ---------- |
| Channels    | Mono       |
| Bitrate     | 48–64 kbps |
| Sample Rate | 44.1 kHz   |

These settings are ideal for spoken lessons and dramatically reduce file size.

---

## 🔹 Convert WAV → MP3 (Single File)

```bash
ffmpeg -i input.wav -vn -ac 1 -ar 44100 -b:a 64k output.mp3
```

---

## 🔹 Batch Convert WAV → MP3

```bash
mkdir mp3

for f in *.wav; do
  ffmpeg -i "$f" -vn -ac 1 -ar 44100 -b:a 64k "mp3/${f%.wav}.mp3"
done
```

---

## 🔹 Smaller Alternative: WAV → M4A (AAC)

```bash
mkdir m4a

for f in *.wav; do
  ffmpeg -i "$f" -vn -ac 1 -ar 44100 -c:a aac -b:a 48k "m4a/${f%.wav}.m4a"
done
```

**Typical size reduction:** 80–95%

---

## 🎬 VIDEO CONVERSION (Course Videos)

### ❌ Avoid

* AVI
* Uncompressed MOV
* Large raw MP4 files

### ✅ Recommended Format

* **MP4 (H.264 video + AAC audio)** — best compatibility and balance
* **WebM (VP9)** — optional, smaller, not always needed

---

## 🎯 Recommended Video Settings

| Setting     | Value          |
| ----------- | -------------- |
| Video Codec | H.264          |
| Audio Codec | AAC            |
| Resolution  | 720p or 1080p  |
| CRF         | 23 (balanced)  |
| Preset      | slow or medium |

---

## 🔹 Convert Any Video → Web-Ready MP4

```bash
ffmpeg -i input.mov \
  -c:v libx264 -preset slow -crf 23 \
  -pix_fmt yuv420p \
  -c:a aac -b:a 128k \
  output.mp4
```

✔ Plays everywhere
✔ Good quality
✔ Smaller file size

---

## 🔹 Reduce Video Size Further (Courses)

```bash
ffmpeg -i input.mp4 \
  -c:v libx264 -preset slow -crf 26 \
  -c:a aac -b:a 96k \
  smaller.mp4
```

---

## 🔹 Batch Convert Multiple Videos

```bash
mkdir converted

for f in *.mov *.avi *.mkv; do
  ffmpeg -i "$f" \
    -c:v libx264 -preset slow -crf 23 \
    -c:a aac -b:a 128k \
    "converted/${f%.*}.mp4"
done
```

---

## 📦 Storage Impact (Typical Results)

| Media Type    | Before        | After        |
| ------------- | ------------- | ------------ |
| WAV audio     | 500 KB – 5 MB | 50–150 KB    |
| AVI video     | 500 MB        | 40–80 MB     |
| Optimized MP4 | —             | ~10× smaller |

---

## 🧠 Rules of Thumb

* **Audio:** WAV → MP3 or M4A
* **Video:** Anything → MP4 (H.264)
* **Speech:** Mono + low bitrate
* **Video size:** CRF controls quality vs size

---

## ✅ Best Choice for LearnDash

* **Audio:** MP3 (64 kbps mono)
* **Video:** MP4 (H.264, CRF 23–26)

These formats are widely supported by browsers, WordPress themes, and LMS players.

---

If you want, this README can be extended with:

* A **single script** for audio + video
* Settings for **screen recordings vs talking head**
* LearnDash-specific playback recommendations

Just say the word 👍

