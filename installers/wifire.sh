#!/bin/bash
set -e

PREFIX="${PREFIX:-/usr/local}"
BIN_DIR="$PREFIX/bin"

if [ "$(id -u)" -ne 0 ]; then
    echo "[*] starting installation"
    echo "Enter sudo password"
    exec sudo "$0" "$@"
fi

cd "$(dirname "$0")/.."

echo "[*] Building wifire..."
./installers/build.sh

echo "[*] Installing to $BIN_DIR..."
install -Dm755 wifire "$BIN_DIR/wifire"
[ -f logo.png ] && install -Dm644 logo.png "$BIN_DIR/logo.png"

IW_PATH=$(which iw 2>/dev/null || true)
if [ -n "$IW_PATH" ]; then
    echo "[*] Setting capabilities on iw..."
    setcap cap_net_raw,cap_net_admin=eip "$IW_PATH" 2>/dev/null || true
fi

echo "[+] wifire installed to $BIN_DIR/wifire"
echo "    Run: wifire"
