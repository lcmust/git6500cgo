<?php
    session_start();
    $sid = session_id();
    $sessionVars = session_encode();
    echo "sid:",$sid;
    echo "<br/>";
    echo "username:",$_SESSION['username'];
    echo "<br/>";
    echo "sessionVAR:",$sessionVars;
    $_SESSION['username'] = "chengl6500";
    echo "<br/>";
    echo "Now, username is:",$_SESSION['username'];
    $timezone = "zh_CN";
    $_SESSION['loggedon'] = date("M d Y H:i:s");
    $sessionVars = session_encode();
    echo "<br/>";
    echo "sessionVAR:",$sessionVars;
    echo "<br/>";
    echo "sid:",$sid;
    $username = "django";
    $result = mysql_connect("localhost", "root", "mysql");
    mysql_select_db("mysql");
    $query = "select user,host,password from user where
             username='$username'";
    mysql_query($query, $result);
    if (mysql_num_rows($result) == 1)
    {
        $_SESSION['username'] = mysql_result($result, 0, "username");
        echo "Your are successfully logged in.";
    }
        echo "<br/>";
        echo "name:",$result;

    $persion = array("cheng","liu","zhang","yue");
    foreach ($persion as $tmp) {
        echo "name:",$tmp;
        echo "<br/>";
    }

?>
