#!/bin/sh

echo "WSL1 32bit ELF Enabler (Needed for 32bit pointers used by N64)"

dpkg -s "qemu-user-static" >/dev/null 2>&1 && {
    echo ""
} || {
    echo "Installing Required patches."
    apt update
    apt install -y qemu-user-static
}

sudo update-binfmts --install i386 /usr/bin/qemu-i386-static --magic '\x7fELF\x01\x01\x01\x03\x00\x00\x00\x00\x00\x00\x00\x00\x03\x00\x03\x00\x01\x00\x00\x00' --mask '\xff\xff\xff\xff\xff\xff\xff\xfc\xff\xff\xff\xff\xff\xff\xff\xff\xf8\xff\xff\xff\xff\xff\xff\xff'
sudo service binfmt-support start

dpkg -s "libc6:i386" >/dev/null 2>&1 && {
    echo ""
} || {
    apt update
    apt install -y libc6:i386 libncurses5:i386 libstdc++6:i386 zlib1g:i386 zlib1g-dev:i386
}

