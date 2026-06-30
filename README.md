<div align="center">
  <img src="https://img.icons8.com/fluency/96/000000/shield.png" alt="Logo" width="120" height="120"/>
  <h1>🛡️ OMP-Security</h1>
  <p><strong>Lightweight Anti‑Abuse Module for open.mp Servers</strong></p>
  <p>
    <img src="https://img.shields.io/badge/open.mp-2.0.0+-blue?style=for-the-badge&logo=openmp" alt="open.mp">
    <img src="https://img.shields.io/badge/Pawn-3.10.11+-orange?style=for-the-badge&logo=pawn" alt="Pawn">
    <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License">
    <img src="https://img.shields.io/badge/Status-Stable-brightgreen?style=for-the-badge" alt="Status">
    <img src="https://img.shields.io/badge/Version-1.0.0-blueviolet?style=for-the-badge" alt="Version">
  </p>
</div>

---

## 📖 Overview

**OMP-Security** is a robust, drop‑in security include for open.mp servers. It automatically detects and blocks suspicious connections based on:

- **VPN / Proxy** usage
- **Hosting / VPS** providers
- **Geographic origin** (country)
- **High ping** (latency)

Using a simple risk‑scoring system, it ensures that only legitimate players can join your server, protecting you from abuse, cheating, and DDoS attacks.

---

## ✨ Features

| Icon | Feature | Description |
|------|---------|-------------|
| <i class="bi bi-eye-slash"></i> | **VPN/Proxy Detection** | Automatically detects and penalises VPN, proxy, and Tor connections. |
| <i class="bi bi-cloud"></i> | **Hosting Detection** | Flags connections from VPS/cloud providers often used for malicious purposes. |
| <i class="bi bi-geo-alt"></i> | **Geolocation Scoring** | Applies a penalty to players from regions outside your primary player base. |
| <i class="bi bi-speedometer2"></i> | **Ping Filtering** | Kicks players with exceptionally high latency (>250ms by default). |
| <i class="bi bi-clock"></i> | **Non‑blocking** | Runs asynchronously – players are not delayed during connection. |
| <i class="bi bi-code-square"></i> | **Lightweight** | Uses only one HTTP request and a single timer per player. |
| <i class="bi bi-clipboard-data"></i> | **Detailed Logging** | Prints country, score, and ping to the server console for auditing. |
| <i class="bi bi-arrow-repeat"></i> | **Configurable** | All thresholds (ping, score, country) can be easily adjusted. |

---

## 📦 Installation

### 1. Place the include
Copy `omp-security.inc` into your Pawn include directory (e.g., `pawno/include/`).

### 2. Include in your script
Add this line to your gamemode or filterscript:

```pawn
#include <omp-security>
