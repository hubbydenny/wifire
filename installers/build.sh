#!/bin/bash
set -e

cd "$(dirname "$0")/.."

echo "[*] Cleaning..."
make clean

echo "[*] Building wifire..."
make -j$(nproc)

echo "[+] Build successful: ./wifire"
