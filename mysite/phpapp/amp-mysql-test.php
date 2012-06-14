<html>
        <head>
           <title>
           hello_php_mysql
           </title>
        </head>

<body>
<?php
        $mysql_server_name="localhost"; //数据库服务器名称
        $mysql_username="root"; // 连接数据库用户名
        $mysql_password="abcdefg"; // 连接数据库密码
        $mysql_database="mysql"; // 数据库的名字
        $db_conn1=mysql_connect($mysql_server_name, $mysql_username,$mysql_password);
        mysql_select_db("mysql" , $db_conn1);
        $content=mysql_query("select user,host,password from user",$db_conn1);
        echo "<table border=2 >";
        echo "<tr><th>用户名</th><th>主机</th><th>密码</th></tr>\n";
        while($myrow=mysql_fetch_row($content))
        {
            printf("<tr> <td>%s</td> <td>%s</td><td>%s</td><tr>",$myrow[0],$myrow[1],$myrow[2]);
        }
        echo "</table>";
        mysql_close($db_conn1);

        echo "end_mysql!<br>";
        include("client-info.php");
?>
</body>
</html>
