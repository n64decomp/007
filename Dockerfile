# Pinned by digest so the same Dockerfile always starts from the same base.
# This is the multi-arch index digest (not one platform's manifest), so it
# builds on both linux/amd64 and linux/arm64. To bump it:
#   docker buildx imagetools inspect ubuntu:22.04
# and take the top-level Digest. The tag is ignored by Docker when a digest is
# given; it is kept so the reader knows where the digest came from.
FROM ubuntu:22.04@sha256:0a9887931b0e38af2e3487ed39e29436b0535c4f3f52e57745baaf79d1898956

RUN echo ">> install distro packages ..." &&  \
    apt update && \
    apt -y install bash-completion sudo binutils-mips-linux-gnu wget make git python3 build-essential

# qemu-irix is only needed for IDO_RECOMP=NO, and it is only published as an
# amd64 .deb, so it is installed on amd64 only. The default IDO_RECOMP=YES
# compiles tools/ido5.3_recomp from source and works on either architecture.
# TARGETARCH is set by BuildKit; dpkg is the fallback for builders that don't.
ARG TARGETARCH
RUN arch="${TARGETARCH:-$(dpkg --print-architecture)}"; \
    if [ "$arch" = "amd64" ]; then \
        echo ">> install qemu ..." && \
        wget https://github.com/n64decomp/qemu-irix/releases/download/v2.11-deb/qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb -P /tmp && \
        dpkg -i /tmp/qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb; \
    else \
        echo ">> skipping qemu-irix: no $arch build is published, so IDO_RECOMP=NO is unavailable"; \
    fi

RUN echo ">> setup workspace ..." &&  \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers && \
    useradd -ms /bin/bash dev && usermod -aG sudo dev
USER dev
WORKDIR /home/dev/project

CMD ["/bin/bash"]
