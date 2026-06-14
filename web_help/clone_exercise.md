👍 Got it. Here is a **SHORT, CLEAN, REPEATABLE PLAN** you can reuse **anytime** without me.

Save this.

---

# 🔁 LearnDash Backup & Restore — REPEATABLE CHECKLIST

**Environment**

* Host: **Bluehost**
* Backup: **CodeGuard (Professional)**
* LMS: **LearnDash**

---

## **STEP 1 — Prepare a test course**

1.a WordPress Admin → LearnDash → Courses
1.b Clone an existing course
1.c Rename clearly (example: `Dummy Restore Test`)
1.d Confirm:

* Course exists
* Lessons attached
* Front-end loads

---

## **STEP 2 — Create backup (DO NOT SKIP)**

2.a Bluehost → Websites
2.b Manage site
2.c Backups / CodeGuard
2.d Click **Create New Backup**
2.e Wait until a **NEW backup timestamp appears**

📌 Write down the **date & time**

---

## **STEP 3 — Delete the test course**

3.a WordPress Admin → LearnDash → Courses
3.b Delete **Dummy Restore Test**
3.c Empty Trash
3.d Confirm course + lessons are gone

---

## **STEP 4 — Restore from backup**

4.a Bluehost → Websites → Manage → Backups / CodeGuard
4.b Find the backup from **Step 2**
4.c Click **Restore**
4.d Choose **Entire Website**
4.e Wait for **Restore Successful**

---

## **STEP 5 — Verify**

5.a WordPress Admin → LearnDash → Courses
5.b Confirm:

* Course is back
* Lessons restored
  5.c Open front end and verify

---

## **STEP 6 — Cleanup (recommended)**

6.a Settings → Permalinks → Save Changes
6.b LearnDash → Settings → Save
6.c Clear cache (host + plugin + browser)

---

# ✅ SUCCESS CHECK

* Course restored ✔
* Lessons intact ✔
* Front-end loads ✔
* Backup process confirmed ✔

---

## ⚠️ RULES (do not break)

* ❌ Never delete before a confirmed backup
* ❌ Never rely on “old” backups for tests
* ❌ Never test restores without timestamps
* ✅ One backup → one delete → one restore

---

## 🧠 PRO TIP

Repeat this test:

* After major updates
* Before deleting real courses
* Monthly (best practice)

---

If you want, next time I can:

* Turn this into a **1-page PDF**
* Or a **printed checklist**
* Or a **shell-style runbook**

Just say the word.

