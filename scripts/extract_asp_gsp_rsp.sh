#!/bin/bash

if ! command -v md5sum &> /dev/null
then
    echo "md5sum could not be found"
    exit 1
fi

if ! command -v dd &> /dev/null
then
    echo "dd could not be found"
    exit 1
fi

if ! command -v dd &> /dev/null
then
    echo "gzip could not be found"
    exit 1
fi


DATA_FILENAME=
OUT_FILENAME=
ROM_MD5=

# US
ROM_FILENAME="baserom.u.z64"
OUT_FILENAME="baserom.u.cdata"
MD5_US="70c525880240c1e838b8b1be35666c3b"
if [ -f "${ROM_FILENAME}" ]; then
    ROM_MD5=$(md5sum "${ROM_FILENAME}" | cut -d " " -f1)

    if [ "${ROM_MD5}" = "${MD5_US}" ]; then
        echo "extracting US compressed data segment"
        dd bs=1 skip=137616 count=71760 if="${ROM_FILENAME}" of="${OUT_FILENAME}" status=none
        GZ=gzip tools/1172inflate.sh "${OUT_FILENAME}" "${OUT_FILENAME}.bin"
        rm "${OUT_FILENAME}"
    else
        echo "cannot extract compressed data segment from ${ROM_FILENAME}, md5=${ROM_MD5}, expected ${MD5_US}"
    fi
else
    echo "${ROM_FILENAME} not found"
fi

MD5_DATA_US="055525d9087f953d43d80639773b4291"


RAMSTART=0x80020d90
rspbootTextStart_ADDR=$((0x80020d90-RAMSTART))                #rspbootTextStart
rspbootTextEnd_ADDR=$((0x80020e60-RAMSTART))                #rspbootTextEnd
rspbootTextSize=$((rspbootTextEnd_ADDR-rspbootTextStart_ADDR))

gsp3DTextStart_ADDR=$((0x80020e60-RAMSTART))                #gsp3DTextStart
gsp3DTextEnd_ADDR=$((0x80022280-RAMSTART))                #gsp3DTextEnd
gsp3DTextSize=$((gsp3DTextEnd_ADDR-gsp3DTextStart_ADDR))

aspMainTextStart_ADDR=$((0x80022280-RAMSTART))                #aspMainTextStart
aspMainTextEnd_ADDR=$((0x80023040-RAMSTART))                #aspMainTextEnd
aspMainTextSize=$((aspMainTextEnd_ADDR-aspMainTextStart_ADDR))

gsp3DDataStart_ADDR=$((0x8005c820-RAMSTART))                #gsp3DDataStart
gsp3DDataEnd_ADDR=$((0x8005d020-RAMSTART))                #gsp3DDataEnd
gsp3DDataSize=$((gsp3DDataEnd_ADDR-gsp3DDataStart_ADDR))

aspMainDataStart_ADDR=$((0x8005d020-RAMSTART))                #aspMainDataStart
aspMainDataEnd_ADDR=$((0x8005d2e0-RAMSTART))                #aspMainDataEnd
aspMainDataSize=$((aspMainDataEnd_ADDR-aspMainDataStart_ADDR))

# rsp text
OUT_FILENAME="bin/rspboot.text.bin"
DATA_FILENAME="baserom.u.cdata.bin"
START=${rspbootTextStart_ADDR}
SIZE=${rspbootTextSize}
if [ -f "${DATA_FILENAME}" ]; then
    ROM_MD5=$(md5sum "${DATA_FILENAME}" | cut -d " " -f1)

    if [ "${ROM_MD5}" = "${MD5_DATA_US}" ]; then
        echo "extracting ${OUT_FILENAME}"
        dd bs=1 skip=${START} count=${SIZE} if="${DATA_FILENAME}" of="${OUT_FILENAME}" status=none
    else
        echo "cannot ${OUT_FILENAME} from ${DATA_FILENAME}, md5=${ROM_MD5}, expected ${MD5_DATA_US}"
    fi
else
    echo "${DATA_FILENAME} not found"
fi

# gsp3d text
OUT_FILENAME="bin/gspboot.text.bin"
DATA_FILENAME="baserom.u.cdata.bin"
START=${gsp3DTextStart_ADDR}
SIZE=${gsp3DTextSize}
if [ -f "${DATA_FILENAME}" ]; then
    ROM_MD5=$(md5sum "${DATA_FILENAME}" | cut -d " " -f1)

    if [ "${ROM_MD5}" = "${MD5_DATA_US}" ]; then
        echo "extracting ${OUT_FILENAME}"
        dd bs=1 skip=${START} count=${SIZE} if="${DATA_FILENAME}" of="${OUT_FILENAME}" status=none
    else
        echo "cannot ${OUT_FILENAME} from ${DATA_FILENAME}, md5=${ROM_MD5}, expected ${MD5_DATA_US}"
    fi
else
    echo "${DATA_FILENAME} not found"
fi

# gsp3d data
OUT_FILENAME="bin/gspboot.data.bin"
DATA_FILENAME="baserom.u.cdata.bin"
START=${gsp3DDataStart_ADDR}
SIZE=${gsp3DDataSize}
if [ -f "${DATA_FILENAME}" ]; then
    ROM_MD5=$(md5sum "${DATA_FILENAME}" | cut -d " " -f1)

    if [ "${ROM_MD5}" = "${MD5_DATA_US}" ]; then
        echo "extracting ${OUT_FILENAME}"
        dd bs=1 skip=${START} count=${SIZE} if="${DATA_FILENAME}" of="${OUT_FILENAME}" status=none
    else
        echo "cannot ${OUT_FILENAME} from ${DATA_FILENAME}, md5=${ROM_MD5}, expected ${MD5_DATA_US}"
    fi
else
    echo "${DATA_FILENAME} not found"
fi

# asp text
OUT_FILENAME="bin/aspboot.text.bin"
DATA_FILENAME="baserom.u.cdata.bin"
START=${aspMainTextStart_ADDR}
SIZE=${aspMainTextSize}
if [ -f "${DATA_FILENAME}" ]; then
    ROM_MD5=$(md5sum "${DATA_FILENAME}" | cut -d " " -f1)

    if [ "${ROM_MD5}" = "${MD5_DATA_US}" ]; then
        echo "extracting ${OUT_FILENAME}"
        dd bs=1 skip=${START} count=${SIZE} if="${DATA_FILENAME}" of="${OUT_FILENAME}" status=none
    else
        echo "cannot ${OUT_FILENAME} from ${DATA_FILENAME}, md5=${ROM_MD5}, expected ${MD5_DATA_US}"
    fi
else
    echo "${DATA_FILENAME} not found"
fi

# asp data
OUT_FILENAME="bin/aspboot.data.bin"
DATA_FILENAME="baserom.u.cdata.bin"
START=${aspMainDataStart_ADDR}
SIZE=${aspMainDataSize}
if [ -f "${DATA_FILENAME}" ]; then
    ROM_MD5=$(md5sum "${DATA_FILENAME}" | cut -d " " -f1)

    if [ "${ROM_MD5}" = "${MD5_DATA_US}" ]; then
        echo "extracting ${OUT_FILENAME}"
        dd bs=1 skip=${START} count=${SIZE} if="${DATA_FILENAME}" of="${OUT_FILENAME}" status=none
    else
        echo "cannot ${OUT_FILENAME} from ${DATA_FILENAME}, md5=${ROM_MD5}, expected ${MD5_DATA_US}"
    fi
else
    echo "${DATA_FILENAME} not found"
fi
