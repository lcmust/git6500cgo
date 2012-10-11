#!/usr/bin/bash
netstat -an|grep -Ev "0.0.0.0|127.0.0.1|::|\*:\*"|grep -E "([0-9]{1,3}\.){3}[0-9]{1,3}"|awk '{print $3,$2}'|awk -F":" '{print $1,$0}'|awk '{print $1,$3}'
#  this_bash_name  | sort | uniq -c
