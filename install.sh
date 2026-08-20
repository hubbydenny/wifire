#!/bin/bash
set -e

ROOT="$(cd "$(dirname "$0")" && pwd)"
PREFIX="${PREFIX:-/usr/local}"
BIN_DIR="$PREFIX/bin"

if [ "$(id -u)" -ne 0 ]; then
    echo "[*] Need root. Enter sudo password:"
    exec sudo "$0" "$@"
fi

echo "========================================="
echo "  S-ecosystem Installer"
echo "========================================="
echo ""

# --- WiFire ---
echo "[1/2] Building wifire..."
cd "$ROOT"
make clean > /dev/null 2>&1
make -j$(nproc)

echo "[2/2] Installing..."
install -Dm755 wifire "$BIN_DIR/wifire"
install -Dm644 logo.png "$BIN_DIR/logo.png"

IW_PATH=$(which iw 2>/dev/null || true)
if [ -n "$IW_PATH" ]; then
    setcap cap_net_raw,cap_net_admin=eip "$IW_PATH" 2>/dev/null || true
    echo "  - iw capabilities set"
fi

echo ""
echo "========================================="
echo "  Installed:"
echo "  - wifire  -> $BIN_DIR/wifire"
echo "  - logo    -> $BIN_DIR/logo.png"
echo "========================================="
echo ""
echo "  Run: wifire"
