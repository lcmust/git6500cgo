import os
import sys
sys.path.append('/mnt/sda2h/tools/git1/chengl6500/mysite')
os.environ['DJANGO_SETTINGS_MODULE'] = 'settings'
import django.core.handlers.wsgi
application = django.core.handlers.wsgi.WSGIHandler()
