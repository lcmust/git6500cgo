###backup
#/mnt/sda2h/tools/mysql/bin/mysqldump  -udjango -p django  >/tmp/django-`date +%x%X`.sql
/mnt/sda2h/tools/mysql/bin/mysqldump  -udjango -p django  >/tmp/django-`date +%Y%m%d%H%M%S`.sql
###restore
#/mnt/sda2h/tools/mysql/bin/mysql -udjango -p django < /tmp/django-2012年05月04日10时45分49秒.sql
/mnt/sda2h/tools/mysql/bin/mysql -udjango -p django < /tmp/django-20120724221201.sql
