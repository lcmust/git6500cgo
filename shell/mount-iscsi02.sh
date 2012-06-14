#!/bin/bash

#//if the iscsi-target not mount at /mnt/iscsi02, we will mount it;
#//elseif it mounted, exit.
MOUNTED=$(mount|grep iscsi02|awk '{printf $1 }' );
if [  -n "${MOUNTED}" ]
then {
	 echo "--${MOUNTED}--(The iSCSI-TARGET)-has MOUNTED at /mnt/iscsi02/--";
	 exit 0;
}
fi

#// $fdisk -l <<<Disk /dev/sdb: 2040.2 GB, 2040243683328 bytes>>>
#//if the iSCSI-target wasn't mount,then find the dev;
TARGET=$(sudo /sbin/fdisk -l| grep 2040 )
#//if we dont't find the iSCSI-target dev,then exit.
#//else we will mount the iSCSI-target at the /mnt/iscsi02;
#//and restart the mysqld.
if [ ! -n "$TARGET" ]
then {
         echo "WARNING: not found the Iscsi drive !!!!!!";
	 exit -1;
}
else {
	echo "......${ISCSI}1 is mountting at /mnt/iscsi02/......";
	ISCSI=$(echo $TARGET | awk '{print $2}'|tr -d : );
#	echo "$ISCSI";
#	echo "${ISCSI}1";
 	mount "${ISCSI}1" /mnt/iscsi02/;
	echo "!!!!!---${ISCSI}1 has mounted at /mnt/iscsi02/-----OK";
	/sbin/service mysqld restart;
}
fi


