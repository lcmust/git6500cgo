#!/bin/bash
printf "command\t count\n";
if [ -z "$1" ]
then 
	where="/home/love/.bash_history"
else
	where="$1"
fi
	cat "$where" | sed -e 's/sudo//' |awk '{ list[$1]++; }\
END{
	for(i in list)
	{
		printf("%s\t%d\n", i , list[i]);
	}
   }' | sort -nrk 2 | head
