#!/bin/bash
printf "command\t count\n";
if [ -z "$1" ]
then
	arg1=~
else
	arg1="$1"
fi
where="${arg1}/.bash_history"
if [ -f "$where" ] ; then
   printf "$where\n"
else
   exit 0
fi

	cat "$where" | sed -e 's/sudo//' |awk '{ list[$1]++; }\
END{
	for(i in list)
	{
		printf("%s\t%d\n", i , list[i]);
	}
   }' | sort -nrk 2 | head
