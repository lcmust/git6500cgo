#!/bin/bash

start_mysql()
{
  ###/mnt/sda2h/tools/mysql/
  if [  "$(pidof mysqld)" ]
  then
      echo "mysql !is! already running!!!"
      return 0
  fi
  /etc/init.d/mysqld start
}
stop_mysql()
{
  ###/mnt/sda2h/tools/mysql/
  if [ ! "$(pidof mysqld)" ]
  then
      echo "mysql -isnot- running!!!"
      return 0
  fi
  /etc/init.d/mysqld stop
}

start_uwsgi()
{
  ###/home/love/cl-dep/mysite/django.wsgi
  if [  "$(pidof uwsgi)" ]
  then
      echo "uwsgi !is! already running!!!"
      return 0
  fi
  uwsgi  --wsgi-file /home/love/cl-dep/mysite/django.wsgi -s 127.0.0.1:9090 -d /tmp/django.uwsgi.log
}
stop_uwsgi()
{
  ###/home/love/cl-dep/mysite/django.wsgi
  if [ ! "$(pidof uwsgi)" ]
  then
      echo "uwsgi -isnot- running!!!"
      return 0
  fi
  kill -9 `pidof uwsgi`
}

start_php4fpm()
{
  ###/mnt/sda2h/tools/php/php-fpm.conf
  if [  "$(pidof php-fpm)" ]
  then
      echo "php-fpm !is! already running!!!"
      return 0
  fi
  /mnt/sda2h/tools/php/sbin/php-fpm
}
stop_php4fpm()
{
  ###/mnt/sda2h/tools/php/php-fpm.conf
  if [ ! "$(pidof php-fpm)" ]
  then
      echo "php-fpm -isnot- running!!!"
      return 0
  fi
  kill -9 `pidof php-fpm`
}

start_apache()
{
  ###/mnt/sda2h/tools/apache/
  if [  "$(pidof httpd)" ]
  then
      echo "apache !is! already running!!!"
      return 0
  fi
  /mnt/sda2h/tools/apache/bin/apachectl -k start
}
stop_apache()
{
  ###/mnt/sda2h/tools/apache/
  if [ !  "$(pidof httpd)" ]
  then
      echo "apache -isnot- running!!!"
      return 0
  fi
  /mnt/sda2h/tools/apache/bin/apachectl -k stop
}

start_nginx()
{
  ###/mnt/sda2h/tools/nginx/
  if [  "$(pidof nginx)" ]
  then
      echo "nginx !is! already running!!!"
      return 0
  fi
  /mnt/sda2h/tools/nginx/sbin/nginx
}
stop_nginx()
{
  ###/mnt/sda2h/tools/nginx/
  if [ !  "$(pidof nginx)" ]
  then
      echo "nginx -isnot- running!!!"
      return 0
  fi
  kill -9 `pidof nginx`
}

status_12345()
{
  ###mysql_uwsgi_php4fpm_apache_nginx
  pid_mysql=`pidof mysqld`
  pid_uwsgi=`pidof uwsgi`
  pid_php4fpm=`pidof php-fpm`
  pid_apache=`pidof httpd`
  pid_nginx=`pidof nginx`

  if [ -n "${pid_mysql}" ]
  then
      echo "mysql is running at:${pid_mysql}"
  fi
  if [ -n "${pid_uwsgi}" ]
  then
      echo "uwsgi is running at:${pid_uwsgi}"
  fi
  if [ -n "${pid_php4fpm}" ]
  then
      echo "php-fpm is running at:${pid_php4fpm}"
  fi
  if [ -n "${pid_apache}" ]
  then
      echo "apache is running at:${pid_apache}"
  fi
  if [ -n "${pid_nginx}" ]
  then
      echo "nginx is running at:${pid_nginx}"
  fi
}

start_12345()
{
for arg_loop in "$@"
do
  case "${arg_loop}" in
    "all")
       echo "start mysql..."
       start_mysql
       echo "start uwsgi..."
       start_uwsgi
       echo "start php-fpm..."
       start_php4fpm
       echo "start apache..."
       start_apache
       echo "start nginx..."
       start_nginx
       return 0
       ;;
    "mysql")
       echo "start mysql..."
       start_mysql
       ;;
    "uwsgi")
       echo "start uwsgi..."
       start_uwsgi
       ;;
    "php-fpm")
       echo "start php-fpm..."
       start_php4fpm
       ;;
    "apache")
       echo "start apache..."
       start_apache
       ;;
    "nginx")
       echo "start nginx..."
       start_nginx
       ;;
    *)
       echo "not start anything!!!"
       exit -1
       ;;
  esac
done
}

stop_12345()
{
echo "stop_12345()"
for arg_loop in "$@"
do
  case "${arg_loop}" in
    "all")
       echo "stop apache..."
       stop_apache
       echo "stop nginx..."
       stop_nginx
       echo "stop uwsgi..."
       stop_uwsgi
       echo "stop php-fpm..."
       stop_php4fpm
       echo "stop mysql..."
       stop_mysql
       return 0
       ;;
    "apache")
       echo "stop apache..."
       stop_apache
       ;;
    "nginx")
       echo "stop nginx..."
       stop_nginx
       ;;
    "uwsgi")
       echo "stop uwsgi..."
       stop_uwsgi
       ;;
    "php-fpm")
       echo "stop php-fpm..."
       stop_php4fpm
       ;;
    "mysql")
       echo "stop mysql..."
       stop_mysql
       ;;
    *)
       echo "not stop anything!!!"
       exit -1
       ;;
  esac
done
}

print_help()
{
    help_msg="help:\r
	$0 status\r
	$0 start mysql [uwsgi, php-fpm, apache, nginx]\r
	$0 start all\r
	$0 stop all\r
	$0 stop mysql [,uwsgi, php-fpm, apache, nginx]\r
	\r"
    printf   "${help_msg}"
    exit 0
}

arg_no=$#
if [ ${arg_no} -lt  2 ]
then
    if [ "$1" == "status" ]
    then
        status_12345
    else
        print_help
    fi
elif [ "$1" == "start" ]
then
    shift
    start_12345 $@
elif [ "$1" == "stop" ]
then
    shift
    stop_12345 $@
fi
