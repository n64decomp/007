#!/bin/bash

OBJDUMP="mips-linux-gnu-objdump -D -z -bbinary -mmips -EB"
OPTIONS="--start-address=$(($1)) --stop-address=$(($2))"
$OBJDUMP $OPTIONS baserom.u.z64 > baserom.u.dump
$OBJDUMP $OPTIONS ge007.u.z64 > ge007.u.dump
diff baserom.u.dump ge007.u.dump | colordiff
