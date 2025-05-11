#!/bin/bash

set -e

PKG_NAME="rivers"
VERSION="1.0.0"
BUILD_DIR="build"
DEBIAN_DIR="$BUILD_DIR/DEBIAN"
BIN_DIR="$BUILD_DIR/usr/bin"

# Clean previous build
rm -rf "$BUILD_DIR" "$PKG_NAME-$VERSION.deb"
mkdir -p "$DEBIAN_DIR" "$BIN_DIR"

# Build the binary
echo "Compiling binary..."
g++ -std=c++17 -Wall -Wextra -O2 -o rivers main.cpp rivers.cpp

# Copy binary
cp rivers "$BIN_DIR/rivers"
chmod 755 "$BIN_DIR/rivers"

# Create control file
cat <<EOF > "$DEBIAN_DIR/control"
Package: $PKG_NAME
Version: $VERSION
Architecture: amd64
Maintainer: Your Name <you@example.com>
Description: A C++ river classification and tree tester.
EOF

# Optional: license & changelog
mkdir -p "$BUILD_DIR/usr/share/doc/$PKG_NAME"
echo "River Program - Version $VERSION" > "$BUILD_DIR/usr/share/doc/$PKG_NAME/changelog"
gzip -9 "$BUILD_DIR/usr/share/doc/$PKG_NAME/changelog"

cat <<EOF > "$BUILD_DIR/usr/share/doc/$PKG_NAME/copyright"
Copyright (C) 2025
License: MIT
This is free software with no warranty.
EOF

chmod 0644 "$BUILD_DIR/usr/share/doc/$PKG_NAME/"*

# Permissions
chmod 0755 "$BUILD_DIR/usr"
chmod 0755 "$BUILD_DIR/usr/bin"
chmod 0755 "$BUILD_DIR/usr/share"
chmod 0755 "$BUILD_DIR/usr/share/doc"
chmod 0755 "$BUILD_DIR/usr/share/doc/$PKG_NAME"

# Fix ownership (if running as root or in packaging)
if [ "$(id -u)" -eq 0 ]; then
  chown -R root:root "$BUILD_DIR"
fi

# Build the .deb package
dpkg-deb --build "$BUILD_DIR" "${PKG_NAME}-${VERSION}.deb"

echo "Debian package built: ${PKG_NAME}-${VERSION}.deb"
