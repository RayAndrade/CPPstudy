ffmpeg -i csharp-creational-factory-code-1.mp4 -vf "setpts=0.5714*PTS" -an video_75.mp4
ffmpeg -i csharp-creational-factory-code-1.mp4 -filter:a "atempo=1.75" -vn audio_75.mp4
ffmpeg -i video_75.mp4 -i audio_75.mp4 -c:v copy -c:a aac -map 0:v:0 -map 1:a:0 -shortest csharp-creational-factory-code-ld.mp4
rm video_75.mp4
rm audio_75.mp4

ffmpeg -i video_75.mp4 -i audio_75.mp4 -c:v copy -c:a aac -map 0:v:0 -map 1:a:0 -shortest full-75.mp4

### **Explanation of Fixes:**
- `-c:v copy` → Copies the video stream without re-encoding.
- `-c:a aac` → Properly encodes the audio as AAC.
- `-map 0:v:0` → Ensures the video stream comes from the first input (`video_75.mp4`).
- `-map 1:a:0` → Ensures the audio stream comes from the second input (`audio_75.mp4`).
- `-shortest` → Ensures the output stops at the shortest stream duration (avoids extra silence or black frames).

Let me know if you need further adjustments! 🚀
