# S-ecosystem

WiFi manager for Void Linux (musl) built with ImGui + OpenGL + GLFW.

## Features

- Scan & connect to WiFi networks (via `iw` + `wpa_cli`)
- Real-time RX/TX traffic graphs
- 6 color themes + fully customizable colors
- English / Russian localization
- Encrypted config persistence (`~/.config/wifire/config`)
- Auto-connect to last network
- Autostart on login

## Install

```sh
sudo ./install.sh
```

Builds from source, installs binary to `/usr/local/bin`, sets `iw` capabilities.

## Build only

```sh
make
```

## Uninstall

```sh
sudo rm -f /usr/local/bin/wifire /usr/local/bin/logo.png
sudo setcap -r /usr/bin/iw 2>/dev/null
```

## Requirements

- `g++` (C++17)
- `glfw`
- `opengl`
- `iw`
- `wpa_supplicant` (`wpa_cli`)
