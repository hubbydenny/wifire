# WiFire

WiFi manager for Void Linux (musl) built with ImGui + OpenGL + GLFW.

## Features

- Scan & connect to WiFi networks (via `iw` + `wpa_cli`)
- Real-time RX/TX traffic graphs
- 6 color themes, adjustable font size
- English / Russian

## Build

```sh
make
```

Requires: `gcc`, `make`, `glfw`, `opengl`, `libpthread`

## Install

```sh
sudo ./installers/wifire.sh
```

Copies binary to `/usr/local/bin`, installs icon, sets `cap_net_raw,cap_net_admin` on `iw`.

## Uninstall

```sh
sudo rm -f /usr/local/bin/wifire /usr/local/bin/logo.png
sudo setcap -r /usr/bin/iw 2>/dev/null
```

## Run

```sh
./wifire
```

`iw scan` requires root — the installer sets capabilities so it works without sudo.
