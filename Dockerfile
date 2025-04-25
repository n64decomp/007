FROM ubuntu:22.04

# install distro packages
RUN apt update
RUN apt -y install bash-completion sudo binutils-mips-linux-gnu wget make git python3 libcapstone-dev pkg-config build-essential

# install qemu (can be removed if you're using ido recomp)
RUN wget https://github.com/n64decomp/qemu-irix/releases/download/v2.11-deb/qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb -P /tmp
RUN dpkg -i /tmp/qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb

# setup sudo
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# setup developer directory
RUN useradd -ms /bin/bash dev
RUN usermod -aG sudo dev
USER dev
WORKDIR /home/dev

CMD ["/bin/bash"]
