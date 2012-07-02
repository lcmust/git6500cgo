#!/bin/bash
#批量修改文件编码（文件内容的编码，由GBK修改为UTF-8）
#
cd $1
file_source=`file ./*.txt|grep -Evi "utf"|awk '{print $1}'`
if [ -d /tmp/.tmp ]
then
    rm -r /tmp/.tmp
fi
mkdir /tmp/.tmp

for file in $file_source
do
### printf "$file\n"
### "./filename.txt  =>  filename.txt, but is filename.txt:"
    file_tmp=${file#*/}
### printf "$file_tmp\n"
### "filename.txt:  =>  filename.txt"
    file_tmp2=${file_tmp%:*}
    printf "$file_tmp2\n"
### target is "/tmp/.tmp/filename.txt"
    file_out="/tmp/.tmp/${file_tmp2}"
    file_new="$1/${file_tmp2}"
### printf "$file_new\n"
    if [ -f ${file_new} ]
    then
        iconv -f GBK -t UTF-8 ${file_new}  -o ${file_out}
    else
        printf "${file_new} is not exist!!!\n"
    fi
done

