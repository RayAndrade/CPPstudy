Excellent — and very wise.
Here is your **Printable Git Large File Best Practices Cheat Sheet**:

---

# 📝 **Git Large File Best Practices Cheat Sheet**

---

### 🚩 **Golden Rule:**

**Never commit large binary files directly into Git history.**

* Avoid `.mp4`, `.mp3`, `.wav`, `.mkv`, `.zip`, `.tar`, `.iso`, `.pdf`, `.exe`, `.odp`, `.odt`, `.png`, `.jpg` if large.

---

## ✅ **Before Committing**

### 1️⃣ Add file size protection to `.gitignore`:

```bash
*.mp4
*.mkv
*.mp3
*.wav
*.zip
*.tar
*.iso
*.odp
*.odt
*.jpg
*.png
*.pdf
*.exe
```

### 2️⃣ Use `git lfs` for large files you **must** version:

```bash
git lfs install
git lfs track "*.mp4"
git lfs track "*.wav"
```

### 3️⃣ Verify what's staged before each commit:

```bash
git status
git diff --cached --stat
```

---

## ✅ **Ongoing Maintenance**

### Run disk check before pushing:

```bash
git count-objects -vH
du -sh .git/objects/pack/
```

### Detect large committed files:

```bash
git verify-pack -v .git/objects/pack/pack-*.idx | sort -k 3 -n | tail -n 20
```

---

## ❌ **If Large Files Accidentally Get Committed**

### Use BFG Repo Cleaner:

#### Delete by file extension:

```bash
java -jar bfg.jar --delete-files '*.mp4'
```

#### Delete by blob size:

```bash
java -jar bfg.jar --strip-blobs-bigger-than 100M
```

#### Clean up after:

```bash
git reflog expire --expire=now --all
git gc --prune=now --aggressive
```

---

## 🚩 **NEVER Use Git for:**

* Video editing assets
* Audio project files
* High-resolution media
* Backups
* Virtual machine images
* Database dumps

---

## 🛑 **Warning Signs You Are In Trouble**

* `git push` very slow
* GitHub rejects pushes: `pack exceeds maximum allowed size (2.00 GiB)`
* `.git/objects/pack` folder growing beyond **500MB**

---

## ✅ **Safe Practice Summary**

| Action             | Frequency            |
| ------------------ | -------------------- |
| `git status`       | Always before commit |
| `.gitignore` setup | At repo creation     |
| Use Git LFS        | When needed          |
| `bfg.jar`          | If emergency cleanup |
| `git gc`           | Occasionally         |

---

> 🧭 **Proverb for Git Users:**
> *"It's easier to prevent pollution than to clean up the toxic waste afterwards."*

---

✅ **You can print this, laminate it, and tape it near your workstation.**

---

If you want, I can also generate you:

* **A ready-to-go `.gitignore` template for your entire project stack**
* **A minimal BFG emergency shell script you can run anytime.**

👉 Shall I generate those as well?

