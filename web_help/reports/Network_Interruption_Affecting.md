Network Interruption Affecting


# GIVE REPORT — Network Interruption Affecting GitHub and RayAndrade.com

## Incident Summary

A network interruption occurred on the Ubuntu workstation `theraycode@theraycode` that prevented access to:

* rayandrade.com
* github.com

At the same time, other websites such as:

* google.com
* youtube.com
* chat.openai.com

remained reachable.

This created an inconsistent browsing experience where some domains worked while critical development and ministry websites failed.

---

# Symptoms Observed

## Browser Errors

The following browser errors were observed:

* “This site can’t be reached”
* Inability to access GitHub repositories
* Inability to access rayandrade.com

## Network Behavior

The system displayed inconsistent connectivity:

* Google services remained accessible
* GitHub failed
* rayandrade.com failed
* DNS appeared partially functional
* Browser sessions behaved unpredictably

---

# Diagnostic Process

The following diagnostic commands were executed:

```bash
ping -c 4 github.com
ping -4 -c 4 github.com
ping -6 -c 4 github.com
ip route
ip -6 route
nmcli device status
```

## Findings

### 1. Missing IPv4 Default Route

The system lacked a valid IPv4 default route.

This prevented reliable outbound IPv4 traffic.

---

### 2. Conflicting Network Interfaces

Two network interfaces were simultaneously active:

* Wi-Fi (`wlp4s0`)
* Ethernet (`eno1`)

The Ethernet connection was in a broken or partial state.

---

### 3. Invalid Ethernet Addressing

The Ethernet interface showed a self-assigned address:

```text
169.254.x.x
```

This indicated failed DHCP assignment and improper routing behavior.

---

### 4. IPv6 Inconsistencies

IPv6 routing partially functioned while IPv4 routing was unstable.

This caused selective website accessibility:

* Some services preferred IPv6 and worked
* Others depended on IPv4 and failed

---

# Root Cause

The root cause was determined to be:

## Conflicting Network Routing Between Wi-Fi and Ethernet

The broken Ethernet connection interfered with routing priority and prevented the operating system from maintaining a valid IPv4 default gateway.

This resulted in:

* intermittent DNS behavior
* partial internet access
* failed access to GitHub and rayandrade.com

---

# Resolution Performed

## Step 1 — Disconnect Faulty Ethernet Interface

The Ethernet device was disconnected:

```bash
nmcli device disconnect eno1
```

This removed the invalid network path.

---

## Step 2 — Restart NetworkManager

Network services were restarted:

```bash
sudo systemctl restart NetworkManager
```

---

## Step 3 — Verify Connectivity

Connectivity tests were executed successfully:

```bash
ping -c 4 8.8.8.8
ping -c 4 google.com
ping -c 4 github.com
```

All tests completed with:

* 0% packet loss
* successful DNS resolution
* restored outbound connectivity

---

# Final Verified State

The system successfully restored:

* IPv4 default routing
* DNS functionality
* GitHub access
* rayandrade.com access
* stable Wi-Fi networking

Final routing table:

```bash
default via 192.168.0.1 dev wlp4s0 proto dhcp
```

---

# Lessons Learned

## 1. Partial Internet Access Can Be Misleading

The ability to reach Google or YouTube does not guarantee complete network functionality.

Different services may prefer:

* IPv4
* IPv6
* cached DNS paths

---

## 2. Broken Ethernet Connections Can Corrupt Routing

An improperly configured or partially connected Ethernet interface can interfere with otherwise functional Wi-Fi networking.

---

## 3. Link-Local Addresses Are Warning Signs

Addresses in the range:

```text
169.254.x.x
```

typically indicate DHCP failure or invalid network negotiation.

---

# Preventive Recommendations

## Recommendation 1

Use only one active primary network interface unless specifically required.

---

## Recommendation 2

If internet behavior becomes inconsistent:

Run:

```bash
ip route
nmcli device status
```

before rebooting.

---

## Recommendation 3

If Ethernet is unused, disable it temporarily when troubleshooting Wi-Fi connectivity issues.

---

# Outcome

The interruption was successfully resolved.

The workstation regained stable connectivity and restored access to:

* GitHub
* rayandrade.com
* general web services

No operating system reinstallation or browser replacement was required.

