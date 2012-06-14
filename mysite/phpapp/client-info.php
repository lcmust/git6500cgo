<?php
echo("<br/>") ;
$file = $_SERVER['PHP_SELF'];
$user = $_SERVER['HTTP_USER_AGENT'];
$address = $_SERVER['REMOTE_ADDR'];

echo("<p> You are running the file <b>$file</b>.</p>\n");
echo("<p> You are viewing this page using:<br/><b>$user</b><br/><br/>from the IP addreee:<br/><b>$address</b></p>\n");

$client_info = "$file".' '."$user".' '."$address";
echo("<p>$client_info</p>");
?>