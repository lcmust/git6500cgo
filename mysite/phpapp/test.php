<?php
require("class_person.php");
    $personA = new Person;
    $personA->setName("chengliu");
    if ($personA->getName()) {
        echo "personA's name:".$personA->getName();
    }
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
    date_default_timezone_set("PRC");
    //datetimezone = "Asia/Shanghai";
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
    /*if (mysql_num_rows($result) == 1)
    {
        $_SESSION['username'] = mysql_result($result, 0, "username");
        echo "Your are successfully logged in.";
    }
    */
    echo "<br/>";
    echo "name:",$result;
    echo "<br/>";

    $str = array(array("name" =>"chengliu","age"=>22),array("name"=>"sunch","age"=>33));
    foreach ($str as $str_1) {
        foreach ($str_1 as $str_2) {
	    echo "  " . $str_2;
        }
	    echo "<br/>";
    }
    function square ($x)
    {
        return $x * $x;
    }
    echo square(20);

    $i1 = 0;
    function increment(&$i1, $increment =1)
    {
	$i1 += $increment;
    }
    increment($i1);
    increment($i1);
    echo "<br/>";
    echo $i1;
    include "client-info.php";
?>
