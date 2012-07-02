#!/usr/bin/env python
# -*- coding: utf-8 -*-

from bottle import route, run, get, post, request, debug, template
import sqlite3

@route('/hello')
@route('/hello/')
@route('/hello/<name>')
@route('/hello/<name>/')
def greet(name='Stranger'):
    return '<b>Hello %s, how are you?</b>' % name

@get('/login')
def login_form():
    return '''<form action="/login" method="POST">
            name:<input name ="name" type="text" />
            passwd:<input name ="password" type="password" />
            <input type="submit" value="login" />
            </form>'''

@post('/login')
def login_submit():
    name = request.forms.get('name')
    password = request.forms.get('password')
    return '<b>Hello, %s.</b>' % name
    if check_login(name, password):
        return "<p>Your login was correct</p>"
    else:
        return "<p>Login failed</p>"

@route('/todo')
@route('/todo/')
def todo_list():
    conn = sqlite3.connect('todo.db')
    c = conn.cursor()
    ###c.execute("select id, task from todo where status like '1'")
    c.execute("select * from todo where status like '1'")
    result = c.fetchall()
    c.close()
    output = template('make_table', rows=result)
    return output

debug(True)
run(reloader=True, host='192.168.1.219', port=8080)
