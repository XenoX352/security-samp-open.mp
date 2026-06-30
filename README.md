<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</head>
<body>

# <i class="bi bi-shield-lock-fill" style="color:#2ecc71;"></i> Security System

> **Lightweight anti‑abuse module for open.mp servers** – automatically detects and blocks suspicious connections.

<p align="center">
  <img src="https://img.shields.io/badge/open.mp-2.0.0+-blue?style=for-the-badge&logo=openmp" alt="open.mp">
  <img src="https://img.shields.io/badge/Pawn-3.10.11+-orange?style=for-the-badge&logo=pawn" alt="Pawn">
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License">
  <img src="https://img.shields.io/badge/Status-Stable-brightgreen?style=for-the-badge" alt="Status">
</p>

---

## <i class="bi bi-info-circle"></i> Overview

This include integrates into your gamemode to perform a non‑intrusive risk assessment whenever a player connects. It queries the public IP‑API service (`ip-api.com`) to determine:

- <i class="bi bi-globe"></i> **Country** of the IP address
- <i class="bi bi-shield-exclamation"></i> **Proxy** status (VPN, Tor, etc.)
- <i class="bi bi-hdd-stack"></i> **Hosting** status (VPS, cloud provider)

Combined with the player’s <i class="bi bi-speedometer2"></i> **ping**, it calculates a risk score. If the score exceeds the configured threshold, the player is automatically kicked with a clear message.

---

## <i class="bi bi-stars"></i> Features

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

## <i class="bi bi-download"></i> Installation

### Step 1: Place the file
Copy `security.inc` into your Pawn include directory (e.g., `pawno/include/`).

### Step 2: Include in your script
Add this line to your gamemode or filterscript:

```pawn
#include <security>
