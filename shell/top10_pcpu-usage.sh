#!/bin/bash
if [ -z "$1" ] ;then
	SECS=360
	echo "SECS=$SECS, waitting 10 minutes"
elif [ "-h" == "$1" ] ; then
	echo "READ me!!!"
	exit 1
elif [ "$1" -lt 1 -o "$1" -gt 999 ] ; then
	echo "argument is ERROR, READ me, first!"
	exit -1
else
	SECS=$(( $1 * 60 ))
	echo "SECS=$SECS, waitting $1 minutes"
fi

UNIT_TIME=10
SETPS=$(( $SECS / $UNIT_TIME ))
echo Watching CPU usage... ;

for((i=0;i<SETPS;i++))
do
	ps -eo comm,pcpu | tail -n +2 >> /tmp/cpu_usage.$$
	echo -n ".$i"
	sleep $UNIT_TIME
done
echo
echo CPU eaters:
cat /tmp/cpu_usage.$$ |\
awk '{process[$1]+=$2;}
END{
	for(i in process)
	{
		printf("%-20s\t %s\n", i, process[i]);
	}
  }' |sort -nrk 2 | head

if [ -f /tmp/cpu_usage.$$ ]
then
	rm /tmp/cpu_usage.$$
fi
